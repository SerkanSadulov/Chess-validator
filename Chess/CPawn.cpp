#include "CPawn.h"
extern std::array<std::array<CFigure*, 8>, 8> board;

bool CPawn::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom]->GetPiece();
	ETeam teamm = board[xFrom][yFrom]->getTeam();
	//Pawn validation
	if (xFrom == 1 && board[xFrom][yFrom]->getTeam() == ETeam::white) {
		if (yTo == yFrom) {
			if (board[xTo][yTo] == nullptr && xTo == xFrom + 1) {
				return true;
			}
			if (board[xTo][yTo] == nullptr && xTo == xFrom + 2) {
				return true;
			}
		}

	}
	//Checking if it is the fist move of a black pawn
	if (xFrom == 6 && board[xFrom][yFrom]->getTeam() == ETeam::black) {
		if (yTo == yFrom) {
			if (board[xTo][yTo]== nullptr && xTo == xFrom - 1) {
				return true;
			}
			if (board[xTo][yTo] == nullptr&& xTo == xFrom - 2) {
				return true;
			}
		}
	}
	//Move validation for white pawn
	if (yTo == yFrom && board[xFrom][yFrom]->getTeam() == ETeam::white) {
		if (board[xTo][yTo] == nullptr && xTo == xFrom + 1) {
			return true;
		}
		//Move validation for black pawn
		if (board[xFrom][yFrom]->getTeam() == ETeam::black && board[xTo][yTo] == nullptr && xTo == xFrom - 1) {
			return true;
		}
	}
	//Checking if i can get opposite pawn when white
	if (board[xFrom][yFrom]->getTeam() == ETeam::white && board[xTo][yTo] -> getTeam() == ETeam::black && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (xTo == xFrom + 1) {
			return true;
		}
	}
	//Checking if i can get opposite pawn when black
	if (board[xFrom][yFrom]->getTeam() == ETeam::black && board[xTo][yTo]->getTeam() == ETeam::white && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (xTo == xFrom - 1) {
			return true;
		}
	}
	else return false;

}
EPiece CPawn::GetPiece() {
	return EPiece::pawn;
}
