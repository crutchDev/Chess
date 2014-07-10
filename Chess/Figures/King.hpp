
#ifndef KING_H
#define KING_H
#include "../chessInclude.h"

class King : public Figure {
public :
	King(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	bool isAttacked();
	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();

};

#endif 