#include <gtest/gtest.h>

#include "../ChessStructure/chessInclude.h"

void testCastling(int dir);

TEST(MovementTests, Rook_allowed_moves_count) {
	Chessboard board;
	Rook* rookFig = new Rook(&board,WHITE,ChessboardPos(A,0) );
	board.putFigureToPos(rookFig);
	rookFig->calcNewAllowedMoves();
	EXPECT_TRUE( rookFig->getAllowedMove().size() == 14 );
}

TEST(MovementTests, Castling_left_should_succeed) {
	testCastling(-1);
}

TEST(MovementTests, Castling_right_should_succeed) {
	testCastling(1);
}

void testCastling(int dir) {
	if (abs(dir) != 1) return;
	Chessboard board;
	Rook* rook = new Rook(&board, WHITE, ChessboardPos((dir < 0) ? A : H, 0));
	King* king = new King(&board, WHITE, ChessboardPos(E, 0));

	board.putFigureToPos(rook);
	board.putFigureToPos(king);

	king->calcNewAllowedMoves();
	ChessboardPos castlingPos = ChessboardPos(E + dir * 2, 0);
	king->move(castlingPos);

	EXPECT_EQ(board[ChessboardPos(A, 0)], nullptr);
	EXPECT_EQ(board[ChessboardPos(E, 0)], nullptr);
	EXPECT_EQ(board[ChessboardPos(E + 2*dir, 0)], (Figure*)king);
	EXPECT_EQ(board[ChessboardPos(E + dir, 0)], (Figure*)rook);
}

TEST(MovementTests, Castling_left_should_fail) {
	Chessboard board;
	Rook* rook = new Rook(&board, WHITE, ChessboardPos(A, 3));
	King* king = new King(&board, WHITE, ChessboardPos(E, 0));

	board.putFigureToPos(rook);
	board.putFigureToPos(king);
	rook->calcNewAllowedMoves();

	rook->move(ChessboardPos(A, 0));
	king->calcNewAllowedMoves();

	ChessboardPos castlingPos = ChessboardPos(C, 0);
	auto moves = king->getAllowedMove();
	EXPECT_TRUE(find(moves.begin(), moves.end(), castlingPos) == moves.end());
}

//

// PAWN 

