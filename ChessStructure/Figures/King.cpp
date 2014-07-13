
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
	if (!moved) {
		tryCastling(pos, A);
		tryCastling(pos, H);
	}
	Figure::move(pos);
	moved = true;
}

//checks if king can castle in any direction
void King::checkCastling() {
	if (moved) return;
	checkCastlingWith(A);

	checkCastlingWith(H);
	
}
//checks if pos - is position to castle in direction, and moves rook to right position
void King::tryCastling(ChessboardPos & pos, CharCoord rookPos)
{
	if (pos.number != currntPos.number) return;

	int direction = (rookPos > currntPos.letter) ? +1 : -1;
	if (pos.letter - currntPos.letter == 2 * direction) {
		Rook* rook = dynamic_cast<Rook*>((*board)[ChessboardPos(rookPos, currntPos.number)]);
		if (rook != nullptr && !rook->isMoved())
			rook->move(ChessboardPos(currntPos.letter + direction, pos.number));
	}
}
//checks if king can castle with rook at letter
void King::checkCastlingWith(CharCoord ch) {
	if (ch != A && ch != H || isAttacked()) return;
	
	Figure* fig = (*board)[ChessboardPos(ch, currntPos.number)];
	Rook* rook = dynamic_cast<Rook*>(fig);
	int direction = (currntPos.letter < ch) ? +1 : -1;
	if (rook != nullptr) {
		//if rook didn't move, and other positions are empty
		
		if (rook->isMoved()) return;
		for (auto i = ChessboardPos(currntPos.letter + direction,currntPos.number); 
			i.letter > 0 && i.letter < MAX_INDEX; 
			i.letter = CharCoord(i.letter + direction)) 
		{
			if (!board->isFreePos(i)) return;
		}
		//if position is not under attack
		if (!binary_search(enemiesPosCoverage.begin(), enemiesPosCoverage.end(),
			ChessboardPos(currntPos.letter + 2 * direction, currntPos.number))) {
		
			allowedMoves.insert(ChessboardPos(currntPos.letter + 2 * direction, currntPos.number));
		}
	}
	
}

