import threading
import time

count = 0
def printit():
  #print "Hello, World!"
  threading.Timer(0.5, printit).start()
  global count
  count = count + 10


#printit()

#import Timer


