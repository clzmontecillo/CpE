total, i, v = 0.00, 0, 0
n = int(input(str("Enter No of Values: ")))
values = [None] * int(n)
while(n > i):
	values[v] = input(str("Enter Prices: "))
	i += 1
	v += 1
print("Item\t\t Prices")
i,v = 0,0
while(n > i):
	print("%d" % i, "\t\t", values[v])
	i += 1
	v += 1
print("_______________________")
i,v = 0,0
total = sum(float(x) for x in values)
print("Total: %14.2f" % total)
