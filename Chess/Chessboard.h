


#pragma once

#include "chessInclude.h"


struct ChessboardPos {

	ChessboardPos(CharCoord letter,int number) : letter(letter),number(number) {
		if ( number < 0 || number > MAX_INDEX )
			throw invalid_argument("Invalid pos number.");
	}

	ChessboardPos(int letterNumb, int numb ) {
		if ( letterNumb < 0 || letterNumb > MAX_INDEX )
			throw invalid_argument("Invalid pos letter number.");
		if ( numb < 0 || numb > MAX_INDEX )
			throw invalid_argument("Invalid pos number.");
		letter = CharCoord(letterNumb);
		number = numb;
	}

	ChessboardPos(const ChessboardPos& cp) : letter(cp.letter),number(cp.number) { } 

	ChessboardPos& operator=(const ChessboardPos& cp) {
		letter = cp.letter;
		number = cp.number;
		return *this;
	}

	bool operator==(const ChessboardPos& pos) {
		return number == pos.number && letter == pos.letter;
	}

	// let (0,0) be low left corner
	CharCoord letter;	
	int number;
};

class Chessboard {
public:
	Chessboard();
	~Chessboard();

	void putFigureToPos(ChessboardPos& pos,Figure* figr);

	// for test only 
	void outBoard(ostream& o);

private:
	// first coordinate - letter 
	// second coordinate - number 
	// [0][0] it is cell A1
	// [0][1] it is cell A2
	// [1][0] it is cell B1 
	// and so on 
	vector< vector< Figure* > > board;

};
