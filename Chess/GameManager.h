


#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "chessInclude.h"

class GameInterface {
public:
	virtual string requestPlayerNameForColor(::Color clr) = 0;
	virtual Figure* selectFigure(vector <Figure*> from) = 0;
	ChessboardPos selectPosToMove(set < ChessboardPos >& allowedMoves ) { 
		selectPosToMove(move(allowedMoves));
	}
	virtual ChessboardPos selectPosToMove(set < ChessboardPos >&& allowedMoves ) = 0;
	virtual void introducePlayerStep(Player* plr) = 0;
	virtual bool isExist() = 0;
	virtual void start() = 0;
	virtual void showBoard(Chessboard* board);
};

// class ConsoleInterface : public GameInterface {
//public:
//	virtual string requestPlayerNameForColor(::Color clr);
//	virtual Figure* selectFigure(vector<Figure*> from);
//	virtual ChessboardPos selectPosToMove(set < ChessboardPos >&& allowedMoves );
//	virtual void introducePlayerStep(Player* plr);
//};
//
class GameManager {
public:
	GameManager(GameInterface* communicator);
	~GameManager();
	
	void startGame() {
				
	}

	void reset() {

	}
	
	void gameActivity();


private : 
	void achivement(Player* who) {

	}

	GameInterface* communicator;

	Chessboard* board;
	list < MoveInfo > history;
	Player* white;
	Player* black;

};

#endif
