

#include "chessInclude.h"


GameManager::GameManager(void) {
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
