
#include "../chessInclude.h"

void Bishop::addDiagonals() {
	int num = currntPos.number, letter = currntPos.letter;
	//straight lines
	for (int i = 0; i <= MAX_INDEX; i++){
		addCell(letter - i, num - i);
		addCell(letter + i, num + i);
		addCell(letter + i, num - i);
		addCell(letter - i, num + i);
	}
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
