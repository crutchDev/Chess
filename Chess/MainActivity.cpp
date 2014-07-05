/************************************************************************
*file: MainActivity.cpp
*purpose: program entry point
*author: Melnyk Andriy
*written: 17/05/2014
*last modified: 17/05/2014
*************************************************************************/


#include <SFML/Graphics.hpp>
#include "chessInclude.h"
#include <thread>

using namespace sf;

int main ()  {
	
	thread window([] ()->void {
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

	ConsoleInterface iface;
	GameManager manager(&iface);
	manager.gameActivity();


		
	return 0;
}
