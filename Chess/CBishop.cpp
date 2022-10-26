#include "CBishop.h"
extern std::array<std::array<CFigure*, 8>, 8> board;
bool CBishop::ValidMove(int xFrom, int yFrom, int xTo, int yTo){
	EPiece peice = board[xFrom][yFrom] -> GetPiece();
	ETeam teamm = board[xFrom][yFrom]->getTeam();
	//Bishop move validation
	if (board[xTo][yTo] == nullptr && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
		// Checking if there is something in the way
		int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
		int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
		int checkX;
		int checkY;
		for (checkX = xTo + xOffSet, checkY = yTo + yOffSet; checkX != xFrom; checkX = checkX + xOffSet, checkY = checkY + yOffSet) {
			if (board[checkX][checkY] != nullptr) {
				return false;
			}
		}
		return true;
	}
	//Getting the opposite color piece
	else {
		if ((board[xTo][yTo] != nullptr && board[xTo][yTo]->getTeam() != board[xFrom][yFrom]->getTeam()) && yFrom - yTo == xFrom - xTo || yFrom - yTo == xTo - xFrom) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			int checkX;
			int checkY;
			for (checkX = xTo + xOffSet, checkY = yTo + yOffSet; checkX != xFrom; checkX = checkX + xOffSet, checkY = checkY + yOffSet) {
				if (board[checkX][checkY] != nullptr) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
EPiece CBishop::GetPiece() {
	return EPiece::bishop	;
}
