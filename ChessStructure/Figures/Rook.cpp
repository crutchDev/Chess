

#include "../chessInclude.h"

void Rook::calcDirection(int from,int direction,int to,bool isHorizontal,bool isVertical) {
	int horizontalOffset = (isHorizontal) ? ( 1 ) : ( 0 );
	int verticalOffset = (isVertical) ? ( 1 ) : ( 0 );
	if ( from != to ) {
		function<bool (int,int) > comparator; 
		if ( to > from  ) 
			comparator = [] (int i,int j)->bool { return i <= j; };
		else 
			comparator = [] (int i,int j)->bool { return i >= j; };
		for ( int iter = direction; comparator(iter,to - from) ; iter += direction ) {
			ChessboardPos pos( currntPos.letter + horizontalOffset*iter , currntPos.number + verticalOffset*iter );
			if ( board->isFreePos(pos)  ) 
				allowedMoves.insert(pos); 
			else {
				if ( this->isEnemy(pos) )
					allowedMoves.insert(pos);
				else 
					(*board)[pos]->support = true;
				break;
			}
		}
	}
}

void Rook::addVerticalHorizontal() {
	calcDirection(currntPos.number,+1,MAX_INDEX,false,true);
	calcDirection(currntPos.number,-1,0,false,true);
	calcDirection(currntPos.letter,+1,MAX_INDEX,true,false);
	calcDirection(currntPos.letter,-1,0,true,false);
}

void Rook::calcNewAllowedMoves() {
	allowedMoves.clear();
	addVerticalHorizontal();
}

short Rook::hashCode() {
	return (short) ( ROOK_TYPE << 8) | clr;
}

std::string Rook::getStringSchematicRep() const {
	return colorSchemeRep() + "_" + "R";
}

