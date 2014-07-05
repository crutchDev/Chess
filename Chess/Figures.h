
#pragma once 

#include "chessInclude.h"

class King : public Figure {
public :
	King(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	bool isAttacked() {
		// TODO
		return false;
	}


	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "K";
	}

	virtual void calcNewAllowedMoves() {
			int num = currntPos.number, letter = currntPos.letter;
			for (int i = -1; i <= 1; i++){
				for (int j = -1; j <= 1; j++)
					addCell(letter + i, num + j);
			}

	}



};


class Pawn : public Figure {
public:
	Pawn(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	void Transform() {
		//TODO
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "P";
	}


	virtual void calcNewAllowedMoves() {
		int num = currntPos.number, letter = currntPos.letter;
		if (num == 2 && colorSchemeRep() == "W" || num == MAX_INDEX - 1 && colorSchemeRep() == "B"){
			allowedMoves.emplace((int)currntPos.letter, currntPos.number + 2);
		}
		addCell(letter, num + 1);

		if (letter > 0 && num < MAX_INDEX){
			ChessboardPos pos(letter - 1, num + 1);
			if ((*board)[pos]){
				if ((*board)[pos]->getColor() != this->getColor()){
					allowedMoves.emplace(pos);
				}
			}
		}
		if (letter < MAX_INDEX && num < MAX_INDEX){
			ChessboardPos pos(letter + 1, num + 1);
			if ((*board)[pos]){
				if ((*board)[pos]->getColor() != this->getColor()){
					allowedMoves.emplace(pos);
				}
			}
		}
	}

};

class Rook : public Figure {
public:
	Rook(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	
	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "R";
	}


	virtual void calcNewAllowedMoves() {
		int num = currntPos.number, letter = currntPos.letter;
		for (int i = 0; i <= MAX_INDEX; i++){
			addCell(letter,i);
			addCell(i, num);
		}
	}
};

class Queen : public Figure {
public:
	Queen(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "Q";
	}


	virtual void calcNewAllowedMoves() {
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
};

class Bishop : public Figure {
public:
	Bishop(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "B";
	}

	virtual void calcNewAllowedMoves() {
		int num = currntPos.number, letter = currntPos.letter;
		//straight lines
		for (int i = 0; i <= MAX_INDEX; i++){
			addCell(letter - i, num - i);
			addCell(letter + i, num + i);
			addCell(letter + i, num - i);
			addCell(letter - i, num + i);
		}
	}

};

class Horse : public Figure{
public:
	Horse(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "H";
	}

	virtual void calcNewAllowedMoves() {
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
};
 