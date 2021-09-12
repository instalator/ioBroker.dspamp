'use strict';
const utils = require('@iobroker/adapter-core');
const ws = require('ws');
const fs = require('fs');
const xml2js = require('xml2js');

let adapter, host, port, dsp, timeOutSend, pollTimeout, pingTimer, timeoutTimer, timeOutReconnect, isAlive = false, device = {}, dataFile = 'device.json', iteration = 0,
    pause = 10, permit = false, states = {}, old_states = {};
const scheme_modules = [];
const maxdBLevel = 0; // Максимальнуй уровень в дБ

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

/**
 Чтение регистров:
 RD[uint16_t reg][unsigned short count]  RDFFFF|FF  RD0066|04  //Чтение регистра DSP
 RN[uint8_t node][uint8_t slaveAddr][unsigned char AddrReg] RN00|FF|FF  RN00|6A|0F  //Чтениер регистров слейвов на нодах
 RS[uint8_t node][uint8_t AddrReg]  RSFF|FF  RS00|0D  //Счетние регистров слейва
 RM[uint8_t reg]  RMFF  RM66  //Чтение регистров мастер ноды

 Запись в регистры:
 WD[uint16_t reg][bytes]  WFFFF|FFFFFFFF  WD0066|00000001  //Запись в регистр DSP
 WN[uint8_t node][uint8_t slaveAddr][bytes(addr,data)] WN0|FF|FF|00  WN00|6A|21|80  //Запись регистров слейвов на нодах
 WS[uint8_t node][uint8_t AddrReg][uint8_t data]  WSFF|FF|FF  WS00|0D|01  //Запись регистра слейва
 WM[uint8_t reg][uint8_t data]  WMFF|FF  WM66|01  //Запись регистра мастер ноды
 */

