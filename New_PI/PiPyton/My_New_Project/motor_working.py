#! /usr/bin/env python

import RPi.GPIO as GPIO
import time

CLOCK_W=1
C_CLOCK_W=1

MotorPin_A=16
MotorPin_B=18

def init():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(MotorPin_A, GPIO.OUT)
    GPIO.setup(MotorPin_B, GPIO.OUT)
    global pwm_b
    pwm_b = GPIO.PWM(MotorPin_B, 2000)
    print "init done.."


def setup( s_type ):
    if s_type == CLOCK_W :
#    GPIO.setwarnings(False)
#    GPIO.setmode(GPIO.BOARD)
#    GPIO.setup(MotorPin_A, GPIO.OUT)
#    GPIO.setup(MotorPin_B, GPIO.OUT)
        GPIO.output(MotorPin_A, GPIO.HIGH)
        GPIO.output(MotorPin_B, GPIO.LOW)
        pwm_b.start(0)
    if s_type == C_CLOCK_W :
        GPIO.output(MotorPin_A, GPIO.LOW)
        GPIO.output(MotorPin_B, GPIO.HIGH)
        pwm_b.start(100)
    print "setup done.."

def motorStop():
    GPIO.output(MotorPin_A, GPIO.HIGH)
    GPIO.output(MotorPin_B, GPIO.LOW)
    global pwm_b
    pwm_b.stop()


def motor_clockwise(status):
    global pwm_b
    GPIO.output(MotorPin_A, GPIO.HIGH)
    #pwm_b.start(100)
    #Run at high speed.. 
    pwm_b.ChangeDutyCycle(5)
    #pwm_b.ChangeDutyCycle(100-status)
    print "runn motor.."


def motor_c_clockwise(status):
    global pwm_b
    GPIO.output(MotorPin_A, GPIO.LOW)
    #pwm_b.start(100)
    #Run at high speed.. 
    pwm_b.ChangeDutyCycle(100-status)
    #pwm_b.ChangeDutyCycle(100-status)
    print "runn motor.."


def destroy():
    motorStop()
    GPIO.cleanup()

if __name__ == '__main__':
    #GPIO.cleanup()
    init()
    try:
        setup(CLOCK_W)
        i = 0
        time.sleep(0.1)
        while ( i < 100 ):
            motor_clockwise(i)
            time.sleep(1)
            i += 10
        # counter-clockwise
        setup(C_CLOCK_W)
        i = 0
        time.sleep(0.1)
        while ( i < 100 ):
            motor_c_clockwise(i)
            time.sleep(1)
            i += 10

        destroy()
    except KeyboardInterrupt:
        destroy()

