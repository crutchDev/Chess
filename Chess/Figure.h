
/// purpose : 

#pragma once

#include "chessInclude.h"

class Figure {
public:

	//Figure();
	Figure(Chessboard* b, Color c) : board(b), clr(c),currntPos(ChessboardPos(A,0) ) { };
	virtual ~Figure();

	virtual bool canMove(ChessboardPos& pos) const = 0;
	virtual void move(ChessboardPos& pos) = 0;
	virtual vector< ChessboardPos > getAllowedMove() = 0;
	
	Color getColor() { return clr; }
	Chessboard* boardWhereLocated() { return board; }
	ChessboardPos posWhereLocated() { return currntPos; }
	void changeLocation(ChessboardPos newPos) { currntPos = newPos; } 

protected:
	Color clr;

	Chessboard* board;
	ChessboardPos currntPos;

};


