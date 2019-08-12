import threading
import time
import  new_file 

new_file.printit()
print "MAIN thread do other stuff"
i = 0
while  i < 100:
    print i
    time.sleep(1)
    i = i + 1
#    global new_file.count
    if i%5 == 0 :
        print "count=", new_file.count
        print "i=", i

#def printit():
#  threading.Timer(1.0, printit).start()
#  print "Hello, World!"

#printit()

#import Timer

#def f():
#    print "f started"
#    while True:
#        time.sleep(.5)
#        print "f finished"


#def timeout():
#        print("Game over")

#t = Timer(.5, f)
#t.start()

#threading.Thread(target=f).start()

