

#include "chessInclude.h"
#include <iostream>

#define WINDOW_NAME "Awesome Chess"
#define WINDOW_ICON "res\\icon.png"
#define CELL_SIDE_SIZE 80

using namespace sf;


GuiInterface::GuiInterface(const VideoMode& vm ) : playWindow(nullptr) {
	xWindowSize = vm.width;
	yWindiwSize = vm.height;
}


GuiInterface::~GuiInterface() {
	delete playWindow;
	delete textures;
}

std::string GuiInterface::requestPlayerNameForColor(::Color clr) {
	sf::RenderWindow reqestWindow(sf::VideoMode(600, 200), "enter name:");
	sf::Font font;
	if (!font.loadFromFile("res\\fonts\\arial.ttf")) {
		throw runtime_error("couldn't load font!\n");
	}
	string welcomeMessage = (clr == BLACK) ? "Black" : "White";
	welcomeMessage += " player name:";
	string playerName = "";
	sf::Text text("Name:",font,40);
	text.setFont(font);
	
	text.setString(welcomeMessage);
	text.setColor(sf::Color::Red);

	while (reqestWindow.isOpen()){
		sf::Event event;
		while (reqestWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				reqestWindow.close();
			}
			if (event.type == sf::Event::KeyReleased
				&& event.key.code == Keyboard::Return) {
				reqestWindow.close();
				return playerName;
			}
			if (event.type == sf::Event::TextEntered &&
				static_cast<char>(event.text.unicode) != '\r') {
				playerName += static_cast<char>(event.text.unicode);
				text.setString(welcomeMessage + playerName);
			}

		}

		reqestWindow.clear(sf::Color::Yellow);
		reqestWindow.draw(text);
		reqestWindow.display();
	}
	return "";
}

Figure* GuiInterface::selectFigure(vector<Figure*> from) {
	
	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i pos = sf::Mouse::getPosition(*playWindow);
			ChessboardPos boardPos = getBoardPosFromMousePos(pos);
			auto findRes = find_if(from.begin(), from.end(), [&](Figure* f) -> bool { return f->posWhereLocated() == boardPos; });
			if (findRes != from.end() && (*findRes)->canMove()) {
				cout << "hooray\n";
				//check if figure has moves available, else show error
				return *findRes;
			}
		}
	}

}

ChessboardPos GuiInterface::selectPosToMove(set< ChessboardPos >&& allowedMoves)
{
	while (true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i pos = sf::Mouse::getPosition(*playWindow);
			ChessboardPos boardPos = getBoardPosFromMousePos(pos);
			if (binary_search(allowedMoves.begin(),allowedMoves.end(),boardPos)) {
				cout << "you chose to go to: " << boardPos << endl;
				return boardPos;
			}
		}
	}
}

void GuiInterface::introducePlayerStep(Player* plr)
{
	//in new window
	throw std::logic_error("The method or operation is not implemented.");
}


bool GuiInterface::isExist() {
	return playWindow->isOpen();
}

void GuiInterface::start() {
	playWindow = createWindowAndWindowHandlerThread();
	Image icon;
	icon.loadFromFile(WINDOW_ICON);
	playWindow->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
	textures = fillTextures();
}

void GuiInterface::showBoard(Chessboard* board) {

	playWindow->clear(sf::Color::White);
	playWindow->draw(Sprite(textures->at(CHESSBOARD_HASH_CODE)));

	for (auto iter = board->getIterator() ; iter.hasMoreFigures() ; iter++ ) 
		if ( (*iter) != nullptr ) {
			Sprite spr(textures->at( (*iter)->hashCode() ));
			spr.setPosition(CELL_SIDE_SIZE*iter.getPos()->letter,yWindiwSize - (iter.getPos()->number + 1)*CELL_SIDE_SIZE);
			playWindow->draw(spr);
		}

	playWindow->display();

}

map< short , Texture >* GuiInterface::fillTextures() {
	map < short , Texture >* textures = new map < short , Texture >();
	Texture t;

	t.loadFromFile("res\\chessboard.png");
	(*textures)[CHESSBOARD_HASH_CODE] = t;
// white sprites 
	t.loadFromFile("res\\figures\\w_pawn.png");
	(*textures)[Figure::figureHashCode<Pawn>(WHITE)] = t;
	t.loadFromFile("res\\figures\\w_rook.png");
	(*textures)[Figure::figureHashCode<Rook>(WHITE)] = t;
	t.loadFromFile("res\\figures\\w_king.png");
	(*textures)[Figure::figureHashCode<King>(WHITE)] = t;
	t.loadFromFile("res\\figures\\w_horse.png");
	(*textures)[Figure::figureHashCode<Horse>(WHITE)] = t;
	t.loadFromFile("res\\figures\\w_bishop.png");
	(*textures)[Figure::figureHashCode<Bishop>(WHITE)] = t;
	t.loadFromFile("res\\figures\\w_queen.png");
	(*textures)[Figure::figureHashCode<Queen>(WHITE)] = t;
// black sprites 
	t.loadFromFile("res\\figures\\b_pawn.png");
	(*textures)[Figure::figureHashCode<Pawn>(BLACK)] = t;
	t.loadFromFile("res\\figures\\b_rook.png");
	(*textures)[Figure::figureHashCode<Rook>(BLACK)] = t;
	t.loadFromFile("res\\figures\\b_king.png");
	(*textures)[Figure::figureHashCode<King>(BLACK)] = t;
	t.loadFromFile("res\\figures\\b_horse.png");
	(*textures)[Figure::figureHashCode<Horse>(BLACK)] = t;
	t.loadFromFile("res\\figures\\b_bishop.png");
	(*textures)[Figure::figureHashCode<Bishop>(BLACK)] = t;
	t.loadFromFile("res\\figures\\b_queen.png");
	(*textures)[Figure::figureHashCode<Queen>(BLACK)] = t;

	return textures;
}

RenderWindow* GuiInterface::createWindowAndWindowHandlerThread() const {
	RenderWindow* returnedWindow = nullptr;
	thread windowEventsHandler([=,&returnedWindow] ()->void {
		RenderWindow* createdWindow = new RenderWindow(VideoMode(xWindowSize,yWindiwSize),WINDOW_NAME);
		createdWindow->setActive(false);
		returnedWindow = createdWindow;
		while (createdWindow->isOpen()) {
			sf::Event event;
			while (createdWindow->pollEvent(event))
				if (event.type == sf::Event::Closed)
					createdWindow->close();
		}
	});
	windowEventsHandler.detach();
	while ( returnedWindow == nullptr );
	returnedWindow->setActive(true);
	return returnedWindow;
}

ChessboardPos GuiInterface::getBoardPosFromMousePos(sf::Vector2i pos) {
	return ChessboardPos(pos.x / CELL_SIDE_SIZE, MAX_INDEX - ( pos.y / CELL_SIDE_SIZE));
}

