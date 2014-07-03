
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
	calcNewAllowedMoves();
}

bool Figure::isGoodCell(ChessboardPos pos) {
	if ( !(pos.letter > MAX_INDEX || pos.number > MAX_INDEX || pos.number < 0) ) 
		if ((*board)[pos] == nullptr || (*board)[pos]->getColor() != this->getColor() ) {
			return true;
		}
	return false;
}

void Figure::addCell(int letter, int num) {
	if (isGoodCell(ChessboardPos(letter, num)))
		allowedMoves.emplace(ChessboardPos(letter, num));
}

bool Figure::canMove(ChessboardPos& pos) const {
	return binary_search(allowedMoves.begin(),allowedMoves.end(),pos);
}