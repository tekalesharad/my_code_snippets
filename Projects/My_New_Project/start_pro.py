#!/usr/sbin/env python

import RPi.GPIO as GPIO
import gpio_pins as gcnf
import time

DEBUG=1

def setup():
    GPIO.setmode(GPIO.BOARD)

#setup motor pins
    for pin in gcnf.motor_pins:
        if(DEBUG):
            print "pin nimber initialization:",  pin
        GPIO.setup(pin, GPIO.OUT)
    
    for pin in gcnf.motor_pins:
        if(DEBUG):
            print "pin default value:", pin, GPIO.LOW
        GPIO.output(pin, GPIO.LOW)

    global pwm_in12, pwm_in22
    pwm_in12 = GPIO.PWM(gcnf.IN1_PIN2, 2000)
    #pwm_in22 = GPIO.PWM(gcnf.IN2_PIN2, 2000)

def cleanup():
    for pin in gcnf.motor_pins:
        GPIO.output(pin, GPIO.LOW)
    GPIO.cleanup()

def runFWD(speed):
    global pwm_in12, pwd_in22

    GPIO.output(gcnf.IN1_PIN1, GPIO.HIGH)
    #GPIO.output(gcnf.IN2_PIN1, GPIO.HIGH)

    #GPIO.output(gcnf.IN1_PIN2, GPIO.LOW)
    #GPIO.output(gcnf.IN2_PIN2, GPIO.LOW)

    #pwm_in12.start(100 - (speeed*20))
    pwm_in12.start(100)
    #pwm_in22.start(100)
    pwm_in12.ChangeDutyCycle(100 -  (speed*5))
    #pwm_in22.ChangeDutyCycle(60)


#    for pin in gcnf.IN1_PINS:
#        GPIO.output(pin, GPIO.LOW)
#def runBWD():
    

if  __name__ == "__main__":
    setup()
    try:
        print "Rotate in Fowarded direction "
        for i in range(1, 20):
            runFWD(i)
            time.sleep(.1)
            print "sleep for .1 seconds"
#        print "sleep for 2 seconds"
#        time.sleep(2)
#        print "Rotate in Reverse direction "
#        for i in range(1, 100):
#            runBWD()
#            time.sleep(.1)

        cleanup()
    except KeyboardInterrupt:
        print "Keyboard Interrupt..."
        cleanup()
        print " cleanp...."


