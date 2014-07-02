
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
};

class Officer : public Figure{

public:
	Officer(Chessboard* b, Color c) : Figure(b,c) {}

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
};
 