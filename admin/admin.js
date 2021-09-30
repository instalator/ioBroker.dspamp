const namespace = 'dspamp.' + instance,
    namespaceLen = namespace.length;
let device = {}, lang, _onChange, timeoutPreloaderStart;

function load(settings, onChange){
    if (!settings) return;
    sockets();
    _onChange = onChange;
    lang = systemLang || 'en';
    //console.log(lang); // TODO translate
    isAlive(function (alive){
        if (!alive){
            showMessage(_('Adapter is not running'), _('Error'), 'error_outline');
        } else {
            M && M.updateTextFields();
            getConfigFromDevice(function (){
                checkXmlProject(() => {
                    getDeviceFile(function (){
                        $('.value').each(function (){
                            const $key = $(this);
                            const id = $key.attr('id');
                            if ($key.attr('type') === 'checkbox'){
                                $key.prop('checked', settings[id]).change(function (){
                                    onChange();
                                });
                            } else {
                                $key.val(settings[id]).change(function (){
                                    onChange();
                                }).keyup(function (){
                                    onChange();
                                });
                            }
                        });
                        onChange(false);
                        setDeviceSettings();
                        M && M.updateTextFields();
                    });
                });
            });
        }
    });
}

function setDeviceSettings(){
    let config = device.config;
    $('#mqtt_server').val(config.mqtt_server);
    $('#mqtt_port').val(config.mqtt_port);
    $('#mqtt_user').val(config.mqtt_user);
    $('#mqtt_pass').val(config.mqtt_pass);
    $('#mqtt_client_id').val(config.mqtt_client_id);
    $('#mqtt_topic').val(config.mqtt_topic);
    $('#host_name').val(config.host_name);
    $('#retain').prop('checked', config.retain === 'true');
    $('#use_mqtt').prop('checked', config.mqtt === 'true');
    $('#set_topic').prop('checked', config.set === 'true');
    if (config.mqtt === 'true'){
        $('#mqtt-settings').show();
    } else {
        $('#mqtt-settings').hide();
    }
}

