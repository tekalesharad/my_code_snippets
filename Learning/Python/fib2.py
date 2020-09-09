
def fib1(n):
	a = 0
	b = 1
	if n < 0:
		print "not a fib", n
	for i in range(2, n):
		c = a+b
		prev_num = b 
		if c > n:
			print "last num is ", prev_num
			return
		a = b
		b = c
		print c,  
		if c > n:
			print "last num is ",c

n = input("Enter number to Find last fib number: ") 
fib1(n)
