#!/usr/bin/python
import time
import picamera
import sys

if len(sys.argv) != 2:
  sys.exit("Not enough args")
ca_one = str(sys.argv[1])
#ca_two = str(sys.argv[2])

print "My command line args are " + ca_one

#opts, extraparams = getopt.getopt(sys.argv[1:]) 
# starts at the second element of argv since the first one is the script name
# extraparms are extra arguments passed after all option/keywords are assigned
# opts is a list containing the pair "option"/"value"
#print 'Opts:',opts
#print 'Extra parameters:',extraparam

with picamera.PiCamera() as camera:
    camera.start_preview()
    time.sleep(5)
    camera.capture('/home/pi/capture/'+ca_one+'.jpg')
    camera.stop_preview()
