
#ifndef ROOK_H
#define ROOK_H
#include "../chessInclude.h"

class Rook : public virtual Figure {
public:
	Rook(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();

protected:

	void addVerticalHorizontal();

private:
	void calcDirection(int from,int direction,int to,bool isHorizontal,bool isVertical);
};

#endif