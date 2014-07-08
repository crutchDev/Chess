

#include "chessInclude.h"
#include <iostream>

#define WINDOW_NAME "Awesome Chess"
#define WINDOW_ICON "res\\icon.png"
#define CELL_SIDE_SIZE 80

using namespace sf;


GuiInterface::GuiInterface(const VideoMode& vm ) : playWindow(nullptr) {
	xWindowSize = vm.width;
	yWindiwSize = vm.height;
	//thread escHandler([&] () {
	//	while ( true ) {
	//		if ( Keyboard::isKeyPressed(Keyboard::Escape) ) {
	//			exit(EXIT_SUCCESS);
	//		}
	//	}
	//});
	//escHandler.detach();
}


GuiInterface::~GuiInterface() {
	delete playWindow;
	delete textures;
}

std::string GuiInterface::requestPlayerNameForColor(::Color clr) {
	//create window
	return "";
}

Figure* GuiInterface::selectFigure(vector<Figure*> from) {
	
	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i pos = sf::Mouse::getPosition(*playWindow);
			ChessboardPos boardPos = getBoardPosFromMousePos(pos);
			//cout << boardPos << endl;
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



//void GuiInterface::drawPlayWindow() {
//
//	playWindow = new RenderWindow(VideoMode(xWindowSize,yWindiwSize),"Game");
//	RectangleShape fieldFiller(Vector2f( (float)xWindowSize, (float)yWindiwSize));
//	fieldFiller.setFillColor(sf::Color::Blue);
//	
//	vector < Shape* > squares = getFieldSquares();
//
//	while (playWindow->isOpen()) {
//		sf::Event event;
//		while (playWindow->pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				playWindow->close();
//		}
//		playWindow->clear();
//		playWindow->draw(fieldFiller);
//		for_each(squares.begin(),squares.end(), [&] (Shape* shp)->void {
//			playWindow->draw(*shp);
//		});
//
//		playWindow->display();
//	}
//
//	for_each(squares.begin(),squares.end(), [&] (Shape* shp)->void {
//		delete shp;
//	});
//}

//vector < Shape* > GuiInterface::getFieldSquares() {
//	vector < Shape* > retVect; 
//	RectangleShape* addedRect;
//	Vector2f outPos(80,540);
//	for ( auto i = 0; i <= MAX_INDEX; i++ ) {
//		for (auto j = 0 ; j <= MAX_INDEX; j++ ) {
//			addedRect = new RectangleShape(Vector2f(80,80));
//			addedRect->setPosition(outPos);
//			addedRect->setFillColor( ((i + j)%2 == 0 )?(sf::Color::Black):(sf::Color::White ) );
//			retVect.push_back(addedRect);	
//			outPos.x += 80;
//		}
//		outPos.y -= 80;
//		outPos.x = 80;
//	}
//	return retVect;
//}

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

