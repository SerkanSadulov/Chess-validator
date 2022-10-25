#pragma once
#include "CFigure.h"
class CKnight :public CFigure{
	public:
	virtual bool ValidMove(int xFrom, int yFrom, int xTo, int yTo) override;
	virtual EPiece GetPiece() override;
};

