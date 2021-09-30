'use strict';
const utils = require('@iobroker/adapter-core');
const ws = require('ws');
const fs = require('fs');
const xml2js = require('xml2js');
const splice = require('buffer-splice');
const net = require('net');
//const client = new net.Socket();

let adapter, host = '127.0.0.1', port = 81, dsp, timeOutSend, pollTimeout, pingTimer, timeoutTimer, timeOutReconnect, isAlive = false, device = {}, dataFile = 'device.json',
    iteration = 0,
    pause = 10, permit = false, states = {}, old_states = {};
let timeoutSigma, timeoutSendSigma, timeSendSigma = 1, _socket, server, client, next = true;
let buffer_sigma = Buffer.from([]);
const scheme_modules = [];

const maxdBLevel = 0; // Максимальный уровень в дБ

const formats = {
    ExternalGainAlgSlew145X: {
        type:     'hex',
        inverse:  false,
        valToHex: (val) => {
            return val;
        },
        hexToVal: (val) => {
            return val;
        }
    },
    DCInpAlg145X:            {
        type:     'hex',
        inverse:  false,
        valToHex: (val) => {
            return val;
        },
        hexToVal: (val) => {
            return val;
        }
    },
    ASRCInwithGainAlg:       {
        type:     'hex',
        inverse:  false,
        valToHex: (val) => {
            return val;
        },
        hexToVal: (val) => {
            return val;
        }
    },
    MuteNoSlewADAU145XAlg:   {
        type:     'boolean',
        inverse:  true,
        valToHex: (val) => {
            return hex32(!val);
        },
        hexToVal: (val) => {
            return !parseInt(val, 10);
        }
    },
    NxNMixS3004p6Alg:        {
        type:     'float',
        inverse:  false,
        valToHex: (val) => {
            return linear_to_hexFloat(val);
        },
        hexToVal: (val) => {
            if (!hexFloatToLinear(val)){
            }
            return hexFloatToLinear(val); // hexFloat to linear
        }
    }
};

const modules = [
    {
        name:       '8 Channel Amplifier',
        img:        '8champ.png',
        i2cAddress: '6A',
        checkReg:   '01'
    },
    {
        name:       '4 analog input',
        img:        '4analoginput.png',
        i2cAddress: '11',
        checkReg:   '01'
    },
    {
        name:       '16 analog output',
        img:        '16analogoutput.png',
        i2cAddress: '6C',
        checkReg:   '01'
    }
];

const subObjects = {
    zones:   {
        volume: {
            role:  'level.volume',
            name:  'Volume zone',
            type:  'number',
            min:   0,
            max:   100,
            read:  true,
            write: true
        },
        mute:   {
            role:  'media.mute',
            name:  'Volume zone',
            type:  'boolean',
            read:  true,
            write: true
        },
        inputs: {
            role:  'state',
            name:  'Devices with output to the zone',
            type:  'string',
            read:  true,
            write: true
        }
    },
    inputs:  {
        volume:  {
            role:  'level.volume',
            name:  'Volume input',
            type:  'number',
            min:   0,
            max:   100,
            read:  true,
            write: true
        },
        mute:    {
            role:  'media.mute',
            name:  'Volume input',
            type:  'boolean',
            read:  true,
            write: true
        },
        to_zone: {
            role:  'state',
            name:  'Outputting sound to zones',
            type:  'string',
            read:  true,
            write: true
        }
    },
    control: {
        // Are created in a function "setSubObjectsControl"
    }
};

const checkRole = (str) => {
    let role = 'state';
    if (~str.indexOf('Gain')){
        role = 'level.volume';
    }
    if (~str.indexOf('NxN')){
        role = 'level.volume';
    }
    if (~str.indexOf('Mute')){
        role = 'media.mute';
    }
    return role;
};

const checkType = (str) => {
    let type = 'string';
    if (~str.indexOf('Mute')){
        type = 'boolean';
    }
    if (~str.indexOf('NxN')){
        type = 'number';
    }
    return type;
};

