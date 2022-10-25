#include "CKnight.h"
extern EPiece  board[8][8];
extern ETeam boardT[8][8];
extern ETeam currentTeam;


bool CKnight::ValidMove(int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom];
	ETeam teamm = boardT[xFrom][yFrom];
	//Knight validation
	if (board[xTo][yTo] == EPiece::none && yTo == yFrom + 1 || yTo == yFrom - 1) {
		if (board[xTo][yTo] == EPiece::none && xTo == xFrom + 2 || xTo == xFrom - 2) {
			peice = board[xTo][yTo];
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	if (board[xTo][yTo] == EPiece::none && yTo == yFrom + 2 || yTo == yFrom - 2) {
		if (board[xTo][yTo] == EPiece::none && xTo == xFrom + 1 || xTo == xFrom - 1) {
			peice = board[xTo][yTo];
			boardT[xFrom][yFrom] = ETeam::nothing;
			boardT[xTo][yTo] = teamm;
			return true;
		}
	}
	//Getting the opposite color piece
	else {
		if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && yTo == yFrom + 1 || yTo == yFrom - 1) {
			if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && board[xTo][yTo] == EPiece::none && xTo == xFrom + 2 || xTo == xFrom - 2) {
				peice = board[xTo][yTo];
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}
		if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && yTo == yFrom + 2 || yTo == yFrom - 2) {
			if ((boardT[xTo][yTo] != boardT[xFrom][yFrom]) && xTo == xFrom + 1 || xTo == xFrom - 1) {
				peice = board[xTo][yTo];
				boardT[xFrom][yFrom] = ETeam::nothing;
				boardT[xTo][yTo] = teamm;
				return true;
			}
		}
	}
	return false;
}
EPiece CKnight::GetPiece() {
	return EPiece::knight;

}