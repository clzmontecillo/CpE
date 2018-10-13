#!/usr/bin/python3

import random

global firstGame

#Player class
class Player:
	def __init__(self, name, win, marker, score):
		self.name = name
		self.win = win
		self.marker = marker
		self.score = 0
		
# 3x3 board at its fresh state
class Board:
	top = ['0','0','0']
	middle = ['0','0','0']
	bottom = ['0','0','0']

# main program function
def main(firstGame):
	if(firstGame == False):
		print("\nINSTRUCTIONS:\n[ 0 1 2 ]\n[ 3 4 5 ]\n[ 6 7 8 ]\n")
		player1Name = input("Player Name: ")
		player1 = Player(player1Name, False, 'x', 0)
		player2 = Player('CPU', False, 'o', 0)
	occupied = []
	firstGame = True
	
	# prints the updated board state
	def statusUpdate():
		print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		print("Occupied Points: " + str(occupied))	

	# checks for winning sequences
	def winCheck():
		# horizontal patterns
		# three possible configurations
		if(Board.top == ['x','x','x'] or Board.middle == ['x','x','x'] or Board.bottom == ['x','x','x']):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top == ['o','o','o'] or Board.middle == ['o','o','o'] or Board.bottom == ['o','o','o']):
			player2.win = True
			player2.score += 1
			return True
		# vertical patterns
		# three possible configurations
		elif(Board.top[0] == 'x' and Board.middle[0] == 'x' and Board.bottom[0] == 'x'):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top[1] == 'x' and Board.middle[1] == 'x' and Board.bottom[1] == 'x'):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top[2] == 'x' and Board.middle[2] == 'x' and Board.bottom[2] == 'x'):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top[0] == 'o' and Board.middle[0] == 'o' and Board.bottom[0] == 'o'):
			player2.win = True
			player2.score += 1
			return True
		elif(Board.top[1] == 'o' and Board.middle[1] == 'o' and Board.bottom[1] == 'o'):
			player2.win = True
			player2.score += 1
			return True
		elif(Board.top[2] == 'o' and Board.middle[2] == 'o' and Board.bottom[2] == 'o'):
			player2.win = True
			player2.score += 1
			return True
		# diagonal patterns
		# two possible configurations
		elif(Board.top[0] == 'x' and Board.middle[1] == 'x' and Board.bottom[2] == 'x'):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top[2] == 'x' and Board.middle[1] == 'x' and Board.bottom[0] == 'x'):
			player1.win = True
			player1.score += 1
			return True
		elif(Board.top[0] == 'o' and Board.middle[1] == 'o' and Board.bottom[2] == 'o'):
			player2.win = True
			player2.score += 1
			return True
		elif(Board.top[2] == 'o' and Board.middle[1] == 'o' and Board.bottom[0] == 'o'):
			player2.win = True
			player2.score += 1
			return True
		
	
	# reports game results
	# executes if winCheck() returns True
	def winReport():
		if(player1.win == True):
			print("\n\nWINNER: Player #1 (" + player1.name + ")")
			print("\nSCORE: " + str(player1.score) + "-" + str(player2.score))
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		elif(player2.win == True):
			print("\n\nWINNER: Player #2 (CPU)")
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))
		elif(len(occupied) == 8):
			print("\n\nDRAW")
			print(str(Board.top) + "\n" + str(Board.middle) + "\n" + str(Board.bottom))

	# opponent gameplay loop
	def oppTurn():
		# loop will only break if a unique number (or unoccupied point) has been generated 
		# once a unique number is generated, the loop will mark the point for Player #2 (CPU)
		while True:
			# generate a random number between 0-8
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
	
	# reverts the board's state
	def boardReset():
		Board.top = ['0','0','0']
		Board.middle = ['0','0','0']
		Board.bottom = ['0','0','0']
		occupied = []
		player1.win = False
		player2.win = False
		main(firstGame)
	
	# main gameplay loop
	try:
		while True:
			while True:
				playerTurn()
				if winCheck():
					break
				oppTurn()
				if winCheck():
					break
				statusUpdate()
			winReport()
			boardReset()
	except KeyboardInterrupt:
		print("\n\nSession Terminated.")

firstGame = False
main(firstGame)
