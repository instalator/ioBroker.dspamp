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
    $('#use_mqtt').prop('checked', config.use_mqtt === 'true');
    if (config.use_mqtt === 'true'){
        $('#mqtt-settings').show();
    } else {
        $('#mqtt-settings').hide();
    }
}

$(document).ready(function (){
    showDonate();
    $('.modal').modal();
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
            const index = event.detail.draggedElement.outerText.substring(event.detail.draggedElement.outerText.indexOf('Output_') + 7/*, event.detail.draggedElement.outerText.indexOf('Output_') + 9*/);
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
            const index = event.detail.draggedElement.outerText.substring(event.detail.draggedElement.outerText.indexOf('Input_') + 6/*, event.detail.draggedElement.outerText.indexOf('Input_') + 9*/);
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
                showMapZone();
            } else if (tab.index === 2){
                $('.navbar-fixed ul #add-button').removeClass('scale-out').addClass('scale-in');
                $('#add-button').attr('href', '#modaladd-input');
                showMapInput();
            } else {
                $('.navbar-fixed ul #add-button').removeClass('scale-in').addClass('scale-out');
            }
        }, 100);
    });

    $('.modalupload').modal({
        onOpenStart(){
            addFileList();
            document.getElementById('uploads').addEventListener('change', handleFileSelect, false);
        },
    });

    function handleFileSelect(evt){
        const files = evt.target.files;
        let count = 0;
        for (let i = 0, f; f = files[i]; i++) { //for (let i = 0, f; f = files[i]; i++) {
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
    let html = '';
    html += '<div class="col s2">\n' +
        '                    <div class="grid undefined">' +
        '                        <div class="title z-depth-2 outputs-grid" ><i class="material-icons" >grid_off</i><span>Free outputs</span></div>';
    device.zones.undefined.outputs.forEach(function (item){
        html += '<div class="z-depth-3 item col s12">' +
            '       <div class="content lmdd-block"><i class="material-icons handle" >volume_up</i>' +
            '<span >Output_' + item + '</span>' +
            /*'            <div class="task">Output_' + item + '</div>\n' +*/
            '       </div>' +
            '    </div>';
    });
    html += '</div></div>';
    $('#map-zones').html(html);
    cb && cb();
}

function showMapInputsContainer(cb){
    let html = '';
    html += '<div class="col s2">\n' +
        '                    <div class="grid undefined">' +
        '                        <div class="title z-depth-2 outputs-grid" ><i class="material-icons" >grid_off</i><span>Unnamed inputs</span></div>';
    device.inputs.undefined.inputs.forEach(function (item){
        html += '<div class="z-depth-3 item col s12">' +
            '       <div class="content lmdd-block"><i class="material-icons handle" >input</i>' +
            '<span >Input_' + item + '</span>' +
            '       </div>' +
            '    </div>';
    });
    html += '</div></div>';
    $('#map-inputs').html(html);
    cb && cb();
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
                    '               <a class="" onclick="delZone(\'' + zone + '\')"><i class="delZone material-icons cyan-text text-darken-4 right" style="cursor:pointer;">clear</i></a>' +
                    '           </div>';
                if (device.zones[zone].outputs.length > 0){
                    device.zones[zone].outputs.forEach(function (item){
                        html += '<div class="z-depth-3 item col s12 ">\n' +
                            '       <div class="content lmdd-block"><i class="material-icons handle">volume_up</i>' +
                            '<span>Output_' + item + '</span>' + //launch speaker speaker_group headset
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
                    '               <a class="" onclick="delInput(\'' + input + '\')"><i class="delInput material-icons cyan-text text-darken-4 right" style="cursor:pointer;">clear</i></a>' +
                    '           </div>';
                if (device.inputs[input].inputs.length > 0){
                    device.inputs[input].inputs.forEach(function (item){
                        html += '<div class="z-depth-3 item col s12 ">\n' +
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
        cb && cb();
    });
}

function showMapZone(){
    //checkXmlProject(() => {
    drawMapZone();
    //});
}

function showMapInput(){
    //checkXmlProject(() => {
    drawMapInput();
    //});
}

function addFileList(){
    sendToadapter('readDir', null, function (msg){
        let html = '<table><tr><th class="translate">filename</th><th>size</th><th>del</th></tr>';
        if (msg.length > 0){
            for (let i = 0; i < msg.length; i++) {
                html += '<tr><td><i class="material-icons cyan-text text-darken-4">description</i><span style="vertical-align: super;">' + msg[i].name + '</span></td>' +
                    '<td>' + parseFloat(msg[i].stats.size / 1024).toFixed(1) + ' kB</td>' +
                    '<td><a class="" onclick="delFile(\'' + msg[i].name + '\')"><i class="delfile material-icons cyan-text text-darken-4" style="cursor: pointer;">clear</i></a></td></tr>';
            }
        }
        html += '</table>';
        $('#fileList').html(html);
    });
}

function delFile(file){
    sendToadapter('delFile', {filename: file}, function (msg){
        addFileList();
    });
}

function uploadFile(file, cb){
    const reader = new FileReader();
    reader.onload = function (e){
        const data = e.target.result;
        const filename = file.name;
        sendToadapter('writeFile', {
            filename,
            data
        }, function (msg){
            cb && cb(file.name);
        });
    };
    reader.onerror = function (){
        console.error('uploadFile Error - ' + reader.error);
    };
    reader.readAsArrayBuffer(file);
}

function getDeviceFile(cb){
    sendToadapter('getDeviceFile', {}, function (msg){
        device = msg;
        showMap();
        cb && cb();
    });
}

function preloader(state){
    if (state){
        timeoutPreloaderStart = setTimeout(function (){
            window.parent.$('#connecting').show();
        }, 200);
    } else {
        timeoutPreloaderStart && clearTimeout(timeoutPreloaderStart);
        window.parent.$('#connecting').hide();
    }
}

function saveConfigToDevice(cb){
    preloader(true);
    const data = { // TODO Привести к соответсвию обьекта в прошивке и в адаптере.
        mqtt_server:    $('#mqtt_server').val(),
        mqtt_port:      $('#mqtt_port').val(),
        mqtt_user:      $('#mqtt_user').val(),
        mqtt_pass:      $('#mqtt_pass').val(),
        mqtt_client_id: $('#mqtt_client_id').val().replaceAll('.', '_'),
        mqtt_topic:     $('#mqtt_topic').val().replaceAll('.', '_'),
        host_name:      $('#host_name').val(),
        retain:         $('#retain').prop('checked').toString(),
        set_topic:      $('#set_topic').prop('checked').toString(),
        use_mqtt:       $('#use_mqtt').prop('checked').toString(),
    };
    sendToadapter('saveConfigToDevice', {data}, function (msg){
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
                showMessage(_(msg.error), _('Error'), 'error_outline');
                msg = null;
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
        device = msg;
        cb ? cb() :showMap();
    });
}

function showMap(){
    let html = '<table>' +
        '<thead>' +
        '<tr>' +
        '<th>Main</th>';
    for (let i = 0; i < device.num_nodes; i++) {
        html += '<th>Node ' + i + '</th>';
    }
    html += '</tr>' +
        '</thead>' +
        '<tbody>' +
        '<tr>';
    html += '<td style="padding: 10px 0;"><img src="img/main.png" alt="" style="height: 200px"/>' +
        '<img src="img/arrow.png" alt="" style="margin-left: 0px;height: 200px"/></td>';
    for (let i = 0; i < device.num_nodes; i++) {
        if (device.modules[i]){
            html += '<td style="padding: 10px 0;"><img src="img/' + device.modules[i].img + '" alt="" style="height: 200px"/>';
        } else {
            html += '<td style="padding: 10px 0;"><img src="img/undefined.png" alt="" style="height: 200px"/>';
        }
        if (i < device.num_nodes - 1){
            html += '<img src="img/arrow.png" alt="" style="margin-left: 0px;height: 200px"/>';
        }
        '</td>';
    }
    html += '</tr>' +
        '</tbody>' +
        '</table>';
    $('#map').html(html);
}

function sockets(){
    socket.emit('subscribe', namespace + '.info.*');
    socket.emit('subscribeObjects', namespace + '.*');
    socket.on('stateChange', function (id, state){
        if (id.substring(0, namespaceLen) !== namespace) return;
        if (state){

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
