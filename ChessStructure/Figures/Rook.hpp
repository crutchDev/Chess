
#ifndef ROOK_H
#define ROOK_H
#include "../chessInclude.h"

class Rook : public virtual Figure {
public:
	Rook(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos), moved(false) {}

	bool isMoved() const { return moved; }

	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();
	virtual void move(ChessboardPos& pos);
protected:
	bool moved;
	void addVerticalHorizontal();

private:

	void calcDirection(int from,int direction,int to,bool isHorizontal,bool isVertical);
};

#endif