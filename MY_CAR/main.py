#! /bin/python

import sys
import time
import threading
#import Tkinter as tk

from motors.L289N_motor import forward, reverse, left, right, destroy, setup_motor, motorStop
from motors.servo import destroy_servo, setup_servo, motorStop, horizontal, vertical
#from dist_sensor.us_sensor import setup_sensor, distance, destroy_sensor, calc_distance
import sensors.us_sensor as us_sens
import sensors.temp_sensor as temp_sensor

def lforward():
    #print "LLforward"
    forward(5)

def lreverse():
    #print "LReverse"
    reverse(1)
    
def lleft():
    #print "Lleft"
    left(1)

def lright():
    #print "LRight"
    right(1)

def ltemp_sensor():
    #print "LTempSensor"
    temp_sensor.get_temperature(1)

def stop():
    #print "Lstop"
    motorStop()
    #destroy()

def pivot_left():
    left(.5)
    forward(1)

def pivot_right():
    right(.5)
    forward(1)


def oper(i):
        switcher={
                'fwd': lforward,
                'rev': lreverse,
                'back': lreverse,
                'left': lleft,
                'right': lright,
                'temp': ltemp_sensor,
                'pleft': pivot_left,
                'pright': pivot_right,
                "stop": stop,
            }
        func=switcher.get(i, lambda:"Invalid operation")
        return func()

'''def key_input(event):
    print 'Key:', event.char
    key_press = event.char
    sleep_time = 0.030

    if key_press.lower() =='w':
        forward(sleep_time)
    elif key_press.lower() =='s':
        reverse(sleep_time)
    elif key_press.lower() =='d':
        right(sleep_time)
    elif key_press.lower() =='a':
        left(sleep_time)
    elif key_press.lower() =='e':
        pivot_right(sleep_time)
    elif key_press.lower() =='q':
        pivot_left(sleep_time)
    else:
        pass

command = tk.Tk()
command.bind('<KeyPress>', key_input)
command.mainloop()
'''

if __name__ == '__main__':
#    us_sens.setup()
#    temp_sensor.setup()
    setup_motor()
    setup_servo()
    #setup_sensor()
    try:
#        us_sens.create_distance_thread()
        #destroy()
        while 1:
            direction = raw_input("Enter command: ")
            #print direction
            oper(direction)
            
            #print dist
            #if dist <= 2:
            #    print "Less than 10cm target.. stoppp"
            #    break
            time.sleep(.5)


        #sens.destroy_sensor()
        #destroy()
#        us_sens.destroy_sensor()
    except KeyboardInterrupt:
#        us_sens.destroy_sensor()
        motorStop()
        destroy() 
        destroy_servo() 
