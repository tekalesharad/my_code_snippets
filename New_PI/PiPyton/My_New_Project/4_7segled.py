#!/usr/sbin/evn pythin

import RPi.GPIO as GPIO
import time
import sys

PinA=3    #1
PinB=5    #2  
PinC=7    #3
PinD=8    #4
PinE=10   #5
PinF=11   #6
PinG=12   #7
PinDP=13  #8

PinD1=15  #9
PinD2=16  #10
PinD3=18  #11
PinD4=19  #12

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
SELECT_PIN=[PinD1, PinD2, PinD3, PinD4]
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
    
import pdb
def setup():
    #global TRIGGER_OFF
    GPIO.setmode(GPIO.BOARD)
    #pdb.set_trace()
    #trigger_type(type)
    for sel in SELECT_PIN:
        GPIO.setup(sel, GPIO.OUT)
    #    GPIO.output(sel, TRIGGER_ON)
    for pinN in ALL_PINS:
        GPIO.setup(pinN, GPIO.OUT)
        GPIO.output(pinN, GPIO.HIGH)
        #GPIO.output(pinN, TRIGGER_ON)

def blink_one():
    #global TRIGGER_ON
    #for sel in SELECT_PIN:
        #GPIO.setup(sel, GPIO.OUT)
    GPIO.output(PinD1, GPIO.LOW)
    for i in range(1,10):
        for pinN in my_dict[str(i)]:
            GPIO.output(pinN, TRIGGER_ON)
        time.sleep(0.5)


def blinkAll():
    #global TRIGGER_ON
    for sel in SELECT_PIN:
        #GPIO.setup(sel, GPIO.OUT)
        GPIO.output(sel, TRIGGER_ON)
    for pinN in ALL_PINS:
        GPIO.output(pinN, TRIGGER_ON)

def clearAll():
    #global TRIGGER_OFF
    for pinN in ALL_PINS:
        GPIO.output(pinN, TRIGGER_OFF)
    for sel in SELECT_PIN:
        GPIO.output(sel, TRIGGER_OFF)

def display(num):
    #global TRIGGER_ON
    GPIO.output(PinD1, TRIGGER_OFF)
    for pinN in my_dict[num]:
        GPIO.output(pinN, TRIGGER_ON)
        

if __name__ == '__main__':
    #setup(str(sys.argv))
    setup()
    try:
        blink_one()
        #blinkAll()
        time.sleep(1)
        clearAll()

        #for pins in DISPLAY_ALL:
        #    display(pins)
        #    time.sleep(1)
        #    clearAll()
        #clearAll()
        GPIO.cleanup()
    except KeyboardInterrupt:
        clearAll()
        GPIO.cleanup()

