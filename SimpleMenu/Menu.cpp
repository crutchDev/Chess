#include "Button.h"
#include <iostream>
//using namespace std;


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chess");

	Button *newGameButton = new Button ();
	newGameButton->SetButParams ( 100 , 100 , 40 , 150 , sf::Color::Green , sf :: Color::Red , "NewGame" );

	
	Button *optionsButton = new Button ();
	optionsButton->SetButParams ( 100 , 200 , 40 , 150 , sf::Color::Green , sf :: Color::Red , "Options" );

	Button *aboutButton = new Button ();
	aboutButton->SetButParams ( 100 , 300 , 40 , 150 , sf::Color::Green , sf :: Color::Red , "About" );

	Button *exitButton = new Button ();
	exitButton->SetButParams ( 100 , 400 , 40 , 150 , sf::Color::Green , sf :: Color::Red , "Exit" );


    // run the program as long as the window is open
    while (window.isOpen())     {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))         {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) 			{
				/*delete (newGame);
			    delete (Options);
			    delete (About);
			    delete (Exit);*/
                window.close();
			}

        }

		if (event.type == sf::Event::MouseButtonPressed) {  
			cout << "pressed";
			if (event.mouseButton.button == sf::Mouse::Left) {
				cout << "left";
				//window.close();
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				if (newGameButton->zone.contains(localPosition)) {
					cout << "new game" << endl;
				}
				if (optionsButton->zone.contains (localPosition)) {
					cout << "Op" << endl;
				}										
				if (aboutButton->zone.contains (localPosition)) {
					cout <<"ab" << endl;
				}
				if (exitButton->zone.contains (localPosition)) {
					window.close();
				}
			}
		}

        // clear the window with black color
        window.clear(sf::Color::White);

		window.draw ( newGameButton->rect );
		window.draw ( newGameButton->text );
		window.draw ( optionsButton->rect );
		window.draw ( optionsButton->text );
		window.draw ( aboutButton->rect );
		window.draw ( aboutButton->text );
		window.draw ( exitButton->rect );
		window.draw ( exitButton->text );
        // end the current frame
        window.display();
    }

	delete newGameButton;
	delete optionsButton;
	delete aboutButton;
	delete exitButton;


    return 0;
}

