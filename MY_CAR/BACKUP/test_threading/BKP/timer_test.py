import Timer

def f():
    print "f started"
    while True:
        time.sleep(.5)
        print "f finished"


#def timeout():
#        print("Game over")

t = Timer(.5, f)
t.start()

#threading.Thread(target=f).start()

print "do other stuff"
i = 10
while  i < 10:
    print i
    time.sleep(1)
    i = i + 1

