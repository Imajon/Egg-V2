var net = require('net'),
  fs = require('fs'),
  JsonSocket = require('json-socket');
    
var port = 9838; //The same port that the server is listening on
var host = '192.168.1.77';
var socket = new JsonSocket(new net.Socket()); //Decorate a standard net.Socket with JsonSocket
socket.connect(port, host);
fs.readFile('scripts/resultPulse.txt', 'utf8', function (err,data) {
	var resultServer = '';
	console.log("readFile : "+data);
	if (err) {
		return console.log(err);
	}
	if(data){
		result = JSON.parse(data);
	    socket.sendMessage(result);
	}
})
socket.on('connect', function() { //Don't send until we're connected
    socket.on('message', function(message) {
        console.log('The result is: '+message.result);
    });
});
