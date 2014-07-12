

#ifndef QUEEN_H
#define QUEEN_H

#include "../chessInclude.h"
#include "Bishop.hpp"
#include "Rook.hpp"

class Queen : public virtual Rook, public virtual Bishop {
public:
	Queen(Chessboard* b, ::Color c, ChessboardPos pos) : Rook(b, c, pos),Bishop(b, c, pos),Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();
};

#endif