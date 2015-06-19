#!/usr/bin/env python
import picamera
import time

from time import sleep

camera = picamera.PiCamera()

camera.capture('image1.jpg')
sleep(5)
camera.capture('image2.jpg')
