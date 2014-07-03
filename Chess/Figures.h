
#pragma once 

#include "chessInclude.h"

class King : public Figure {
public :
	King(Chessboard* b, Color c) : Figure(b,c) {}

	bool isAttacked() {
		// TODO
		return false;
	}

	virtual bool canMove( ChessboardPos& pos ) const {
		// TODO
		return false;
	}
	
	virtual void move( ChessboardPos& pos ) {
			// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "K";
	}

};

class Pawn : public Figure {
public:
	Pawn(Chessboard* b, Color c) : Figure(b,c) {}

	void Transform() {
		//TODO
	}

	virtual bool canMove(ChessboardPos& pos) const {
		// TODO
		return false;
	}

	virtual void move(ChessboardPos& pos) {
		// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "P";
	}
};

class Rook : public Figure {
public:
	Rook(Chessboard* b, Color c) : Figure(b,c) {}

	virtual bool canMove(ChessboardPos& pos) const {
		// TODO
		return false;
	}

	virtual void move(ChessboardPos& pos) {
		// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "R";
	}
};

class Queen : public Figure {
public:
	Queen(Chessboard* b, Color c) : Figure(b,c) {}

	virtual bool canMove(ChessboardPos& pos) const {
		// TODO
		return false;
	}

	virtual void move(ChessboardPos& pos) {
		// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "Q";
	}
};

class Bishop : public Figure{

public:
	Bishop(Chessboard* b, Color c) : Figure(b,c) {}

	virtual bool canMove(ChessboardPos& pos) const {
		// TODO
		return false;
	}

	virtual void move(ChessboardPos& pos) {
		// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "B";
	}
};

class Horse : public Figure{
public:
	Horse(Chessboard* b, Color c) : Figure(b,c) {}

	virtual bool canMove(ChessboardPos& pos) const {
		// TODO
		return false;
	}

	virtual void move(ChessboardPos& pos) {
		// TODO
	}

	virtual vector< ChessboardPos > getAllowedMove() {

		// TODO
		return vector< ChessboardPos >();
	}

	virtual string getStringSchematicRep() const {
		return colorSchemeRep() + "_" + "H";
	}
};
 