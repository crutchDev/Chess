

#ifndef PAWN_H
#define PAWN_H

#include "../chessInclude.h"

class Pawn : public Figure {
public:
	Pawn(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;
	virtual short hashCode();
	void calcNewAllowedMoves() { }
	
protected:

	void checkDiagonal(int verticalDirection,int horizontalDirection);
	void checkVertical(int doubleStepNumber,int verticalDirecion);
};

class WhitePawn : public Pawn {
#define DOUBLE_STEP_WHITE_POS 1
public:
	WhitePawn(Chessboard* b, ChessboardPos pos) : Pawn(b,WHITE,pos) {}

	virtual void calcNewAllowedMoves();
};

class BlackPawn : public Pawn {
#define DOUBLE_STEP_BLACK_POS 6
public:
	BlackPawn(Chessboard* b, ChessboardPos pos) : Pawn(b,BLACK,pos) {}

	virtual void calcNewAllowedMoves();
};

#endif