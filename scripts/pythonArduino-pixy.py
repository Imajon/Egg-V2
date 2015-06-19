#!/usr/bin/python
# -*- coding: utf-8 -*-

#import binascii
import os
import time
import sys
import serial
    
# Opening mirror.
mirror = serial.Serial("/dev/ttyACM0", 9600)
#time.sleep(10)
#print('ok')
while True:
    donnee = mirror.readline()
    if(donnee[0:3]=="sig"):
      #donneeArray = donnee.split(' ')
      os.system("omxplayer video/fond3.mp4")
      print(donnee)
      sys.stdout.flush()
      time.sleep(10)
    #if donnee == 'ok1':
    #     print('OK1 serial')
    #    if donnee == 'ok1': # Puce posée
            #print "Serial identifiée"
            #os.system("echo '1-' >> /home/pi/resultPythonEgg")
     #       print('Ok-egg')
            #sys.stdout.flush()            
      #      time.sleep(5)