$(document).ready(function (){
    preloader(false);
    showDonate();
    $('.modal').modal();
    $('.modalsigma').modal({
        onOpenStart:  function (modal, trigger){
            $('#sigmalog').val('');
        },
        onCloseStart: function (){
            sendToadapter('sigmaTCP', {val: false}, function (){
            });
        }
    });

    lmdd.set(document.getElementById('map-zones'), {
        containerClass:     'grid',
        draggableItemClass: 'item',
        handleClass:        'handle'
    });

    lmdd.set(document.getElementById('map-inputs'), {
        containerClass:     'grid',
        draggableItemClass: 'item',
        handleClass:        'handle'
    });

    document.getElementById('map-zones').addEventListener('lmddend', handleDragEventOutput, false);

    document.getElementById('map-inputs').addEventListener('lmddend', handleDragEventInput, false);

    function handleDragEventOutput(event){
        if (event.detail.from && event.detail.to && event.detail.to.container && event.detail.to.container.className !== event.detail.from.container.className){
            _onChange();
            const from = event.detail.from.container.className.replace('grid', '').replace(/\s/g, '');
            const to = event.detail.to.container.className.replace('grid', '').replace(/\s/g, '');
            //const index = event.detail.draggedElement.outerText.substring(event.detail.draggedElement.outerText.indexOf('Output_') + 7/*, event.detail.draggedElement.outerText.indexOf('Output_') + 9*/);
            const index = event.detail.draggedElement.id.substring(event.detail.draggedElement.id.indexOf('Output_') + 7);
            if (device.zones[from]){
                if (device.zones[from].outputs.indexOf(index) !== -1){
                    device.zones[from].outputs = device.zones[from].outputs.toString().replace(index, '').replace('', '').split(',').filter(String).sort();
                }
                device.zones[to].outputs.push(index);
                device.zones[to].outputs.sort();
            } else {
                console.error('Error handleDragEventOutput. ' + from + ' not found in device.zones');
            }
        }
    }

    function handleDragEventInput(event){
        if (event.detail.from && event.detail.to && event.detail.to.container && event.detail.to.container.className !== event.detail.from.container.className){
            _onChange();
            const from = event.detail.from.container.className.replace('grid', '').replace(/\s/g, '');
            const to = event.detail.to.container.className.replace('grid', '').replace(/\s/g, '');
            //const index = event.detail.draggedElement.outerText.substring(event.detail.draggedElement.outerText.indexOf('Input_') + 6/*, event.detail.draggedElement.outerText.indexOf('Input_') + 9*/);
            const index = event.detail.draggedElement.id.substring(event.detail.draggedElement.id.indexOf('Input_') + 6);
            if (device.inputs[from]){
                if (device.inputs[from].inputs.indexOf(index) !== -1){
                    device.inputs[from].inputs = device.inputs[from].inputs.toString().replace(index, '').replace('', '').split(',').filter(String).sort();
                }
                console.log(device);
                device.inputs[to].inputs.push(index);
                device.inputs[to].inputs.sort();
            } else {
                console.error('Error handleDragEventInput. ' + from + ' not found in device.inputs');
            }
        }
    }

    $('#use_mqtt').change(function (){
        if (this.checked){
            $('#mqtt-settings').show();
        } else {
            $('#mqtt-settings').hide();
        }
    });

    $('#get-config-btn').click(function (){
        getConfigFromDevice();
    });

    $('#save_to_dev-btn').click(function (){
        saveConfigToDevice();
    });

    $('#server-state-button').click(function (){
        let val = false;
        if (~$(this).attr('class').indexOf('red')){
            val = true;
        }
        sendToadapter('sigmaTCP', {val}, function (){
        });
    });

    $('#reboot_dev-btn').click(function (){
        sendToadapter('reboot', {}, function (msg){
            showMessage(_(''), _('Successfully'), '');
            //cb && cb();
        });
    });
    $('#reset_agree').click(function (){
        sendToadapter('reset', {}, function (msg){
            showMessage(_(''), _('Successfully'), '');
            //cb && cb();
        });
    });

    $('#confirm-add-zone-btn').click(function (){
        const nameZone = $('#name-zone').val().replace(/\s/g, '_').replace(/\./g, '_');
        if (!device.zones.hasOwnProperty(nameZone)){
            $('.modaladd-zone').modal('close');
            device.zones[nameZone] = {
                outputs: []
            };
            drawMapZone();
        } else {
            showMessage(_('The entered name ' + nameZone + 'is invalid or it is busy'), _('Error'), 'error_outline');
        }
        if (!device.splitter){
            device.splitter = {
                inputs: {},
                zones:  {}
            };
        }
        if (!device.splitter.zones[nameZone]){
            device.splitter.zones[nameZone] = [];
        }
    });

    $('#confirm-add-input-btn').click(function (){
        const nameInput = $('#name-input').val().replace(/\s/g, '_').replace(/\./g, '_');
        console.log(device);
        if (!device.inputs.hasOwnProperty(nameInput)){
            $('.modaladd-input').modal('close');
            device.inputs[nameInput] = {
                inputs: []
            };
            drawMapInput();
        } else {
            showMessage(_('The entered name ' + nameZone + 'is invalid or it is busy'), _('Error'), 'error_outline');
        }
        if (!device.splitter){
            device.splitter = {
                inputs: {},
                zones:  {}
            };
        }
        if (!device.splitter.inputs[nameInput]){
            device.splitter.inputs[nameInput] = [];
        }
        console.log(device);
    });

    $('ul.tabs li').click(function (){
        setTimeout(function (){
            let tab = M.Tabs.getInstance($('.tabs'));
            if (tab.index === 1){
                $('.navbar-fixed ul #add-button').removeClass('scale-out').addClass('scale-in');
                $('#add-button').attr('href', '#modaladd-zone');
                drawMapZone();
            } else if (tab.index === 2){
                $('.navbar-fixed ul #add-button').removeClass('scale-out').addClass('scale-in');
                $('#add-button').attr('href', '#modaladd-input');
                drawMapInput();
            } else {
                $('.navbar-fixed ul #add-button').removeClass('scale-in').addClass('scale-out');
            }
        }, 100);
    });

    $('.modalupload').modal({
        onOpenStart(){
            addFileList();
            document.getElementById('uploads_config_project').addEventListener('change', handleFileSelect, false);
        },
    });

    function handleFileSelect(evt){
        const files = evt.target.files;
        let count = 0;
        for (let i = 0, f; f = files[i]; i++) { //for (let i = 0, f; f = files[i]; i++) {
            f = files[i];
            if (f.size > 1024 * 1024){
                showMessage(_('File %s is too big. Maximum 1MB', escape(f.name)));
                return;
            }
            count++;
            uploadFile(f, function (name){
                count--;
                if (!count){
                    addFileList();
                }
            });
        }
    }

    M.updateTextFields();
});

