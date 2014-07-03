
/// purpose : 

#pragma once

#include "chessInclude.h"

class Player {
public:
	Player(Color team,Chessboard *,string name);
	~Player();
	
	bool gameOver();	
	void step();

private:
	string genStdPlayerName();
	void initFigures(ChessboardPos corner,bool direction);
	static int playerCounter;

	list<Figure*> figures;
	Chessboard* board;
	King* king;
	Color team;
	string name;

};