function startAdapter(options){
    return adapter = utils.adapter(Object.assign({}, options, {
        systemConfig: true,
        name:         'dspamp',
        ready:        main,
        unload:       (callback) => {
            try {
                saveDevice();
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
                                adapter.log.debug(`WARN! ${id} / Send control (${obj.native.detailedname}) not found in formats!\n Native obj = ${JSON.stringify(obj.native)} \nSend this information to the developer!`);
                            }
                        }
                    });
                }
                if (type_cmd === 'zones'){
                    if (cmd === 'mute'){
                        val = val ? 0 :30; // TODO сохранить значение громкости до мьюта
                    }
                    const zone = name;
                    device.splitter.zones[zone].forEach((input) => {
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
                        obj.callback && adapter.sendTo(obj.from, obj.command, {result: msg}, obj.callback);
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

            } else {
                adapter.log.debug(`message x ${obj.command}`);
            }
        }
    }));
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
    send(JSON.stringify(data), () => {
        cb && cb('ok');
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
            module.Algorithm[0].ModuleParameter[i].Value = item.Value[0];
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

function getConfig(_host, cb){
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
            device.config = JSON.parse(str);
            cb && cb(true);
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
    send('RDF405|02', () => {
        checkNumNodes(0, -1, (nodes) => {
            device.num_nodes = nodes + 1;
            checkModuleFromNodes(0, 0, () => {
                device.modules = scheme_modules;
                saveDevice();
                dsp && dsp.close();
                cb && cb();
            });
        });
    });
}

function getConfigFromDevice(_host, _port, cb){
    adapter.log.debug('getConfigFromDevice ');
    if (!_host){
        _host = host;
    }
    if (!_port){
        _port = port;
    }
    adapter.log.info('DSP AMP connect to: ' + _host + ':' + _port);
    getConfig(_host, () => {
        dsp && dsp.close();
        dsp = new ws('ws://' + _host + ':' + _port, {
            perMessageDeflate: false
        });
        dsp.on('open', () => {
            adapter.log.debug(dsp.url + ' DSP AMP connected');
            discovery(cb);
        });
        dsp.on('error', (e) => {
            adapter.log.debug('Error WS - ' + e);
            dsp && dsp.close();
            cb && cb('Error getConfigFromDevice WS - ' + e);
        });
        dsp.on('close', (e) => {
            adapter.log.debug('getConfigFromDevice WS CLOSED, CODE - ' + e);
            dsp && dsp.close();
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
    pollTimeout = setTimeout(() => {
        pollTimeout && clearTimeout(pollTimeout);
        pollTimeout = null;
        pause = 10;
        const reg = hex16(addresses[iteration]);
        const name = device.address_map[addresses[iteration]].name;
        const main = device.address_map[addresses[iteration]].main;
        send('RD' + reg + '|04', (val) => {
            if (val !== 'error'){
                const detailname = device.schematic.modules[main].DetailedName.replace(/[\d.]+$/, '');
                let id = adapter.namespace + '.control.' + main + '.' + name;
                if (formats[detailname]){
                    val = formats[detailname].hexToVal(val);
                } else {
                    adapter.log.debug(`WARN! ${adapter.namespace + '.control.' + main + '.' + name} / Read value (${detailname}) not found in formats!\n Send this information to the developer!`);
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

function setSatates(states){
    permit = false;
    for (const id in states) {
        if (states.hasOwnProperty(id)){
            if (old_states[id] !== states[id] || states[id] === null){
                const val = states[id];
                console.log('val = ' + val);
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
    getAddressArray((addresses) => {
        iterator(addresses);
    });
}

function getAddressesMap(cb){
    if (!device.address_map){
        device.address_map = {};
    }
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
    dsp = new ws('ws://' + host + ':' + port, {
        perMessageDeflate: false
    });

    dsp.on('open', () => {
        adapter.log.info(dsp.url + ' DSP AMP connected');
        permit = true;
        pollDevice();
        timeOutSend = setTimeout(() => {
            timeOutSend && clearTimeout(timeOutSend);
            timeOutSend = null;
            //send('~');
        }, 5000);
        pingTimer = setInterval(() => {
            dsp.ping('ping'); // Работает только на "ws": "^5.1.0", на последних версиях возращает ошибку.
        }, 10000);
        timeoutTimer = setInterval(() => {
            if (!isAlive){
                dsp && dsp.close();
            } else {
                isAlive = false;
            }
        }, 60000);
        //cb && cb();
    });
    dsp.on('pong', (msg) => {
        isAlive = true;
        adapter.log.debug(dsp.url + ' receive a pong : ' + msg);
    });

    /*dsp.on('message', (msg) => {
        adapter.log.debug('Response message - ' + msg);
        isAlive = true;
        if (msg === 'Connected'){
            adapter.setState('info.connection', true, true);
        }
        if (msg !== 'OK' && msg !== 'Connected'){
            //parse(msg);
        }
    });*/

    dsp.on('error', (e) => {
        adapter.log.debug('Error WS - ' + e);
    });
    dsp.on('close', (e) => {
        pingTimer && clearInterval(pingTimer);
        timeoutTimer && clearInterval(timeoutTimer);
        adapter.log.debug('ERROR! WS CLOSE, CODE - ' + e);
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
            adapter.log.debug('Response data - ' + msg);
            /*if (msg !== 'OK' && msg !== 'Connected'){
                //parse(msg);
            }*/
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
        dsp.send(data, (e) => {
            if (e){
                adapter.log.error('Send command: {' + data + '}, ERROR - ' + e);
                if (~e.toString().indexOf('CLOSED')){
                    adapter.setState('info.connection', false, true);
                    connect();
                }
            } else {
                adapter.log.debug('Sended command:{' + data + '}');
            }
        });
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
        let /*role = 'state', */name = key, /*type = 'number',*/ min = null, max = null, write = true;
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

                /*
                            "Name": "ExternalGainAlgSlew145X2slew_mode",
                            "Type": "FixedPoint",
                            "Address": 24603,
                            "Value": "15600",
                            "Size": 4,
                            "Data": [
                              "0x00",
                              "0x00",
                              "0x3C",
                              "0xF0"
                            ]
                 */
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
                    createObjects(() => {
                        confirmSplitterToObjects(() => {
                            getAddressesMap(() => {
                                connect();
                            });
                        });
                    });
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
    fs.readFile(dataFile, (err, data) => {
        if (!err){
            try {
                device = JSON.parse(data);
                cb && cb();
            } catch (err) {
                cb && cb(err);
            }
        } else {
            cb && cb(err);
        }
    });
}

function saveDevice(_device, cb){
    if (!cb){
        cb = _device;
    } else {
        device = _device;
    }
    //adapter.log.debug('Сохраняем в файл ' + JSON.stringify(device));
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

function linear_to_hexFloat(linear){ // linear 0-100 // TODO
    return dB_to_hex(linear_to_dB(linear));
}

function dB_to_float(dB){
    return Math.pow(10.0, dB / 20.0);
}

function float_to_dB(float){
    return 20 * Math.log10(float);
}

function linear_to_dB(linear){ // linear 0-100 // TODO
    return /*(maxdBLevel ? maxdBLevel :0) + */ 20.0 * Math.log10(linear / 100.0);  // !!! 20 * Math.log(linear / 100)
    // TODO for 0  20.0 * Math.log10(0/100.0) = -infinity
}

function hexFloatToLinear(val){
    const sign = (parseInt(val, 16) & 0x800000) ? -1 :1;
    const float = sign * parseInt(val, 16) / Math.pow(2, 24);
    return Math.round((Math.pow(10.0, float_to_dB(float) / 20.0) * 100) * 10) / 10;
    //return Math.round((Math.pow(Math.exp(1), float_to_dB(float) / 20.0) * 100) * 10) / 10;
}

function linear_to_float(linear){ // linear 0-100 // TODO
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