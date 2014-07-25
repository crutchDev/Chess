#include "Button.h"
#include <iostream>
//using namespace std;


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chess");
    //window.
	sf::Font font;
	if (!font.loadFromFile("C:\\software\\sfml\\examples\\pong\\resources\\sansation.ttf")) {
		// error...
	}
	sf::Text text;
	text.setPosition(10, 10); // font is a sf::Font
	text.setFont(font);
	// set the string to display
	text.setString("Made by ClutchDev");
	// set the character size
	text.setCharacterSize(24); // in pixels, not points!
	// set the color
	text.setColor(sf::Color::Red);
	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	Button *newGameButton = new Button ();
	newGameButton->SetButParams ( 100 , 100 , 40 , 150 , sf::Color::Cyan , sf :: Color::Red , "NewGame" );

	
	Button *optionsButton = new Button ();
	optionsButton->SetButParams ( 100 , 200 , 40 , 150 , sf::Color::Cyan , sf :: Color::Red , "Options" );

	Button *aboutButton = new Button ();
	aboutButton->SetButParams ( 100 , 300 , 40 , 150 , sf::Color::Cyan , sf :: Color::Red , "About" );

	Button *exitButton = new Button ();
	exitButton->SetButParams ( 100 , 400 , 40 , 150 , sf::Color::Cyan , sf :: Color::Red , "Exit" );

	Button *BackButton = new Button();
	BackButton->SetButParams(600, 500, 40, 150, sf::Color::Cyan, sf::Color::Red, "Back");


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


		sf::Vector2i localPosition1 = sf::Mouse::getPosition(window);
		if (newGameButton->zone.contains(localPosition1))
		{
			newGameButton->SetButParams(100, 100, 40, 150, sf::Color::Black, sf::Color::Red, "NewGame");
		}
		else newGameButton->SetButParams(100, 100, 40, 150, sf::Color::Cyan, sf::Color::Red, "NewGame");


		if (optionsButton->zone.contains(localPosition1))
		{
			optionsButton->SetButParams(100, 200, 40, 150, sf::Color::Black, sf::Color::Red, "Options");
		}
		else optionsButton->SetButParams(100, 200, 40, 150, sf::Color::Cyan, sf::Color::Red, "Options");

	
		if (aboutButton->zone.contains(localPosition1))
		{
			aboutButton->SetButParams(100, 300, 40, 150, sf::Color::Black, sf::Color::Red, "About");
		}
		else aboutButton->SetButParams(100, 300, 40, 150, sf::Color::Cyan, sf::Color::Red, "About");


		if (exitButton->zone.contains(localPosition1))
		{
			exitButton->SetButParams(100, 400, 40, 150, sf::Color::Black, sf::Color::Red, "Exit");
		}
		else exitButton->SetButParams(100, 400, 40, 150, sf::Color::Cyan, sf::Color::Red, "Exit");


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
					bool back = false;

					while (!back)
					{
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

						sf::Vector2i localPosition1 = sf::Mouse::getPosition(window);
						if (BackButton->zone.contains(localPosition1))
						{
							BackButton->SetButParams(600, 500, 40, 150, sf::Color::Black, sf::Color::Red, "Back");
						}
						else BackButton->SetButParams(600, 500, 40, 150, sf::Color::Cyan, sf::Color::Red, "Back");

						if (event.type == sf::Event::MouseButtonPressed)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								
								if (BackButton->zone.contains (localPosition1))
								{
									back = true;
								}

							}

						}

						window.clear(sf::Color::Yellow);
						window.draw(text);
                        window.draw(BackButton->rect);
						window.draw(BackButton->text);
						window.display();
					}
				}
				if (exitButton->zone.contains (localPosition)) {
					window.close();
				}
			}
		}


	    

        // clear the window with black color
        window.clear(sf::Color::Yellow);

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
	delete BackButton;

    return 0;
}

