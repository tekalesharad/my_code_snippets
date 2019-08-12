#!/usr/sbin/evn pythin

import RPi.GPIO as GPIO
import time
import sys

PinA=11
PinB=12
PinC=13
PinD=15
PinE=16
PinF=18
PinG=19
PinDP=21


#COM_CATHODE_TRIGGER
#TRIGGER_ON=GPIO.HIGH
#TRIGGER_OFF=GPIO.LOW
#COM_ANODE_TRIGGER


TRIGGER_ON=GPIO.HIGH
TRIGGER_OFF=GPIO.LOW

def trigger_type(type):
    #global TRIGGER_ON
    #global TRIGGER_OFF
    if type == "cathode":
        TRIGGER_ON=GPIO.HIGH
        TRIGGER_OFF=GPIO.LOW
    else:
        TRIGGER_ON=GPIO.LOW
        TRIGGER_OFF=GPIO.HIGH

ALL_PINS = [ PinA, PinB, PinC, PinD, PinE, PinF, PinG, PinDP ]
DISPLAY_ALL = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "dot"]

my_dict={
        "1":[PinB, PinC],
        "2":[PinA, PinB, PinG, PinE, PinD],
        "3":[PinA, PinB, PinG, PinC, PinD],
        "4":[PinF, PinG, PinC, PinB],
        "5":[PinA, PinF, PinG, PinC, PinD],
        "6" :[PinA, PinF, PinE, PinD, PinC, PinG],
        "7":[PinA, PinB, PinC],
        "8": ALL_PINS,
        "9":[PinA, PinF, PinG, PinB, PinC],
        "dot":[PinDP]
        }
    

def setup(type):
    #global TRIGGER_OFF
    GPIO.setmode(GPIO.BOARD)
    #trigger_type(type)
    for pinN in ALL_PINS:
        GPIO.setup(pinN, GPIO.OUT)
        GPIO.output(pinN, TRIGGER_OFF)

def blinkAll():
    #global TRIGGER_ON
    for pinN in ALL_PINS:
        GPIO.output(pinN, TRIGGER_ON)

def clearAll():
    #global TRIGGER_OFF
    for pinN in ALL_PINS:
        GPIO.output(pinN, TRIGGER_OFF)

def display(num):
    #global TRIGGER_ON
    for pinN in my_dict[num]:
        GPIO.output(pinN, TRIGGER_ON)
        

if __name__ == '__main__':
    setup(str(sys.argv))
    try:
        blinkAll()
        time.sleep(1)
        clearAll()

        for pins in DISPLAY_ALL:
            display(pins)
            time.sleep(1)
            clearAll()
        clearAll()
        GPIO.cleanup()
    except KeyboardInterrupt:
        clearAll()
        GPIO.cleanup()

