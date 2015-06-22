#!/usr/bin/python
# -*- coding: utf-8 -*-

#import binascii
import os
import time
import sys
import serial
    
# Opening mirror.
mirror = serial.Serial("/dev/ttyACM0", 9600)

while True:
    donnee = mirror.readline()
    if donnee!="/x00/x00" :
          if donnee[0:2] == '/x00/x00': # Puce posée
              print('Ok-egg')
              sys.stdout.flush()            
              time.sleep(5)

