import RPi.GPIO as GPIO
from  car_gpios import *
import time
import threading

from motors.L289N_motor import  destroy,   motorStop, reverse

destroy_thread=0
tid=0
dist_value=0
# distance ranging: 2cm to 500 cm
# resolution  .3cm
# frequency 40khz
# cycle period 50ms 

# speed = dist/time
def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(TRIG, GPIO.OUT)
    GPIO.setup(ECHO, GPIO.IN)
    GPIO.output(TRIG, GPIO.LOW)
    print "Waiting For Sensor To Settle eco", ECHO, "print", TRIG
    time.sleep(.5)

def distance():
    print "Distance Measurement In Progress"
    GPIO.output(TRIG, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(TRIG, GPIO.LOW)
    pulse_end = 0
    pulse_start = 0
    while GPIO.input(ECHO) == 0:
        pulse_start = time.time()

    while GPIO.input(ECHO) == 1:
        pulse_end = time.time()

# speed of sound at sea level is 343m/s
# We also need to divide our time by two because what we have calculated above is actually the 
# time it takes for the ultrasonic pulse to travel the distance to the object and back again 
# speed = dist/time
#speed = dist/time/2
# (speed of sound) 34300 = dist/time/2
#  17150 = dist/time
# 17150 * time = dist
    pulse_duration = pulse_end - pulse_start
    print "pd:",pulse_duration
    distance = pulse_duration * 17150
    
#Now we need to round our distance to 2 decimal places (for neatness!)
    dist_value = round(distance, 2)

    print "Distance:",dist_value,"cm"
    #return dist_value


def test_distance():
    while True:
        distance()
        time.sleep(1)


def destroy_sensor():
    #GPIO.output(ECHO, GPIO.LOW)
    motorStop()
    global destroy_thread
    global tid
    destroy_thread=1
    GPIO.output(TRIG, GPIO.LOW)
    if tid.is_alive() :
        time.sleep(1)
        tid.join()

    if not tid.is_alive() :
        print "thread stopped"
        GPIO.cleanup()


def operate_thread():
    while True:
        global destroy_thread
        if destroy_thread :
            break
        measured_dist=distance()
        if measured_dist < 20 :
            #if command != 'rev':
            #reverse(2)
            motorStop()
            print "1 Distance:", measured_dist,"cm"
        time.sleep(.4)


'''def create_distance_thread():
    global tid
    tid=threading.Thread(target=operate_thread, name="cal_dist")
    tid.start()
'''


if __name__ == '__main__':
    #GPIO.cleanup()
    setup()
    test_distance()



