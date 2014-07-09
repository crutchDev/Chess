
/// purpose : 



#ifndef FIGURE_H
#define FIGURE_H

#include "chessInclude.h"


class Figure {
public:

	Figure(Chessboard* b, ::Color c, ChessboardPos pos) : board(b), clr(c),currntPos(pos),dead(false) { };
	virtual ~Figure();

	bool canMove(ChessboardPos& pos) const ;
	bool canMove() const { return allowedMoves.size() != 0; }
	set< ChessboardPos > getAllowedMove() { return allowedMoves; }
	::Color getColor() { return clr; }
	Chessboard* boardWhereLocated() const { return board; }
	ChessboardPos posWhereLocated() const { return currntPos; }
	void setLocation(ChessboardPos& newPos) { currntPos = newPos; } 
	void move(ChessboardPos& pos);
	bool isDead() { return dead; }
	bool isEnemy(ChessboardPos& pos) { 
		return (*board)[pos] != nullptr && (*board)[pos]->clr != this->clr;
	}
	bool isAlly(ChessboardPos& pos) {
		return (*board)[pos] != nullptr && (*board)[pos]->clr == this->clr;
	}


	// test only 
	// first letter it is color symbol W - white , B - black 
	// second letter it is figure symbol 
	// K - king  ; P - pawn   ; R - rook 
	// Q - queen ; B - bishop ; H - horse 
	virtual string getStringSchematicRep() const = 0;
	virtual void calcNewAllowedMoves() = 0;

	// hash code is two bytes 
	// first is color 00001111 - white 11110000 - black
	// second is type 
#define HORSE_TYPE	0x01
#define BISHOP_TYPE 0x02
#define QUEEN_TYPE  0x03
#define KING_TYPE	0x04
#define PAWN_TYPE   0x05
#define ROOK_TYPE   0x06
	virtual short hashCode() = 0;

	template <typename T> static short figureHashCode(::Color clr) {
		return T(nullptr,clr,ChessboardPos()).hashCode();
	}

protected:
	string colorSchemeRep() const ;
	void addCell(int letter, int num);
	bool isGoodCell(ChessboardPos pos);

	
	::Color clr;
	Chessboard* board;
	ChessboardPos currntPos;
	set < ChessboardPos > allowedMoves; 
	bool dead;
};

#endif