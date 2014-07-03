
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
	Chessboard* boardWhereLocated() const { return board; }
	ChessboardPos posWhereLocated() const { return currntPos; }
	void changeLocation(ChessboardPos newPos) { currntPos = newPos; } 

	// test only 
	// first letter it is color symbol W - white , B - clack 
	// second letter it is figure symbol 
	// K - king  ; P - pawn   ; R - rook 
	// Q - queen ; B - bishop ; H - horse 
	virtual string getStringSchematicRep() const = 0;

protected:
	string colorSchemeRep() const ;

	Color clr;

	Chessboard* board;
	ChessboardPos currntPos;

};

