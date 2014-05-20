
#pragma once 

#include "chessInclude.h"

class King : public Figure {
public :
	bool isAttacked() {
		// TODO
		return false;
	}

	virtual bool canMove( ChessboardPos& pos ) {
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

class Pawn : public Figure{
	void Transform(){
		//TODO
	}

	virtual bool canMove(ChessboardPos& pos) {
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

class Rook : public Figure{
	virtual bool canMove(ChessboardPos& pos) {
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

	virtual bool canMove(ChessboardPos& pos) {
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

class Knight : public Figure{


	virtual bool canMove(ChessboardPos& pos) {
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

class Bishop : public Figure{
	virtual bool canMove(ChessboardPos& pos) {
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