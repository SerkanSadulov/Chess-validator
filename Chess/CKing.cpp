#include "CKing.h"
extern EPiece  board[8][8];
extern ETeam boardT[8][8];
bool CKing::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	//King move validation

	int validKingX = xFrom - xTo;
	int  validKingY = yFrom - yTo;

	if (board[xTo][yTo] == EPiece::none && (validKingX >= -1 && validKingX <= 1) && (validKingY >= -1 && validKingY <= 1) ) {
		return true;
	}
	else {
		if ((boardT[xFrom][yFrom] != boardT[xTo][yTo]) && (validKingX >= -1 && validKingX <= 1) && (validKingY >= -1 && validKingY <= 1)  ) {
			return true;
		}
	}
	return false;
}
EPiece CKing::GetPiece() {
	return EPiece::king;

}