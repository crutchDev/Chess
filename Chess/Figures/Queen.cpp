
#include "../chessInclude.h"

void Queen::calcNewAllowedMoves() {
	allowedMoves.clear();
	addVerticalHorizontal();
	addDiagonals();
}

short Queen::hashCode() {
	return (short) ( QUEEN_TYPE << 8) | clr;
}

std::string Queen::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "Q";
}