function showMapZoneOtputsContainer(cb){
    if (device.zones){
        let html = '';
        html += '<div class="col s2">\n' +
            '                    <div class="grid undefined">' +
            '                        <div class="title z-depth-2 outputs-grid" ><i class="material-icons" >grid_off</i><span>Free outputs</span></div>';
        device.zones.undefined.outputs.forEach(function (item){
            html += '<div class="z-depth-3 item col s12" id="Output_' + item + '">' +
                '       <div class="content lmdd-block"><i class="material-icons handle" >volume_up</i>' +
                '<span >Output_' + item + '</span>' +
                /*'            <div class="task">Output_' + item + '</div>\n' +*/
                '<a class="translateT" onclick="beepZone(\'' + item + '\')"  title="Play a beep on this output"><i class="beepZone material-icons cyan-text text-darken-4 Tiny" style="cursor:pointer;vertical-align: middle;position: absolute;float: right;right: 5px;top: 14px;">hearing</i></a>' +
                '       </div>' +
                '    </div>';
        });
        html += '</div></div>';
        $('#map-zones').html(html);
        cb && cb();
    } else {
        checkXmlProject(() => {
            showMapZoneOtputsContainer(cb);
        });
    }
}

function showMapInputsContainer(cb){
    if (device.zones){
        let html = '';
        html += '<div class="col s2">\n' +
            '                    <div class="grid undefined">' +
            '                        <div class="title z-depth-2 outputs-grid" ><i class="material-icons" >grid_off</i><span>Unnamed inputs</span></div>';
        device.inputs.undefined.inputs.forEach(function (item){
            html += '<div class="z-depth-3 item col s12" id="Input_' + item + '">' +
                '       <div class="content lmdd-block"><i class="material-icons handle" >input</i>' +
                '<span >Input_' + item + '</span>' +
                '       </div>' +
                '    </div>';
        });
        html += '</div></div>';
        $('#map-inputs').html(html);
        cb && cb();
    } else {
        checkXmlProject(() => {
            showMapInputsContainer(cb);
        });
    }
}

function drawMapZone(){
    showMapZoneOtputsContainer(function (){
        for (const zone in device.zones) {
            let html = '';
            if (zone !== 'undefined'){
                html += '<div class="col s2">' +
                    '       <div class="grid ' + zone + '">' +
                    '           <div class="title z-depth-2" style="font-size: 1.3em;">' +
                    '               <i class="material-icons" style="vertical-align: bottom;">grid_on</i><span>' + zone + '</span>' +
                    '               <a class="translateT" title="Delete zone" onclick="delZone(\'' + zone + '\')"><i class="delZone material-icons cyan-text text-darken-4 right" style="cursor:pointer;">clear</i></a>' +
                    '           </div>';
                if (device.zones[zone].outputs.length > 0){
                    device.zones[zone].outputs.forEach(function (item){
                        html += '<div class="z-depth-3 item col s12 " id="Output_' + item + '">\n' +
                            '       <div class="content lmdd-block"><i class="material-icons handle">volume_up</i>' +
                            '<span>Output_' + item + '</span>' + //launch speaker speaker_group headset
                            '<a class="translateT" title="Play a beep on this output" onclick="beepZone(\'' + item + '\')" title="Play a beep on this output"><i class="beepZone material-icons cyan-text text-darken-4 Tiny" style="cursor:pointer;vertical-align: middle;position: absolute;float: right;right: 5px;top: 14px;">hearing</i></a>' +
                            '       </div>' +
                            '    </div>';
                    });
                }
            }
            $('#map-zones').append(html);
        }
        $('#map-zones').append('</div></div>');
    });
}

