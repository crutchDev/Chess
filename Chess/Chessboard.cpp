
#include "chessInclude.h"

// Chessboard

Chessboard::Chessboard(void) 
	: board(SIDE_SIZE,vector<Figure*>(SIDE_SIZE,nullptr)) { }


Chessboard::~Chessboard(void) {
	for ( auto i = 0 ; i <= MAX_INDEX  ; i++ ) 
		for ( auto j = 0 ; j <= MAX_INDEX ; j++ )
			delete board[i][j];
}

void Chessboard::putFigureToPos(ChessboardPos& pos,Figure* figr) {
	board[pos.letter][pos.number] = figr;
	figr->setLocation(pos);
}

Figure*& Chessboard::operator[](ChessboardPos pos) {
	return board[pos.letter][pos.number];
}

void Chessboard::outBoard(ostream& out) {
	for ( auto numberScaleIter = MAX_INDEX ; numberScaleIter >= 0 ; numberScaleIter-- ) {
		out << "-" << numberScaleIter + 1 << "- ";
		for ( auto letterScaleIter = 0 ; letterScaleIter <= MAX_INDEX ; letterScaleIter++ ) 
			if ( board[letterScaleIter][numberScaleIter] != nullptr )
				out << board[letterScaleIter][numberScaleIter]->getStringSchematicRep() << " "; 
			else 
				out << "[0]" << " "; 
		out << endl;
	}
	out << "    ";
	for ( char ch = 'A' ; ch <= 'H' ; ch++ ) {
		out << "-" << ch << "- ";
	}
	out << endl;
}

// ChessboardPos

ChessboardPos::ChessboardPos(int letterNumb, int numb)
{
	if ( letterNumb < 0 || letterNumb > MAX_INDEX )
		throw invalid_argument("Invalid pos letter number.");
	if ( numb < 0 || numb > MAX_INDEX )
		throw invalid_argument("Invalid pos number.");
	letter = CharCoord(letterNumb);
	number = numb;
}

ChessboardPos::ChessboardPos(CharCoord letter,int number) : letter(letter),number(number) {
	if ( number < 0 || number > MAX_INDEX )
		throw invalid_argument("Invalid pos number.");
}


ChessboardPos& ChessboardPos::operator=(const ChessboardPos& cp) {
	letter = cp.letter;
	number = cp.number;
	return *this;
}

bool ChessboardPos::operator==(const ChessboardPos& pos) const {
	return number == pos.number && letter == pos.letter;
}

bool ChessboardPos::operator<(const ChessboardPos& pos) const {
	return number < pos.number;
}

bool ChessboardPos::operator>(const ChessboardPos& pos) const {
	return number > pos.number;
}

bool ChessboardPos::isImagine() {
	return number == -1;
}

ostream& operator<<(ostream& out,ChessboardPos& pos) {
	out << "[" << (char) (pos.letter + 65) << "," << pos.number + 1 << "]";
	return out;
}

istream& operator>>(istream& in,ChessboardPos& pos) {

	string input;
	in >> input;
	if ( !regex_match(input,regex("^\\[[A-H],[1-8]\\]$")) )
		throw exception("bad pos representation.");
	pos = ChessboardPos(CharCoord(input[1]-65),input[3] - 49);
	return in;
}