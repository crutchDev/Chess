
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

bool Figure::goodCell(ChessboardPos pos) {
	if (pos.letter > MAX_INDEX || pos.number > MAX_INDEX){
		return false;
	}
	if ((*board)[pos] == nullptr){
		return true;
	}
	if ((*board)[pos]->getColor() != this->getColor()){
		return true;
	}
	return false;
}

void Figure::AddCell(int letter, int num)
{
	if (goodCell(ChessboardPos(letter, num)))
		allowedMoves.emplace(ChessboardPos(letter, num));
}

bool Figure::canMove(ChessboardPos& pos) const {
	return binary_search(allowedMoves.begin(),allowedMoves.end(),pos);
}