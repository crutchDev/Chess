


#pragma once

#include "chessInclude.h"


struct ChessboardPos {

	ChessboardPos(CharCoord letter,int number);
	ChessboardPos(int letterNumb, int numb );
	ChessboardPos () : letter(A),number(-1) { }
	ChessboardPos(const ChessboardPos& cp) : letter(cp.letter),number(cp.number) { } 

	ChessboardPos& operator=(const ChessboardPos& cp);
	
	bool operator==(const ChessboardPos& pos) const;
	bool operator<(const ChessboardPos& pos) const;
	bool operator>(const ChessboardPos& pos) const ;
	bool isImagine() ;

	friend ostream& operator<<(ostream&,ChessboardPos&);	
	friend istream& operator>>(istream&,ChessboardPos&);


	// let (0,0) be low left corner
	CharCoord letter;	
	int number;
};

class Chessboard {
public:
	Chessboard();
	~Chessboard();

	Figure*& Chessboard::operator[](ChessboardPos pos);
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
