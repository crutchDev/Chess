
#ifndef MOVE_INFO_H
#define  MOVE_INFO_H


#include "chessInclude.h"

class MoveInfo {
public:
	MoveInfo();
	MoveInfo(ChessboardPos beg, ChessboardPos end, Figure* _killed);
	~MoveInfo();
	ChessboardPos startPos, endPos;
	Figure* killed;
	bool transformed; //pawn to queen

	//subject to change
	Chessboard* snapshot;
};

#endif