function drawMapInput(){
    showMapInputsContainer(function (){
        for (const input in device.inputs) {
            let html = '';
            if (input !== 'undefined'){
                html += '<div class="col s2">' +
                    '       <div class="grid ' + input + '">' +
                    '           <div class="title z-depth-2" style="font-size: 1.3em;">' +
                    '               <i class="material-icons" style="vertical-align: bottom;">grid_on</i><span>' + input + '</span>' +
                    '               <a class="translateT" title="Delete input" onclick="delInput(\'' + input + '\')"><i class="delInput material-icons cyan-text text-darken-4 right" style="cursor:pointer;">clear</i></a>' +
                    '           </div>';
                if (device.inputs[input].inputs.length > 0){
                    device.inputs[input].inputs.forEach(function (item){
                        html += '<div class="z-depth-3 item col s12 " id="Input_' + item + '">\n' +
                            '       <div class="content lmdd-block"><i class="material-icons handle">input</i>' +
                            '<span>Input_' + item + '</span>' + //launch speaker speaker_group headset
                            '       </div>' +
                            '    </div>';
                    });
                }
            }
            $('#map-inputs').append(html);
        }
        $('#map-inputs').append('</div></div>');
    });
}

function beepZone(zone){
    sendToadapter('beepZone', {zone}, function (msg){
    });
}

function delZone(zone){
    device.zones.undefined.outputs = device.zones.undefined.outputs.concat(device.zones[zone].outputs).sort();
    delete device.zones[zone];
    if (device.splitter && device.splitter.zones[zone]){
        delete device.splitter.zones[zone];
    }
    $('.' + zone).parent().fadeOut(300, function (){
        $(this).remove();
    });
    setTimeout(() => {
        drawMapZone();
        _onChange();
    }, 300);
}

function delInput(input){
    device.inputs.undefined.inputs = device.inputs.undefined.inputs.concat(device.inputs[input].inputs).sort();
    delete device.inputs[input];
    if (device.splitter && device.splitter.inputs[input]){
        delete device.splitter.inputs[input];
    }
    $('.' + input).parent().fadeOut(300, function (){
        $(this).remove();
    });
    setTimeout(() => {
        drawMapInput();
        _onChange();
    }, 300);
}

function checkXmlProject(cb){
    sendToadapter('checkXmlProject', {}, function (msg){
        if (!msg.error){
            device = msg;
            if (!device.zones){
                device.zones = {
                    undefined: {
                        outputs: device.mxn.output.list_array
                    }
                };
            }
            if (!device.inputs){
                device.inputs = {
                    undefined: {
                        inputs: device.mxn.input.list_array
                    }
                };
            }
        }
        cb && cb();
    });
}

function addFileList(){
    sendToadapter('readDir', null, function (msg){
        if (!msg.error){
            let html = '<table><tr><th class="translate">File name</th><th>Size</th><th>Del</th></tr>';
            if (msg.length > 0){
                for (let i = 0; i < msg.length; i++) {
                    html += '<tr><td><i class="material-icons cyan-text text-darken-4">description</i><span style="vertical-align: super;">' + msg[i].name + '</span></td>' +
                        '<td>' + parseFloat(msg[i].stats.size / 1024).toFixed(1) + ' kB</td>' +
                        '<td><a class="translateT" title="Delete file" onclick="delFile(\'' + msg[i].name + '\')"><i class="delfile material-icons cyan-text text-darken-4" style="cursor: pointer;">clear</i></a></td></tr>';
                }
            }
            html += '</table>';
            $('#fileList').html(html);
        }
    });
}

