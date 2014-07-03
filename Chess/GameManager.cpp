

#include "chessInclude.h"
#include <iostream>

GameManager::GameManager(GameInterface* communicator) {
	board = new Chessboard();
	white = new Player(WHITE,board, communicator->requestNameForColor(WHITE));
	black = new Player(BLACK,board, communicator->requestNameForColor(BLACK));

	board->outBoard(cout);
}

void GameManager::gameActivity() {

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

std::string ConsoleInterface::requestNameForColor(Color clr) {
	cout << "Please, enter name for " << ((clr == WHITE)?("white"):("black")) << " player : ";
	string name;
	cin >> name;
	return name;
}
