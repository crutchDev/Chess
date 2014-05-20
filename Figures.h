
#pragma once 

#include "chessInclude.h"

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

