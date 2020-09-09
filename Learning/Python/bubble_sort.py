
def sort(list):
	top_len = len(list)
	bottom = len(list)
	print(list, len(list))
	j=0
	while( j <= top_len):
		i = 0
		bottom = bottom - 1
		
		while i < bottom :
			if(list[i] > list[i+1]):
				temp = list[i]
				list[i] = list[i+1]
				list[i+1] = temp
			i = i+1
		print(i, list)	
		j = j+1



list = [98,7,6,4,2,1]
sort(list)