function startAdapter(options){
    return adapter = utils.adapter(Object.assign({}, options, {
        systemConfig: true,
        name:         'dspamp',
        ready:        main,
        unload:       (callback) => {
            try {
                saveDevice();
                dsp && dsp.close();
                _socket && _socket.destroy();
                server && server.close();
                timeOutSend && clearTimeout(timeOutSend);
                timeOutReconnect && clearTimeout(timeOutReconnect);
                pollTimeout && clearTimeout(pollTimeout);
                pingTimer && clearInterval(pingTimer);
                timeoutTimer && clearInterval(timeoutTimer);
                callback();
            } catch (e) {
                callback();
            }
        },
        stateChange:  (id, state) => {
            if (id && state && !state.ack){
                adapter.log.debug(`state ${id} changed: ${state.val} (ack = ${state.ack})`);
                permit = false;
                const ids = id.split('.');
                const type_cmd = ids[2];
                const name = ids[3];
                let cmd = ids[ids.length - 1];
                let val = state.val;
                if (type_cmd === 'control'){
                    adapter.getObject(id, (e, obj) => {
                        if (!e && obj){
                            if (formats[obj.native.detailedname]){
                                const reg = hex16(obj.native.address);
                                val = formats[obj.native.detailedname].valToHex(val);
                                cmd = 'WD' + reg + '|' + val;
                                adapter.log.debug(`Send control (${obj.native.detailedname}) / AddrReg = ${reg} Val= ${val} / WS CMD = ${cmd}`);
                                send(cmd, (res) => {
                                    if (res === 'OK'){
                                        adapter.setState(id, {
                                            val: state.val,
                                            ack: true
                                        });
                                    }
                                });
                            } else {
                                //adapter.log.debug(`WARN! ${id} / Send control (${obj.native.detailedname}) not found in formats!\n Native obj = ${JSON.stringify(obj.native)} \nSend this information to the developer!`);
                            }
                        }
                    });
                }
                if (type_cmd === 'zones'){
                    if (cmd === 'mute'){
                        val = val ? 0 :30; // TODO сохранить значение громкости до мьюта
                    }
                    const zone = name;
                    device.splitter.zones[zone].forEach((input, i) => {
                        if (device.inputs[input] && device.zones[zone]){
                            const _in = device.inputs[input].inputs;
                            const _out = device.zones[zone].outputs;
                            if (_in.length === _out.length){
                                _in.forEach((item, i) => {
                                    const st = device.mxn.name + 'vol_' + _out[i] + '_' + _in[i];
                                    adapter.setState(adapter.namespace + '.control.' + device.mxn.name_module + '.' + st, {
                                        val: val,
                                        ack: false
                                    });
                                });
                            }
                        } else {
                            if (!device.inputs[input]){
                                device.splitter.zones[zone].splice(i, 1);
                            }
                        }
                    });
                }
                if (type_cmd === 'inputs'){
                    if (cmd === 'to_zone'){
                        if (val !== ''){
                            val = val.replace(/\s/g, '').split(',');
                            device.splitter.inputs[name] = val.filter(onlyUnique).sort();
                            val.forEach((zone, i) => {
                                if (device.splitter.zones[zone]){
                                    device.splitter.zones[zone].push(name);
                                } else {
                                    device.splitter.inputs[name].splice(i, 1);
                                    adapter.log.error(`Zone (${zone}) not found, missed!`);
                                }
                            });
                            adapter.log.debug(`setState (${id}) val: ${device.splitter.inputs[name]}`);
                            adapter.setState(id, {
                                val: device.splitter.inputs[name].join(','),
                                ack: true
                            });
                            device.splitter.inputs[name].forEach((zone) => {
                                device.splitter.zones[zone] = device.splitter.zones[zone].filter(onlyUnique).sort();
                                adapter.log.debug(`setState (${adapter.namespace + '.zones.' + zone + '.inputs'}) val: ${device.splitter.zones[zone]}`);
                                adapter.setState(adapter.namespace + '.zones.' + zone + '.inputs', {
                                    val: device.splitter.zones[zone].join(','),
                                    ack: true
                                });
                            });
                        }
                    }
                    if (cmd === 'mute' || cmd === 'volume'){
                        if (cmd === 'mute'){
                            val = val ? 0 :30; // TODO сохранить значение громкости до мьюта
                        }
                        const input = name;
                        device.splitter.inputs[input].forEach((zone) => {
                            const _in = device.inputs[input].inputs;
                            const _out = device.zones[zone].outputs;
                            if (_in.length === _out.length){
                                _in.forEach((item, i) => {
                                    const st = device.mxn.name + 'vol_' + _out[i] + '_' + _in[i];
                                    adapter.setState(adapter.namespace + '.control.' + device.mxn.name_module + '.' + st, {
                                        val: val,
                                        ack: false
                                    });
                                });
                            }
                        });
                    }
                }
                if (type_cmd === 'sigmaTCP'){
                    if (cmd === 'running'){
                        sigmaTCPServer(val);
                    }
                }
            }
        },
        message:      obj => {
            if (typeof obj === 'object' && obj.command){
                adapter.log.debug(`message ******* ${JSON.stringify(obj)}`);
                if (obj.command === 'getConfigFromDevice'){
                    getConfigFromDevice(obj.message.host, obj.message.port, () => {
                        obj.callback && adapter.sendTo(obj.from, obj.command, device, obj.callback);
                    });
                }
                if (obj.command === 'saveConfigToDevice'){
                    saveConfigToDevice(obj.message.data, (msg) => {
                        if (msg === 'OK'){
                            obj.callback && adapter.sendTo(obj.from, obj.command, {result: msg}, obj.callback);
                        } else {
                            obj.callback && adapter.sendTo(obj.from, obj.command, {error: msg}, obj.callback);
                        }
                    });
                }
                if (obj.command === 'reboot'){
                    adapter.log.debug('Reboot device');
                    send('Q', (res) => {
                        if (res === 'OK'){
                            obj.callback && adapter.sendTo(obj.from, obj.command, {result: res}, obj.callback);
                        } else {
                            obj.callback && adapter.sendTo(obj.from, obj.command, {error: res}, obj.callback);
                        }
                    });
                }
                if (obj.command === 'reset'){
                    adapter.log.debug('Reset config device');
                    send('T', (res) => {
                        if (res === 'OK'){
                            obj.callback && adapter.sendTo(obj.from, obj.command, {result: res}, obj.callback);
                        } else {
                            obj.callback && adapter.sendTo(obj.from, obj.command, {error: res}, obj.callback);
                        }
                    });
                }
                if (obj.command === 'checkXmlProject'){
                    checkXmlProject((e) => {
                        if (!e){
                            obj.callback && adapter.sendTo(obj.from, obj.command, device, obj.callback);
                        } else {
                            obj.callback && adapter.sendTo(obj.from, obj.command, {error: e}, obj.callback);
                        }
                    });
                }
                if (obj.command === 'getDeviceFile'){
                    getDeviceFile((e) => {
                        if (!e){
                            obj.callback && adapter.sendTo(obj.from, obj.command, device, obj.callback);
                        } else {
                            obj.callback && adapter.sendTo(obj.from, obj.command, {error: e}, obj.callback);
                        }
                    });
                }
                if (obj.command === 'saveDevice'){
                    saveDevice(obj.message.device, (msg) => {
                        obj.callback && adapter.sendTo(obj.from, obj.command, msg, obj.callback);
                    });
                }
                if (obj.command === 'writeFile'){
                    writeFile(obj.message.filename, obj.message.data, (msg) => {
                        obj.callback && adapter.sendTo(obj.from, obj.command, {result: msg}, obj.callback);
                    });
                }
                if (obj.command === 'delFile'){
                    delFile(obj.message.filename, (msg) => {
                        obj.callback && adapter.sendTo(obj.from, obj.command, {result: msg}, obj.callback);
                    });
                }
                if (obj.command === 'readDir'){
                    readDir((msg) => {
                        obj.callback && adapter.sendTo(obj.from, obj.command, msg, obj.callback);
                    });
                }
                if (obj.command === 'beepZone'){
                    const zone = obj.message.zone;
                    const maxInput = Math.max.apply(null, device.mxn.input.list_array);
                    let regMxn, regBeep;
                    for (const key in device.address_map) {
                        if (device.address_map[key].name === device.mxn.name + 'vol_' + zone + '_' + maxInput){
                            regMxn = hex16(key);
                        }
                        if (device.address_map[key].name === 'BeepAlg_S3001enable'){ //TODO жестко завязано на имя модуля
                            regBeep = hex16(key);
                        }
                    }
                    if (regMxn && regBeep){
                        send('WD' + regMxn + '|01000000', () => {
                            send('WD' + regBeep + '|01000000', () => {
                                setTimeout(() => {
                                    send('WD' + regBeep + '|00000000', () => {
                                        send('WD' + regMxn + '|00000001', () => {
                                        });
                                    });
                                }, 500);
                            });
                        });
                    }
                    obj.callback && adapter.sendTo(obj.from, obj.command, {result: 'OK'}, obj.callback);
                }
                if (obj.command === 'sigmaTCP'){
                    adapter.setState('sigmaTCP.running', !!obj.message.val, false);
                    obj.callback && adapter.sendTo(obj.from, obj.command, {result: 'OK'}, obj.callback);
                }
            } else {
                adapter.log.debug(`message x ${obj.command}`);
            }
        }
    }));
}

