import RPi.GPIO as GPIO
import time
import sys
from car_gpios import *

SERVO_PIN_1 = 33
def setup_servo():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(SERVO_PIN_1, GPIO.OUT)
    GPIO.setup(SERVO_PIN_2, GPIO.OUT)
    print "set-up()"
    global mtr_horiz
    global mtrVertical
    mtr_horiz=GPIO.PWM(SERVO_PIN_1, 50)
    mtrVertical=GPIO.PWM(SERVO_PIN_2, 50)
    mtr_horiz.start(7.5)
    mtrVertical.start(7.5)
    time.sleep(1)

def destroy_servo():
    global mtr_horiz
    global mtrVertical
    GPIO.output(SERVO_PIN_1, GPIO.LOW)
    GPIO.output(SERVO_PIN_2, GPIO.LOW)
    mtr_horiz.stop()
    mtrVertical.stop()
    print "destroy-()"
    GPIO.cleanup()

def s_horizontal(degree) 
    global mtr_horiz
    mtr_horiz.ChangeDutyCycle(degree)  # turn towards 90 degree
    print "val-",degree
    time.sleep(1) # sleep 1 second

def horizantal():
    print "Horizontal... "
    global mtr_horiz
    time.sleep(1) # sleep 1 second
    mtr_horiz.ChangeDutyCycle(7.5)  # turn towards 90 degree
    print "val-90 degree"
    time.sleep(1) # sleep 1 second
    mtr_horiz.ChangeDutyCycle(2.5)  # turn towards 0 degree
    print "val-0 degree"
    time.sleep(1) # sleep 1 second
    mtr_horiz.ChangeDutyCycle(12.5)  # turn towards 180 degree
    print "val-180 degree"
    time.sleep(1) # sleep 1 second
    mtr_horiz.ChangeDutyCycle(2.5)  # turn towards 0 degree
    print "val-0 degree"
    time.sleep(1) # sleep 1 second


def vertical():
    print "Vertical... "
    global mtrVertical
    time.sleep(1) # sleep 1 second
    mtrVertical.ChangeDutyCycle(7.5)  # turn towards 90 degree
    print "val-90 degree"
    time.sleep(1) # sleep 1 second
    mtrVertical.ChangeDutyCycle(2.5)  # turn towards 0 degree
    print "val-0 degree"
    time.sleep(1) # sleep 1 second
    mtrVertical.ChangeDutyCycle(12.5)  # turn towards 180 degree
    print "val-180 degree"
    time.sleep(1) # sleep 1 second
    mtrVertical.ChangeDutyCycle(2.5)  # turn towards 0 degree
    print "val-0 degree"
    time.sleep(1) # sleep 1 second
    mtrVertical.ChangeDutyCycle(7.5)  # turn towards 90 degree
    print "val-90 degree"
    time.sleep(1) # sleep 1 second


def servo_motor():
    horizantal()
    vertical()
    
'''def servo_motor():
    #while True:
        #global mtr_horiz
        time.sleep(1) # sleep 1 second
        #mtr_horiz.ChangeDutyCycle(7.5)  # turn towards 90 degree
        print "val-90"
        #time.sleep(2) # sleep 1 second
        #global mtrVertical
        #mtr_horiz.ChangeDutyCycle(6)  # turn towards 90 degree
        #print "val-6"
        time.sleep(1) # sleep 1 second
        #mtr_horiz.ChangeDutyCycle(1)  # turn towards 90 degree
        #mtrVertical.ChangeDutyCycle(6)  # turn towards 90 degree
        #time.sleep(1) # sleep 1 second
        mtr_horiz.ChangeDutyCycle(2.5)  # turn towards 0 degree
        print "val-0"
        time.sleep(1) # sleep 1 second
        #mtrVertical.ChangeDutyCycle(1)  # turn towards 0 degree
        #time.sleep(4) # sleep 1 second
        #mtr_horiz.ChangeDutyCycle(11) # turn towards 180 degree
        #print "val-11"
        #time.sleep(10) # sleep 1 second 
        #mtrVertical.ChangeDutyCycle(11) # turn towards 180 degree
        #time.sleep(1) # sleep 1 second 
        #print "server_motor-()"
        #mtr_horiz.ChangeDutyCycle(1)  # turn towards 90 degree
        #print "val-0"
        #time.sleep(2) # sleep 1 second
        #mtrVertical.ChangeDutyCycle(6)  # turn towards 90 degree
        #time.sleep(1) # sleep 1 second
        mtr_horiz.ChangeDutyCycle(7.5)  # turn towards 90 degree
        print "val-90"
        time.sleep(1) # sleep 1 second
        print "val-end"
'''


if __name__ == '__main__':
    setup()
    servo_motor()
    destroy()
    #try:
    #    servo_motor()
    #    destroy()
    #except KeyboardInterrupt:
    #    destroy()

