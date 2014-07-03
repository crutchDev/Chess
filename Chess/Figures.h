
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

	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			for (int i = -1; i <= 1; i++){
				for (int j = -1; j <= 1; j++)
					AddCell(letter + i, num + j);
			}
			
		}
		catch (...)
		{
			//do something
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


	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			if (num == 2 && colorSchemeRep() == "W" || num == MAX_INDEX - 1 && colorSchemeRep() == "B"){
				allowedMoves.emplace((int)currntPos.letter, currntPos.number + 2);
			}
			for (int i = -1; i <= 1; i++)
				AddCell(letter + i, num);
		}
		catch (...)
		{
			//do something
		}
	}

};

class Rook : public Figure {
public:
	Rook(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}



	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "R";
	}


	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			for (int i = 0; i <= MAX_INDEX; i++){
					AddCell(letter,i);
					AddCell(i, num);
			}

		}
		catch (...)
		{
			//do something
		}
	}
};

class Queen : public Figure {
public:
	Queen(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "Q";
	}


	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			//straight lines
			for (int i = 0; i <= MAX_INDEX; i++){
				AddCell(letter, i);
				AddCell(i, num);
				AddCell(letter - i, num - i);
				AddCell(letter + i, num + i);
				AddCell(letter + i, num - i);
				AddCell(letter - i, num + i);
			}

		}
		catch (...)
		{
			//do something
		}
	}
};

class Bishop : public Figure{

public:
	Bishop(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "B";
	}

	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			//straight lines
			for (int i = 0; i <= MAX_INDEX; i++){
				AddCell(letter - i, num - i);
				AddCell(letter + i, num + i);
				AddCell(letter + i, num - i);
				AddCell(letter - i, num + i);
			}

		}
		catch (...)
		{
			//do something
		}
	}

};

class Horse : public Figure{
public:
	Horse(Chessboard* b, Color c, ChessboardPos pos) : Figure(b, c, pos) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "H";
	}

	virtual void calcNewAllowedMoves()
	{
		try{
			int num = currntPos.number, letter = currntPos.letter;
			for (int i = -2; i <= 2; i++){
				if (i == 0) continue;
				for (int j = -2; j <= 2; j++){
					if (j == 0) continue;
					if (abs(i) == abs(j)) continue;
					AddCell(letter + i, num + j);
				}
			}
		}
		catch (...)
		{
			//do something
		}
	}
};
 