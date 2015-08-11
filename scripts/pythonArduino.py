#!/usr/bin/python
# -*- coding: utf-8 -*-

#import binascii
import os
import time
import sys
import serial
    
# Opening mirror.
mirror = serial.Serial("/dev/ttyACM0", 9600)
millis1 = int(round(time.time() * 1000))
millis2 = int(round(time.time() * 1000))
millis3 = int(round(time.time() * 1000))
millis4 = int(round(time.time() * 1000))
millis5 = int(round(time.time() * 1000))
millis6 = int(round(time.time() * 1000))

while True:
    donnee = mirror.readline()
    if donnee!="0000" :
#          print(donnee)
#          print(millis1+2000)
          if donnee[0:1] == "A" and int(round(time.time() * 1000))>(millis1+5000): # Puce posée
              print('egg01')
              #os.system("wget http://192.168.0.14/echoA.htm > /dev/null")
              sys.stdout.flush()            
              millis1 = int(round(time.time() * 1000))
          if donnee[0:1] == 'B' and int(round(time.time() * 1000))>(millis2+2000): # Puce posée
              print('egg02')
              sys.stdout.flush()            
              #os.system("wget http://192.168.0.14/echoB.htm > /dev/null")
              millis2 = int(round(time.time() * 1000))
          if donnee[0:1] == 'C' and int(round(time.time() * 1000))>(millis3+2000): # Puce posée
              print('egg03')
              sys.stdout.flush()
              #os.system("wget http://192.168.0.14/echoC.htm > /dev/null")
              #os.system("wget http://10.0.0.235/omx--MA3.mp4 > /dev/null")
              millis3 = int(round(time.time() * 1000))
          if donnee[0:1] == 'D' and int(round(time.time() * 1000))>(millis4+2000):
              print('egg04')
              sys.stdout.flush()
              #os.system("wget http://192.168.0.14/echoD.htm > /dev/null")
              #os.system("wget http://10.0.0.235/omx--MA3.mp4 > /dev/null")
              millis3 = int(round(time.time() * 1000))
