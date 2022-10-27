#pragma once
#include "Struct.h"
#include <string>
#include <array>
class CFigure{
protected:
	ETeam color;
	int xPosStart = 0;
	int yPosStart= 0;
public:
	CFigure(ETeam setColor) {
		color = setColor;
	}
	virtual ~CFigure() = default;
	ETeam getTeam() { return color; }
	
	virtual bool ValidMove(std::array<std::array<CFigure*, 8>, 8> arrBoard,int xFrom, int yFrom, int xTo, int yTo) = 0;
	virtual EPiece GetPiece() = 0;
};

