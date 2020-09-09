class Top:
	def show_d(self):
		print ("DT TOP")

class Bottom:
	def show_d(self):
		print ("DT Bottom")

class Common:
	def info(self, obj):
		obj.show_d()


myobj = Common()

k = Top()

l = Bottom()

myobj.info(l)