function parseSigma(){
    if (next){
        let packet, lenPacket, lenData, data, addr, mode;
        if (buffer_sigma[0] === 0x09){
            mode = 'Block Write';
            lenPacket = buffer_sigma.slice(3, 7).readUInt32BE(0);
            packet = buffer_sigma.slice(0, lenPacket);
            buffer_sigma = splice(buffer_sigma, 0, lenPacket);
            lenData = packet.slice(8, 12).readUInt32BE(0);
            data = packet.slice(14, lenPacket).toString('hex').toUpperCase();
            addr = packet.slice(12, 14).toString('hex').toUpperCase();
        }
        if (buffer_sigma[0] === 0x0A){
            mode = 'Read Request';
            lenPacket = buffer_sigma.slice(1, 5).readUInt32BE(0);
            packet = buffer_sigma.slice(0, lenPacket);
            buffer_sigma = splice(buffer_sigma, 0, lenPacket);
            lenData = packet.slice(6, 10).readUInt32BE(0);
            data = packet.slice(12, lenPacket).toString('hex').toUpperCase();
            addr = packet.slice(10, 12).toString('hex').toUpperCase();
        }
        if (addr === '0034'){ //Erase EEPROM
            timeSendSigma = 5000;
        } else {
            timeSendSigma = 1;
        }
        if (packet){
            next = false;
            const space = '                                                                                                         ';
            SIGMA_LOG('Send to DSP > Mode: ' + mode + ' / Address: 0x' + addr + ' / Bytes: ' + lenData + '  / Data: ' + (lenData > 4 ? '\n'+ space : '')  + '0x'.concat(data.match(/[0-9a-f]{2}/g).join(', 0x')).match(/.{1,24}/g).join('\n'+space));
            adapter.log.debug('client.write(' + packet.toString('hex').toUpperCase() + ')');
            client && client.write(packet);
        }
    }
}

function sigmaTCPClient(){
    client = net.connect(8086, adapter.config.host, () => {
        SIGMA_LOG(`Amplifier connected`);
        adapter.setState('sigmaTCP.connected', true, true);
    });
    client.on('data', (data) => {
        //adapter.log.debug('client data - ' + data);
        if (data.toString() === '>'){
            adapter.log.debug('Send next packet to Amplifier');
            timeoutSendSigma = setTimeout(() => {
                next = true;
            }, timeSendSigma);
        } else {
            _socket && _socket.write(data);
        }
    });
    client.on('error', (e) => {
        SIGMA_LOG(`Amplifier client error: ${e}`);
    });
    client.on('close', () => {
        SIGMA_LOG(`Amplifier connection closed`);
        adapter.setState('sigmaTCP.connected', false, true);
    });
}

