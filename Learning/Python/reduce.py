from functools import reduce

nums = [1,2,3,4,5, 6, 6]
#y = [4,3,2,4,5]
op = reduce(lambda a,b : a+b, nums, 5 )
print op
