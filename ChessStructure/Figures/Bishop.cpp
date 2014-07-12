
#include "../chessInclude.h"

void Bishop::addDiagonals() {
	calcDiagonal(1,1);
	calcDiagonal(1,-1);
	calcDiagonal(-1,1);
	calcDiagonal(-1,-1);
}

short Bishop::hashCode() {
	return (short) ( BISHOP_TYPE << 8) | clr;
}

void Bishop::calcNewAllowedMoves() {
	allowedMoves.clear();
	addDiagonals();
}

std::string Bishop::getStringSchematicRep() const{
	return colorSchemeRep() + "_" + "B";
}

void Bishop::calcDiagonal(int horizontalDirection,int verticalDirection) {
	int verticalIter = currntPos.number + verticalDirection;
	int horizontaIter = currntPos.letter + horizontalDirection;

	while ( verticalIter <= MAX_INDEX && verticalIter >= 0 && 
		horizontaIter <= MAX_INDEX && horizontaIter >= 0 ) {
			ChessboardPos pos(horizontaIter,verticalIter);
			if ( isAlly(pos)  ) {
				(*board)[pos]->support = true;
				break;
			} else {
				allowedMoves.insert(pos);
				if ( isEnemy(pos) )
					break;
			}
			verticalIter += verticalDirection;
			horizontaIter += horizontalDirection;
	}
}
