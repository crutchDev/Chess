#pragma once

#include "chessInclude.h"

//#include "Figure.h"
#include "MoveInfo.h"



class Chessboard {
public:
	Chessboard();
	~Chessboard();
	void Reset();
	bool GameOver();

private:
	vector<vector<Figure>> board;
	vector<MoveInfo> hist;
};

