#pragma once
#include "Struct.h"

class CFigure{
public:
	CFigure() = default;
	virtual ~CFigure() = default;

	virtual bool ValidMove(int xFrom, int yFrom, int xTo, int yTo) = 0;
	virtual EPiece GetPiece() = 0;
};

