#!/usr/bin/python3

import random

#Player class
class Player:
	def __init__(self, name, win, marker):
		self.name = name
		self.win = win
		self.marker = marker
		
# 3x3 board at its fresh state
class Board:
	top = ['0','0','0']
	middle = ['0','0','0']
	bottom = ['0','0','0']
	
# main program function
def main():
	print("INSTRUCTIONS:\n[ 0 1 2 ]\n[ 3 4 5 ]\n[ 6 7 8 ]\n")
	player1Name = input("Player Name: ")
	player1 = Player(player1Name, False, 'x')
	player2 = Player('CPU', False, 'o')
	turns = 0
	endGame = False
	occupied = []
	
	# prints the updated board state
	def statusUpdate():
		print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		print("Occupied Points: " + str(occupied))	
		#print("P1 State: " + str(player1.win))
		#print("CPU State: " + str(player2.win))

	# checks for winning sequences
	def winCheck():
		# horizontal patterns
		if(Board.top == ['x','x','x'] or Board.middle == ['x','x','x'] or Board.bottom == ['x','x','x']):
			player1.win = True
			return True
		elif(Board.top == ['o','o','o'] or Board.middle == ['o','o','o'] or Board.bottom == ['o','o','o']):
			player2.win = True
			return True
		# vertical patterns
		elif(Board.top[0] == 'x' and Board.middle[0] == 'x' and Board.bottom[0] == 'x'):
			player1.win = True
			return True
		# diagonal patterns
		# add em here
	
	# reports game results
	def winReport():
		#print("ERROR: winReport() function is called")
		if(player1.win == True):
			print("\n\nWINNER: Player #1")
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		elif(player2.win == True):
			print("\n\nWINNER: CPU")
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		else:
			print("\n\nDRAW")
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))

	# opponent gameplay loop
	def oppTurn():
		while True:
			cpuInput = random.randint(0,8)
			if(int(cpuInput) <= 2 and int(cpuInput) >= 0):
				if(Board.top[int(cpuInput)] == '0'):
					Board.top[int(cpuInput)] = player2.marker
					occupied.append(cpuInput)
					break
			elif(int(cpuInput) <= 5 and int(cpuInput) >= 3):
				cpuInput = int(cpuInput) - 3
				if(Board.middle[int(cpuInput)] == '0'):
					Board.middle[int(cpuInput)] = player2.marker
					occupied.append(cpuInput + 3)
					break
			elif(int(cpuInput) <= 8 and int(cpuInput) >= 6):
				cpuInput = int(cpuInput) - 6
				if(Board.bottom[int(cpuInput)] == '0'):
					Board.bottom[int(cpuInput)] = player2.marker
					occupied.append(cpuInput + 6)
					break
		
	# human player gameplay loop
	def playerTurn():
		while True:
			turnInput = int(input("Player #1 Turn: "))
			if(turnInput > 8 or turnInput < 0):
				print("INVALID: Out of Bounds")
			elif(int(turnInput) <= 2 and int(turnInput) >= 0):
				if(Board.top[int(turnInput)] == '0'):
					Board.top[int(turnInput)] = player1.marker
					occupied.append(turnInput)
					break
				else:
					print("INVALID: Occupied Point")
			elif(int(turnInput) <= 5 and int(turnInput) >= 3):
				turnInput = int(turnInput) - 3
				if(Board.middle[int(turnInput)] == '0'):
					Board.middle[int(turnInput)] = player1.marker
					occupied.append(turnInput + 3)
					break
				else:
					print("INVALID: Occupied Point")
			elif(int(turnInput) <= 8) and int(turnInput >= 6):
				turnInput = int(turnInput) - 6
				if(Board.bottom[int(turnInput)] == '0'):
					Board.bottom[int(turnInput)] = player1.marker
					occupied.append(turnInput + 6)
					break
				else:
					print("INVALID: Occupied Point")	
	
	# main gameplay loop
	try:
		while True:
			playerTurn()
			#winCheck()
			if winCheck():
				break
			oppTurn()
			#winCheck()
			if winCheck():
				break
			statusUpdate()
		winReport()
	except KeyboardInterrupt:
		print("\n\nSession Terminated")

main()
