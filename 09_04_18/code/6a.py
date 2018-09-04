#!/usr/bin/python3

import re

addBill = 0		#additional bills
areaCode = 0
phoneNumber = 0
messageQty = 0
loopFunction = True
monthBill = 5		#default bill/basic bill
totalBill = 0

try:
	while loopFunction == True:
		areaCode = str(input("Area Code: "))
		while not len(areaCode) == 3 or not re.match("^[0-9]*$", areaCode):
			print("Please input only 3 digits.")
			areaCode = str(input("Area Code: "))
		phoneNumber = str(input("Phone Number: "))
		while not len(phoneNumber) == 7 or not re.match("^[0-9]*$", phoneNumber):
			print("Please input only 7 digits.")
			phoneNumber = str(input("Phone Number: "))
		messageQty += 1

except KeyboardInterrupt:
	if messageQty > 60 and messageQty < 180:
		excess1 = messageQty - 60
		addBill += 0.05 * excess1
		monthBill += addBill
	if messageQty > 180:
		excess2 = messageQty - 180
		addBill += 0.1 * excess2
		monthBill += addBill
	tax = monthBill * 0.12
	totalBill = monthBill + tax
	print(" ")
	print("===================================")
	print("Area Code: " + areaCode)
	print("Phone Number: " + phoneNumber)
	print("No. of Messages: " + str(messageQty))
	print("Bill ($): " + str(monthBill))
