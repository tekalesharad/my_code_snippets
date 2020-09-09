#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

LedPin=11
LedPin1=12
LedPin2=13

GPIO.setmode(GPIO.BOARD);

GPIO.setup(LedPin, GPIO.OUT)
GPIO.setup(LedPin1, GPIO.OUT)
GPIO.setup(LedPin2, GPIO.OUT)

#p = GPIO.
def default_function():
    print "Green Led"
    GPIO.output(LedPin, GPIO.LOW)
    time.sleep(1)
    GPIO.output(LedPin, GPIO.HIGH)
    time.sleep(1)
    print "Red Led"
    GPIO.output(LedPin1, GPIO.LOW)
    time.sleep(1)
    GPIO.output(LedPin1, GPIO.HIGH)
    time.sleep(1)
    print "Blue Led"
    GPIO.output(LedPin2, GPIO.LOW)
    time.sleep(1)
    GPIO.output(LedPin2, GPIO.HIGH)
    time.sleep(1)
    print "... Led"
    GPIO.output(LedPin, GPIO.LOW)
    GPIO.output(LedPin1, GPIO.LOW)
    time.sleep(2)
    GPIO.output(LedPin, GPIO.HIGH)
    GPIO.output(LedPin1, GPIO.HIGH)
    time.sleep(1)
    print "Purle. Led"
    GPIO.output(LedPin1, GPIO.LOW)
    GPIO.output(LedPin2, GPIO.LOW)
    time.sleep(2)
    GPIO.output(LedPin1, GPIO.HIGH)
    GPIO.output(LedPin2, GPIO.HIGH)
    time.sleep(1)
    print ".... Led"
    GPIO.output(LedPin2, GPIO.LOW)
    GPIO.output(LedPin, GPIO.LOW)
    time.sleep(2)
    GPIO.output(LedPin2, GPIO.HIGH)
    GPIO.output(LedPin, GPIO.HIGH)

    time.sleep(1)
    print "Pink Led"
    GPIO.output(LedPin2, GPIO.LOW)
    GPIO.output(LedPin1, GPIO.LOW)
    GPIO.output(LedPin, GPIO.LOW)
    time.sleep(2)
    GPIO.output(LedPin2, GPIO.HIGH)
    GPIO.output(LedPin1, GPIO.HIGH)
    GPIO.output(LedPin, GPIO.HIGH)

try:
    default_function()
except KeyboardInterrupt:
    GPIO.output(LedPin2, GPIO.HIGH)
    GPIO.output(LedPin1, GPIO.HIGH)
    GPIO.output(LedPin, GPIO.HIGH)
    GPIO.cleanup()


