
def fact(n):
	print n 
	val = 1
	for i in range(1, n+1):
		val *= i
	return val


a = input("Enter a fct num: ")
print("fact: ", fact(a))


