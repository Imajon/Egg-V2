#!/bin/bash

/usr/local/bin/gpio mode 0 out
/usr/local/bin/gpio mode 12 out
/usr/local/bin/gpio mode 13 out
/usr/local/bin/gpio mode 14 out
/usr/local/bin/gpio mode 2 out
/usr/local/bin/gpio mode 3 out

/usr/local/bin/gpio write 0 0
/usr/local/bin/gpio write 2 0
/usr/local/bin/gpio write 3 0
/usr/local/bin/gpio write 12 0
/usr/local/bin/gpio write 13 0
/usr/local/bin/gpio write 14 0

/usr/local/bin/gpio write 0 1
sleep 0.1
/usr/local/bin/gpio write 0 0
/usr/local/bin/gpio write 2 1
sleep 0.1
/usr/local/bin/gpio write 2 0
/usr/local/bin/gpio write 3 1
sleep 0.1
/usr/local/bin/gpio write 3 0
/usr/local/bin/gpio write 12 1
sleep 0.1
/usr/local/bin/gpio write 12 0
/usr/local/bin/gpio write 13 1
sleep 0.1
/usr/local/bin/gpio write 13 0
/usr/local/bin/gpio write 14 1
sleep 0.1
/usr/local/bin/gpio write 14 0
echo ok
/local/bin/gpio write 14 0
echo ok
