/************************************************************************
*file: MainActivity.cpp
*purpose: program entry point
*author: Melnyk Andriy
*written: 17/05/2014
*last modified: 17/05/2014
*************************************************************************/

#include "chessInclude.h"

int main ()  {
	ConsoleInterface iface;
	GameManager manager(&iface);
	manager.gameActivity();


	return 0;
}
