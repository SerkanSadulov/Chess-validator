#include "CKnight.h"

extern std::array<std::array<CFigure*, 8>, 8> board;


bool CKnight::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom]->GetPiece();
	ETeam teamm = board[xFrom][yFrom]->getTeam();
	//Knight validation
	if (board[xTo][yTo] == nullptr && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (board[xTo][yTo] == nullptr && xTo == xFrom + 2 || xTo == xFrom - 2) {
			return true;
		}
	}
	if (board[xTo][yTo] == nullptr && yTo == yFrom + 2 || yTo == yFrom - 2) {
		if (board[xTo][yTo] == nullptr && xTo == xFrom + 1 || xTo == xFrom - 1) {
			return true;
		}
	}
	//Getting the opposite color piece
	else {
		if ((board[xTo][yTo] ->getTeam() != board[xFrom][yFrom]->getTeam()) && yTo == yFrom + 1 || yTo == yFrom - 1) {
			if ((board[xTo][yTo] -> getTeam() != board[xFrom][yFrom] -> getTeam()) && board[xTo][yTo] == nullptr && xTo == xFrom + 2 || xTo == xFrom - 2) {
				return true;
			}
		}
		if ((board[xTo][yTo] -> getTeam() != board[xFrom][yFrom]->getTeam()) && yTo == yFrom + 2 || yTo == yFrom - 2) {
			if ((board[xTo][yTo]-> getTeam() != board[xFrom][yFrom]-> getTeam()) && xTo == xFrom + 1 || xTo == xFrom - 1) {
				return true;
			}
		}
	}
	return false;
}
EPiece CKnight::GetPiece() {
	return EPiece::knight;

}