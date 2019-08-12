#! /usr/sbin/env python

import RPi.GPIO as GPIO
import time

TRIG_PIN=16
ECHO_PIN=18

# speed = dist / time
# speed = 340m/sec
# 340 = 2d/time
# d = 170 * timem
# d - 170 * 100 * time cms

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ECHO_PIN, GPIO.IN)
    GPIO.setup(TRIG_PIN, GPIO.OUT, initial=GPIO.LOW)
    time.sleep(0.1)

def check_dist():
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(10/1000000)
    GPIO.output(TRIG_PIN, GPIO.LOW)
    while GPIO.input(ECHO_PIN) == 0:
        pass
    t1 = time.time()
    while GPIO.input(ECHO_PIN) == 1:
        pass
    t2 = time.time()

    #return ((t2-t1)*340)/2
    return ((t2-t1)*1700)



if __name__ == "__main__":
    setup()
    try:
        while True:
            print "Calculate distance: ", check_dist()
            time.sleep(1)

    except KeyboardInterrupt:
        GPIO.cleanup()
    


    








