#include <iostream>
#include <string>
#include <vector>			// to create arrays where you can append new elements
#include <cstdlib>			// to generate random numbers

using namespace std;

bool firstGame = false;

class Board{
	public:
		// Fresh State of a 3x3 Board
		char top[4] = {'0', '0', '0', '\0'};
		char middle[4] = {'0', '0', '0', '\0'};
		char bottom[4] = {'0', '0', '0', '\0'};
		// Just an array that will store all occupied points
		vector<int> occupied;

		// Member Functions
		bool winCheck(void);
		void showStatus(void);
};

class Player{
	public:
		string name;
		bool win;
		char marker;
};

int main(){
	try{
		// Class Constructor
		// Declare objects
		Board ticTac;
		Player player1;
		Player player2;

		string p1name;
		cout << "\n" << "INSTRUCTIONS:" << "\n" << "[ 0 1 2 ]" << "\n" << "[ 3 4 5 ]" << "\n" << "[ 6 7 8 ]" << "\n\n";
		cout << "[?] Player Name: ";
		cin >> p1name;

		// By default, all players will start with a win value of false
		// Player and CPU will differ in terms of their marker (x and o) and name
		cout << "\n" << "[*] Initializing Player #1" << "\n";
		player1.name = p1name;
		player1.win = false;
		player1.marker = 'x';

		cout << "\n" << "[*] Initializing Player #2" << "\n\n";
		player2.name = "CPU";
		player2.win = false;
		player2.marker = 'o';

		// Gaming Loop
		while(true){
			while(true){

				// Player's Turn
				while(true){
						int turnInput;
						cout << "Player #1 Turn: ";
						cin >> turnInput;
						// This part is a bit tricky for people who are not used to C++
						// You need to use a vector library to be able to modify the array
						// You also have to be very explicit in your conditions
						if(turnInput >= 0 && turnInput < 9){
							if(turnInput >= 0 && turnInput <= 2){
								if(ticTac.top[turnInput] == '0'){
									ticTac.top[turnInput] = player1.marker;
									ticTac.occupied.push_back(turnInput);
									break;
								}else{
									cout << "[!] Occupied Point" << endl;
								}
							}else if(turnInput >= 3 && turnInput <= 5){
								turnInput = turnInput - 3;
								if(ticTac.middle[turnInput] == '0'){
									ticTac.middle[turnInput] = player1.marker;
									turnInput = turnInput + 3;
									ticTac.occupied.push_back(turnInput);
									break;
								}else{
									cout << "[!] Occupied Point" << endl;
								}
							}else if(turnInput >= 6 && turnInput <= 8){
								turnInput = turnInput - 6;
								if(ticTac.bottom[turnInput] == '0'){
									ticTac.bottom[turnInput] = player1.marker;
									turnInput = turnInput + 6;
									ticTac.occupied.push_back(turnInput);
									break;
								}else{
									cout << "[!] Occupied Point" << endl;
								}
							}
						}else{
							cout << "[!] Out of Bounds" << endl;
						}
				}

				// Check for Winning Patterns
				if(ticTac.winCheck() == true){
					player1.win = true;
					break;
				}

				//Opponent's Turn
				while(true){
					int oppTurn = (rand()%8);
					if(oppTurn <= 2 && oppTurn >= 0){
						if(ticTac.top[oppTurn] == '0'){
							ticTac.top[oppTurn] = player2.marker;
							ticTac.occupied.push_back(oppTurn);
							break;
						}
					}else if(oppTurn <= 5 && oppTurn >= 3){
						oppTurn = oppTurn-3;
						if(ticTac.middle[oppTurn] == '0'){
							ticTac.middle[oppTurn] = player2.marker;
							oppTurn = oppTurn+3;
							ticTac.occupied.push_back(oppTurn);
							break;
						}
					}else if(oppTurn <= 8 && oppTurn >= 6){
						oppTurn = oppTurn-6;
						if(ticTac.bottom[oppTurn] == '0'){
							ticTac.bottom[oppTurn] = player2.marker;
							oppTurn = oppTurn+6;
							ticTac.occupied.push_back(oppTurn);
							break;
						}
					}
				}

				// Check for Winning Patterns
				if(ticTac.winCheck() == true){
					player2.win = true;
					break;
				}

				// Show Board's Status
				ticTac.showStatus();
			}
			// Declare the Winner
			if(player1.win == true){
				cout << "\n" << "WINNER: Player 1" << "\n"; 
			}else if(player2.win == true){
				cout << "\n" << "WINNER: CPU" << "\n"; 
			}else{
				cout << "\n" << "DRAW" << "\n"; 
			}
			break;
		}
	}catch(...){
		cout << "An error occured";
	}
}


// Shows the Board's Current State
void Board::showStatus(void){
	cout << "| " << top[0] << " | " << top[1] << " | " << top[2] << " | " << "\n";
	cout << "| " << middle[0] << " | " << middle[1] << " | " << middle[2] << " | " << "\n";
	cout << "| " << bottom[0] << " | " << bottom[1] << " | " << bottom[2] << " | " << "\n";
}

// Checks for Winning Patterns
bool Board::winCheck(void){
	// Horizontal Patterns
	if(top[0]=='x' && top[1]=='x' && top[2]=='x'){
		return true;
	}else if(top[0]=='o' && top[1]=='o' && top[2]=='o'){
		return true;
	}else if(middle[0]=='x' && middle[1]=='x' && middle[2]=='x'){
		return true;
	}else if(middle[0]=='o' && middle[1]=='o' && middle[2]=='o'){
		return true;
	}else if(bottom[0]=='x' && bottom[1]=='x' && bottom[2]=='x'){
		return true;
	}else if(bottom[0]=='o' && bottom[1]=='o' && bottom[2]=='o'){
		return true;
	}
	// Vertical Patterns
	else if(top[0]=='x' && middle[0]=='x' && bottom[0]=='x'){
		return true;
	}else if(top[0]=='o' && middle[0]=='o' && bottom[0]=='o'){
		return true;
	}else if(top[1]=='x' && middle[1]=='x' && bottom[2]=='x'){
		return true;
	}else if(top[1]=='o' && middle[1]=='o' && bottom[2]=='o'){
		return true;
	}else if(top[2]=='x' && middle[2]=='x' && bottom[2] == 'x'){
		return true;
	}else if(top[2]=='o' && middle[2]=='o' && bottom[2] == 'o'){
		return true;
	}
	// Diagonal Patterns
	else if(top[0]=='x' && middle[1]=='x' && bottom[2]=='x'){
		return true;
	}else if(top[0]=='o' && middle[1]=='o' && bottom[2]=='o'){
		return true;
	}else if(top[2]=='x' && middle[1]=='x' && bottom[0]=='x'){
		return true;
	}else if(top[2]=='o' && middle[2]=='o' && bottom[2]=='o'){
		return true;
	}else{
		return false;
	}
}