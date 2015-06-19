var app = require('http').createServer(handler)
  ,fs = require('fs')
  ,exec = require('child_process').exec
  ,util = require('util')  
  ,url = require("url")
  ,path = require("path")
  ,spawn = require('child_process').spawn
  ,ls = spawn('python', ["pythonArduino.py"]);

var idTwt = 0;
var users = [];
var arrayTwit = {};
var arrayTwitTxt = {};
var usersNum= 0;    	
var boolTwitt = true;
var boolEgg = true;
var resultImg = '';
var size = new Object();
app.listen(80);
var random = 0;
var randomMain = true;
/*ls.stdout.on('data', function (data) {
	if(boolEgg == true){    	
		execDebian("wget http://192.168.0.14/echoA > /dev/null");			
		boolEgg = false;
	    var millisID = setTimeout(millisEgg,1000);			
	}
});*/

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
function handler ( request, response ) {
	function throw404(cible){
		response.writeHead(404, {
			"Content-Type": "text/plain"
		});
		response.write("404 Not Found "+cible+"\n");
		response.end();
		return false;			
	}
	function throw500(){
		response.writeHead(500, {
			"Content-Type": "text/plain"
		});
		response.write("500 Not Found\n");
		response.end();
		return;
	}	
	var uri = url.parse(request.url).pathname;
	if (uri.match(/\/$/)) uri = uri + 'index.htm';
	if (uri == '/server.js') throw404();
	var filename = path.join(process.cwd(), uri);
	var boolLink = true;
	fs.exists(filename, function(exists){
		console.log("ok");
		if (!exists){
			if(uri.indexOf('echoA')==1){			
				execDebian('sudo echo "A" > /home/pi/ttyUSB0');
			}else if(uri.indexOf('echoB')==1){
				execDebian('sudo echo "B" > /home/pi/ttyUSB0');
			}else if(uri.indexOf('echoC')==1){
				execDebian('sudo echo "C" > home/pi/ttyUSB0');
			}
			throw404();
		}	
		throw404(uri);
		return;		
	});		
};
