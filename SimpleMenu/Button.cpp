#include "button.h"

Button ::Button () {
	//rect = new sf::RectangleShape();
	//text = new sf::Text ();
	//zone = new sf::Rect<sf::RectangleShape>();
	if (!font.loadFromFile("C:\\software\\sfml\\examples\\pong\\resources\\sansation.ttf") ) {
    // error...
	}
}


void Button::SetButParams ( float _x_position ,
	float _y_position,
	float _buttonHeith ,
	float _buttonLength,
	sf::Color _ButtonColor,
	sf::Color _TextColor, string _name )
{
	x_position = _x_position;
	x_position_text = x_position + 10;
	y_position = _y_position;
	buttonHeith = _buttonHeith;
	buttonLength = _buttonLength;
	ButtonColor = _ButtonColor;
	TextColor = _TextColor;
	name = _name;

	rect.setSize ( sf::Vector2f(buttonLength, buttonHeith));
	rect.setFillColor(ButtonColor);
	rect.setPosition ( x_position , y_position );
	text.setPosition(x_position_text , y_position); // font is a sf::Font
	text.setFont ( font );
	// set the string to display
	text.setString( name );
    // set the character size
	text.setCharacterSize(24); // in pixels, not points!
    // set the color
	text.setColor(TextColor);
    // set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//sf::Vector2i position ( (int) x_position , (int) y_position );
	//sf::Vector2i size ( (int) buttonLength , (int) buttonHeith );
    //sf::Rect<int> zone ( position , size ); 
	zone.left = (int) x_position;
	zone.top = (int) y_position;
	zone.width = (int) buttonLength;
	zone.height = (int) buttonHeith;
}

Button::~Button() {

}

