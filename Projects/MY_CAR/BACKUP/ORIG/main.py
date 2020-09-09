#! /bin/python

import sys

from L289N_motor import forward, reverse, left, right, destroy, setup

def lforward():
    print "LLforward"
    forward(2)

def lreverse():
    print "LReverse"
    reverse(2)
    

def lleft():
    print "Lleft"
    left(2)

def lright():
    print "LRight"
    right(2)

def stop():
    print "Lstop"
    destroy()


def oper(i):
        switcher={
                'fwd': lforward,
                'rev': lreverse,
                'left': lleft,
                'right': lright,
                "stop": stop,
            }
        func=switcher.get(i, lambda:"Invalid operation")
        return func()

if __name__ == '__main__':
    setup()
    try:

        #destroy()
        while 1:
            direction = raw_input("Enter direction: ")
            print direction
            oper(direction)

        destroy()
    except KeyboardInterrupt:
        destroy() 
