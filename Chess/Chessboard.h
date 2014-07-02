


#pragma once

#include "chessInclude.h"


struct ChessboardPos {

	ChessboardPos(CharCoord letter,int number) : letter(letter),number(number) {
		if ( number < 0 || number > 7 )
			throw invalid_argument("Invalid pos number.");
	}

	ChessboardPos(int letterNumb, int numb ) {
		if ( letterNumb < 0 || letterNumb > 7 )
			throw invalid_argument("Invalid pos letter number.");
		ChessboardPos(CharCoord(letterNumb),numb);
	}

	// let (0,0) be low left corner
	CharCoord letter;	
	int number;
};

class Chessboard {
public:
	Chessboard();
	~Chessboard();

	void putFigureToPos(ChessboardPos pos,Figure* figr);

private:
	// first coordinate - letter 
	// second coordinate - number 
	// [0][0] it is cell A1
	// [0][1] it is cell A2
	// [1][0] it is cell B1 
	// and so on 
	vector< vector< Figure* > > board;

};
