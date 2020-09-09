def fib(n):
	a = 0
	b = 1
	c = 0
	if n < 0:
		print "enter a positive number", n
		return
	
	if n ==  1:
		print a, b,
	for i in range(2, n):
		last_num_before_max = b
		c = a+b
		if(c >= n):
			print "last_num_before_max, ", last_num_before_max
			return last_num_before_max
		a = b
		b = c
		print c, 
	print "last_num_before_max, ", last_num_before_max
		#if n == c:
			#print c, " is fib series"
			#return

	#print n, " - is not a fib"

n = input("Enter a number for  fib: ")	
fib(n)
