#include "CRook.h"
extern EPiece  board[8][8];
extern ETeam boardT[8][8];

bool CRook::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom];
	ETeam teamm = boardT[xFrom][yFrom];
	if (board[xTo][yTo] == EPiece::none && xFrom == xTo) {
		// Checking if there is something in the way
		int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
		for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
			if (board[xTo][checkY] != EPiece::none) {
				return false;
			}

		}
		boardT[xFrom][yFrom] = ETeam::nothing;
		boardT[xTo][yTo] = teamm;
		return true;
	}
	else if (board[xTo][yTo] == EPiece::none && yFrom == yTo) {
		// Checking if there is something in the way
		int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
		for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
			if (board[checkX][yTo] != EPiece::none) {
				return false;
			}
		}
		boardT[xFrom][yFrom] = ETeam::nothing;
		boardT[xTo][yTo] = teamm;
		return true;
	}
	//Getting the opposite color piece
	else {
		if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && xFrom == xTo) {
			// Checking if there is something in the way
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
				if (board[xTo][checkY] != EPiece::none) {
					return false;
				}

			}
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
		else if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && yFrom == yTo) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
				if (board[checkX][yTo] != EPiece::none) {
					return false;
				}
			}
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	return false;

 }
 EPiece CRook::GetPiece() {
	 return EPiece::rook;
 }
