#!/usr/bin/python
# -*- coding: utf-8 -*-

import serial
ser = serial.Serial('/dev/tty.usbmodemfd131', 9600)
ser.write("1")
