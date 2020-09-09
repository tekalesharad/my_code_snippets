def fun1(name, **data):

	print(name)
	print(data.values())
	print(data.keys())
	for i, j in data.items():
		print i, j

fun1('sharad', place='Mumbai', mob=988161611)


'''
def fun1(*st):

	for i in st:
		print i

#fun1('sharad', 'chandra', 'tekale')
fun1('sharad', 5, 6 )



def fun1(st, num=18):
	print st
	print num + 2

#fun1(num=2, st='sharad')
'''
