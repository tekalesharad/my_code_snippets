
import RPi.GPIO as GPIO
import time

ledPin = 12
print "In program"

def setup():
    print "In setup"
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.HIGH)

def loop():
    print "In loop"
    while 1:
        print "led on..."
        GPIO.output(ledPin, GPIO.HIGH)
        time.sleep(2)    
        print "led off.."	
        GPIO.output(ledPin, GPIO.LOW)
        time.sleep(2)  

def destroy():
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()

if __name__ == '__main__':
    setup() 
    try: 
        loop()
    except KeyboardInterrupt:
        destroy() 
