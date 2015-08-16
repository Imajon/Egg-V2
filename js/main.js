function updateClock()
{
  var currentTime = new Date();
  var currentHours = currentTime.getHours();
  var currentMinutes = currentTime.getMinutes();
  var currentSeconds = currentTime.getSeconds();
  var currentDay = currentTime.getDay();
  currentMinutes = ( currentMinutes < 10 ? '0' : '' ) + currentMinutes;
  currentSeconds = ( currentSeconds < 10 ? '0' : '' ) + currentSeconds;
  //var currentTimeString = currentHours + ":" + currentMinutes + ":" + currentSeconds;
  $('#spanHour').html(currentHours);
  $('#spanMinute').html(currentMinutes);
  $('#spanSecond').html(currentSeconds);
  console.log(currentDay);
  console.log('clock');
}
//var idInter = setInterval(updateClock,1000);  
var numJour = 0;
var totalJour = 0;
var hourDay = 'h';
var numScroll = 0;
var arrayResult = Array();  
var numSousSouvenir = 0;
var idHistoire = 0;
window.mobilecheck = function() {
    var check = false;
    (function(a,b){if(/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|mobile.+firefox|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows ce|xda|xiino/i.test(a)||/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0,4)))check = true})(navigator.userAgent||navigator.vendor||window.opera);
    return check;
  }
