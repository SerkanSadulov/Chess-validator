#include "CBoard.h"


CBoard::CBoard(){
	//Sorting the board
	setUpBoard();
	
}

CBoard::~CBoard(){
}

void CBoard::run(){
	while (start) {
		//Printing the board
		printBoard();
		//Checking if for turns
		if (turn == true) {
			std::cout << "Move white: ";
			cin >> input;
			turn = false;

		}
		else if (turn == false) {
			std::cout << "Move black: ";
			cin >> input;
			turn = true;
		};
		//Input validation
		if (input.length() != 5) {
			std::cout << "Invalid input\n";
			start = false;
			break;
		}
		//Conversion from ASII to Numbers
		else {
			if ((!isdigit(input[0])) && !isdigit(input[3]) && (isdigit(input[1])) && isdigit(input[4])) {
				bool result = false;
				int boardInpZero = input[0] - 97;
				int boardInpOne = input[1] - 49;
				int boardInpThree = input[3] - 97;
				int boardInpFour = input[4] - 49;
				if (board[boardInpOne][boardInpZero] != nullptr) {
					result = board[boardInpOne][boardInpZero]->ValidMove(board,boardInpOne, boardInpZero, boardInpFour, boardInpThree);
					//Returning true or false if the move is valid
					if (result == true) {
						std::cout << "Valid move\n";
						board[boardInpFour][boardInpThree] = board[boardInpOne][boardInpZero];
						board[boardInpOne][boardInpZero] = nullptr;
					}
					else std::cout << "Invalid move\n";
				}
				else std::cout << "Invalid move\n";
			}

		}
	}
}

void CBoard::setUpBoard(){
	//Setting up the pieces on the board 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = nullptr;
		}
	}
	board[0][0] = new CRook(ETeam::white);
	board[0][1] = new CKnight(ETeam::white);
	board[0][2] = new CBishop(ETeam::white);
	board[0][3] = new CQueen(ETeam::white);
	board[0][4] = new CKing(ETeam::white);
	board[0][5] = new CBishop(ETeam::white);
	board[0][6] = new CKnight(ETeam::white);
	board[0][7] = new CRook(ETeam::white);
	board[7][0] = new CRook(ETeam::black);
	board[7][1] = new CKnight(ETeam::black);
	board[7][2] = new CBishop(ETeam::black);
	board[7][3] = new CQueen(ETeam::black);
	board[7][4] = new CKing(ETeam::black);
	board[7][5] = new CBishop(ETeam::black);
	board[7][6] = new CKnight(ETeam::black);
	board[7][7] = new CRook(ETeam::black);
	//Loop for declaring the pawns
	for (int i = 0; i < 8; i++) {
		board[1][i] = new CPawn(ETeam::white);
		board[6][i] = new CPawn(ETeam::black);

	}

}

void CBoard::printBoard(){
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << ' ' << '|';
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == nullptr) {
				std::cout << " " << "|";
				continue;
			}
			switch (board[i][j]->GetPiece()) {
			case EPiece::none: {
				std::cout << ' ';
				break;
			}

			case EPiece::king: {
				std::cout << "K";
				break;
			}

			case EPiece::queen: {
				std::cout << "Q";
				break;
			}

			case EPiece::bishop: {
				std::cout << "B";
				break;
			}

			case EPiece::pawn: {
				std::cout << "P";
				break;
			}

			case EPiece::knight: {
				std::cout << "N";
				break;
			}

			case EPiece::rook: {
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
		switch (i) {
		case 0: {
			std::cout << " A";
			break;
		}

		case 1: {
			std::cout << " B";
			break;
		}

		case 2: {
			std::cout << " C";
			break;
		}

		case 3: {
			std::cout << " D";
			break;
		}

		case 4: {
			std::cout << " E";
			break;
		}

		case 5: {
			std::cout << " F";
			break;
		}

		case 6: {
			std::cout << " G";
			break;
		}

		case 7: {
			std::cout << " H";
			break;
		}

		default:
			break;
		}
	}
	std::cout << '\n';
}

