
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "chessInclude.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
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
	virtual bool isExist();
	virtual void start();
	virtual void showBoard(Chessboard* board);


private:
	sf::RenderWindow* createWindowAndWindowHandlerThread() const ;
	map< short , sf::Texture >* fillTextures() ;
	ChessboardPos getBoardPosFromMousePos(sf::Vector2i pos);

	sf::RenderWindow* playWindow;	
	//sf::Sound clickSound;
	//sf::SoundBuffer clickBuffer;
	int xWindowSize;
	int yWindiwSize;


	map< short , sf::Texture >* textures;

};


#endif