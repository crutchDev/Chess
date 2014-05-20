#pragma  once


#include "Figure.h"

class MoveInfo
{
public:
	MoveInfo();
	MoveInfo(Figure::ChessboardPos beg, Figure::ChessboardPos end, Figure* _killed);
	~MoveInfo();
	Figure::ChessboardPos startPos, endPos;
	Figure* killed;
	bool transformed; //pawn to queen
	//subject to change
	//Chessboard* snapshot;
};

