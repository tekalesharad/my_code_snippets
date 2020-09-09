#import GPIO from Rpi.GPIO
import time

import RPi.GPIO as GPIO
PIN_IN=3  # GPIO2


def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(PIN_IN, GPIO.IN)

if __name__ == '__main__':
    setup()
    try:
        i = 0 
        while i < 20: 
            print GPIO.input(PIN_IN)
            time.sleep(1)
            i=i+1

    except KeyboardInterrupt:
        GPIO.cleanup()


