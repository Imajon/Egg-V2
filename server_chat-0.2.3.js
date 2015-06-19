var app = require('http').createServer(handler)
  ,fs = require('fs')
  ,exec = require('child_process').exec
  ,util = require('util')  
  ,url = require("url")
  ,path = require("path")
  ,spawn = require('child_process').spawn;

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
	function throw404(){
		response.writeHead(301,
		  {Location: 'http://10.0.0.1/index.htm'}
		);		
		/*response.writeHead(404, {
			"Content-Type": "text/plain"
		});*/
		response.write("404 Not Found\n");
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
	path.exists(filename, function(exists){
		if(boolLink){
			boolLink = false;
			if (!exists){
				throw404();
				if(uri.indexOf('load')==1){			
					execDebian("sudo /home/pi/wiringPi/examples/softTone");
					execDebian("NOREFRESH=1 omxplayer /home/pi/noob/video/Oeuf_video_load.mov");	
				}else if(uri.indexOf('FBI')==1){
					var uro = uri.split('--');
					execDebian("sudo /home/pi/wiringPi/examples/softTone");
					execDebian("sudo fbi -T 2 http://10.0.0.1/"+uro[1]+" -noverbose");	
					//execDebian("sudo scripts/pythonCapture.py");	
					if(randomMain==true){
						randomMain=false;
						setTimeout(function(){
							randomMain=true;
							execDebian("sudo fbi -T 2 Design_interface1_black.jpg -noverbose");	
						},5000); 													
					}
				}else if(uri.indexOf('capture')==1){
					//execDebian("NOREFRESH=1 omxplayer /home/pi/noob/video/Explosion_4.mov");	
					execDebian("sudo scripts/pythonCapture.py");									
				}else if(uri.indexOf('omx')==1){
					var uro = uri.split('--');
					execDebian("/home/pi/noob/next_omx.sh /home/pi/noob/video/"+uro[1]+"");	
					console.log(uro[1]);
				}else{
					execDebian("NOREFRESH=1 omxplayer /home/pi/noob/video/Oeuf_video_presentation.mov");					
				}
			} else{
				if(random<8){
					random++;
				}else{
					random=0;
				}			
				execDebian("NOREFRESH=1 omxplayer /home/pi/noob/video/Oeuf_video_"+random+".mov");	
			}		
			var idTime2 = setTimeout(returnFalse,4000,boolLink,true);	
		}
		fs.readFile(filename, "binary", function(err, file){
			if (err) throw500();
			response.writeHead(200);
			response.write(String(file), "binary");
			response.end();
		});
		return;
	});		
};
