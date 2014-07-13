

#ifndef QUEEN_H
#define QUEEN_H

#include "../chessInclude.h"
#include "Bishop.hpp"
#include "Rook.hpp"

class Queen : public virtual Bishop, public virtual Rook {
public:
	Queen(Chessboard* b, ::Color c, ChessboardPos pos) : Rook(b, c, pos),Bishop(b, c, pos),Figure(b, c, pos) {
		moved = true; 
	}

	virtual string getStringSchematicRep() const;
	virtual void calcNewAllowedMoves();
	virtual short hashCode();
	virtual void move(ChessboardPos& pos) { Figure::move(pos); }

};

#endif