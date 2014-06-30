


#pragma once

#include "chessInclude.h"

class Chessboard {
public:
	Chessboard();
	~Chessboard();

private:
	vector< vector< Figure* > > board;

};

struct ChessboardPos {
	ChessboardPos(int x,int y) : x(x),y(y) { }
	// let (0,0) be low left corner
	int x;	// are good names ?
	int y;
};