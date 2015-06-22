var app = require('http').createServer(handler)
  ,io = require('socket.io').listen(app)
  ,fs = require('fs')
  ,exec = require('child_process').exec
  ,formidable = require('formidable')
  ,util = require('util')  
  ,url = require("url")
  ,path = require("path")
  ,spawn = require('child_process').spawn
  ,ls = spawn('python', ["pythonArduino.py"]);
//io.set('destroy upgrade',false);
//ls.stdout.setEncoding('utf8');

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
	io.sockets.emit('arduino_notif', nbTouch);	
});
ls.stderr.on('data', function (data) {
    console.log('stderr: ' + data);
});	

function execDebian(cible){
	exec(cible, function(err, stdout, stderr) {
		console.log(err);
		console.log(stdout);
		console.log(stderr);
	});			
}
function returnFalse(cible,cible2){
	cible=cible2;
}

/*ls.stdout.on('data', function (data) {
	if(data.indexOf("egg01")!=-1){    						
		io.sockets.emit('notifEgg', data);
		//execDebian("echo ,uploadsDir/mini/icone_pied.png>> scripts/index.txt");			
		//io.sockets.emit('notifEgg', 'images/compo_loopa/back_eggB.png');		
	}else if(data.indexOf("egg02")!=-1){    						
		//io.sockets.emit('notifEgg', data);
		execDebian("echo ,uploadsDir/mini/icone_main.png>> scripts/index.txt");			
		io.sockets.emit('upload_notif', 'uploadsDir/mini/icone_main.png');		
	}else if(data.indexOf("egg03")!=-1){    						
		//io.sockets.emit('notifEgg', data);
		execDebian("echo ,uploadsDir/mini/icone_medaille.png>> scripts/index.txt");			
		io.sockets.emit('upload_notif', 'uploadsDir/mini/icone_medaille.png');		
	}else if(data.indexOf("egg04")!=-1){    						
		//io.sockets.emit('notifEgg', data);
		execDebian("echo ,uploadsDir/mini/icone_feuille.png>> scripts/index.txt");			
		io.sockets.emit('upload_notif', 'uploadsDir/mini/icone_feuille.png');		
	}else if(data.indexOf("egg04")!=-1){    						
		//io.sockets.emit('notifEgg', data);
		execDebian("echo ,uploadsDir/mini/icone_medaille2.png>> scripts/index.txt");			
		io.sockets.emit('upload_notif', 'uploadsDir/mini/icone_medaille2.png');		
	}else if(data.indexOf("egg04")!=-1){    						
		//io.sockets.emit('notifEgg', data);
		execDebian("echo ,uploadsDir/mini/icone_voiture.png>> scripts/index.txt");			
		io.sockets.emit('upload_notif', 'uploadsDir/mini/icone_voiture.png');		
	}
});
ls.stderr.on('data', function (data) {
    console.log('stderr: ' + data);
});*/
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
				//execDebian("/home/pi/noob/scripts/writeSerie 'E'");
				fileName = filo.substring(filo.indexOf('/')+1,filo.length);	
			    result.push({"img": fileName, "mess": fields.messButon, "date": datejour, "like": 0});
			    var resultJson = JSON.stringify(result);
				fs.writeFile('scripts/index.txt', resultJson, function(err) {
				    if(err) {
				        console.log(err);
				    } else {
				        console.log("The file was saved!");
				    }
				}); 			    
				execDebian("/home/pi/noob/scripts/writeSerie 'C'");
			});
			form.on('end', function(err, fields, files) {
				exec('/home/pi/noob/scripts/resizeScript '+fileName, function(err, stdout, stderr) {
					console.log(err);
					console.log(stdout);
					console.log(stderr);						
					io.sockets.emit('upload_notif', {img:'uploadsDir/'+fileName,mess:mess,date:datejour});						
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
				//execDebian("/home/pi/noob/scripts/writeSerie 'E'");
			}			 
 			if(uri.indexOf('capture')==1){			
				var uro = uri.split('--');
					//execDebian("echo ,http://10.0.0.235/"+uro[1]+">> scripts/index.txt");			
			}		
			throw404();	 		 			
			//filename = path.join(process.cwd(), 'index.htm');
		};
		fs.readFile(filename, "binary", function(err, file){
			//if (err) throw500();
			response.writeHead(200);
			response.write(String(file), "binary");
			response.end();
 			//if(uri.indexOf('shut101')==1){			
			//	execDebian("sudo /home/pi/noob/scripts/shut.sh");			
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
function addTwit(){
	if(idTwt<=33){
	  var resultTwit = Math.floor(idTwt/3);
	  //execDebian('/home/pi/noob/scripts/showOeuf '+resultTwit);
	}
	idTwt++;
}
addTwit();
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
    	socket.emit('newusr',me);
    	usersNum++;    	
		//execDebian("wget http://10.0.0.235 > /dev/null");		
		execDebian('/home/pi/noob/scripts/writeSerie "6;90;0;0;50;1000"');
		console.log('write')
	    //execDebian("/home/pi/noob/scripts/writeSerie 'C'");				    	
	    //execDebian("/home/pi/noob/scripts/writeSerie 'Q'");				    	
	});
	var resultImg2 = '';
	socket.on('message_notif', function (mess) {
		execDebian("echo ,"+mess+">> scripts/chat.txt");			
		socket.broadcast.emit('message_notif', mess);	
	});
	socket.on('arduino_click', function (mess) {
	    execDebian("echo 'B' > /dev/tty.usbserial-A40364NT");				    	
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
