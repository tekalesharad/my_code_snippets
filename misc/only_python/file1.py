#!/usr/sbin/evn pythin

import RPi.GPIO as GPIO
import time

PinA=11
PinB=12
PinC=13
PinD=15
PinE=16
PinF=18
PinG=19
PinDP=21

my_dict={
        "one":[PinA, PinB],
        "two":[PinA, PinB, PinG, PinE, PinD]
        }
    

ALL_PINS = [ PinA, PinB, PinC, PinD, PinE, PinF, PinG, PinDP ]


def fun(num):
    for val in my_dict[num]:
        print val



fun("one")
