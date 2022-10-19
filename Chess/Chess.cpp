#include <iostream>
#include <string>
using namespace std;

enum piece {
	none,
	king,
	queen,
	bishop,
	pawn,
	knight,
	rook,
};
piece board[8][8];
void Board() {
	//Clearing out the board
	memset(board, 0, sizeof(board));
	//Setting up the pieces on the board 
	board[0][0] = rook;
	board[0][1] = knight;
	board[0][2] = bishop;
	board[0][3] = queen;
	board[0][4] = king;
	board[0][5] = bishop;
	board[0][6] = knight;
	board[0][7] = rook;
	board[7][0] = rook;
	board[7][1] = knight;
	board[7][2] = bishop;
	board[7][3] = queen;
	board[7][4] = king;
	board[7][5] = bishop;
	board[7][6] = knight;
	board[7][7] = rook;
	for (int i = 0; i < 8; i++) {
		board[1][i] = pawn;
		board[6][i] = pawn;

	}

}


bool validMove(int xFrom, int yFrom, int xTo, int yTo) {

	int xValid = abs(xFrom - xTo);
	int yValid = abs(yFrom - yTo);
	int yValidR = abs(yFrom - yTo);
	int xValidR = abs(xFrom - xTo);
	bool valid = true;
	piece peice = board[xFrom][yFrom];

	switch (peice) {
	case none:
		break;
	case king:

		if (xValid < 2 && yValid < 2 && board[xTo][yTo] == none) {
			peice = board[xTo][yTo];
			return true;
		}
		else return false;


		break;
	case queen:

		break;
	case bishop:

		break;
	case pawn:

		break;
	case knight:

		break;
	case rook:
		
		if (xFrom != xTo && yFrom != yTo) {
			return false;
		}
		if (yFrom == yTo) {
			int directionX = xTo - xFrom;
			if (directionX < 0) {
				for (int i = 1; i < xValidR;i++) {
					valid = peice = board[xFrom - i][yFrom];
					if (!valid) {
						return false;
					}
				}
			}
			else {
				for (int i = 1; i < xValidR ;i++) {
					valid = peice = board[xFrom + i][yTo]; 
					if (!valid) {
						return false;
					}
				}
			}
		}
		else {
			if (yTo == yTo) {
				int directionY = yTo - yFrom;
				if (directionY > 0) {
					for (int i = 1; i < yValidR; i++) {
						valid = peice = board[xFrom][yFrom + i];
						if (!valid) {
							return false;
						}
					}
				}
				else {
					for (int i = 1; i < yValidR; i++) {
						valid = peice = board[xFrom][yFrom - i];
						if (!valid) {
							return false;
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

int main() {
	string input;
	Board();
	cout << "Move: ";	cin >> input;
	if (input.length() != 5) {
		cout << "Invalid input";
	}
	else {
		if ((!isdigit(input[0])) && !isdigit(input[3])) {
			if ((isdigit(input[1])) && isdigit(input[4])) {

				bool result = validMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);

				if (result == true) {
					cout << "Valid move";
				}
				else cout << "Invalid move";
			}

		}
	}



}