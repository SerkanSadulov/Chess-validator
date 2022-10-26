#pragma once
#include "Struct.h"
#include <string>
#include <array>
class CFigure{
protected:
	ETeam color;
public:
	CFigure() = default;
	virtual ~CFigure() = default;
	ETeam getTeam() { return color; }
	void setTeam(ETeam setColor) {
		color = setColor;
	}
	virtual bool ValidMove(int xFrom, int yFrom, int xTo, int yTo) = 0;
	virtual EPiece GetPiece() = 0;
};

