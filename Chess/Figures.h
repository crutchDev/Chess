
#pragma once 

#include "chessInclude.h"

class King : public Figure {
public :
	King(Chessboard* b, Color c) : Figure(b,c) {}

	bool isAttacked() {
		// TODO
		return false;
	}


	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "K";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

class Pawn : public Figure {
public:
	Pawn(Chessboard* b, Color c) : Figure(b,c) {}

	void Transform() {
		//TODO
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "P";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

class Rook : public Figure {
public:
	Rook(Chessboard* b, Color c) : Figure(b,c) {}



	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "R";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

class Queen : public Figure {
public:
	Queen(Chessboard* b, Color c) : Figure(b,c) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "Q";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

class Bishop : public Figure{

public:
	Bishop(Chessboard* b, Color c) : Figure(b,c) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "B";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

class Horse : public Figure{
public:
	Horse(Chessboard* b, Color c) : Figure(b,c) {}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "H";
	}

	virtual void calcNewAllowedMoves()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};
 