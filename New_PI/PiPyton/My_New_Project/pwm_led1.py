#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

LedPin=12

GPIO.setmode(GPIO.BOARD);


GPIO.setup(LedPin, GPIO.OUT )
GPIO.output(LedPin, GPIO.LOW )

p = GPIO.PWM(LedPin, 1000)
p.start(0)

try:
    while True:
        time.sleep(1)
        for dc in range(0, 100, 4):
            time.sleep(0.05)
            p.ChangeDutyCycle(dc)
            time.sleep(0.05)
        time.sleep(1)
        for dc in range(100, -1 , -4):
            time.sleep(0.05)
            p.ChangeDutyCycle(dc)
            time.sleep(0.05)
        time.sleep(1)
except KeyboardInterrupt:
    p.stop()
    GPIO.output(LedPin, GPIO.HIGH)
    GPIO.cleanup()

