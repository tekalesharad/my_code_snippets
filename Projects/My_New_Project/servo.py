#! /usr/sbin/env python
import RPi.GPIO as GPIO
import time

import signal
import atexit

atexit.register(GPIO.cleanup)  



TRIG=11

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(TRIG, GPIO.OUT, initial=False)
    #GPIO.output(TRIG, GPIO.LOW)
    print "setup done.."
    global p
    p = GPIO.PWM(TRIG, 50)
    p.start(0)
    time.sleep(2)

def rotate_1():
    while(True):
        for i in range(0,181,10):
            val = 2.5 + 10 * i/180 
            print "rotate angle:", val
            p.ChangeDutyCycle(val)
            time.sleep(0.02)
            p.ChangeDutyCycle(0)
            time.sleep(0.2)

        for i in range(181,0,-10):
            val = 2.5 + 10 * i/180 
            print "rotate angle:", val
 	    p.ChangeDutyCycle(val)
            time.sleep(0.02)
	    p.ChangeDutyCycle(0)
    	    time.sleep(0.2)




def rotate():
    GPIO.output(TRIG, GPIO.HIGH)
    print "first roate done.."
    pwm_b.ChangeDutyCycle(50)
    time.sleep(10/1000)
    print "Rotate 45 degree.."
    time.sleep(15/1000)
    print "Rotate 90 degree.."
    time.sleep(20/1000)
    print "Rotate 135 degree.."
    time.sleep(25/1000)
    print "Rotate 180 degree.."

def destroy():
    GPIO.output(TRIG, GPIO.LOW)
    GPIO.cleanup()


if __name__ == "__main__":
    setup()
    try:
        rotate_1()

    except KeyboardInterrupt:
        destroy()

    #for i in range(20):
        #rotate()
        #time.sleep(1)
        #destroy()
    	#except KeyboardInterrupt:
        #destroy()





