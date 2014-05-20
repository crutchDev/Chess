
#pragma once 

#include "chessInclude.h"

class Figure {
public:

	Figure();
	virtual ~Figure();

	virtual bool canMove(ChessboardPos& pos) const = 0;
	virtual void move(ChessboardPos& pos) = 0;
	virtual vector< ChessboardPos > getAllowedMove() = 0;


	Color getColor() { return clr; }
protected:
	Color clr;

	//Chessboard* board;
};

class King : public Figure {
public :
	bool isAttacked() {
		
		// TODO
		return false;
	}

	virtual bool canMove( ChessboardPos& pos ) {
	
		// TODO
		return false;
	}
	
	virtual void move( ChessboardPos& pos ) {
			// TODO
	}


	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}


};

