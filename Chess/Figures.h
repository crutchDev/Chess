
#ifndef FIGURES_H
#define FIGURES_H

#include "chessInclude.h"

class King : public Figure {
public :
	King(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	bool isAttacked() {
		// TODO
		return false;
	}


	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "K";
	}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		int num = currntPos.number, letter = currntPos.letter;
		for (int i = -1; i <= 1; i++){
			for (int j = -1; j <= 1; j++)
				addCell(letter + i, num + j);
		}

	}

	virtual short hashCode() {
		return (short) ( KING_TYPE << 8) | clr;
	}

};


class Pawn : public Figure {
public:
	Pawn(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "P";
	}

	virtual short hashCode() {
		return (short) ( PAWN_TYPE << 8) | clr;
	}

	void calcNewAllowedMoves() { }
	
protected:
	void checkDiagonal(int verticalDirection,int horizontalDirection) {
		ChessboardPos pos(currntPos.letter + horizontalDirection, currntPos.number + verticalDirection);
		if ( !pos.isImagine() && this->isEnemy(pos) ) {
			allowedMoves.insert(pos);
		}
	}

	void checkVertical(int doubleStepNumber,int verticalDirecion) {
			ChessboardPos pos;
			if ( !isAlly(pos = ChessboardPos(currntPos.letter,currntPos.number + verticalDirecion))) {
			allowedMoves.insert(pos);			
			if ( currntPos.number == doubleStepNumber 
				 && !isAlly(pos = ChessboardPos(currntPos.letter,currntPos.number + 2*verticalDirecion))) 
			{
				allowedMoves.insert(pos);
			}
		} 
	}

};

class WhitePawn : public Pawn {
#define DOUBLE_STEP_WHITE_POS 1
public:
	WhitePawn(Chessboard* b, ChessboardPos pos) : Pawn(b,WHITE,pos) {}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		checkVertical(DOUBLE_STEP_WHITE_POS,1);
		checkDiagonal(1 ,-1);
		checkDiagonal(1 , 1);
	}
};

class BlackPawn : public Pawn {
#define DOUBLE_STEP_BLACK_POS 6
public:
	BlackPawn(Chessboard* b, ChessboardPos pos) : Pawn(b,BLACK,pos) {}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		checkVertical(DOUBLE_STEP_BLACK_POS,-1);
		checkDiagonal(-1 ,-1);
		checkDiagonal(-1 , 1);
	}
};

class Rook : public Figure {
public:
	Rook(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	
	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "R";
	}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		if ( currntPos.number != MAX_INDEX) {
			for ( auto vertical = currntPos.number + 1 ; vertical <= MAX_INDEX ; vertical++ ) {
				ChessboardPos pos(currntPos.letter,vertical);
				if ( (*board)[pos] == nullptr  ) 
					allowedMoves.insert(pos); 
				else {
					if ( this->isEnemy(pos) )
						allowedMoves.insert(pos); 
					break;
				}
			}
		}

		if ( currntPos.number != 0) {
			for ( auto vertical = currntPos.number - 1; vertical >= 0 ; vertical-- ) {
				ChessboardPos pos(currntPos.letter,vertical);
				if ( (*board)[pos] == nullptr  ) 
					allowedMoves.insert(pos); 
				else {
					if ( this->isEnemy(pos) )
						allowedMoves.insert(pos); 
					break;
				}
			}
		}

		if ( currntPos.letter != MAX_INDEX) {
			for ( int horizontal = currntPos.letter + 1; horizontal <= MAX_INDEX  ; horizontal++ ) {
				ChessboardPos pos(horizontal,currntPos.number);
				if ( (*board)[pos] == nullptr  ) 
					allowedMoves.insert(pos); 
				else {
					if ( this->isEnemy(pos) )
						allowedMoves.insert(pos); 
					break;
				}
			}
		}

		if ( currntPos.letter != 0 ) {
			for ( int horizontal = currntPos.letter - 1 ; horizontal >= 0 ; horizontal-- ) {
				ChessboardPos pos(horizontal,currntPos.number);
				if ( (*board)[pos] == nullptr  ) 
					allowedMoves.insert(pos); 
				else {
					if ( this->isEnemy(pos) )
						allowedMoves.insert(pos); 
					break;
				}
			}
		}

	}

	virtual short hashCode() {
		return (short) ( ROOK_TYPE << 8) | clr;
	}
};

class Queen : public Figure {
public:
	Queen(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "Q";
	}


	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		int num = currntPos.number, letter = currntPos.letter;
		//straight lines
		for (int i = 0; i <= MAX_INDEX; i++){
			addCell(letter, i);
			addCell(i, num);
			addCell(letter - i, num - i);
			addCell(letter + i, num + i);
			addCell(letter + i, num - i);
			addCell(letter - i, num + i);
		}
	}

	virtual short hashCode() {
		return (short) ( QUEEN_TYPE << 8) | clr;
	}
};

class Bishop : public Figure {
public:
	Bishop(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "B";
	}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		int num = currntPos.number, letter = currntPos.letter;
		//straight lines
		for (int i = 0; i <= MAX_INDEX; i++){
			addCell(letter - i, num - i);
			addCell(letter + i, num + i);
			addCell(letter + i, num - i);
			addCell(letter - i, num + i);
		}
	}

	virtual short hashCode() {
		return (short) ( BISHOP_TYPE << 8) | clr;
	}

};

class Horse : public Figure{
public:
	Horse(Chessboard* b, ::Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "H";
	}

	virtual void calcNewAllowedMoves() {
		allowedMoves.clear();
		int num = currntPos.number, letter = currntPos.letter;
		for (int i = -2; i <= 2; i++){
			if (i == 0) continue;
			for (int j = -2; j <= 2; j++){
				if (j == 0) continue;
				if (abs(i) == abs(j)) continue;
				addCell(letter + i, num + j);
			}
		}
	}

	virtual short hashCode() {
		return (short) ( HORSE_TYPE << 8) | clr;
	}
};
 
#endif