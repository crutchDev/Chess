
#include "../chessInclude.h"

void Pawn::checkVertical(int doubleStepNumber,int verticalDirecion) {
	ChessboardPos pos;
	if ( !isAlly(pos = ChessboardPos(currntPos.letter,currntPos.number + verticalDirecion))) {
		allowedMoves.insert(pos);			
		if ( currntPos.number == doubleStepNumber 
			&& !isAlly(pos = ChessboardPos(currntPos.letter,currntPos.number + 2*verticalDirecion))) 
		{
			allowedMoves.insert(pos);
		}
	}
}

void Pawn::checkDiagonal(int verticalDirection,int horizontalDirection) {
	ChessboardPos pos(currntPos.letter + horizontalDirection, currntPos.number + verticalDirection);
	if ( !pos.isImagine() && this->isEnemy(pos) ) {
		allowedMoves.insert(pos);
	}
}

short Pawn::hashCode() {
	return (short) ( PAWN_TYPE << 8) | clr;
}

std::string Pawn::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "P";
}


void WhitePawn::calcNewAllowedMoves() {
	allowedMoves.clear();
	checkVertical(DOUBLE_STEP_WHITE_POS,1);
	checkDiagonal(1 ,-1);
	checkDiagonal(1 , 1);
}

void BlackPawn::calcNewAllowedMoves() {
	allowedMoves.clear();
	checkVertical(DOUBLE_STEP_BLACK_POS,-1);
	checkDiagonal(-1 ,-1);
	checkDiagonal(-1 , 1);
}
