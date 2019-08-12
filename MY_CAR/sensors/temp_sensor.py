import RPi.GPIO as GPIO
import sys
import time
from car_gpios import *
import dht11
import datetime

def setup():
    GPIO.setmode(GPIO.BOARD)
    #GPIO.setup(TEMP_PIN, GPIO.IN)
    global instance
    instance = dht11.DHT11(pin=TEMP_PIN)
    print "setup done"
    time.sleep(.1)

def cal_temperature():
    global instance
    result = instance.read()
    if result.is_valid():
        print "now:  ", str(datetime.datetime.now())
        print "temperature ", result.temperature, "C"
        print "humidity ", result.humidity, "%%"


def get_temperature( times ):
    if times == 1:
        cal_temperature()
    else:
        while True:
            cal_temperature()
            time.sleep(1)

def destroy():
    GPIO.cleanup()

#if __name__ == '__main__':
#    temp_sensor_setup()
#    try:
#        get_temperature()
#    except KeyboardInterrupt:
#        destroy()
#temp_sensor_setup()
#get_temerture()
