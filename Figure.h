
/// purpose : 

#pragma once

#include "chessInclude.h"
#include "Chessboard.h"

class Figure {
public:

	typedef enum { BLACK,WHITE } Color;
	struct ChessboardPos {
		ChessboardPos(int x,int y) : x(x),y(y) { }
		// let (0,0) be low left corner
		int x;	// are good names ?
		int y;
	};


	Figure();
	virtual ~Figure();

	virtual bool canMove( ChessboardPos& pos ) const = 0;
	virtual void move( ChessboardPos& pos ) = 0;
	virtual std::vector< ChessboardPos > getAllowedMove() = 0; 

	Color getColor() { return clr; }
protected:
	Color clr;
	
	//Chessboard* board;
};


