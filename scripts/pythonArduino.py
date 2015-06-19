#!/usr/bin/python
# -*- coding: utf-8 -*-

#import binascii
import os
import time
import sys
import serial
    
# Opening mirror.
#mirror = serial.Serial("/dev/tty.usbserial-DA00SY1R", 115200)
mirror = serial.Serial("/dev/ttyUSB0", 9600)

while True:
    print('ok')
    donnee = mirror.readline()
#    donnee2 = mirror2.readline()
    if donnee!="0000" :
          print(donnee)
          sys.stdout.flush()             
              #time.sleep(5)

#    if donnee2 == "0102":
#        print('Ok-gesture')
#        sys.stdout.flush()
        #time.sleep(5)
