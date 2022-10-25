#include "CBishop.h"
extern EPiece  board[8][8];
extern ETeam boardT[8][8];
bool CBishop::ValidMove(int xFrom, int yFrom, int xTo, int yTo){
	EPiece peice = board[xFrom][yFrom];
	ETeam teamm = boardT[xFrom][yFrom];
	//Bishop move validation
	if (board[xTo][yTo] == EPiece::none && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
		// Checking if there is something in the way
		int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
		int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
		int checkX;
		int checkY;
		for (checkX = xTo + xOffSet, checkY = yTo + yOffSet; checkX != xFrom; checkX = checkX + xOffSet, checkY = checkY + yOffSet) {
			if (board[checkX][checkY] != EPiece::none) {
				return false;
			}
		}
		boardT[xFrom][yFrom] = ETeam::nothing;
		boardT[xTo][yTo] = teamm;
		return true;
	}
	//Getting the opposite color piece
	else {
		if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			int checkX;
			int checkY;
			for (checkX = xTo + xOffSet, checkY = yTo + yOffSet; checkX != xFrom; checkX = checkX + xOffSet, checkY = checkY + yOffSet) {
				if (board[checkX][checkY] != EPiece::none) {
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
EPiece CBishop::GetPiece() {
	return EPiece::bishop	;
}
