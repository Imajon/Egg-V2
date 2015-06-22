#!/bin/sh
filename=$(date +"%m-%d-%y-%H%M%S")
/home/pi/noob/pythonJPG.py $filename
#fswebcam -r 356x292 -d /dev/video0 $filename.jpg
scp /home/pi/capture/$filename.jpg u39199937@enygmart.info:loopa/capture/$filename.jpg
