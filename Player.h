
/// purpose : 

#pragma once

#include "chessInclude.h"

class Player {
public:
	Player(Color team);
	~Player();


	bool gameOver() {
		return king->isAttacked() && king->getAllowedMove().size() == 0;
	}
		
	void step() {
		
	}



private:
	list<Figure*> figures;
	King* king;
	Color team;
	string name;

};