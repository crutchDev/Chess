
#include "../chessInclude.h"

void Pawn::checkVertical(int doubleStepNumber,int verticalDirecion) {
	ChessboardPos pos;
	if ( board->isFreePos(pos = ChessboardPos(currntPos.letter,currntPos.number + verticalDirecion))) {
		allowedMoves.insert(pos);			
		if ( currntPos.number == doubleStepNumber 
			&& board->isFreePos(pos = ChessboardPos(currntPos.letter,currntPos.number + 2*verticalDirecion))) 
		{
			allowedMoves.insert(pos);
		}
	}
}

void Pawn::checkDiagonal(int verticalDirection,int horizontalDirection) {
	ChessboardPos pos(currntPos.letter + horizontalDirection, currntPos.number + verticalDirection);
	if ( !(pos.isImagine() ) ) {
		if ( board->isFreePos(pos) )
			coveragedPos.insert(pos);
		else
			if ( isEnemy(pos) ) {
				coveragedPos.insert(pos);
				allowedMoves.insert(pos);
			} else 
				(*board)[pos]->support = true;
	}
}

short Pawn::hashCode() {
	return (short) ( PAWN_TYPE << 8) | clr;
}

std::string Pawn::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "P";
}
