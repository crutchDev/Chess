
/// purpose : 

#include "chessInclude.h"

Figure::~Figure(void) {

}

string Figure::colorSchemeRep() const {
	return (clr == WHITE) ? ( "W" ) : ( "B" );
}

void Figure::move(ChessboardPos& pos) {
	if ( isEnemy(pos) ) 
		(*board)[pos]->dead = true;
	(*board)[pos] = this; 
	(*board)[currntPos] = nullptr; 
	currntPos = pos;
	calcNewAllowedMoves();
}

bool Figure::canMove(ChessboardPos& pos) const {
	return binary_search(allowedMoves.begin(),allowedMoves.end(),pos);
}

bool Figure::isAlly(ChessboardPos& pos) {
	return (*board)[pos] != nullptr && (*board)[pos]->clr == this->clr;
}

bool Figure::isEnemy(ChessboardPos& pos) {
	return (*board)[pos] != nullptr && (*board)[pos]->clr != this->clr;
}
