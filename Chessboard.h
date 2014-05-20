


#pragma once

#include "chessInclude.h"

class Chessboard {
public:
	Chessboard();
	~Chessboard();
	void Reset();


private:
	vector< vector< Figure > > board;
	vector< MoveInfo > history;
};

struct ChessboardPos {
	ChessboardPos(int x,int y) : x(x),y(y) { }
	// let (0,0) be low left corner
	int x;	// are good names ?
	int y;
};