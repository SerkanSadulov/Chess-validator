#pragma once
#include <iostream>
#include <string>
#include "Struct.h"
#include "CBishop.h"
#include "CKing.h"
#include "CKnight.h"
#include "CPawn.h"
#include "CQueen.h"
#include "CRook.h"
#include "CFigure.h"
#include <array>
#include "CBoard.h"
using namespace std;
class CBoard{
protected:
	bool turn = true;
	bool start = true;
	string input;
	void setUpBoard();
	std::array<std::array<CFigure*, 8>, 8> board;
	void printBoard();

public:
	CBoard();
	~CBoard();
	void run();
};

