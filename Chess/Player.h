

/// purpose : 

#ifndef PLAYER_H
#define PLAYER_H

#include "chessInclude.h"

class Player {
public:
	Player(::Color team,Chessboard *,string name);
	~Player();
	
	bool gameOver();	
	void step(GameInterface* communicator);
	string getName() const { return name; }
	vector<Figure*>& getFigures(){ return figures; }
private:
	string genStdPlayerName();
	void initFigures(ChessboardPos corner,bool direction);
	Figure* storeFigure(Figure* f);
	static int playerCounter;

	vector<Figure*> figures;
	Chessboard* board;
	King* king;
	::Color team;
	string name;

};
#endif