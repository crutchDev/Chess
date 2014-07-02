
#include "chessInclude.h"

Chessboard::Chessboard(void) {
	for ( auto i = 0 ; i < 8  ; i++ ) 
		for ( auto j = 0 ; j < 8 ; i++ )
			board[i][j] = nullptr;
}


Chessboard::~Chessboard(void) {
	for ( auto i = 0 ; i < 8  ; i++ ) 
		for ( auto j = 0 ; j < 8 ; i++ )
			delete board[i][j];
}

void Chessboard::putFigureToPos(ChessboardPos pos,Figure* figr) {
	board[pos.letter][pos.number] = figr;
	figr->changeLocation(pos);
}
