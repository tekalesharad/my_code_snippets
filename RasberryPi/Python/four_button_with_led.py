import RPi.GPIO as GPIO
import time

LedPin = 11
BtnPin = 12

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(LedPin, GPIO.OUT)
    GPIO.setup(BtnPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    GPIO.output(LedPin, GPIO.HIGH)

def loop():
    while 1:
        if GPIO.input(BtnPin) == GPIO.LOW:
            print "Led on.. button pressed"
            GPIO.output(LedPin, GPIO.LOW)
        else:
            print "Led off"
            GPIO.output(LedPin, GPIO.HIGH)
            time.sleep(2)

def destroy():
    GPIO.output(LedPin, GPIO.HIGH)
    GPIO.cleanup()


if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        destroy()