function createMessage(cible,file,message,date){
      $('.contain_Sujet').append('<div id="draggable'+cible+'" class="blocHistoire sortable" alt="'+cible+'"><a href="uploadsDir/mini/'+file+'" class="dragImgClass"><img class="img'+cible+'" id="img'+cible+'" src="uploadsDir/mini/'+file+'"  exif="true" width="70" class="imgHistoire imgHistoire'+cible+'"></a><span class="titreImg">'+message+'<br>'+date+'</span></div>');                    
}
function createMessageLive(cible,file,message,date){
    var dateScreen = convertDate(date)  
    $('.contain_Sujet').prepend('<div id="draggable'+cible+'" class="blocHistoire sortable" alt="'+cible+'"><a href="'+file+'" class="dragImgClass"><img class="img'+cible+'" id="img'+cible+'" src="'+file+'"  exif="true" width="70" class="imgHistoire imgHistoire'+cible+'"></a><span class="titreImg">'+message+'<br>'+dateScreen+'</span></div>');                    
    var wido = $('#draggable'+cible).css('width');
    $('#draggable'+cible).css('height',($('#draggable'+cible+' div img').parent().parent().width()/1.33)+20);       
    $('#draggable'+cible+' div').css('height',($('#draggable'+cible+' div img').parent().parent().width()/1.33)+20);       
    $('#draggable'+cible+' img').load(function(){
        numScroll++;
        idHistoire--;
        var wCible = ($('#draggable'+cible).width()-$(this).width())/2;
        var hCible = ($('#draggable'+cible).height()-$(this).height())/2;
        $('#draggable'+cible).css('height',wido);
        if($(this).height()>$(this).width()){
          $(this).css('width','100%');
          //$(this).css('margin-top',hCible+'px');
          $(this).css('height','auto');
        }else{
          $(this).css('height',wido);
          //$(this).css('margin-left',wCible+'px');
          $(this).css('width','auto');
        }
        if(idHistoire>=0){
          recapHistoire(idHistoire,cible2,totalJour,numJour);
        }else{
         
        }
    });   
}
function convertDate(date){
    var dateToday = new Date();
    dateToday.getTime();
    var difDate = dateToday-date;
    var dateScreen = '';
    difDate = difDate/1000;
    if(difDate<60){
      dateScreen = Math.floor(difDate)+' sec';
    }else if(difDate<3600 && difDate>60){
      dateScreen = Math.floor(difDate/60)+' min';      
    }else if(difDate<86400 && difDate>3600){
      dateScreen = Math.floor(difDate/3600)+' h';      
    }else if(difDate>86400){
      dateScreen = Math.floor(difDate/86400)+' jour';      
    }
    return dateScreen;
}
function recapHistoire(cible,cible2,numJour){
  var retourALT = cible;
  var posX = Math.floor(Math.random()*80);
  var posY = Math.floor(Math.random()*100);
  var randomJour = Math.floor(Math.random()*10);
  totalJour = numJour+randomJour;      
  //$('.contain_Sujet').append('<div id="draggable'+cible+'" style="left:'+posX+';top:'+posY+';" class="blocHistoire sortable" alt="'+retourALT+'"><div class="dragImgClass"><img class="img'+cible+'" src="'+cible2[cible]+'" width="70" class="imgHistoire imgHistoire'+cible+'"></div></div>');
  //$('.contain_Sujet').append('<div id="draggable'+cible+'" style="left:'+posX+';top:'+posY+';" class="blocHistoire sortable" alt="'+retourALT+'"><div class="dragImgClass"><img class="img'+cible+'" src="'+cible2[cible]+'" width="70" class="imgHistoire imgHistoire'+cible+'"></div></div>');
  if(cible2[cible].img!='' && cible2[cible].img!=undefined && cible2[cible].type!=numJour){
    var dateScreen = convertDate(cible2[cible].date)
    $('.contain_Sujet').append('<div id="draggable'+cible+'" class="blocHistoire sortable" alt="'+retourALT+'"><a href="uploadsDir/mini/'+cible2[cible].img+'" class="dragImgClass"><img class="img'+cible+'" id="img'+cible+'" src="uploadsDir/mini/'+cible2[cible].img+'"  exif="true" width="70" class="imgHistoire imgHistoire'+cible+'"></a><span class="titreImg">'+cible2[cible].mess+'<br>'+dateScreen+'</span></div>');                    
    var fileImg = document.getElementById('img'+cible);
    var wido = $('#draggable'+cible).css('width');
    $('#draggable'+cible).css('height',($('#draggable'+cible+' div img').parent().parent().width()/1.33)+20);       
    $('#draggable'+cible+' div').css('height',($('#draggable'+cible+' div img').parent().parent().width()/1.33)+20);       
    $('#draggable'+cible+' img').load(function(){
        numScroll++;
        idHistoire--;
        var wCible = ($('#draggable'+cible).width()-$(this).width())/2;
        var hCible = ($('#draggable'+cible).height()-$(this).height())/2;
        $('#draggable'+cible).css('height',wido);
        if($(this).height()>$(this).width()){
          $(this).css('width','100%');
          //$(this).css('margin-top',hCible+'px');
          $(this).css('height','auto');
        }else{
          $(this).css('height',wido);
          //$(this).css('margin-left',wCible+'px');
          $(this).css('width','auto');
        }
        if(idHistoire>=0){
          recapHistoire(idHistoire,cible2,totalJour,numJour);
        }else{
         
        }
    });
  }else{
      scrollBool=true;
  }
  $('#draggable'+cible).bind('click',function(){
    document.getElementById('links').onclick = function (event) {
        event = event || window.event;
        var target = event.target || event.srcElement,
            link = target.src ? target.parentNode : target,
            options = {index: link, event: event},
            links = this.getElementsByTagName('a');
        blueimp.Gallery(links, options);
    };    
  });
  numSousSouvenir ++;                      
}
var scrollBool = false;
window.addEventListener("load",function() {
    setTimeout(function(){
        window.scrollTo(0, 1);
    }, 0);
});

