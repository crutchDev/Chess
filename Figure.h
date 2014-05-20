
/// purpose : 

#pragma once

#include "chessInclude.h"

class Figure {
public:

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


