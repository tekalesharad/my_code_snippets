import RPi.GPIO as GPIO
import time

RelayPin = 12

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(RelayPin, GPIO.OUT)
    GPIO.output(RelayPin, GPIO.HIGH)

def loop():
    while 1:
        print '..close..'
        GPIO.output(RelayPin, GPIO.LOW)
        time.sleep(0.5)
        print '..open..'
        GPIO.output(RelayPin, GPIO.HIGH)
        time.sleep(0.5)

def destroy():
        GPIO.output(RelayPin, GPIO.HIGH)
        GPIO.cleanup()

if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        destroy()

