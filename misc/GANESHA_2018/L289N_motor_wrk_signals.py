#! /usr/bin/env python

import RPi.GPIO as GPIO
import time
import signal


#MotorAEn=12

#MotorA=17
#MotorA1=22

MotorBEn=18
MotorB=23
MotorB1=24
#MotorPin_B=18

def setup():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)

    #motorStop()
    GPIO.cleanup()
 #   GPIO.setup(MotorAEn, GPIO.OUT)
 #   GPIO.setup(MotorA, GPIO.OUT)
 #   GPIO.setup(MotorA1, GPIO.OUT)

    GPIO.setup(MotorBEn, GPIO.OUT)
    GPIO.setup(MotorB, GPIO.OUT)
    GPIO.setup(MotorB1, GPIO.OUT)

 #   global Aen
 #   Aen = GPIO.PWM(MotorAEn, 2000)

    global Ben
    Ben = GPIO.PWM(MotorBEn, 2000)
    signal.signal(signal.SIGUSR1, received_signal)
    print "setup done.."

def init():
#    GPIO.output(MotorA, GPIO.LOW)
#    GPIO.output(MotorA1, GPIO.LOW)
#    global Aen
#    Aen.start(25)


    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)

    global Ben
    Ben.start(25)
    


def forward(tf):
    init()

#    global Aen
#    GPIO.output(MotorA, GPIO.HIGH)
#    GPIO.output(MotorA1, GPIO.LOW)
#    Aen.ChangeDutyCycle(80)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)


def reverse(tf):
    init()
#    global Aen
#    GPIO.output(MotorA, GPIO.LOW)
#    GPIO.output(MotorA1, GPIO.HIGH)
#    Aen.ChangeDutyCycle(80)

    global Ben
    GPIO.output(MotorB, GPIO.HIGH)
    GPIO.output(MotorB1, GPIO.LOW)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)

def left(tf):
    init()
    global Aen
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)
    Aen.ChangeDutyCycle(10)

    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(80)
    time.sleep(.9)

    Aen.ChangeDutyCycle(80)

    time.sleep(tf)

def right(tf):
    init()
    global Aen
    GPIO.output(MotorA, GPIO.HIGH)
    GPIO.output(MotorA1, GPIO.LOW)
    global Ben
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.HIGH)
    Ben.ChangeDutyCycle(10)
    Aen.ChangeDutyCycle(80)
    time.sleep(.9)
    Ben.ChangeDutyCycle(80)
    time.sleep(tf)

def motorStop():
    #GPIO.output(MotorAEn, GPIO.LOW)
    #GPIO.output(MotorA, GPIO.LOW)
    #GPIO.output(MotorA1, GPIO.LOW)

    GPIO.output(MotorBEn, GPIO.LOW)
    GPIO.output(MotorB, GPIO.LOW)
    GPIO.output(MotorB1, GPIO.LOW)

def destroy():
    motorStop()
    GPIO.cleanup()


def received_signal(signum, stack):
    print 'Received', signum
    #destroy()
    return
    #exit 0 




if __name__ == '__main__':
    setup()
    try:
        print "forward"
        forward(10800)
        #motorStop()

        #print "reverse"
        #reverse(5)
        #motorStop()

#        print "left.."
#        left(5)

#        print "right.."
#        right(5)

        destroy()
    except KeyboardInterrupt:
        destroy()
