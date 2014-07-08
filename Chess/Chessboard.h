


#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessInclude.h"
#include <functional>

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
	void makeImagine() { number = -1; }

	friend ostream& operator<<(ostream&,ChessboardPos&);	
	friend istream& operator>>(istream&,ChessboardPos&);


	// let (0,0) be low left corner
	CharCoord letter;	
	int number;
};

class Chessboard {
public:
	class Iterator {
	public:
		void operator++(int) {
			this->nextFigure();
		}

		Figure* operator*() {
			return (*iterable)[currentPos];
		}
		
		bool hasMoreFigures( ) {
			return !currentPos.isImagine() ;
		}
		
		void nextFigure() {
			iterFunc();
		}

		const ChessboardPos* getPos() const {
			return &currentPos;
		}

		void reset() { currentPos = startPos; }
	private:
		friend class Chessboard;

#define GEN_ITER_FUNC(startLeter,endLeter,numberInc,endNumber)	if ( this->currentPos.letter != endLeter ) this->currentPos.letter = CharCoord(this->currentPos.letter + numberInc); \
																else { \
																if ( this->currentPos.number != endNumber) { \
																	this->currentPos.letter = startLeter; \
																	this->currentPos.number += numberInc; } else \
																if ( this->currentPos.isImagine() ) throw logic_error("There is no more elements.");  \
																else this->currentPos.makeImagine(); } 		
		
		Iterator(Chessboard* board,bool isReverse = false) : iterable(board) {
			if ( isReverse ) {
				currentPos = startPos = ChessboardPos(H,7);
				iterFunc = [&]()->void { GEN_ITER_FUNC(H,A,-1,0) };
			} else {
				currentPos = startPos = ChessboardPos(A,0);
				iterFunc = [&]()->void { GEN_ITER_FUNC(A,H,1,MAX_INDEX) };
			}
		}

		ChessboardPos startPos;
		ChessboardPos currentPos;
		function<void (void) > iterFunc; 
		Chessboard* iterable;
	};

	Chessboard();
	~Chessboard();

	Figure*& Chessboard::operator[](ChessboardPos pos);
	void putFigureToPos(Figure* figr);
	void foreach(function<void (Figure*)> func);
	void foreach(function<void(Figure*)> func, ::Color c);

	/*void foreachWhite(function<void (Figure*)> func);
	void foreachBlack(function<void (Figure*)> func);*/

	Iterator getIterator() {
		return Iterator(this);
	}
	Iterator getReverseIterator() {
		return Iterator(this,true);
	}


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
#endif