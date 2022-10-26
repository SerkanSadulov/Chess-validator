#include "CKing.h"
extern std::array<std::array<CFigure*, 8>, 8> board;
bool CKing::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	//King move validation
	int validKingX = xFrom - xTo;
	int  validKingY = yFrom - yTo;

	if (board[xTo][yTo] == nullptr && (validKingX >= -1 && validKingX <= 1) && (validKingY >= -1 && validKingY <= 1)) {
		return true;
	}
	else {
		if ((board[xFrom][yFrom]->getTeam() != board[xTo][yTo]->getTeam()) && (validKingX >= -1 && validKingX <= 1) && (validKingY >= -1 && validKingY <= 1)) {
			return true;
		}
	}
	return false;
}
EPiece CKing::GetPiece() {
	return EPiece::king;

}