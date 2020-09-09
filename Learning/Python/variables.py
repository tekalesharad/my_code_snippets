
a = 10
b =  3
c = 'sharad'
def fun():
	print(id(a))
	x = globals()['a']
	print(id(x))

fun()

