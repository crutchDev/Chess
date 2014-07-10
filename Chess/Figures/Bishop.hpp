

#ifndef BISHOP_H
#define BISHOP_H

#include "../chessInclude.h"

class Bishop : public virtual Figure {
public:
	Bishop(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();

protected:

	void addDiagonals();
};
#endif