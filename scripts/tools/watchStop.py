#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os, sys
if not os.getuid() == 0:
    sys.exit('Needs to be root for running this script.')
import RPi.GPIO as GPIO
import time
import subprocess
# the button is connected on GPIO4 (pin 7 of header)
BTN_IO = 4
# we use the Broadcom numbering of the I/O
# (instead of the RasPi header pin numbering)
GPIO.setmode(GPIO.BCM)
# the I/O is configured as input with pullup enabled
GPIO.setup(BTN_IO, GPIO.IN, GPIO.PUD_UP)
print('monitoring started')
while True:
    pressed = (GPIO.input(BTN_IO) == 0)
    if pressed:
        print('pressed')
        time.sleep(4)
        pressed = (GPIO.input(BTN_IO) == 0)
        if pressed:
            break
    else:
        time.sleep(0.1)
print('Shutdown button pressed. System is going to halt now')
#subprocess.call('halt')