function sigmaTCPServer(state){
    if (state){
        const sigma_port = 8086, sigma_host = '127.0.0.1';
        server && server.close();
        server = null;
        server = net.createServer((socket) => {
            _socket = socket;
            SIGMA_LOG(`SigmaStudio connected`);
            sigmaTCPClient();
            socket.on('data', (data) => {
                buffer_sigma = Buffer.concat([buffer_sigma, data]);
                timeoutSigma && clearInterval(timeoutSigma);
                timeoutSendSigma && clearTimeout(timeoutSendSigma);
                timeoutSigma = setInterval(() => {
                    if (buffer_sigma.length > 0){
                        parseSigma();
                    }
                }, 100);
                timeoutSendSigma = setTimeout(() => {
                    next = true;
                }, 10000);
            });
            socket.on('connect', () => { //del
                SIGMA_LOG(`socket connected`);
            });
            socket.on('close', () => {
                SIGMA_LOG(`SigmaStudio connection closed`);
                timeoutSigma && clearInterval(timeoutSigma);
                client && client.end();
                client && client.destroy();
                //adapter.setState('sigmaTCP.running', false, true);
            });
        }).on('error', (e) => {
            SIGMA_LOG(`TCPi server error: ${e}`);
            timeoutSigma && clearInterval(timeoutSigma);
            client && client.end();
            adapter.setState('sigmaTCP.running', false, true);
        }).on('close', () => {
            SIGMA_LOG(`TCPi server closed`);
            adapter.setState('sigmaTCP.running', false, true);
        });
        server.listen(sigma_port, sigma_host, () => {
            buffer_sigma = Buffer.from([]);
            SIGMA_LOG(`TCPi server started on ${JSON.stringify(server.address())}`);
            adapter.setState('sigmaTCP.running', true, true);
        });
    } else {
        _socket && _socket.destroy();
        client && client.end();
        server && server.close();
        server = null;
    }
}

function SIGMA_LOG(txt){
    adapter.setState('sigmaTCP.log', txt, true);
    adapter.log.debug(txt);
}

function writeFile(filename, data, cb){
    const dir = utils.controllerDir + '/' + adapter.systemConfig.dataDir + adapter.namespace.replace('.', '_') + '/';
    filename = dir + filename;
    fs.writeFile(filename, data, (err) => {
        if (err) adapter.log.error('writeFile ERROR = ' + JSON.stringify(err));
        cb && cb('ok');
    });
}

function saveConfigToDevice(data, cb){
    send(JSON.stringify(data), (res) => {
        adapter.log.debug('Response save Config To Device - ' + res);
        cb && cb(res);
    });
}

function delFile(filename, cb){
    const dir = utils.controllerDir + '/' + adapter.systemConfig.dataDir + adapter.namespace.replace('.', '_') + '/';
    filename = dir + filename;
    fs.unlink(filename, (err) => {
        if (err) adapter.log.error('delFile ERROR = ' + JSON.stringify(err));
        cb && cb('ok');
    });
}

function parseXMLFiles(xmlFiles, cb){
    adapter.log.debug('Start parseXMLFiles');
    const parser = new xml2js.Parser();
    const dir = utils.controllerDir + '/' + adapter.systemConfig.dataDir + adapter.namespace.replace('.', '_') + '/';
    xmlFiles.forEach((filename) => {
        fs.readFile(dir + filename, (e, data) => {
            if (!e){
                parser.parseString(data, (e, result) => {
                    if (!e){
                        cb && cb(result);
                    } else {
                        adapter.log.error('Error pase XML file ' + filename + ' ' + e);
                        cb && cb('Error pase XML file ' + filename + ' ' + e);
                    }
                });
            } else {
                adapter.log.error('Error read file ' + filename + ' ' + e);
                cb && cb('Error read file ' + filename + ' ' + e);
            }
        });
    });
}

function checkXMLConfigFile(obj, cb){
    adapter.log.debug('Start checkXMLConfigFile');
    if (obj.hasOwnProperty('Schematic') && obj.Schematic.hasOwnProperty('IC') && obj.Schematic.IC[0].PartNumber[0] === 'ADAU1452'){
        cb && cb(obj.Schematic.IC[0].Module);
    } else {
        cb && cb({error: 'ERROR checkXMLConfigFile. File not valid'});
    }
}

function parseSchematicModules(data, cb){
    const mxn = {
        name:        '',
        name_module: '',
        input:       {
            list_array: []
        },
        output:      {
            list_array: []
        }
    };
    device.schematic = {};
    device.schematic.modules = {};
    data.forEach((module) => {
        const key = module.CellName[0] = module.CellName[0].replace(/\s/g, '_').replace(/ /g, '_').replace(/\./g, '_');
        module.Algorithm[0].ModuleParameter.forEach((item, i) => {
            module.Algorithm[0].ModuleParameter[i].Name = item.Name[0];
            module.Algorithm[0].ModuleParameter[i].Type = item.Type[0];
            module.Algorithm[0].ModuleParameter[i].Address = parseInt(item.Address[0], 10);
            if (item.Type === 'HexArray'){
                module.Algorithm[0].ModuleParameter[i].Value = item.Data[0];
            } else {
                module.Algorithm[0].ModuleParameter[i].Value = item.Value[0];
            }
            module.Algorithm[0].ModuleParameter[i].Size = parseInt(item.Size[0], 10);
            module.Algorithm[0].ModuleParameter[i].Data = item.Data[0].replace(/\s/g, '').split(',').filter(Boolean)/*.map(Number)*/;
        });
        device.schematic.modules[key] = {
            AlgoName:        module.Algorithm[0].AlgoName[0],
            DetailedName:    module.Algorithm[0].DetailedName[0],
            Description:     module.Algorithm[0].Description[0],
            ModuleParameter: module.Algorithm[0].ModuleParameter
        };
        if (module.CellName[0] === 'NxM_Mixer1'){ // TODO Должно соответсвовать проекту сигмы, сделать настраиваемым имя???
            module.Algorithm[0].ModuleParameter.forEach((param) => {
                const outin = param.Name.slice(param.Name.indexOf('vol_')).replace('vol_', '').split('_');
                const _input = outin[1];
                const _output = outin[0];
                mxn.name_module = module.CellName[0];
                mxn.name = module.Algorithm[0].DetailedName[0];
                if (!~mxn.input.list_array.indexOf(_input)){
                    mxn.input.list_array.push(_input);
                }
                if (!~mxn.output.list_array.indexOf(_output)){
                    mxn.output.list_array.push(_output);
                }
            });
        }
    });
    device.mxn = mxn;
    cb && cb();
}

