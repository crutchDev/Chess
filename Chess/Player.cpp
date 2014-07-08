
/// purpose : 


#include "chessInclude.h"

#include <sstream>
#include <iostream>
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

	board->putFigureToPos(storeFigure(new Rook(board, team, ChessboardPos(corner.letter + ROOK_SYMMETRIC_SHIFT, corner.number))));
	board->putFigureToPos(storeFigure(new Rook(board, team, ChessboardPos(corner.letter + MAX_INDEX - ROOK_SYMMETRIC_SHIFT, corner.number))));

	board->putFigureToPos(storeFigure(new Horse(board, team, ChessboardPos(corner.letter + HORSE_SYMETRIC_SHIFT, corner.number))));
	board->putFigureToPos(storeFigure(new Horse(board, team, ChessboardPos(corner.letter + MAX_INDEX - HORSE_SYMETRIC_SHIFT, corner.number))));

	board->putFigureToPos(storeFigure(new Bishop(board, team, ChessboardPos(corner.letter + BISHOP_SYMMETRIC_SHIFT, corner.number))));
	board->putFigureToPos(storeFigure(new Bishop(board, team, ChessboardPos(corner.letter + MAX_INDEX - BISHOP_SYMMETRIC_SHIFT, corner.number))));

	board->putFigureToPos(storeFigure(new Queen(board, team, ChessboardPos(corner.letter + QUEEN_RELATIVE_LEFT_CORNER_SHIFT, corner.number))));
	board->putFigureToPos(storeFigure(new King(board, team, ChessboardPos(corner.letter + KING_RELATIVE_LEFT_CORNER_SHIFT, corner.number))));

	for ( int i = 0 ; i <= MAX_INDEX ; i++) {
		board->putFigureToPos(storeFigure(new Pawn(board, team, ChessboardPos(CharCoord(i), pawnNumbCoord))));
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
	
	board->foreach([](Figure* f) -> void {
		std::cout << f->posWhereLocated();
		f->calcNewAllowedMoves();
	}, team);

	movFigure = communicator->selectFigure(figures);	
	newPos = communicator->selectPosToMove(movFigure->getAllowedMove());
	cout << movFigure->posWhereLocated() << endl;
	cout << newPos << endl;
	movFigure->move(newPos);
	cout << "moved\n";
	board->outBoard(cout);

}

Player::~Player() {
	for_each(figures.begin(),figures.end(),[] (Figure* fig)->void {
		delete fig;
	});
}






