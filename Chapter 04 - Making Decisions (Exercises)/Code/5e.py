#!/usr/bin/python3

import re

idNumber = 0
itemDescription = " "
auctionDays = 0
minimumBid = 0
sentinelPresence = False
sentinel = "A21"

try:
	print("MAXIMUM REQUIRED BID: $200.00")
	while bool(sentinelPresence) == False:
		idNumber = str(input("ID Number: "))
		if idNumber == sentinel:
			sentinelPresence = True
		itemDescription = str(input("Description: "))
		auctionDays = int(input("Length of Auction (Days): "))
		minimumBid = float(input("Minimum Bid ($): "))
		if minimumBid > 200:
			sentinelPresence = True
	if sentinelPresence == True:
		if minimumBid < 200:
                	print("ID Number: " + idNumber)
	                print("Item Description: " + itemDescription)
        	        print("Length of Auction in Days: " + str(auctionDays))
                	print("Minimum Bid ($): " + str(minimumBid))

except KeyboardInterrupt:
	if minimumBid < 200:
		print("ID Number: " + idNumber)
		print("Item Description: " + itemDescription)
		print("Length of Auction in Days: " + str(auctionDays))
		print("Minimum Bid ($): " + str(minimumBid))
