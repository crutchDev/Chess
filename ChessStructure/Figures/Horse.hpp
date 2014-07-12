
#ifndef HORSE_H
#define HORSE_H
#include "../chessInclude.h"

class Horse : public Figure {
public:
	Horse(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;

	virtual void calcNewAllowedMoves();

	virtual short hashCode();
};

#endif