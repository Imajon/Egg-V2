#!/bin/bash

echo "Puce 1" > /home/pi/test.txt
sudo /home/pi/PCD/samples/pcd8544_display_txt
/usr/local/bin/gpio mode 12 out
/usr/local/bin/gpio write 12 1
sleep 0.2
/usr/local/bin/gpio write 12 0
sleep 2
ifconfig eth0 | grep "inet ad" | cut -f2 -d: | awk '{print $1}' > /home/pi/test.txt
sudo /home/pi/PCD/samples/pcd8544_display_txt