function checkXmlProject(cb){
    adapter.log.debug('Start checkXmlProject');
    readDir((res) => {
        const xmlFiles = [];
        res.forEach((item) => {
            if (~item.name.indexOf('.xml')){
                xmlFiles.push(item.name);
            }
        });
        if (xmlFiles.length > 0){
            parseXMLFiles(xmlFiles, (obj) => {
                checkXMLConfigFile(obj, (res) => {
                    if (!res.error){
                        parseSchematicModules(res, () => {
                            saveDevice(() => {
                                cb && cb();
                            });
                        });
                    } else {
                        adapter.log.error(res.error);
                        cb && cb(res.error);
                    }
                });
            });
        } else {
            adapter.log.warn('XML file not found, download project XML file first.');
            cb && cb('XML file not found, download project XML file first.');
        }
    });
}

function readDir(cb){
    const path = utils.controllerDir + '/' + adapter.systemConfig.dataDir + adapter.namespace.replace('.', '_') + '/';
    const res = [];
    fs.readdir(path, {withFileTypes: true}, (err, files) => {
        const filesNames = files.filter(files => files.isFile()).map(files => files.name);
        for (let i = 0; i < filesNames.length; i++) {
            res.push({
                file:  filesNames[i],
                stats: {}
            });
            const file = path + '/' + filesNames[i];
            const fileStat = fs.statSync(file);
            if (fileStat){
                res[i] = {
                    name:  filesNames[i],
                    stats: fileStat
                };
            }
        }
        cb && cb(res);
    });
}

function getConfig(_host, _cb, cb){
    const http = require('http');
    const options = {
        host: _host,
        path: '/get_settings'
    };
    const resp = (data) => {
        let str = '';
        data.on('data', (chunk) => {
            str += chunk;
        });
        data.on('end', () => {
            adapter.log.debug('getConfig - ' + str);
            try {
                device.config = JSON.parse(str);
                cb && cb(true);
            } catch (e) {
                adapter.log.error('getConfig parse Error - ' + e);
                _cb && _cb(e);
            }
        });
        data.on('error', (e) => {
            adapter.log.debug('getConfig Error - ' + e);
            cb && cb(false);
        });
    };
    http.request(options, resp).on('error', (e) => {
        adapter.log.error('getConfig Error - ' + e);
        cb && cb(e);
    }).end();
}

function checkNumNodes(i, nodes, cb){
    adapter.log.debug('Start checkNumNodes');
    send('RS' + i + '|02', (data) => {
        i++;
        if (data === 'ad'){
            nodes++;
            checkNumNodes(i, nodes, cb);
        } else if (data === '00'){
            cb && cb(nodes);
        }
    });
}

function checkModuleFromNodes(i, nodes, cb){
    adapter.log.debug('Start checkModuleFromNodes');
    send('RN' + nodes + '|' + modules[i].i2cAddress + '|' + modules[i].checkReg, (data) => { //RN00|6A|0F
        if (data !== '00'){
            scheme_modules[nodes] = {
                img:  modules[i].img,
                name: modules[i].name
            };
            nodes++;
            i = -1;
        }
        i++;
        if (i >= modules.length){
            nodes++;
            i = -1;
        }
        if (nodes < device.num_nodes){
            checkModuleFromNodes(i, nodes, cb);
        } else {
            cb && cb();
        }
    });
}

function discovery(cb){
    adapter.log.debug('Start discovery');
    send('RDF405|02', () => {
        checkNumNodes(0, -1, (nodes) => {
            device.num_nodes = nodes + 1;
            checkModuleFromNodes(0, 0, () => {
                device.modules = scheme_modules;
                saveDevice();
                cb && cb();
            });
        });
    });
}

function getConfigFromDevice(_host, _port, cb){
    if (!_host){
        _host = host;
    }
    if (!_port){
        _port = port;
    }
    pingTimer && clearInterval(pingTimer);
    timeoutTimer && clearInterval(timeoutTimer);
    timeOutSend && clearTimeout(timeOutSend);
    dsp && dsp.removeAllListeners();
    dsp && dsp.close();
    adapter.log.info('getConfigFromDevice/ DSP AMP connect to: ' + _host + ':' + _port);
    getConfig(_host, cb, () => {
        dsp = new ws('ws://' + _host + ':' + _port, {});
        dsp.on('open', () => {
            adapter.log.debug('getConfigFromDevice ' + dsp.url + ' DSP AMP connected');
            discovery(cb);
        });
        dsp.on('error', (e) => {
            adapter.log.debug('Error WS - ' + e);
            dsp && dsp.close();
            cb && cb('Error getConfigFromDevice WS - ' + e);
        });
        dsp.on('close', (e) => {
            adapter.log.debug('getConfigFromDevice WS CLOSED, CODE - ' + e);
            cb && cb('ERROR! getConfigFromDevice WS CLOSE, CODE - ' + e);
        });
    });
}

function getAddressArray(cb){
    const addresses = [];
    for (const addr in device.address_map) {
        addresses.push(addr);
    }
    cb && cb(addresses);
}

