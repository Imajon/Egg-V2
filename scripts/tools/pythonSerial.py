#!/usr/bin/python
# -*- coding: utf-8 -*-

import serial
ser = serial.Serial('/dev/tty.usbmodemfd131', 9600)
fileTXT = open('resultPythonSerial','r')
while 1:
    donnee = fileTXT.read(2)
    if donnee == 'A':
        ser.write('A')
    if donnee == 'C':
        ser.write('B')
    if donnee == 'D':
        ser.write('C')
