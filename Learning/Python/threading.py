#from threading import  Thread
from thread import start_new_thread
import time

#print (__module__)
#class A(Thread):
class A():
	def run(self):
		print("In class a")


#class B(Thread):
class B():
	def run(self):
		print("In class b")


a=A()
start_new_thread(a.run(), "")
