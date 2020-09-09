class Person:
	extraname = ""
	def __init__(self):
		self.name = ""
	def print_name(self):
		print self.name,self.extraname

	@classmethod
	def pclassmtd(cls):
		return cls.extraname

	@staticmethod
	def info():
		print("Static Method... ")

Person.extraname = " Chandra"

a = Person()
a.name = 'Sharad'
a.print_name()

b = Person()
b.name = 'Praful '
b.print_name()

print(Person.pclassmtd())


Person.info()
