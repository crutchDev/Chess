
/// purpose : 


#include "chessInclude.h"

#include <sstream>

#define ROOK_SYMMETRIC_SHIFT 0 
#define HORSE_SYMETRIC_SHIFT 1
#define BISHOP_SYMMETRIC_SHIFT 2
#define QUEEN_RELATIVE_LEFT_CORNER_SHIFT 3
#define KING_RELATIVE_LEFT_CORNER_SHIFT 4


int Player::playerCounter = 0;

Player::Player(Color clr, Chessboard* board ,string name = "") : team(clr),board(board) {
	if ( name.length() == 0 ) 
		this->name = genStdPlayerName();
	else 
		this->name = name;
	
	if ( team == WHITE ) {
		initFigures(ChessboardPos(A,0),true);
	} else {
		initFigures(ChessboardPos(A,7),false);
	}

}

string Player::genStdPlayerName() {
	ostringstream numbConverter;
	numbConverter << playerCounter++;
	return string("player").append(numbConverter.str());
}


void Player::initFigures(ChessboardPos corner,bool direction) {
	int	pawnNumbCoord = corner.number;
	pawnNumbCoord += (direction)?(1):(-1);
		
	board->putFigureToPos( ChessboardPos(corner.letter + ROOK_SYMMETRIC_SHIFT ,corner.number) , storeFigure(new Rook(board,team)) );
	board->putFigureToPos( ChessboardPos(corner.letter + MAX_INDEX - ROOK_SYMMETRIC_SHIFT , corner.number ) , storeFigure(new Rook(board,team)) );

	board->putFigureToPos( ChessboardPos(corner.letter + HORSE_SYMETRIC_SHIFT ,corner.number), storeFigure(new Horse(board,team)) );
	board->putFigureToPos( ChessboardPos(corner.letter + MAX_INDEX - HORSE_SYMETRIC_SHIFT ,corner.number), storeFigure(new Horse(board,team)) );

	board->putFigureToPos( ChessboardPos(corner.letter + BISHOP_SYMMETRIC_SHIFT , corner.number), storeFigure(new Bishop(board,team)) );
	board->putFigureToPos( ChessboardPos(corner.letter + MAX_INDEX - BISHOP_SYMMETRIC_SHIFT ,corner.number), storeFigure(new Bishop(board,team)) );

	board->putFigureToPos( ChessboardPos(corner.letter + QUEEN_RELATIVE_LEFT_CORNER_SHIFT , corner.number), storeFigure(new Queen(board,team)) );
	board->putFigureToPos( ChessboardPos(corner.letter + KING_RELATIVE_LEFT_CORNER_SHIFT , corner.number), storeFigure(king = new King(board,team)) );

	for ( int i = 0 ; i <= MAX_INDEX ; i++) {
		board->putFigureToPos( ChessboardPos(CharCoord(i), pawnNumbCoord ), storeFigure(new Pawn(board,team)) );
	}	
}

Figure* Player::storeFigure(Figure* f) {
	figures.push_back(f);
	return f;
}

bool Player::gameOver() {
	return king->isAttacked() && king->getAllowedMove().size() == 0;
}

void Player::step(GameInterface* communicator) {
	Figure* movFigure;
	ChessboardPos newPos;

	movFigure = communicator->selectFigure(figures);	
	newPos = communicator->selectPosToMove(movFigure->getAllowedMove());
	movFigure->move(newPos);

}

Player::~Player() {

}






