var app = require('http').createServer(handler)
  ,io = require('socket.io').listen(app)
  ,fs = require('fs')
  ,exec = require('child_process').exec
  ,formidable = require('formidable')
  ,util = require('util')  
  ,url = require("url")
  ,path = require("path")
  ,spawn = require('child_process').spawn
  ,ls = spawn('python', ["scripts/pythonArduino.py"]);
//io.set('destroy upgrade',false);
ls.stdout.setEncoding('utf8');

var idTwt = 0;
var users = [];
var arrayTwit = {};
var arrayTwitTxt = {};
var arrayLettreArduino = Array('A','H','I','J','K','L');
var usersNum= 0;    	
var boolTwitt = true;
var boolEgg = true;
var resultImg = '';
var size = new Object();
var idLogin = '';
var dataIMG;
var dataIMG2 = Array();
var boolMain = true;
var boolConnexion = false;
var result = [];
var nbTouch = 0;

app.listen(80);
function execDebian(cible){
	exec(cible, function(err, stdout, stderr) {
		console.log(err);
		console.log(stdout);
		console.log(stderr);
	});			
}

fs.readFile('scripts/index.txt', 'utf8', function (err,data) {
	var resultServer = '';
	//console.log("readFile : "+data);
	if (err) {
		return console.log(err);
	}
	if(data){
		result = JSON.parse(data);
		console.log("result : "+result[0].img);
	}
})
ls.stdout.on('data', function (data) {
	nbTouch++;
	exec('/home/pi/noob/scripts/tools/compositeRandom.sh', function(err, stdout, stderr) {
		console.log(err);
		console.log(stdout);
		console.log(stderr);
		addFile(stdout,'Touch',datejour);
	});
	io.sockets.emit('arduino_notif', nbTouch);	
});
function addFile(fileName,message,datejour){
	var filoTime=new Date();
	var datejour = filoTime.getTime();	
    result.push({"img": fileName, "mess": message, "date": datejour, "like": 0});
    var resultJson = JSON.stringify(result);
	fs.writeFile('scripts/index.txt', resultJson, function(err) {
	    if(err) {
	        console.log(err);
	    } else {
	        console.log("The file was saved!");
	    }
	});	
	console.log(data);
	io.sockets.emit('arduino_notif', nbTouch);	
};
ls.stderr.on('data', function (data) {
    console.log('stderr: ' + data);
});	
function goLed(){
		execDebian('scripts/writeSerie "1;0;0;90;0;6;0"');	
}
var IDtime = setTimeout(goLed,3000);
function returnFalse(cible,cible2){
	cible=cible2;
}
function handler ( request, response ) {
	function throw404(){
		/*response.writeHead(404, {
			"Content-Type": "text/plain"
		});
		response.write("404 Not Found\n");*/
		response.writeHead("301",
		  {Location: 'http://10.0.0.1/index.htm'}
		);
		response.write("ok\n");
		return;			
	}
	function throw500(){
		response.writeHead(500, {
			"Content-Type": "text/plain"
		});
		response.write("500 Not Found\n");
		return;
	}
	if (request.url.indexOf('upload.htm') != -1 && request.method.toLowerCase() == 'post') {
		var form = new formidable.IncomingForm();
		var resultForm = false;
		form.uploadDir = 'uploadsDir/';
		form.keepExtensions = true;
		var fileName ='';
		fs.exists(form.uploadDir, function (exists) {
		  if(exists){
			var filo;
	    	var date = new Date();
	    	var mess;
			var filoTime=new Date();
	    	var datejour = filoTime.getTime();
			form.parse(request, function(err, fields, files) {
				filo=files.upload.path;
		    	mess = fields.messButon;
				fileName = filo.substring(filo.indexOf('/')+1,filo.length);	
    			addFile(fileName,fields.messButon,datejour)
			});
			form.on('end', function(err, fields, files) {
				execDebian('scripts/writeSerie "6;60;0;90;30;1000;0"');
				io.sockets.emit('upload_notif', {img:'uploadsDir/'+fileName,mess:mess,date:datejour});						
				exec('scripts/resizeScript '+fileName, function(err, stdout, stderr) {
					console.log(err);
					console.log(stdout);
					console.log(stderr);						
				});			

				response.writeHead(301,
				  {Location: 'upload.htm'}
				);
				response.write("ok\n");		
				response.end();
			});
		  }
		});
		return;
	}	
	if (request.url.indexOf('uploads') != -1 && request.method.toLowerCase() == 'post') {
		var reponse = '';
		dataIMG = JSON.stringify(result);
		response.writeHead(200);
		response.write(dataIMG);					
		response.end();	
		return;
	}	
	var uri = url.parse(request.url).pathname;
	if (uri.match(/\/$/)) uri = uri + 'index.htm';
	if (uri == '/server.js') throw404();
	//if (uri == '/library/test/success.html') uri = 'index.htm';	
	var filename = path.join(process.cwd(), uri);
	fs.exists(filename, function(exists){
		if (!exists){
 			if(uri.indexOf('RFID')==1){			
			}			 
 			if(uri.indexOf('capture')==1){			
				var uro = uri.split('--');
					//execDebian("echo ,http://10.0.0.235/"+uro[1]+">> scripts/index.txt");			
			}		
			throw404();	 		 			
			//filename = path.join(process.cwd(), 'index.htm');
		};
		fs.readFile(filename, "binary", function(err, file){
			if (err) throw500();
			response.writeHead(200);
			response.write(String(file), "binary");
			response.end();
 			//if(uri.indexOf('shut101')==1){			
			//	execDebian("sudo scripts/shut.sh");			
			//}				
		});
		return;
	});	
};
function millisTwit(){
	boolTwitt = true;
}
function millisEgg(){
	boolEgg = true;
}
io.sockets.on( 'connection', function ( socket ) {
	var resultTW = false;
	var resultIN = false;
	var resultPython = false;
	var me=false;
	boolConnexion = true;
    socket.on('login', function (user) {
    	me = user;
    	me.id = users.length;
    	users.push(me);
    	me.all = users.length;
    	me.img = result.length;
    	me.nbTouch = nbTouch;
    	socket.emit('newusr',me);
    	usersNum++;    	
		execDebian('scripts/writeSerie "6;90;0;0;50;1000;0"');
		console.log('write')
	});
	var resultImg2 = '';
	socket.on('message_notif', function (mess) {
		//execDebian("echo ,"+mess+">> scripts/chat.txt");			
		socket.broadcast.emit('message_notif', mess);	
	});
	socket.on('arduino_click', function (mess) {
	    //execDebian("echo 'B' > /dev/tty.usbserial-A40364NT");				    	
	});
	socket.on('disconnect', function () {
		if(!me){
			return false;
		}
    	users.splice(me.id,1);
	    //execDebian("echo '"+arrayLettreArduino[users.length]+"' > /dev/ttyUSB0");				    	
    	usersNum--;    	
    	me.all = users.length;
	    io.sockets.emit('discousr',me);			
	});	
});
