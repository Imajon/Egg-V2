#!/usr/bin/python
# -*- coding: utf-8 -*-

import binascii
import os

# Opening mirror.
mirror = open("/dev/ttyp0", "rb")

while 1:
    donnee = mirror.read(16)
    if donnee != '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00':
        rfid_id = binascii.hexlify(donnee)[4:]
        if donnee[0:2] == '\x02\x01': # Puce posée
            print "Puce identifiée %s posée." % rfid_id
	    os.system("/home/pi/"+rfid_id+"-in.sh")

        elif donnee[0:2] == '\x02\x02': #Puce retirée
            print "Puce identifiée %s retirée." % rfid_id
	    os.system("/home/pi/blink-o.sh 13")
