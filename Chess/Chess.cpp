#include <iostream>
#include <string>
using namespace std;

//Declaring pieces
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
	//Loop for declaring the pawns
	for (int i = 0; i < 8; i++) {
		board[1][i] = pawn;
		board[6][i] = pawn;

	}

}
void PrintBoard(){
    for (int i = 0; i < 8; i++){
        std::cout << (i + 1) << ' ' << '|';
        for (int j = 0; j < 8; j++){

            switch (board[i][j]){
            case none:{
                std::cout << ' ';
                break;
            }

            case king:{
                std::cout << "K";
                break;
            }

            case queen:{
                std::cout << "Q";
                break;
            }

            case bishop:{
                std::cout << "B";
                break;
            }

            case pawn:{
                std::cout << "P";
                break;
            }

            case knight:{
                std::cout << "N";
                break;
            }

            case rook:{
                std::cout << "R";
                break;
            }
            default:
                break;
            }

            std::cout << '|';
        }

        std::cout << '\n';
    }

    std::cout << "  ";

    for (int i = 0; i < 8; i++)
    {
        switch (i){
        case 0:{
            std::cout << " A";
            break;
        }

        case 1:{
            std::cout << " B";
            break;
        }

        case 2:{
            std::cout << " C";
            break;
        }

        case 3:{
            std::cout << " D";
            break;
        }

        case 4:{
            std::cout << " E";
            break;
        }

        case 5:{
            std::cout << " F";
            break;
        }

        case 6:{
            std::cout << " G";
            break;
        }

        case 7:{
            std::cout << " H";
            break;
        }

        default:
            break;
        }
    }
    std::cout << '\n';
}
//Function for validating the moves of the pieces
bool validMove(int xFrom, int yFrom, int xTo, int yTo) {
	//Getting the absolute value of the valid positions 
	int xValid = abs(xFrom - xTo);
	int yValid = abs(yFrom - yTo);
	int yValidR = abs(yFrom - yTo);
	int xValidR = abs(xFrom - xTo);
	int xValidB = abs(xFrom - xTo);
	int yValidB = abs(yFrom - yTo);
	bool valid = true;
	piece peice = board[xFrom][yFrom];

	switch (peice) {
	case none:
		break;
	case king:
		//King move validation
		if (xValid < 2 && yValid < 2 && board[xTo][yTo] == none) {
			peice = board[xTo][yTo];
			return true;
		}
		else return false;


		break;
	case queen:
		if (board[xTo][yTo] == none && (yFrom - yTo == xFrom - xTo) || (yFrom - yTo == xTo - xFrom)) {
			for (int i = 1; i < xValidB && yValidB; i++) {
				//Liner move
				valid = peice = board[xTo][yTo];
				if (!valid) {
					return false;
				}
			}

		}
		else return false;
		if (xFrom != xTo && yFrom != yTo) {
			return false;
		}
		//Move for X
		if (board[xTo][yTo] == none && yFrom == yTo) {
			int directionX = xTo - xFrom;
			//Move up or down
			if (directionX < 0) {
				for (int i = 1; i < xValidR; i++) {
					valid = peice = board[xFrom - i][yFrom];
					if (!valid) {
						return false;
					}
				}
			}
			else {
				for (int i = 1; i < xValidR; i++) {
					valid = peice = board[xFrom + i][yTo];
					if (!valid) {
						return false;
					}
				}
			}
		}
		else {
			int directionY = yTo - yFrom;
			//Move left and right
			if (board[xTo][yTo] == none) {
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
	case bishop:

		//Bishop move validation
		if (board[xTo][yTo] == none && (yFrom - yTo == xFrom - xTo) || (yFrom - yTo == xTo - xFrom)) {
			for (int i = 1; i < xValidB && yValidB; i++) {
				//Liner move
				valid = peice = board[xTo][yTo];
				if (!valid) {
					return false;
				}
			}

		}
		else return false;



		break;
	case pawn:

		break;
	case knight:
		if ((yTo == yFrom + 1) || (yTo == yFrom - 1) && board[xTo][yTo] == none) {
			if ((xTo == xFrom + 2) || (xTo == xFrom - 2) && board[xTo][yTo] == none) {
				valid = peice = board[xTo][yTo];
				return true;
			}
		}
				if ((yTo == yFrom + 2) || (yTo == yFrom - 2) && board[xTo][yTo] == none) {
		 			if ((xTo == xFrom + 1) || (xTo == xFrom - 1) && board[xTo][yTo] == none) {
						valid = peice = board[xTo][yTo];
						return true;
					}
				}else  return false;
		break;
	case rook:
		//Rook move validation
		if (xFrom != xTo && yFrom != yTo) {
			return false;
		}
		//Move for X
		if (board[xTo][yTo] == none && yFrom == yTo) {
			int directionX = xTo - xFrom;
			//Move up or down
			if (directionX < 0) {
				for (int i = 1; i < xValidR; i++) {
					valid = peice = board[xFrom - i][yFrom];
					if (!valid) {
						return false;
					}
				}
			}
			else {
				for (int i = 1; i < xValidR; i++) {
					valid = peice = board[xFrom + i][yTo];
					if (!valid) {
						return false;
					}
				}
			}
		}
		else {
			int directionY = yTo - yFrom;
			//Move left and right
			if (board[xTo][yTo] == none) {
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

	bool run = true;

	while (run)
	{
		PrintBoard();
		
		std::cout << "Move: ";
		cin >> input;

		//Input validation
		if (input.length() != 5) {
			std::cout << "Invalid input";
			run = false;
			break;
		}
		//Conversion from ASII to Numbers
		else {
			if ((!isdigit(input[0])) && !isdigit(input[3])) {
				if ((isdigit(input[1])) && isdigit(input[4])) {

					bool result = validMove(input[1] - 49, input[0] - 97, input[4] - 49, input[3] - 97);



					if (result == true) {
						std::cout << "Valid move\n";
						board[input[4] - 49][input[3] - 97] = board[input[1] - 49][input[0] - 97];
						board[input[1] - 49][input[0] - 97] = none;

					}
					else std::cout << "Invalid move\n";

			

				}

			}
		}
	}



}