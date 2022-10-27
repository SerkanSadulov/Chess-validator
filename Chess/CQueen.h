#pragma once
#include "CFigure.h"
class CQueen :public CFigure{
public:
	CQueen(ETeam setColor);
	virtual bool ValidMove(std::array<std::array<CFigure*, 8>, 8> arrBoard, int xFrom, int yFrom, int xTo, int yTo) override;
	virtual EPiece GetPiece() override;
};