function iterator(addresses){
    if (device.address_map){
        pollTimeout = setTimeout(() => {
            pollTimeout && clearTimeout(pollTimeout);
            pollTimeout = null;
            pause = 10;
            const reg = hex16(addresses[iteration]);
            const name = device.address_map[addresses[iteration]].name;
            const main = device.address_map[addresses[iteration]].main;
            send('RD' + reg + '|04', (val) => {
                if (val !== 'error'){
                    /*if(!device.schematic.modules[main]){
                        delete device.address_map[addresses[iteration]];
                        iteration++;
                        if (iteration >= addresses.length){
                            iteration = 0;
                            setSatates(states);
                            pause = 2000;
                        }
                        if (permit){
                            iterator(addresses);
                        }
                        return;
                    }*/
                    const detailname = device.schematic.modules[main].DetailedName.replace(/[\d.]+$/, '');
                    let id = adapter.namespace + '.control.' + main + '.' + name;
                    if (formats[detailname]){
                        val = formats[detailname].hexToVal(val);
                    } else {
                        //adapter.log.debug(`WARN! ${adapter.namespace + '.control.' + main + '.' + name} / Read value (${detailname}) not found in formats!\n Send this information to the developer!`);
                    }
                    if (~name.indexOf('NxN')){
                        const outin = name.slice(name.indexOf('vol_')).replace('vol_', '').split('_');
                        const _in = outin[1];
                        const _out = outin[0];
                        for (const zone in device.zones) {
                            if (device.zones.hasOwnProperty(zone)){
                                if (zone !== 'undefined' && device.zones[zone].outputs.length > 0){
                                    for (const zone_out of device.zones[zone].outputs) {
                                        if (zone_out === _out){
                                            for (const input in device.inputs) {
                                                if (device.inputs.hasOwnProperty(input)){
                                                    if (input !== 'undefined' && device.inputs[input].inputs.length > 0){
                                                        for (const input_in of device.inputs[input].inputs) {
                                                            if (zone_out === _out && input_in === _in && device.splitter.inputs[input].includes(zone)){
                                                                states[adapter.namespace + '.inputs.' + input + '.volume'] = val;
                                                                states[adapter.namespace + '.zones.' + zone + '.volume'] = val;
                                                                if (val === 0){
                                                                    states[adapter.namespace + '.inputs.' + input + '.mute'] = true;
                                                                    states[adapter.namespace + '.zones.' + zone + '.mute'] = true;
                                                                } else {
                                                                    states[adapter.namespace + '.inputs.' + input + '.mute'] = false;
                                                                    states[adapter.namespace + '.zones.' + zone + '.mute'] = false;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    states[id] = val;
                    iteration++;
                    if (iteration >= addresses.length){
                        iteration = 0;
                        setSatates(states);
                        pause = 2000;
                    }
                    if (permit){
                        iterator(addresses);
                    }
                } else {
                    adapter.log.error('Response read data ' + 'RD' + reg + '|04 = ' + val);
                }
            });
        }, pause);
    }
}

function setSatates(states){
    permit = false;
    for (const id in states) {
        if (states.hasOwnProperty(id)){
            if (old_states[id] !== states[id] || states[id] === null){
                const val = states[id];
                adapter.setState(id, {
                    val: val,
                    ack: true
                });
                old_states[id] = states[id];
            } else {
                old_states[id] = states[id];
            }
        }
    }
    permit = true;
}

function pollDevice(){
    if (device.address_map){
        getAddressArray((addresses) => {
            iterator(addresses);
        });
    } else {
        getAddressesMap(() => {
            pollDevice();
        });
    }
}

function getAddressesMap(cb){
    //if (!device.address_map){
    device.address_map = {};
    //}
    for (const key in device.schematic.modules) {
        const obj = device.schematic.modules[key];
        if (obj.ModuleParameter.length > 0){
            obj.ModuleParameter.forEach((item) => {
                device.address_map[item.Address] = {
                    name: item.Name,
                    main: key
                };
            });
        } else {
            device.address_map[obj.ModuleParameter[0].Address] = obj.ModuleParameter[0].Name;
        }
    }
    cb && cb();
}

const connect = () => {
    dsp && dsp.close();
    adapter.log.info('DSP AMP connect to: ' + host + ':' + port);
    dsp = new ws('ws://' + host + ':' + port, {});
    dsp.on('open', () => {
        adapter.log.info(dsp.url + ' DSP AMP connected');
        adapter.setState('info.connection', true, true);
        permit = true;
        isAlive = true;
        if (device.schematic){
            pollDevice();
        }
        timeoutTimer && clearInterval(timeoutTimer);
        pingTimer && clearInterval(pingTimer);
        timeOutSend = setTimeout(() => {
            timeOutSend && clearTimeout(timeOutSend);
            timeOutSend = null;
        }, 5000);
        pingTimer = setInterval(() => {
            if (dsp){
                dsp.ping('ping'); // Работает только на "ws": "^5.1.0", на последних версиях возращает ошибку.
            }
        }, 5000);
        timeoutTimer = setInterval(() => {
            if (!isAlive){
                adapter.log.debug(dsp.url + ' not receive a pong');
                dsp && dsp.terminate();
            } else {
                isAlive = false;
            }
        }, 6000);
    });
    dsp.on('pong', (msg) => {
        isAlive = true;
        //adapter.log.debug(dsp.url + ' receive a pong : ' + msg);
    });
    dsp.on('error', (e) => {
        adapter.log.debug('Error WS - ' + e);
    });
    dsp.on('close', (e) => {
        pingTimer && clearInterval(pingTimer);
        timeoutTimer && clearInterval(timeoutTimer);
        timeOutSend && clearTimeout(timeOutSend);
        adapter.log.error('ERROR! WS CLOSE, CODE - ' + e);
        adapter.log.debug('DSP reconnect after 10 seconds');
        adapter.setState('info.connection', false, true);
        timeOutReconnect = setTimeout(() => {
            timeOutReconnect = null;
            connect();
        }, 10000);
    });
};

function send(data, cb){
    if (dsp){
        dsp.once('message', (msg) => {
            //adapter.log.debug('Response data - ' + msg);
            permit = true;
            if (msg === 'Connected'){
                isAlive = true;
                if (msg === 'Connected'){
                    adapter.setState('info.connection', true, true);
                }
                dsp.once('message', (msg) => {
                    cb && cb(msg);
                });
            } else {
                cb && cb(msg);
            }
        });
        try {
            dsp.send(data, (e) => {
                if (e){
                    adapter.log.error('Send command: {' + data + '}, ERROR - ' + e);
                    if (~e.toString().indexOf('CLOSED') || ~e.toString().indexOf('CONNECTING')){
                        adapter.setState('info.connection', false, true);
                        //connect();
                    }
                } else {
                    //adapter.log.debug('Sended command:{' + data + '}');
                }
            });
        } catch (e) {
            adapter.log.error('Send command: {' + data + '}, ERROR - ' + e);
        }
    }
}

function deleteOldObjects(newObj, cb){
    adapter.log.debug('deleteOldObjects from ' + newObj);
    adapter.getAdapterObjects((adapterObjects) => {
        let ids = [], newStates = [], fullids = [];
        for (const id in adapterObjects) {
            id.split('.')[2] === newObj && id.split('.')[3] && ids.push(id.split('.')[3]);
            fullids.push(id);
        }
        ids = ids.filter(onlyUnique).sort();
        if (newObj === 'control'){
            for (const state in device.schematic.modules) {
                newStates.push(state);
            }
        } else {
            for (const state in device[newObj]) {
                newStates.push(state);
            }
        }
        newStates = newStates.sort();
        const candidate = ids.filter((el) => {
            return newStates.indexOf(el) === -1;
        }).filter(onlyUnique).sort();
        adapter.log.debug('Candidates for delete = ' + (candidate.length > 0 ? candidate :'null') + ' \n/ Adapter objects ids = ' + ids + ' \n/ Objects newStates   = ' + newStates);
        if (newStates.length > 0 && candidate.length > 0){
            candidate.forEach((del) => {
                const id = adapter.namespace + '.' + newObj + '.' + del;
                adapter.log.debug('Delete object - ' + id);
                adapter.delObject(id, {recursive: true}, (e) => {
                    adapter.log.error('Error delete object - ' + id + ' Err: ' + e);
                });
            });
        }
        cb && cb(fullids);
    });
}

function setObjects(objName, cb){
    deleteOldObjects(objName, (ids) => {
        for (const key in device[objName]) {
            if (key !== 'undefined'){
                for (const sub in subObjects[objName]) {
                    const id = adapter.namespace + '.' + objName + '.' + key + '.' + sub;
                    const common = {
                        name:  subObjects[objName][sub].name,
                        desc:  subObjects[objName][sub].name,
                        type:  subObjects[objName][sub].type,
                        role:  subObjects[objName][sub].role,
                        read:  subObjects[objName][sub].read,
                        write: subObjects[objName][sub].write
                    };
                    if (ids.indexOf(id) === -1){ //Если нет среди существующих обьектов адаптера - создаем обьект
                        adapter.setObject(id, {
                            type:   'state',
                            common: common,
                            native: {} // TODO
                        }, () => {
                            adapter.setState(id, {
                                val: '',
                                ack: true
                            }); // TODO FIX VAL TYPE
                        });
                    } else {
                        adapter.extendObject(id, {
                            type:   'state',
                            common: common,
                            native: {} // TODO
                        });
                    }
                }
            }
        }
        cb && cb();
    });
}

function setSubObjectsControl(cb){
    for (const key in device.schematic.modules) {
        let name = key, min = null, max = null, write = true;
        subObjects.control[key] = {};
        if (device.schematic.modules[key].ModuleParameter.length > 0){
            device.schematic.modules[key].ModuleParameter.forEach((obj) => {
                const native = {};
                name = obj.Name;
                native.address = obj.Address;
                native.size = obj.Size;
                native.value = obj.Value;
                native.data = obj.Data;
                native.algoname = device.schematic.modules[key].AlgoName;
                native.detailedname = device.schematic.modules[key].DetailedName.replace(/[\d\.]+$/, '');
                native.description = device.schematic.modules[key].Description;
                subObjects.control[key][name] = {
                    role:  checkRole(name),
                    name:  name,
                    type:  checkType(name),
                    read:  true,
                    write: write
                };
                min ? subObjects.control[key][name].min = min :'';
                max ? subObjects.control[key][name].max = max :'';
                subObjects.control[key][name].native = native;
            });
        }
    }
    cb && cb();
}

function setControlObjects(cb){
    deleteOldObjects('control', (ids) => {
        setSubObjectsControl(() => {
            for (const control in subObjects.control) {
                for (const sub in subObjects.control[control]) {
                    const id = adapter.namespace + '.control.' + control + '.' + [sub];
                    const native = subObjects.control[control][sub].native ? subObjects.control[control][sub].native :{};
                    const common = {
                        name:  subObjects.control[control][sub].name,
                        desc:  native.detailedname,
                        type:  subObjects.control[control][sub].type,
                        role:  subObjects.control[control][sub].role,
                        read:  subObjects.control[control][sub].read,
                        write: subObjects.control[control][sub].write
                    };
                    if (ids.indexOf(id) === -1){
                        adapter.log.debug('Create object - ' + id);
                        adapter.setObject(id, {
                            type:   'state',
                            common: common,
                            native: native
                        }, () => {
                            adapter.setState(id, {
                                val: '',
                                ack: true
                            }); // TODO FIX VAL TYPE
                        });
                    } else {
                        adapter.log.debug('Update object - ' + id);
                        adapter.extendObject(id, {
                            type:   'state',
                            common: common,
                            native: native
                        });
                    }
                }
            }
            cb && cb();
        });
    });
}

function createObjects(cb){
    setObjects('zones', () => {
        setControlObjects(() => {
            setObjects('inputs', () => {
                cb && cb();
            });
        });
    });
}

function confirmSplitterToObjects(cb){  // TODO установить текущее распределение Splitter в обьекты при запуске адаптера
    if (!device.splitter) cb && cb(); //Не сконфигурировано
    /*console.log(device.splitter);
    for(const zone in device.splitter.zones){
        device.splitter.zones[zone].forEach((item)=>{
            adapter.setState(adapter.namespace + '.' + );
        });
    }*/
    cb && cb();
}

function main(){
    if (!adapter.systemConfig) return;
    adapter.subscribeStates('*');
    host = adapter.config.host ? adapter.config.host :'127.0.0.1';
    port = adapter.config.port ? adapter.config.port :81;
    if (host && port){
        const dir = utils.controllerDir + '/' + adapter.systemConfig.dataDir + adapter.namespace.replace('.', '_') + '/';
        dataFile = dir + dataFile;
        adapter.log.debug('adapter.config = ' + JSON.stringify(adapter.config));
        if (!fs.existsSync(dir)) fs.mkdirSync(dir);
        fs.readFile(dataFile, (err, data) => {
            if (!err){
                try {
                    device = JSON.parse(data);
                    adapter.log.debug('Parse config file ' + dataFile);
                    if (device.schematic){
                        createObjects(() => {
                            confirmSplitterToObjects(() => {
                                getAddressesMap(() => {
                                    connect();
                                });
                            });
                        });
                    } else {
                        connect();
                    }
                } catch (err) {
                    adapter.log.debug('Parse config file Error: ' + err);
                    fs.writeFile(dataFile, '', (err) => {
                        if (err) adapter.log.error('writeFile ERROR = ' + JSON.stringify(err));
                        adapter.log.debug('New config file created and save.');
                        connect();
                    });
                }
            } else {
                adapter.log.debug('readFile config file Error. Create new file. ' + err);
                fs.writeFile(dataFile, '', (err) => {
                    if (err) adapter.log.error('writeFile ERROR = ' + JSON.stringify(err));
                    adapter.log.debug('New config file created and save.');
                    connect();
                });
            }
        });
    } else {
        adapter.log.error('Config ERROR!');
    }
}

function getDeviceFile(cb){
    adapter.log.debug('Start getDeviceFile');
    fs.readFile(dataFile, (err, data) => {
        if (!err){
            try {
                device = JSON.parse(data);
                cb && cb();
            } catch (e) {
                adapter.log.error('getDeviceFile parse Error - ' + e);
                cb && cb(e);
            }
        } else {
            adapter.log.error('getDeviceFile readFile Error - ' + err);
            cb && cb(err);
        }
    });
}

function saveDevice(_device, cb){
    adapter.log.debug('Start saveDevice');
    if (!cb){
        cb = _device;
    } else {
        device = _device;
    }
    const data = JSON.stringify(device, null, 2);
    fs.writeFile(dataFile, data, (err) => {
        if (err) adapter.log.error('writeFile Error - ' + err);
        adapter.log.debug('Данные сохранены в файл успешно.');
        cb && cb();
    });
}

function hex16(val){
    val &= 0xFFFF;
    const hex = val.toString(16).toUpperCase();
    return ('0000' + hex).slice(-4);
}

function hex32(val){
    val &= 0xFFFFFFFF;
    const hex = val.toString(16).toUpperCase();
    return ('00000000' + hex).slice(-8);
}

function float_to_hex(float){
    if (float === 0){
        return '00000000';
    } else if (float === 1){
        return '01000000';
    } else {
        return '0' + float.toString(16).replace('.', '').substr(0, 7);
    }
}

function dB_to_hex(dB){
    return float_to_hex(dB_to_float(dB));
}

function linear_to_hexFloat(linear){
    return dB_to_hex(linear_to_dB(linear));
}

function dB_to_float(dB){
    return Math.pow(10.0, dB / 20.0);
}

function float_to_dB(float){
    return 20 * Math.log10(float);
}

function linear_to_dB(linear){
    return /*(maxdBLevel ? maxdBLevel :0) + */ 20.0 * Math.log10(linear / 100.0);  // !!! 20 * Math.log(linear / 100)
    // TODO for 0  20.0 * Math.log10(0/100.0) = -infinity
}

function hexFloatToLinear(val){
    const sign = (parseInt(val, 16) & 0x80000000) ? -1 :1;
    const float = sign * parseInt(val, 16) / Math.pow(2, 24);
    return Math.round((Math.pow(10.0, float_to_dB(float) / 20.0) * 100) * 10) / 10;
    // OR return Math.round((Math.pow(Math.exp(1), float_to_dB(float) / 20.0) * 100) * 10) / 10;
}

function linear_to_float(linear){
    return dB_to_float(linear_to_dB(linear));
}

function onlyUnique(value, index, self){
    return self.indexOf(value) === index;
}

if (module.parent){
    module.exports = startAdapter;
} else {
    startAdapter();
}