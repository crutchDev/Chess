
#include "../chessInclude.h"

#include <iostream>

void King::calcNewAllowedMoves() {
	allowedMoves.clear();
	collectEnemiesPosCoverage();	
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			ChessboardPos pos(currntPos.letter + i, currntPos.number + j);
			if ( !(pos.isImagine() || binary_search(enemiesPosCoverage.begin(),enemiesPosCoverage.end(),pos)) ) {
				if ( isAlly(pos) ) {
					(*board)[pos]->support = true;
					continue;
				}
				if ( board->isFreePos(pos) || isEnemy(pos) && !(*board)[pos]->isSupported()  )
					allowedMoves.insert(pos);
			}
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
	return attacked;
}

void King::checkDangerous() {
	attacked = false;
	collectEnemiesPosCoverage(true);
	if ( binary_search(enemiesPosCoverage.begin(),enemiesPosCoverage.end(),currntPos) )
		attacked = true;
}

void King::collectEnemiesPosCoverage(bool recalcEnemyMove ) {
	enemiesPosCoverage.clear();
	board->foreach([&] (Figure* fig)->void {
		if ( recalcEnemyMove ) fig->calcNewAllowedMoves();
		for ( auto iter = fig->getCoveragedPos().begin(); iter != fig->getCoveragedPos().end() ; iter++ ) {
			cout <<  (*iter) << endl;
			enemiesPosCoverage.insert((*iter));
		}
	} , ( clr == WHITE ) ? ( BLACK ) : ( WHITE ) );
}

