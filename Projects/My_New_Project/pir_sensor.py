import RPi.GPIO as GPIO
import time

PIN_IN=3
def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(PIN_IN, GPIO.IN)

if __name__ == '__main__':
    try:
        setup()
        i=0
        while i < 20:
            print GPIO.input(PIN_IN)
            time.sleep(.5)
            i = i + 1

    #except KeyboardInterrupt:
    except :
        GPIO.cleanup()


