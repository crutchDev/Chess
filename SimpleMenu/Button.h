#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Button {
public :
    sf::RectangleShape rect;
	sf::Text text;
	sf::Rect<int> zone;
	Button ();
	~Button ();

	void SetButParams ( float x_position ,
    float y_position,
	float buttonHeith ,
	float buttonLength,
	sf::Color ButtonColor,
	sf::Color TextColor, string _name ); 

	bool Contains ();

 private :
	 
	float x_position ;
	float x_position_text;
	float y_position;
	float buttonHeith ;
	float buttonLength;
	sf::Color ButtonColor;
	sf::Color TextColor;
	sf::Font font;
	string name;

};


#endif // !button_h
