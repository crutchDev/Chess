
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "chessInclude.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <map>

#define STD_WINDOW_X_SIZE 640
#define STD_WINDOW_Y_SIZE 640
#define CHESSBOARD_HASH_CODE (short) 0xFFFF

class GuiInterface : public GameInterface {
public:
	
	GuiInterface(const sf::VideoMode& vm = sf::VideoMode(STD_WINDOW_X_SIZE,STD_WINDOW_Y_SIZE));
	virtual ~GuiInterface(void);

	virtual string requestPlayerNameForColor(::Color clr);
	virtual Figure* selectFigure(vector<Figure*> from);
	virtual ChessboardPos selectPosToMove(set< ChessboardPos >&& allowedMoves);
	virtual void introducePlayerStep(Player* plr);
	//void drawPlayWindow();
	//vector < sf::Shape* > getFieldSquares();
	virtual bool isExist();
	virtual void handleEvents();
	virtual void start();
	virtual void showBoard(Chessboard* board);


private:
	map< short , sf::Texture >* fillTextures() ;
	sf::RenderWindow* playWindow;	
	int xWindowSize;
	int yWindiwSize;

	map< short , sf::Texture >* textures;

};


#endif