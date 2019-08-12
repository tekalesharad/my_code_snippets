import threading
import time



def fun1():
    print "iin fun1"
    time.sleep(1)
    print "iin fun1.1"


def fun2():
    print "iin fun2"
    time.sleep(1)
    print "iin fun2.1"

a=threading.Thread(target=fun1, name='fun11')
b=threading.Thread(target=fun2, name='fun21')

a.start()
b.start()
while True:
    time.sleep(2)
