


#pragma once

#include "chessInclude.h"

class GameInterface {
public:
	virtual string requestNameForColor(Color clr) = 0;
	
};

class ConsoleInterface : public GameInterface {
public:
	virtual string requestNameForColor(Color clr);

};

//class GuiInterface : public GameInterface {
//
//};

class GameManager {
public:
	GameManager(GameInterface* communicator);
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
	GameInterface* communicator;

	Chessboard* board;
	list < MoveInfo > history;
	Player* white;
	Player* black;

};


