
def even_odd(list):
	even = 0
	odd = 0
	for i in list:
		if i%2 == 0:
			even += 1
		else:
			odd  += 1
	return even, odd

#list = [2, 3, 4, 5]
list = []
for i in range(4):
	ls = input('Enter a number:')
	list.append(ls)
even, odd = even_odd(list)
print("list:{} even:{}, odd:{}".format(list, even, odd))
		
	
