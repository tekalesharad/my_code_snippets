#!/usr/sbin/env python
import RPi.GPIO as GPIO
import time

PinA=7

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(PinA, GPIO.OUT)
    GPIO.output(PinA, GPIO.LOW)

def lightUp():
    GPIO.output(PinA, GPIO.HIGH)


def lightDn():
    GPIO.output(PinA, GPIO.LOW)

def cleanup():
    GPIO.output(PinA, GPIO.LOW)
    GPIO.cleanup()



if  __name__ == "__main__":
    print "..Start.."
    setup()
    try:
        i=0;
        while ( i < 10) :  
            lightUp()
            time.sleep(1)
            lightDn()
            time.sleep(1)
            print i
            i +=1
        cleanup()

    except KeyboardInterrupt:
        print "..Interrupt.."
        cleanup()





