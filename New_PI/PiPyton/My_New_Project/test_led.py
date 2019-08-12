#! /usr/bin/env python

import RPi.GPIO as GPIO
import time

MotorPin_A=16
MotorPin_B=18

def setup():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(MotorPin_A, GPIO.OUT)
    GPIO.setup(MotorPin_B, GPIO.OUT)
    print "setup done"
 

def destroy():
    #motorStop()
    GPIO.cleanup()


def ledOn():
    GPIO.output(MotorPin_A, GPIO.HIGH)
    GPIO.output(MotorPin_B, GPIO.HIGH)
    print "led on"

def ledOff():
    GPIO.output(MotorPin_A, GPIO.LOW)
    GPIO.output(MotorPin_B, GPIO.LOW)
    print "led off"

if __name__ == '__main__':
    #GPIO.cleanup()
    setup()
    try:
        i = 0
        time.sleep(0.1)
        while ( i < 100 ):
            #motor(i)
            ledOn()
            time.sleep(1)
            ledOff()
            time.sleep(1)

            i += 20
        destroy()
    except KeyboardInterrupt:
        destroy()

