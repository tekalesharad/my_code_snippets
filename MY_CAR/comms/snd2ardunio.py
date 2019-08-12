import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600)
#print ("Read input " + input.decode("utf-8") + " from Arduino")
while 1: 
    if(ser.in_waiting >0):
        line = ser.read()
        #inum = ord(line)
        print("Read input" + str(line))
    else:
        time.sleep(1)
        ser.write(b'A')

    time.sleep(1)
