#! /usr/bin/env python

import RPi.GPIO as GPIO
from car_gpios import *
import time

A_MOTOR_SPEED=100
B_MOTOR_SPEED=80

#To trun Left/Right
LOW_SPEED=10
#To be in Low speed
LEFT_SLEEP=.9
RIGHT_SLEEP=.9

REV_PER_MIN=2000

def setup():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)

    GPIO.setup(MotorAEn, GPIO.OUT)
    GPIO.setup(MotorA, GPIO.OUT)
    GPIO.setup(MotorA1, GPIO.OUT)

    GPIO.setup(MotorBEn, GPIO.OUT)
    GPIO.setup(MotorB, GPIO.OUT)
    GPIO.setup(MotorB1, GPIO.OUT)

    global Aen
    Aen = GPIO.PWM(MotorAEn, REV_PER_MIN)

    global Ben
    Ben = GPIO.PWM(MotorBEn, REV_PER_MIN)
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
    print "forward"
    global Aen
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(B_MOTOR_SPEED)
    Aen.ChangeDutyCycle(A_MOTOR_SPEED)
    time.sleep(tf)


def reverse(tf):
    init()
    print "reverse"
    global Aen
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.HIGH)
    Aen.ChangeDutyCycle(A_MOTOR_SPEED)

    global Ben
    GPIO.output(MotorB, GPIO.HIGH)
    GPIO.output(MotorB1, GPIO.LOW)
    Ben.ChangeDutyCycle(B_MOTOR_SPEED)
    time.sleep(tf)

def left(tf):
    init()
    print "left"
    global Aen
    #GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.LOW)
    #Aen.ChangeDutyCycle(LOW_SPEED)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(B_MOTOR_SPEED)
    #time.sleep(LEFT_SLEEP)

    #GPIO.output(MotorA, GPIO.HIGH)
    Aen.ChangeDutyCycle(A_MOTOR_SPEED)

    time.sleep(tf)

def right(tf):
    init()
    global Aen
    print "right"
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)
    Aen.ChangeDutyCycle(A_MOTOR_SPEED)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    #GPIO.output(MotorB1, GPIO.HIGH)
    GPIO.output(MotorB1, GPIO.LOW)
    #Ben.ChangeDutyCycle(LOW_SPEED)
    #time.sleep(RIGHT_SLEEP)


    #GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(B_MOTOR_SPEED)
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


'''if __name__ == '__main__':
    setup()
    try:
        print "forward"
        forward(5)
        #motorstop()

        print "reverse"
        reverse(5)
        #motorstop()

        print "left.."
        left(5)

        print "right.."
        right(5)

        destroy()
    except keyboardinterrupt:
        destroy() '''

