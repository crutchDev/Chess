


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
	
	void gameActivity() {
			while ( true ) {
				if ( white->gameOver() ) {
					achivement(black);
					break;
				}
				white->step();
				if ( black->gameOver() ) {
					achivement(white);
					break;
				}				
				black->step();
			}
	}

	void achivement(Player* who) {

	}


private : 
	Chessboard* board;
	list < MoveInfo > history;
	Player* white;
	Player* black;

};

