import  RPi.GPIO as GPIO
import time

#VCC is set to 5v
PIN_IN=3
#PIN_OUT=40
def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(PIN_IN, GPIO.IN)
    #GPIO.setup(PIN_OUT, GPIO.OUT)

if __name__ == '__main__':
    setup()
    try:
        #GPIO.output(PIN_OUT, GPIO.HIGH)
        i=0 
        while i < 20:
            print GPIO.input(PIN_IN)
            time.sleep(.4)
            i = i+1
        GPIO.cleanup()
    except KeyboardInterrupt:
        GPIO.cleanup()

