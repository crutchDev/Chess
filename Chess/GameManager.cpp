

#include "chessInclude.h"
#include <iostream>

GameManager::GameManager(GameInterface* comm) : communicator(comm) {
	board = new Chessboard();
	white = new Player(WHITE,board, communicator->requestPlayerNameForColor(WHITE));
	black = new Player(BLACK,board, communicator->requestPlayerNameForColor(BLACK));
}

GameManager::~GameManager() {
	delete board;
	delete white;
	delete black;
}

void GameManager::gameActivity() {
	communicator->start();
	while ( communicator->isExist() ) {

		communicator->showBoard(board);
		white->step(communicator);
		if ( white->gameOver() ) {
			achivement(black);
			break;
		}
		communicator->showBoard(board);
		black->step(communicator);
		if ( black->gameOver() ) {
			achivement(white);
			break;
		}
	}

}
