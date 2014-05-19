
/// purpose : 

#pragma once

#include "chessInclude.h"


class Figure {
public:

	typedef enum { BLACK,WHITE } Color;
	struct ChessboardPos {
		ChessboardPos(int x,int y) : x(x),y(y) { }
		int x;	// are good names ?
		int y;
	};


	Figure(void);
	virtual ~Figure(void);

	virtual bool canMove( ChessboardPos& pos ) const = 0;
	virtual void move( ChessboardPos& pos ) = 0;
	virtual std::vector< ChessboardPos > getAllowedMove() = 0; 

protected:
	Color clr;

};


