
a=input("Enter a value")
b=input("Enter b value")
try:
	c = a/b
except Exception as e:
	print(e)

finally:
	print("Finally... ")
	
