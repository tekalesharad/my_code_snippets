

def search(list, n):
	l = 0
	u = len(list)-1
	m = 0
	while l <= u:
		print "l, u", l, u, m
		m = (l+u) // 2
		print "l, u", l, u, m
		if(list[m] == n):
			return True
		if( n > list[m]):
			l=m+1
		else:
			u=m-1

	return False

list1 = [2, 3, 6, 7 , 10]
num = 10

if ( search(list1, num)	):
	print "Fount"
else: 
	print "Not Fount"





