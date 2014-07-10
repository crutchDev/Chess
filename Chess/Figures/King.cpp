
#include "../chessInclude.h"

void King::calcNewAllowedMoves() {
	allowedMoves.clear();
	int num = currntPos.number, letter = currntPos.letter;
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++)
			addCell(letter + i, num + j);
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

