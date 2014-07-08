/************************************************************************
*file: MainActivity.cpp
*purpose: program entry point
*author: Melnyk Andriy
*written: 17/05/2014
*last modified: 17/05/2014
*************************************************************************/

//#define TEST_SFML 

#ifdef TEST_SFML

#include <SFML/Graphics.hpp>
#include <thread>

void draw_circle(){
	std::thread window([] ()->void {
		sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
	
	});
	window.detach();
}

#endif // TEST_SFML


#include "chessInclude.h"




int main ()  {
	
#ifdef TEST_SFML
	draw_circle();
#endif // TEST_SFML


	GuiInterface gIface;


	//gIface.drawPlayWindow();

	//ConsoleInterface iface;
	GameManager manager(&gIface);
	manager.gameActivity();



		
	return 0;
}
