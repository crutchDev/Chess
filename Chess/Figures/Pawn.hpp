

#ifndef PAWN_H
#define PAWN_H

#include "../chessInclude.h"

class Pawn : public Figure {
public:
	Pawn(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;
	virtual short hashCode();
	void calcNewAllowedMoves() {
		allowedMoves.clear();
		coveragedPos.clear();
		checkVertical(getDoubleStepPos(),getMoveDirection());
		checkDiagonal(getMoveDirection() ,-1);
		checkDiagonal(getMoveDirection() , 1);
	}
	virtual set< ChessboardPos >& getCoveragedPos() { return coveragedPos; }


protected:
	set < ChessboardPos >  coveragedPos;

	void checkDiagonal(int verticalDirection,int horizontalDirection);
	void checkVertical(int doubleStepNumber,int verticalDirecion);
	virtual int getDoubleStepPos() { return 0; }
	virtual int getMoveDirection() { return 0; }
};

class WhitePawn : public Pawn {
#define DOUBLE_STEP_WHITE_POS 1
#define WHITE_DIRECTION 1
public:
	WhitePawn(Chessboard* b, ChessboardPos pos) : Pawn(b,WHITE,pos) {}

protected:
	virtual int getDoubleStepPos() { return DOUBLE_STEP_WHITE_POS; }
	virtual int getMoveDirection() { return WHITE_DIRECTION; }

};

class BlackPawn : public Pawn {
#define DOUBLE_STEP_BLACK_POS 6
#define BLACK_DIRECTION -1
public:
	BlackPawn(Chessboard* b, ChessboardPos pos) : Pawn(b,BLACK,pos) {}

protected:
	virtual int getDoubleStepPos() { return DOUBLE_STEP_BLACK_POS; }
	virtual int getMoveDirection() { return BLACK_DIRECTION; }

};

#endif