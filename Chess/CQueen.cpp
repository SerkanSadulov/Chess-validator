#include "CQueen.h"
#include "CBishop.h"
#include "CRook.h"
CQueen::CQueen(ETeam team) :CFigure(team) {}

bool CQueen::ValidMove(std::array<std::array<CFigure*, 8>, 8> board, int xFrom, int yFrom, int xTo, int yTo) {
	//Queen validation
	CFigure* bishop = new CBishop(getTeam());
	CFigure* rook = new CRook(getTeam());


	bool valid = bishop->ValidMove(board, xFrom, yFrom, xTo, yTo) || rook->ValidMove(board, xFrom, yFrom, xTo, yTo);
	delete bishop;
	delete rook;

	return valid;
}

EPiece CQueen::GetPiece() {
	return EPiece::queen;
}