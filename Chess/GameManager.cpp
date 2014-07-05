

#include "chessInclude.h"
#include <iostream>

GameManager::GameManager(GameInterface* comm) : communicator(comm) {
	board = new Chessboard();
	white = new Player(WHITE,board, communicator->requestPlayerNameForColor(WHITE));
	black = new Player(BLACK,board, communicator->requestPlayerNameForColor(BLACK));

	//board->outBoard(cout);
}

void GameManager::gameActivity() {

    while ( true ) {
		board->outBoard(cout);
		communicator->introducePlayerStep(white);
      	white->step(communicator);
      	if ( black->gameOver() ) {
        		achivement(white);
        		break;
      	}
		board->outBoard(cout);
		communicator->introducePlayerStep(black);
      	black->step(communicator);
		if ( white->gameOver() ) {
			achivement(black);
			break;
		}
    }

}

GameManager::~GameManager() {
	delete board;
	delete white;
	delete black;
}

std::string ConsoleInterface::requestPlayerNameForColor(Color clr) {
	cout << "Please, enter name for " << ((clr == WHITE)?("white"):("black")) << " player : ";
	string name;
	cin >> name;
	return name;
}


void ConsoleInterface::introducePlayerStep(Player* plr) {
	cout << plr->getName() << " now is your turn." << endl;
}

Figure* ConsoleInterface::selectFigure(vector<Figure*> from) {
	cout << "Next figures are available : " << endl;
	for_each(from.begin(),from.end(),[]( Figure* fig )->void { 
		cout << fig->posWhereLocated() << " " ;
	}   );
	cout << endl;
	ChessboardPos selectedPos;

	do {
		cout << "Please, select one figure by position (example  [A,1]) : " ;
		try {
			cin >> selectedPos;
			auto figIter = find_if(from.begin(),from.end(), [&] (Figure* fig)->bool {  return selectedPos == fig->posWhereLocated(); } );
			if ( figIter != from.end())
				return *figIter;
		}
		catch (...) {}

		cout << "Selected position is invalid." << endl;
	} while ( true );

}


ChessboardPos ConsoleInterface::selectPosToMove(set < ChessboardPos >&& allowedMoves ) {

	ChessboardPos selectedPos;
	do {
		cout << "Please, select new position  (example  [A,1]) : " ;
		try {
			cin >> selectedPos;
			return selectedPos;
		}
		catch (...) {
			cout << "Selected position is invalid." << endl;
		}
	} while ( true ) ;

}

