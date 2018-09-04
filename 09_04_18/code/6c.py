#!/usr/bin/python3

import re

addBill = 0		#additional bills
areaCode = 0
phoneNumber = 0
messageQty = 0
monthBill = 5		#default bill/basic bill
totalBill = 0
sentinel1 = "123"
sentinel2 = "1234567"

sentinelPresence = False

while bool(sentinelPresence) == False:
	areaCode = str(input("Area Code: "))
	while not len(areaCode) == 3 or not re.match("^[0-9]*$", areaCode):
		print("Please input only 3 digits.")
		areaCode = str(input("Area Code: "))
	if areaCode == sentinel1:
		sentinelPresence = True
	phoneNumber = str(input("Phone Number: "))
	while not len(phoneNumber) == 7 or not re.match("^[0-9]*$", phoneNumber):
		print("Please input only 7 digits.")
		phoneNumber = str(input("Phone Number: "))
	if phoneNumber == sentinel2:
		sentinelPresence = True
	messageQty += 1

if bool(sentinelPresence) == True:
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
	if messageQty > 100:
		print(" ")
		print("===================================")
		print("Area Code: " + areaCode)
		print("Phone Number: " + phoneNumber)
		print("No. of Messages: " + str(messageQty))
		print("Bill ($): " + str(monthBill))
