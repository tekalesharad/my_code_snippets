
def smart_dev(func):
	def inner(a,b):
		if ( b == 0):
			print "Errorrr"
			return
		func(a,b)
	return inner

#@smart_dev
def div(a,b):
	return a/b



div = smart_dev(div)
div(2,0)

