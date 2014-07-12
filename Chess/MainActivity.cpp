/************************************************************************
*file: MainActivity.cpp
*purpose: program entry point
*author: Melnyk Andriy
*written: 17/05/2014
*last modified: 17/05/2014
*************************************************************************/


#include "chessInclude.h"

#include <SFML/Graphics.hpp>
using namespace sf;


int main ()  {

	GuiInterface gIface;
	GameManager manager(&gIface);
	manager.gameActivity();

	return 0;
}
