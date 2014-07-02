
/// purpose : 

#pragma once

#include "chessInclude.h"

class Player {
public:
	Player(Color team,string name);
	~Player();


	bool gameOver() {
		return king->isAttacked() && king->getAllowedMove().size() == 0;
	}
		
	void step() {
		
	}

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