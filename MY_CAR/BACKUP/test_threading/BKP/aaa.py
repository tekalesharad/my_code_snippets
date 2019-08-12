import threading as a

def hello():
    print "hello, world"
    t = a.Timer(.5, hello)
    t.start() # after 30 seconds, "hello, world" will be printed

t = a.Timer(.5, hello)
t.start() # after 30 seconds, "hello, world" will be printed


print "main thread"
