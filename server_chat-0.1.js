var app = require('http').createServer(handler)
  ,io = require('socket.io').listen(app)
  ,fs = require('fs')
  ,exec = require('child_process').exec
  ,util = require('util')  
  ,url = require("url")
  ,path = require("path")
  ,spawn = require('child_process').spawn
  ,ls = spawn('python', ['pythonArduino.py'])
  ,Twit = require('twit');
  //,api = require('instagram-node').instagram();

/*api.use({ access_token: '24903000.fdd1f1b.43ba718621e743a5bce1faa8fd3a28d9' });
api.use({ client_id: 'fdd1f1bab8304908843f09fbc1a153dd',
         client_secret: '57e9f29d4f6a4e62ada63a75d1abec4b' });*/

var T = new Twit({
    consumer_key:         '0DIoS6079MdMh7FOkkfdg'
  , consumer_secret:      'aH56PJD1il9hZeCo3vUkKNSgGXF14Om26jAP5lU5K0'
  , access_token:         '69233369-YEdfLX5E87WSpLR0dT6Pqc6hQxBEGscZ6re0Sje2g'
  , access_token_secret:  '0inTQJXewkmV4cshQfzntbGTt0lpFWo83nNFPufYA'
})
//var stream2 = T.stream('statuses/filter', { location: '-74,40,-73,41' });
var stream2 = T.stream('statuses/filter', { track: 'kickstarter' });
app.listen(8080);
stream2.on('tweet', function (tweet) {
	  if(boolTwitt == true){
		  resultTW = tweet;
		  resultTW.namo = tweet['user']['name'];
		  resultTW.texto = tweet['text'];
		  execDebian("echo 'A' > /dev/ttyUSB0");   
		  console.log(tweet['text']);   
		  resultTW.linko = tweet['user']['url'];
		  //resultTW.mediaURL = tweet['user']['entities']['media']['0']['media_url'];
		  resultTW.profile_img = tweet['user']['profile_image_url'];
		  io.sockets.emit('notifTwit', resultTW);
		  arrayTwit[idTwt]=tweet['user']['profile_image_url'];
		  if(idTwt>10){
		  	  var resultTwit = Math.floor(idTwt/3);
			  idTwt=0;
			  //execDebian('/home/pi/noob/scripts/showOeuf '+resultTwit);
		  }
		  //execDebian("echo 'A' > /dev/tty.usbmodemfa14231");
		  idTwt++;
		  boolTwitt = false;
		  var millisID = setTimeout(millisTwit,1000);
	  }
	})
function execDebian(cible){
	exec(cible, function(err, stdout, stderr) {
		console.log(err);
		console.log(stdout);
		console.log(stderr);
	});			
}
function handler ( request, response ) {
	var uri = url.parse(request.url).pathname;
	if (uri.match(/\/$/)) uri = uri + 'index.htm';
	if (uri == '/server.js') throw404();
	var filename = path.join(process.cwd(), uri);
	path.exists(filename, function(exists){
		if (!exists) throw404();
		fs.readFile(filename, "binary", function(err, file){
			if (err) throw500();
			response.writeHead(200);
			response.write(String(file), "binary");
			response.end();
		});
		return;
	});
	function throw404(){
		response.writeHead(404, {
			"Content-Type": "text/plain"
		});
		response.write("404 Not Found\n");
		response.end();
		return;			
	}
	function throw500(){
		response.writeHead(500, {
			"Content-Type": "text/plain"
		});
		response.write("500 Not Found\n");
		response.end();
		return;
	}
};
/*var stream = T.stream('statuses/filter', { track: 'maillardgranit' })
stream.on('tweet', function (tweet) {
	socket.emit('notification', String(tweet));
})*/
var idUsr = 0;
var idTwt = 0;
var users = [];
var arrayTwit = {};
var arrayTwitTxt = {};
var usersNum= 0;    	
var boolTwitt = true;
var boolEgg = true;
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
	var resultImg = '';
    socket.on('pushTwit', function (msg) {
    	stream2 = T.stream('statuses/filter', { location: '-74,40,-73,41' });
    	idTwt=0;
		//stream2 = T.stream('trends/place', { id: '1' });
	});
	var me=false;
    socket.on('login', function (user) {
    	me = user;
    	me.id = idUsr;
    	users[me.id] = me;
    	socket.broadcast.emit('newusr',me);
    	usersNum++;    	
		//execDebian('/home/pi/noob/scripts/showUser '+usersNum+' Users');
	    execDebian("/home/pi/noob/scripts/writeSerie 'C'");				
    	idUsr++;
		fs.readdir("uploads/fullsize",function(error,directoryObject)
		{
			for( var i in directoryObject){
				console.log(directoryObject[i]);
				resultImg += directoryObject[i]+','
			}
	    	socket.emit('allImg',resultImg);
		});   	
	});
    socket.on('dropCenter', function (user) {
    	socket.broadcast.emit('dropCenter_move',me);
    });
    socket.on('drop_move', function (user) {
    	me.bomb = user.bomb;
    	me.posX = user.posX;
    	me.posY = user.posY;    	
    	socket.broadcast.emit('dropbloc_move',me);
    });
    var idLogin = '';
    ls.stdout.on('data', function (data) {
		if(boolTwitt == true){    	
			resultPython = 'http://192.168.0.14/images/ico0.jpg';    	
			io.sockets.emit('notifEgg', resultPython);
			boolTwitt = false;
		    var millisID = setTimeout(millisEgg,1000);			
		}
    });
    ls.stderr.on('data', function (data) {
	    console.log('stderr: ' + data);
	});
	socket.on('disconnect', function (user) {
		if(!me){
			return false;
		}
    	//execDebian('/home/pi/noob/blink-s.sh 12');
    	delete users[user.id];
    	usersNum--;    	
		execDebian('/home/pi/noob/scripts/showUser '+usersNum+'/Users');
	    execDebian("/home/pi/noob/scripts/writeSerie 'C'");		
	    io.sockets.emit('discousr',me);			
	});	
});
