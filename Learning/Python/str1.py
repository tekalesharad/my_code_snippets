

def mycount(i):
	count = 0
	for c in i:
		count += 1
	return count
	
def strings(*names):
	gt = 0
	lt = 0
	for i in names:
		if mycount(i) > 4:
			gt += 1
		else:
	
			lt += 1 
	return gt, lt


gt, lt = strings("a", "b", "shar", "12345", "chandrea")
print(gt, lt)
