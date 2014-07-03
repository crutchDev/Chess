
/// purpose : 

#include "chessInclude.h"

Figure::~Figure(void) {

}

string Figure::colorSchemeRep() const {
	return (clr == WHITE) ? ( "W" ) : ( "B" );
}

void Figure::move(ChessboardPos& pos) {
	(*board)[pos] = this; 
	(*board)[currntPos] = nullptr; 
	currntPos = pos;
	//calcNewAllowedMoves();
}

bool Figure::canMove(ChessboardPos& pos) const {
	return binary_search(allowedMoves.begin(),allowedMoves.end(),pos);
}