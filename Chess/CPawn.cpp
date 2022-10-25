#include "CPawn.h"
extern EPiece  board[8][8];
extern ETeam boardT[8][8];

bool CPawn::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom];
	ETeam teamm = boardT[xFrom][yFrom];

	//Pawn validation
		//Checking if it is the fist move of a white pawn
	if (xFrom == 1 && boardT[xFrom][yFrom] == ETeam::white) {
		if (yTo == yFrom) {
			if (board[xTo][yTo] == EPiece::none && xTo == xFrom + 1) {
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
			if (board[xTo][yTo] == EPiece::none && xTo == xFrom + 2) {
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}

	}
	//Checking if it is the fist move of a black pawn
	if (xFrom == 6 && boardT[xFrom][yFrom] == ETeam::black) {
		if (yTo == yFrom) {
			if (board[xTo][yTo] == EPiece::none && xTo == xFrom - 1) {
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
			if (board[xTo][yTo] == EPiece::none && xTo == xFrom - 2) {
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}
	}
	//Move validation for white pawn
	if (yTo == yFrom && boardT[xFrom][yFrom] == ETeam::white) {
		if (board[xTo][yTo] == EPiece::none && xTo == xFrom + 1) {
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		//Move validation for black pawn
		if (boardT[xFrom][yFrom] == ETeam::black && board[xTo][yTo] == EPiece::none && xTo == xFrom - 1) {
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	//Checking if i can get opposite pawn when white
	if (boardT[xFrom][yFrom] == ETeam::white && boardT[xTo][yTo] == ETeam::black && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (xTo == xFrom + 1) {
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	//Checking if i can get opposite pawn when black
	if (boardT[xFrom][yFrom] == ETeam::black && boardT[xTo][yTo] == ETeam::white && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (xTo == xFrom - 1) {
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	else return false;

}
EPiece CPawn::GetPiece() {
	return EPiece::pawn;
}