function delFile(file){
    sendToadapter('delFile', {filename: file}, function (msg){
        if (!msg.error){
            addFileList();
        }
    });
}

function uploadFile(file, cb){
    const reader = new FileReader();
    //reader.readAsArrayBuffer(file);
    reader.readAsText(file);
    reader.onload = function (e){
        const data = e.target.result;
        const filename = file.name;
        sendToadapter('writeFile', {
            filename,
            data
        }, function (msg){
            if (!msg.error){
                _onChange();
                cb && cb(file.name);
            }
        });
    };
    reader.onerror = function (){
        console.error('uploadFile Error - ' + reader.error);
    };
}

function getDeviceFile(cb){
    sendToadapter('getDeviceFile', {}, function (msg){
        if (!msg.error){
            device = msg;
            showMap();
            cb && cb();
        }
    });
}

function preloader(state){
    if (state){
        timeoutPreloaderStart = setTimeout(function (){
            $('#preloader_dspamp').css({display: 'block'});
        }, 200);
    } else {
        timeoutPreloaderStart && clearTimeout(timeoutPreloaderStart);
        $('#preloader_dspamp').css({display: 'none'});
    }
}

function saveConfigToDevice(cb){
    const data = { // TODO Привести к соответсвию обьекта в прошивке и в адаптере.
        mqtt_server:    $('#mqtt_server').val(),
        mqtt_port:      $('#mqtt_port').val(),
        mqtt_user:      $('#mqtt_user').val(),
        mqtt_pass:      $('#mqtt_pass').val(),
        mqtt_client_id: $('#mqtt_client_id').val().replaceAll('.', '_'),
        mqtt_topic:     $('#mqtt_topic').val().replaceAll('.', '_'),
        host_name:      $('#host_name').val(),
        retain:         $('#retain').prop('checked').toString(),
        set:            $('#set_topic').prop('checked').toString(),
        mqtt:           $('#use_mqtt').prop('checked').toString(),
    };
    sendToadapter('saveConfigToDevice', {data}, function (msg){
        showMessage(_(''), _('Successfully'), '');
        cb && cb();
    });
}

function sendToadapter(cmd, data, cb){
    preloader(true);
    const timer = setTimeout(function (){
        preloader(false);
        showMessage(_('No response, retry the request'), _('Error'), 'error_outline');
    }, 15000);
    sendTo(namespace, cmd, data, function (msg){
        timer && clearTimeout(timer);
        preloader(false);
        if (msg){
            if (msg.error){
                const e = msg.error;
                msg = null;
                showMessage(_(e), _('Error'), 'error_outline');
                cb && cb({error: e});
            } else {
                cb && cb(msg);
            }
        }
    });
}

function getConfigFromDevice(cb){
    const host = $('#host').val();
    const port = $('#port').val();
    sendToadapter('getConfigFromDevice', {
        host,
        port
    }, function (msg){
        if (!msg.error){
            device = msg;
            _onChange();
            cb ? cb() :showMap();
        }
    });
}

function showMap(){
    let nodes = [], edges = [];
    let img = '';
    const container = document.getElementById('map');
    nodes.push({
        id:    0,
        label: 'Main module',
        image: 'img/main.png',
        shape: 'image',
    });
    for (let i = 0; i < device.num_nodes; i++) {
        if (device.modules[i]){
            img = 'img/' + device.modules[i].img;
        } else {
            img = 'img/undefined.png';
        }
        nodes.push({
            id:    i + 1,
            label: device.modules[i] ? device.modules[i].name :'Undefined module',
            image: img,
            shape: 'image'
        });
        edges.push({
            from:   i,
            to:     i + 1,
            //length: 300,
            smooth: {title: 'A2B'}
        });
    }

    const data = {
        nodes: nodes,
        edges: edges,
    };
    const options = {
        autoResize:  true,
        clickToUse:  false,
        layout:      {
            hierarchical: {
                enabled:              true,
                levelSeparation:      300,
                blockShifting:        true,
                edgeMinimization:     true,
                parentCentralization: true,
                direction:            'LR',
                sortMethod:           'hubsize',
                shakeTowards:         'leaves'
            },
        },
        interaction: {
            zoomView: true,
            dragView: true,
            hover:    true
        },
        physics:     {
            enabled: true
        },
        nodes:       {
            physics: true,
            size:    90,
            shadow:  {
                enabled: true
            },
            shape:   'image',
            font:    {
                size: 22
            },
            mass:    0.1
        },
        edges:       {
            label:  'A2B',
            arrows: {
                to:   {
                    enabled: true
                },
                from: {
                    enabled: true
                }
            },
            smooth: {
                enabled: true,
                type:    'continuous'
            }
        }
    };
    const network = new vis.Network(container, data, options);
}

