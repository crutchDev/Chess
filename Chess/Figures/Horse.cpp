
#include "../chessInclude.h"

short Horse::hashCode() {
	return (short) ( HORSE_TYPE << 8) | clr;
}

void Horse::calcNewAllowedMoves() {
	allowedMoves.clear();
	int num = currntPos.number, letter = currntPos.letter;
	for (int i = -2; i <= 2; i++){
		if (i == 0) continue;
		for (int j = -2; j <= 2; j++){
			if (j == 0) continue;
			if (abs(i) == abs(j)) continue;
			ChessboardPos pos(letter + i, num + j);
			if ( !pos.isImagine() )
				if ( isAlly(pos) )
					(*board)[pos]->support = true;
				else
					allowedMoves.insert(pos);
		}
	}
}

std::string Horse::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "H";
}

