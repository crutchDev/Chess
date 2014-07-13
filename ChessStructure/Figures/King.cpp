
#include "../chessInclude.h"

#include <iostream>

void King::calcNewAllowedMoves() {
	allowedMoves.clear();
	collectEnemiesPosCoverage();	
	checkCastling();
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
			enemiesPosCoverage.insert((*iter));
		}
	} , ( clr == WHITE ) ? ( BLACK ) : ( WHITE ) );
}

void King::move(ChessboardPos& pos) {
	if ( moved == false 
			&& pos.number == currntPos.number 
			&& abs(pos.letter - currntPos.letter) == 2) {
		if (pos.letter - currntPos.letter == 2) {
			//castling with rook at H
			Rook* ARook = dynamic_cast<Rook*>((*board)[ChessboardPos(H, currntPos.number)]);
			ARook->move(ChessboardPos(F, pos.number));
			Figure::move(pos);
		} else { 
			if (pos.letter - currntPos.letter == -2) {
				//castling with rook at A
				Rook* ARook = dynamic_cast<Rook*>((*board)[ChessboardPos(A, currntPos.number)]);
				ARook->move(ChessboardPos(D, pos.number));
				Figure::move(pos);
			}
		}
		moved = true;
	} else {
			Figure::move(pos);
	}
}

void King::checkCastling() {
	if (moved) return;
	//castling with rook at A
	Figure* fig = (*board)[ChessboardPos(A, currntPos.number)];
	Rook* rook = dynamic_cast<Rook*>(fig);
	if ( rook != nullptr ) {
		//if rook didn't move, and other positions are empty
		if (!rook->isMoved() 
			&& board->isFreePos(ChessboardPos(B, currntPos.number))
			&& board->isFreePos(ChessboardPos(C, currntPos.number))
			&& board->isFreePos(ChessboardPos(D, currntPos.number)))
		{
			allowedMoves.insert(ChessboardPos(C, currntPos.number));
		}
	}

	//castling with rook at H
	rook = dynamic_cast<Rook*>((*board)[ChessboardPos(H, currntPos.number)]);
	if ( rook != nullptr ) {
		//if rook didn't move, and other positions are empty
		if (!rook->isMoved()
			&& board->isFreePos(ChessboardPos(F, currntPos.number))
			&& board->isFreePos(ChessboardPos(G, currntPos.number)))
		{
			allowedMoves.insert(ChessboardPos(G, currntPos.number));
		}
	}
	
}

