#!/usr/bin/python3

import re

idNumber = 0
itemDescription = " "
auctionDays = 0
minimumBid = 0
sentinelPresence = False
sentinel = "A21"

try:
	while bool(sentinelPresence) == False:
		idNumber = str(input("ID Number: "))
		if idNumber == sentinel:
			sentinelPresence = True
		itemDescription = str(input("Description: "))
		auctionDays = int(input("Length of Auction (Days): "))
		minimumBid = float(input("Minimum Bid ($): "))

	if sentinelPresence == True:
		if minimumBid > 100.00:
                	print("ID Number: " + idNumber)
	                print("Item Description: " + itemDescription)
        	        print("Length of Auction in Days: " + str(auctionDays))
                	print("Minimum Bid ($): " + str(minimumBid))

except KeyboardInterrupt:
	if minimumBid > 100.00:
		print("ID Number: " + idNumber)
		print("Item Description: " + itemDescription)
		print("Length of Auction in Days: " + str(auctionDays))
		print("Minimum Bid ($): " + str(minimumBid))
