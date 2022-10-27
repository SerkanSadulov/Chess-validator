#include "CRook.h"
CRook::CRook(ETeam team) :CFigure(team) {}
bool CRook::ValidMove(std::array<std::array<CFigure*, 8>, 8> board, int xFrom, int yFrom, int xTo, int yTo) {
	EPiece peice = board[xFrom][yFrom]->GetPiece();
	ETeam teamm = board[xFrom][yFrom]->getTeam();
	//Bishop validation
	if(board[xTo][yTo] == nullptr && xFrom == xTo) {
		// Checking if there is something in the way
		int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
		for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
			if (board[xTo][checkY] != nullptr) {
				return false;
			}
		}
		return true;
	}
	else if (board[xTo][yTo] == nullptr && yFrom == yTo) {
	// Checking if there is something in the way
	int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
	for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
		if (board[checkX][yTo] != nullptr) {
			return false;
		}
	}
	return true;
	}
	//Getting the opposite color piece
	else {
		if ((board[xTo][yTo]->getTeam() != board[xFrom][yFrom]->getTeam()) && xFrom == xTo) {
			// Checking if there is something in the way
			int yOffSet = (yFrom - yTo > 0) ? 1 : -1;
			for (int checkY = yTo + yOffSet; checkY != yFrom; checkY = checkY + yOffSet) {
				if (board[xTo][checkY] != nullptr) {
					return false;
				}

			}
			return true;
		}
		else if ((board[xTo][yTo]->getTeam() != board[xFrom][yFrom]->getTeam() && yFrom == yTo)) {
			// Checking if there is something in the way
			int xOffSet = (xFrom - xTo > 0) ? 1 : -1;
			for (int checkX = xTo + xOffSet; checkX != xFrom; checkX = checkX + xOffSet) {
				if (board[checkX][yTo] != nullptr) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

 }
 EPiece CRook::GetPiece() {
	 return EPiece::rook;
 }
