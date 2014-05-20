


#pragma once

#include "chessInclude.h"

class GameManager {
public:
	GameManager();
	~GameManager() {
		delete board;
		delete white;
		delete black;
	}
	
	void startGame() {
				
	}

	void reset() {

	}
	
	void gameActivity();

	void achivement(Player* who) {

	}


private : 
	Chessboard* board;
	list < MoveInfo > history;
	Player* white;
	Player* black;

};

