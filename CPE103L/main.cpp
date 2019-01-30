#include <iostream>
#include <string>

using namespace std;

bool firstGame = false;

class Board{
	public:
		// 3x3 Board
		char top[4] = {'0', '0', '0', '\0'};
		char middle[4] = {'0', '0', '0', '\0'};
		char bottom[4] = {'0', '0', '0', '\0'};
		// Array that would store all occupied points
		char occupied[];

		// Member Functions
		void boardReset(void);
		void winnerStat(void);
		void statusUpdate(void);
		bool winCheck(void);
};

class Player{
	public:
		string name;
		bool win;
		string marker;
		int score;

		// Member Functions
		void playerTurn(void);
		void opponentTurn(void);
};

int main(){
	try{
		Board ticTac;
		Player player1;
		Player player2;
		if(firstGame == false){
			string p1name;
			cout << "\n" << "INSTRUCTIONS:" << "\n" << "[ 0 1 2 ]" << "\n" << "[ 3 4 5 ]" << "\n" << "[ 6 7 8 ]" << "\n\n";
			cout << "[?] Player Name: ";
			cin >> p1name;
			player1.name = p1name;
		}

		cout << "\n" << "[*] Initializing Player #1" << "\n";
		player1.score = 0;
		player1.win = false;
		player1.marker = 'x';

		cout << "\n" << "[*] Initializing Player #2" << "\n\n";
		player2.name = "CPU";
		player2.score = 0;
		player2.win = false;
		player2.marker = 'o';

		while(true){
			while(true){
				player1.playerTurn();
				break;
			}
			break;
		}
		/*while(true){
			while(true){
				player1.playerTurn();
				if(ticTac.winCheck() == true){
					break;
				}
				player2.opponentTurn();
				if(ticTac.winCheck() == true){
					break;
				}
				ticTac.statusUpdate();
			}
			ticTac.winnerStat();
			ticTac.boardReset();
		}*/
	}catch(...){
		cout << "An error occured";
	}
}
void Board::boardReset(void){
	cout << "Called Board::boardReset";
	//char top[4] = {'0', '0', '0', '\0'};
	//char middle[4] = {'0', '0', '0', '\0'};
	//char bottom[4] = {'0', '0', '0', '\0'};
}
void Board::winnerStat(void){
	cout << "Called Board::winnerStat";
}
void Board::statusUpdate(void){
	cout << "Called Board::statusUpdate";
}
bool Board::winCheck(void){
	cout << "Called Board::winCheck";
	return false;
}


void Player::playerTurn(void){
	while(true){
		int turnInput;
		cout << "Player #1 Turn: ";
		cin >> turnInput;
		if(turnInput > 8 || turnInput < 0){
			cout << "Out of Bounds";
		}else if(turnInput <= 2 && turnInput >= 0){
			cout << "Top Board Modified";
			break;
		}else if(turnInput <= 5 && turnInput >= 3){
			cout << "Middle Board Modified";
			break;
		}else if(turnInput <= 8 && turnInput >= 6){
			cout << "Bottom Board Modified";
			break;
		}else{
			cout << "Dunno what to fucking do";
			break;
		}
	}
}
void Player::opponentTurn(void){
	cout << "Called Player::opponentTurn()";
}
