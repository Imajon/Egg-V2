#!/bin/bash

SERVICE='omxplayer'

while true; do
if ps ax | grep -v grep | grep $SERVICE > /dev/null
then
sleep 1
else
omxplayer -o hdmi $1
fi
done
===========================================