/*$(window).scroll(function()
{
    if($(window).scrollTop() > $(document).height() - $(window).height()-80 && scrollBool)
    {
        console.log(numScroll);
        numScroll = 0;
        if(numSousSouvenir<arrayResult.length){
          recapHistoire(idHistoire,arrayResult,numJour); 
        }
    }
});*/
$(document).ready(function(){
  var socket = io.connect('http://192.168.1.13/');
  var stringA = '';
  var stringB = '';          
  var stringC = '';  
  var numSouvenir = 0;
  var numMain = 0;
  var numDrag = 10;
  var numBlocHastag = 4;
  var allImg;
  socket.emit('login' ,{username:''});
  var titleArray = Array('Street Art','Rencontre','Projet');
  var quant_histoire = 6;
  var currentTime = 20;
  var afterSeconds = 0;
  var idInter;  
  var nameDiapo = Array('Julien','Anne','Marion','Jon','Nico','Thomas','Julie','Fabien','Koi');
  var date_story = new Date();
  var yPos = 0;
  var boolLoad = true;
  var arrayEtat = Array('A','B','C','D','E','F','H','G');    
  var nbTouch = 0;
  /*$("body").bind("touchstart", function(evt){
    evt.preventDefault();
  })
  $("body").bind("touchmove", function(evt){
      yPos = evt.originalEvent.touches[0].pageY;
      $('#info').html(yPos);
      evt.preventDefault();
  })
  $("body").bind("touchend", function(evt){
    yPos = evt.originalEvent.touches[0].pageY-yPos;
    if(yPos>0){
      $('#info').html('yPos');
    }
    evt.preventDefault();
  })*/
  $('.blocTitre').css('opacity',1);
  $('.footero').css('opacity',1);
  $('.footero').css('bottom','0px');
  var intMess = 1;
  var time2;
  var random2 = 0;
  function updateOeufIcone(cible){
      //var random2 = Math.floor(Math.random()*arrayEtat.length);
      if(cible=='' || cible==undefined){
        $('#imageCentre2').attr('src','images/compo_loopa/back_egg'+arrayEtat[random2]+'.png');
      }else{
        $('#imageCentre2').attr('src','images/compo_loopa/back_egg'+cible);        
      }
      if(random2<arrayEtat.length-1){
        random2++;
      }else{        
        random2=0;
      }
  }
  /*$( "#icone1" ).click(function() {
    scrollBool=false;
    $('.contain_Sujet').html('');    
    $("#BlocInfo").show();
    $("#textInfo").html($('.introTXT').html());
  $( "#icone2, #imagecentre2" ).click(function() {
    scrollBool=false;
    //$('.contain_Sujet').html('');    
    updateOeufIcone();
    socket.emit('arduino_click','ok');
  });  
  $( "#icone3" ).click(function() {
    scrollBool=false;
    $("#BlocInfo").show();
    $("#textInfo").html($('.geoLoc').html()+'<br>');
  $(".titreBlocInfo").click(function() {
    $( "#BlocInfo" ).hide();
  });
  /*$( ".blocTitre" ).click(function() {
    updateOeufIcone();
  }); */ 
  $(".closebloc").click(function() {
    $( "#BlocInfo" ).hide();
  });
  
  $( ".sortable" ).click(function() {
    switch(this.id){
      case 'draggable100':
          break;
      case 'draggable101':      
          scrollBool=false;    
          $("#BlocInfo").show();
          $("#textInfo").html($(this).find('.sub1').html());
          $(".iframeClass").hide();
          $(".iframeClass").show();
          numScroll = 0;
          if(boolLoad){
            $.ajax({
              url: 'uploads',
              type: 'post',
              dataType: 'json',
              success: function(e){
                 idHistoire = e.length-1;
                 boolLoad=false;
                 recapHistoire(idHistoire,e,numJour,6,'depot'); 
                 $('.subIMG').html(arrayResult.length+' images');
              }            
            });
          }
          break;
      case 'draggable104':      
          scrollBool=false;    
          $("#BlocInfo").show();
          $("#textInfo").html($(this).find('.sub1').html());
          $(".iframeClass").hide();
          $(".iframeClass").show();
          numScroll = 0;
          if(boolLoad){
            $.ajax({
              url: 'uploads',
              type: 'post',
              dataType: 'json',
              success: function(e){
                console.log("e : "+e[0].img);
                 idHistoire = e.length-1;
                 boolLoad=false;
                 recapHistoire(idHistoire,e,numJour,6,'indice'); 
                 $('.subIMG').html(arrayResult.length+' images');
              }            
            });
          }
          break;          
      case 'draggable102':
          //$("#textInfo").html($('.hashtag').html());
          break;
      case 'draggable103':
          //$("#textInfo").html($('.monument').html());
          break;
      case 'draggable104':
          console.log('draggable104');
          break;
    }
  });
  var x = "User-agent header sent: " + navigator.userAgent;
  //$('#BlocInfo').append('<span style="font-size:10px;">'+x+'</span>');
  function hideBloc(){
    $("#BlocInfo").hide();
    //$("#BlocInfo").fadeTo('500',0,function(){document.getElementById("BlocInfo").style.display = 'none;';});
  };
  $( ".follower" ).click(function() {
      stringA = $(this).attr('id');        
      stringB = $(this).find( ".displayOut" ).html();
      stringC = $(this).find( ".displayOut2" ).html();
      if($(this).css('margin')!='4px'){
        $(this).css('border','1px solid #fff');
        $(this).css('margin','4px');                
        socket.emit('follow_subject',{img:stringB,idDiv:stringA,subject:stringC});
      }
  });
      
  function readTwit(cible,cible2){
    if(cible.indexOf('#',cible2)!=-1){
      var place1 = cible.indexOf('#');
      var place2 = cible.indexOf(' ',cible2);
      cible = cible.substr(cible2,place1)+'<span class="fontTitreTwit">'+cible.substr(place1,place2)+'</span>'+cible.substr(place2,cible.length-1);
    }
    if(cible.indexOf('@',cible2)!=-1){
      var place1 = cible.indexOf('@');
      var place2 = cible.indexOf(' ',cible2);
      cible = cible.substr(cible2,place1)+'<span class="fontTitreTwit">'+cible.substr(place1,place2)+'</span>'+cible.substr(place2,cible.length-1);
    }        
    if(cible.indexOf('http',cible2)!=-1){
      var place1 = cible.indexOf('http');
      var place2 = cible.indexOf(' ',cible2);
      cible = cible.substr(cible2,place1)+'<a href="" class="fontTitreTwit">'+cible.substr(place1,place2)+'</a>'+cible.substr(place2,cible.length-1);
    }                    
    return cible;
  }        
  socket.on('upload_notif', function (user) {
      createMessageLive(numSousSouvenir,user.img,user.mess,user.date);
      numSousSouvenir++;
  });
  socket.on('notifEgg', function (user) {
      nbTouch++;
      $('.nbTouch').html(nbTouch);              
  });
  /*socket.on('notifTwit', function (user) {
      $('.contain_Sujet').prepend('<div id="draggable'+numDrag+'" class="blocHistoire" alt="'+user.namo+'"><div class="background_noob blocNotif_txt pos_notif_story">'+(numDrag+2)+'</div><div class="blocTime"></div><div class="storyTitle">'+user.namo+'</div><div class="dragImgClass"><img class="img'+numDrag+'" src="'+user.profile_img+'" width="70" class="imgHistoire imgHistoire'+numDrag+'"></div></div>');
      numDrag++;
  }); */            
  socket.on('notifEgg', function (user) {
      //$('.contain_Sujet').prepend('<div id="draggable'+numSousSouvenir+'" class="blocHistoire_icone blocSensor" alt="'+numDrag+'"><div class="dragImgClass"><img class="img'+numDrag+'" src="images/icone-main.jpg" width="70" class="imgHistoire imgHistoire'+numDrag+'"></div></div>');
      //$('.pos_blocNotif_txt').html(numSousSouvenir);    
      nbTouch++;
      $('.nbTouch').html(nbTouch);    
          
      /*$('.iframeClass').animate({
            height:'60px',
          }, 300);*/
      //$('body').css('background','url("images/fond_oeuf4.jpg") top');
      //$('body').css('background-size','120%');
      //window.clearInterval(idInter);
      //idInter = setInterval(updateClock,1000);  
  });
  /*
  socket.on('socket_open_subject', function (user) {
    allImg = user.split(',');
      for (var i = 0; i <allImg.length-1; i++) {
        $('.containTwit').prepend('<div id="draggable'+numHastag+'" class="blocHistoire_suite"><div class="background_noob blocNotif_txt pos_notif_story">'+(numHastag+2)+'</div><div class="blocTime"></div><div class="storyTitle">Souvenir '+numHastag+'</div><div class="dragImgClass"><img class="img'+numHastag+'" src="'+allImg[numHastag]+'" width="70"></div></div>');
          $('.img'+numHastag).hide();
          $('.img'+numHastag).load(function(){
            $(this).fadeTo('400',1);
          });
          numHastag++; 
      };                
  });    */              
  /*socket.on('new_subject_usr', function (user) {
      $('.containerBloc').append('<div id="draggable'+numBlocHastag+'" class="ui-widget-content font2 dragClass draggable dragor"><span class="displayOut2">'+user.subject+'</span><span class="displayOut">point.png</span></div>');
      numBlocHastag++;
  });*/  
  var Time1;
  function updateIcone(cible1,cible2){
    clearTimeout(Time1);
    returnImg(cible1,cible2);
    //document.images[cible1].src="images/icones/"+cible2+"B.png";
    Time1 = setTimeout(returnImg,1000,cible1,'0px');
  }
  function returnImg(cible1,cible2){
    $('.'+cible1).animate({
            'background-position-y':cible2,
          }, 300,'easeOutQuint'); 
    //document.images[cible1].src=cible2;
  }
  socket.on('arduino_notif', function (data) {
    $('.nbTouch').html(data);
    //updateOeufIcone('2.gif');
  });       
  socket.on('newusr', function (data) {
    //updateIcone('icone01','-62px');
    $('.nbUser').html(data.all);
    $('.nbImg').html(data.img);
    $('.nbTouch').html(data.nbTouch);
    console.log('newuser touch '+data.nbTouch);
    //$('.contain3').prepend('<div id="bloc'+data.id+'" class="background_noob bgd_notif2 "><span>'+data.id+'</span></div>');
    //$('bloc'+numHastag).hide();
    //$('bloc'+numHastag).fadeTo('400',1);
  });            
  socket.on('message_notif', function (data) {
        $(".blocTitre").find("img").attr("src", "images/OUEF2_1.gif");
        //$('.blocTitre').append('<div class="blocMessage" style="top:'+(20*intMess)+'px">'+data+'</div>');
        intMess++
  });            
  socket.on('discousr', function (user) {
      //$('.blocNotif2_txt').html(user.all);
    $('.nbUser').html(data.all);
      $('#bloc'+user.id).remove();
    });     
  /*var idInter = setInterval(function(){
    var random = Math.floor(Math.random()*3)+1;
    var random2 = Math.floor(Math.random()*arrayEtat.length);
    updateIcone('icone0'+random,'-94px');
    $('.blocTitre').css('background','url("images/icones/icone_etat'+arrayEtat[random2]+'.png") no-repeat center');
    $('.blocTitre').fadeTo('300',0,function(){
      $('.blocTitre').css('background','url("images/icones/icone_etat'+arrayEtat[random2]+'.png")');
      $('.blocTitre').fadeTo('300',1);
    })

  },5000);*/
  function updateClock()
  {
    /*var currentTime = new Date();
    var currentHours = currentTime.getHours();
    var currentMinutes = currentTime.getMinutes();
    var currentSeconds = currentTime.getSeconds();
    var currentDay = currentTime.getDay();
    currentMinutes = ( currentMinutes < 10 ? '0' : '' ) + currentMinutes;
    currentSeconds = ( currentSeconds < 10 ? '0' : '' ) + currentSeconds;
    */
    if(afterSeconds<currentTime){
      $('.pos_blocNotif_compteur').html(currentTime-afterSeconds);
      afterSeconds++;            
    }else{
      afterSeconds=0;            
     $('.pos_blocNotif_compteur').html('Oeuf fermé');
     $('.iframeClass').animate({
            height:0,
          }, 300);         
      $('body').css('background','url("images/fond_oeuf.jpg") top');
      $('body').css('background-size','600px');
      window.clearInterval(idInter);
    }
  }
});    