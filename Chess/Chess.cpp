#include <iostream>
#include <string>
using namespace std;

//Declaring pieces
enum team {
	nothing,
	white,
	black
};
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
team boardT[8][8];
void Team() {
	//Clearing out the board
	memset(boardT, 0, sizeof(boardT));
	//Setting up the teams
	boardT[0][0] = white;
	boardT[0][1] = white;
	boardT[0][2] = white;
	boardT[0][3] = white;
	boardT[0][4] = white;
	boardT[0][5] = white;
	boardT[0][6] = white;
	boardT[0][7] = white;
	boardT[7][0] = black;
	boardT[7][1] = black;
	boardT[7][2] = black;
	boardT[7][3] = black;
	boardT[7][4] = black;
	boardT[7][5] = black;
	boardT[7][6] = black;
	boardT[7][7] = black;
	//Loop for declaring teams
	for (int i = 0; i < 8; i++) {
		boardT[1][i] = white;
		boardT[6][i] = black;

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
	team teamm = boardT[xFrom][yFrom];

	switch (peice) {
	case none:
		break;
	case king:
		//King move validation
		if (xValid < 2 && yValid < 2 && board[xTo][yTo] == none) {
			peice = board[xTo][yTo];
			teamm = boardT[xTo][yTo];
			board[xFrom][yFrom] = none;
			boardT[xFrom][yFrom] = nothing;
			return true;
		}
		else return false;


		break;
	case queen:
		//Queen validation
		if (board[xTo][yTo] == none && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			int checkX;
			int checkY;
			for (checkX = xTo + xOffSet, checkY = yTo + yOffSet;checkX != xFrom;checkX = checkX + xOffSet, checkY = checkY + yOffSet){
				if (board[checkX][checkY] != none) {
					return false;
				}
			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		if (xFrom == xTo && board[xTo][yTo] == none) {
			// Checking if there is something in the way
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
				if (board[xTo][checkY] != none) {
					return false;
				}

			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		else if (yFrom == yTo && board[xTo][yTo] == none) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
				if (board[checkX][yTo] != none) {
					return false;
				}
			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		return false;
	

		break;
	case bishop:
		//Bishop move validation
		if (board[xTo][yTo] == none && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			int checkX;
			int checkY;
			for (checkX = xTo + xOffSet, checkY = yTo + yOffSet;checkX != xFrom;checkX = checkX + xOffSet, checkY = checkY + yOffSet){
				if (board[checkX][checkY] != none) {
					return false;
				}
			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		return false;
		


		break;
	case pawn:
		//Pawn validation
		if (xFrom == 1) {
			if (yTo == yFrom) {
				if (board[xTo][yTo] == none && xTo == xFrom + 1) {
					boardT[xFrom][yFrom] = nothing;
					boardT[xTo][yTo] = teamm;
					return true;
				}
				if (board[xTo][yTo] == none && xTo == xFrom + 2) {
					boardT[xFrom][yFrom] = nothing;
					boardT[xTo][yTo] = teamm;
					return true;
				}
			}
			
		}if (xFrom == 6) {
			if (yTo == yFrom) {
				if (board[xTo][yTo] == none && xTo == xFrom - 1) {
					boardT[xFrom][yFrom] = nothing;
					boardT[xTo][yTo] = teamm;
					return true;
				}
				if (board[xTo][yTo] == none && xTo == xFrom - 2) {
					boardT[xFrom][yFrom] = nothing;
					boardT[xTo][yTo] = teamm;
					return true;
				}
			}
		}
		if (yTo == yFrom) {
			if (board[xTo][yTo] == none && xTo == xFrom + 1) {
				boardT[xFrom][yFrom] = nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
			if (board[xTo][yTo] == none && xTo == xFrom - 1) {
				boardT[xFrom][yFrom] = nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}
			else return false;

			
		break;
	case knight:
		//Knight validation
		if (board[xTo][yTo] == none && yTo == yFrom + 1 || yTo == yFrom - 1 ) {
			if (board[xTo][yTo] == none && xTo == xFrom + 2 || xTo == xFrom - 2) {
				peice = board[xTo][yTo];
				boardT[xFrom][yFrom] = nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}
				if (board[xTo][yTo] == none && yTo == yFrom + 2 || yTo == yFrom - 2 ) {
		 			if (board[xTo][yTo] == none && xTo == xFrom + 1 || xTo == xFrom - 1 ) {
						peice = board[xTo][yTo];
						boardT[xFrom][yFrom] = nothing;
						boardT[xTo][yTo] = teamm;
						return true;
					}
				}else  return false;
		break;
	case rook:
		if (xFrom == xTo && board[xTo][yTo] == none) {
			// Checking if there is something in the way
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
				if (board[xTo][checkY] != none) {
					return false;
				}
				
			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		else if (yFrom == yTo && board[xTo][yTo] == none) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
				if (board[checkX][yTo] != none) {
					return false;
				}
			}
			boardT[xFrom][yFrom] = nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

int main() {
	bool run = true;
	string input;
	//Sorting the board
	Board();
	Team();
	//Loop for the input and printing the board
	while (run)
	{
		//Printing the board
		PrintBoard();
		std::cout << "Move: ";
		cin >> input;

		//Input validation
		if (input.length() != 5) {
			std::cout << "Invalid input\n";
			run = false;
			break;
		}
		//Conversion from ASII to Numbers
		else {
			if ((!isdigit(input[0])) && !isdigit(input[3])) {
				if ((isdigit(input[1])) && isdigit(input[4])) {
					//Returning true or false if the move is valid
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