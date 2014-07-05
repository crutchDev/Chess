
/// purpose : 



#ifndef FIGURE_H
#define FIGURE_H

#include "chessInclude.h"


class Figure {
public:

	Figure(Chessboard* b, Color c, ChessboardPos pos) : board(b), clr(c),currntPos(pos) { };
	virtual ~Figure();

	bool canMove(ChessboardPos& pos) const ;
	set< ChessboardPos > getAllowedMove() { return allowedMoves; }
	Color getColor() { return clr; }
	Chessboard* boardWhereLocated() const { return board; }
	ChessboardPos posWhereLocated() const { return currntPos; }
	void setLocation(ChessboardPos newPos) { currntPos = newPos; } 
	void move(ChessboardPos& pos);

	// test only 
	// first letter it is color symbol W - white , B - black 
	// second letter it is figure symbol 
	// K - king  ; P - pawn   ; R - rook 
	// Q - queen ; B - bishop ; H - horse 
	virtual string getStringSchematicRep() const = 0;

protected:
	string colorSchemeRep() const ;
	void addCell(int letter, int num);
	bool isGoodCell(ChessboardPos pos);

	virtual void calcNewAllowedMoves() = 0;
	
	Color clr;
	Chessboard* board;
	ChessboardPos currntPos;
	set < ChessboardPos > allowedMoves; 

};

#endif