function sockets(){
    socket.emit('subscribe', namespace + '.sigmaTCP.*');
    //socket.emit('subscribe', namespace + '.info.*');
    //socket.emit('subscribeObjects', namespace + '.*');
    socket.on('stateChange', function (id, state){
        if (id.substring(0, namespaceLen) !== namespace) return;
        if (state){
            const ids = id.split('.');
            const type_cmd = ids[2];
            let cmd = ids[ids.length - 1];
            let val = state.val;
            //console.log(id + ' stateChange ' + JSON.stringify(state));
            if (cmd === 'running' && state.ack){
                if (val){
                    $('#server-state-button').removeClass('red').addClass('green');
                    $('.server-isrunning').removeClass('red-text').addClass('green-text');
                    $('#server-state-button .material-icons').text('sync');
                } else {
                    $('#server-state-button').removeClass('green').addClass('red');
                    $('.server-isrunning').removeClass('green-text').addClass('red-text');
                    $('#server-state-button .material-icons').text('sync_disabled');
                }
            }
            if (cmd === 'connected' && state.ack){
                if (val){
                    $('.sigma-isrunning').removeClass('red-text').addClass('green-text');
                } else {
                    $('.sigma-isrunning').removeClass('green-text').addClass('red-text');
                }
            }
            if (cmd === 'log' && state.ack){
                const textarea = $('#sigmalog');
                textarea.val(textarea.val() + val + '\n');
                textarea.scrollTop(textarea.prop('scrollHeight') - textarea.height());
            }
        }
    });
    socket.on('objectChange', function (id, obj){
        if (id.substring(0, namespaceLen) !== namespace) return;
        if (obj && obj.type === 'device' && obj.common.type !== 'group'){

        }
    });
    socket.emit('getObject', 'system.config', function (err, res){
        if (!err && res && res.common){
            systemLang = res.common.language || systemLang;
            systemConfig = res;
        }
    });
}

function isAlive(cb){
    socket.emit('getState', 'system.adapter.' + namespace + '.alive', function (err, res){
        if (!err && res){
            cb && cb(res.val);
        } else {
            cb && cb(false);
        }
    });
}

function showDonate(){
    setTimeout(function (){
        $('<div class="m row donate" style=\'display:block;position:absolute;bottom:130px;\'>' +
            '<div class="col right">' +
            '<div class="col" style="margin-top:10px;float:right;margin-right:20px;">' +
            '<a target="_blank" href="https://sobe.ru/na/instalator"><img style="float:right;" src="https://img.shields.io/badge/Donate-YooMoney-green" alt=""></a>' +
            '<a target="_blank" href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=PFUALWTR2CTPY"><img style="float:right;padding-right:10px;" src="https://img.shields.io/badge/Donate-PayPal-green.svg" alt=""></a>' +
            '</div></div></div>').appendTo('.adapter-body').animate({right: 0}, 700).animate({'zoom': 1.5}, 300);
        setTimeout(function (){
            $('.donate').animate({'zoom': 1}, 400);
        }, 700);
    }, 1000);
}

function save(cb){
    sendToadapter('saveDevice', {device}, function (msg){
        const obj = {};
        $('.value').each(function (){
            const $this = $(this);
            if ($this.attr('type') === 'checkbox'){
                obj[$this.attr('id')] = $this.prop('checked');
            } else {
                obj[$this.attr('id')] = $this.val();
            }
        });
        cb(obj);
    });
}
