#include "CKing.h"
CKing::CKing(ETeam team) :CFigure(team) {}
bool CKing::ValidMove(std::array<std::array<CFigure*, 8>, 8> board, int xFrom, int yFrom, int xTo, int yTo) {
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