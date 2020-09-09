
def fact(n):
	if(n == 0):
		return 1
	print  n, fact(n-1)

	return n * fact(n-1)
		

v=input("enter fact: ")
k = fact(v)
print k

