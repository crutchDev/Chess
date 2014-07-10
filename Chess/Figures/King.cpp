
#include "../chessInclude.h"

void King::calcNewAllowedMoves() {
	allowedMoves.clear();
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			ChessboardPos pos(currntPos.letter + i, currntPos.number + j);
			if ( !(pos.isImagine() || isAlly(pos) )) 
				allowedMoves.insert(pos);
		}
	}
}

short King::hashCode() {
	return (short) ( KING_TYPE << 8) | clr;
}

std::string King::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "K";
}

bool King::isAttacked() {
	// TODO
	return false;
}

