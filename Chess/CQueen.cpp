#include "CQueen.h"
#include "CBishop.h"
#include "CRook.h"
extern std::array<std::array<CFigure*, 8>, 8> board;
bool CQueen::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	//Queen validation
	CBishop bishop;
	CRook rook;
	return bishop.ValidMove(xFrom, yFrom, xTo, yTo) || rook.ValidMove(xFrom, yFrom, xTo, yTo);
}

EPiece CQueen::GetPiece() {
	return EPiece::queen;
}