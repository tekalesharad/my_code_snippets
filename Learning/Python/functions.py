
def test(x, y):
	print("Hello")
	c = x + y
	#print c
	return c, x, y

c, x, y = test("Sharad ", "Chandra")
print("c= %s x=%s y=%s", c, x, y)
