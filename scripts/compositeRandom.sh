#!/bin/bash

image1=`ls /home/pi/noob/uploadsDir/mini/ | sort -R | head -n1`
image2=`ls /home/pi/noob/uploadsDir/mini/ | sort -R | head -n1`
name=$RANDOM$RANDOM
temp=`/opt/vc/bin/vcgencmd measure_temp`
composite /home/pi/noob/uploadsDir/mini/$image1 /home/pi/noob/uploadsDir/mini/$image2 -dissolve 50 /home/pi/noob/composite/$name.jpg

convert /home/pi/noob/composite/$name.jpg  -fill white  -pointsize 20 \
          -gravity center   -annotate 0 $temp  /home/pi/noob/composite/$name.jpg

#convert rose:  -fill white  -font Candice  -pointsize 20 \
#          -gravity center   -annotate 0 $temp  /home/pi/noob/composite/$name.jpg
#convert -density 90 -pointsize 72 label:$temp  /home/pi/noob/composite/$name.jpg
