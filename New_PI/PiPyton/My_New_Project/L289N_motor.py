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

    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.LOW)
    global Aen
    Aen = GPIO.PWM(MotorAEn, 2000)
    Aen.start(25)


    GPIO.setup(MotorBEn, GPIO.OUT)
    GPIO.setup(MotorB, GPIO.OUT)
    GPIO.setup(MotorB1, GPIO.OUT)


    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)

    global Ben
    Ben = GPIO.PWM(MotorBEn, 2000)
    Ben.start(25)
    #motorStop()
    #global pwm_b
    #pwm_b = GPIO.PWM(MotorPin_B, 100)
    #pwm_b.start(0)
    print "setup done.."


def forward(tf):
    setup()

    #GPIO.output(MotorAEn, GPIO.HIGH)
    global Aen
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)
    Aen.ChangeDutyCycle(80)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)
    #gpio.cleanup()


def reverse(tf):
    setup()
    GPIO.output(MotorAEn, GPIO.HIGH)
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)

    GPIO.output(MotorBEn, GPIO.HIGH)
    GPIO.output(MotorB, GPIO.HIGH)
    GPIO.output(MotorB1, GPIO.LOW)
    time.sleep(tf)
    #gpio.cleanup()


def motorStop():
    GPIO.output(MotorAEn, GPIO.LOW)
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.LOW)

    GPIO.output(MotorBEn, GPIO.LOW)
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)
    #GPIO.output(MotorPin_B, GPIO.LOW)
    #global pwm_b
    #pwm_b.stop()


'''def motor(status):
    #global pwm_b
    GPIO.output(MotorA, GPIO.LOW)
    GPIO.output(MotorA1, GPIO.HIGH)

    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    #GPIO.output(MotorPin_B, GPIO.HIGH)
    #pwm_b.ChangeDutyCycle(50)
    print "runn motor.."
    time.sleep(4)'''

def destroy():
    motorStop()
    GPIO.cleanup()


if __name__ == '__main__':
    #setup()
    try:
        print "forward"
        forward(120)
        #print "reverse"
        #forward(2)

        #i = 0
        #while ( i < 100 ):
        #    time.sleep(2)
        #    motor(i)
        #    i += 20
        destroy()
    except KeyboardInterrupt:
        destroy()
