
#include "chessInclude.h"

Chessboard::Chessboard(void) 
	: board(SIDE_SIZE,vector<Figure*>(SIDE_SIZE,nullptr)) { }


Chessboard::~Chessboard(void) {
	for ( auto i = 0 ; i <= MAX_INDEX  ; i++ ) 
		for ( auto j = 0 ; j <= MAX_INDEX ; j++ )
			delete board[i][j];
}

void Chessboard::putFigureToPos(ChessboardPos& pos,Figure* figr) {
	board[pos.letter][pos.number] = figr;
	figr->changeLocation(pos);
}

void Chessboard::outBoard(ostream& out) {
	for ( auto numberScaleIter = MAX_INDEX ; numberScaleIter >= 0 ; numberScaleIter-- ) {
		for ( auto letterScaleIter = 0 ; letterScaleIter <= MAX_INDEX ; letterScaleIter++ ) 
			if ( board[letterScaleIter][numberScaleIter] != nullptr )
				out << board[letterScaleIter][numberScaleIter]->getStringSchematicRep() << " "; 
			else 
				out << "[0]" << " "; 
		out << endl;
	}
}
