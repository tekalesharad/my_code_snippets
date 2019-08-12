#! /usr/bin/env python

import RPi.GPIO as GPIO
import time


MotorAEn=12

MotorA=17
MotorA1=22

MotorBEn=18
MotorB=23
MotorB1=24
#MotorPin_B=18


def setup():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(MotorAEn, GPIO.OUT)
    GPIO.setup(MotorA, GPIO.OUT)
    GPIO.setup(MotorA1, GPIO.OUT)

    GPIO.setup(MotorBEn, GPIO.OUT)
    GPIO.setup(MotorB, GPIO.OUT)
    GPIO.setup(MotorB1, GPIO.OUT)

    global Aen
    Aen = GPIO.PWM(MotorAEn, 2000)

    global Ben
    Ben = GPIO.PWM(MotorBEn, 2000)
    print "setup done.."

def init():
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.LOW)
    global Aen
    Aen.start(25)

    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)

    global Ben
    Ben.start(25)
    


def forward(tf):
    init()

    global Aen
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)
    Aen.ChangeDutyCycle(80)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)


def reverse(tf):
    init()
    global Aen
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.HIGH)
    Aen.ChangeDutyCycle(80)

    global Ben
    GPIO.output(MotorB, GPIO.HIGH)
    GPIO.output(MotorB1, GPIO.LOW)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)

def motorStop():
    GPIO.output(MotorAEn, GPIO.LOW)
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.LOW)

    GPIO.output(MotorBEn, GPIO.LOW)
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)

def destroy():
    motorStop()
    GPIO.cleanup()


if __name__ == '__main__':
    setup()
    try:
        print "forward"
        forward(5)
        motorStop()

        print "reverse"
        reverse(5)
        motorStop()

        destroy()

        print "left.."
    except KeyboardInterrupt:
        destroy()
