#include <gtest/gtest.h>

#include "../Chess/chessInclude.h"

TEST(testOne, ChessTest) {
	ChessboardPos a;
	EXPECT_TRUE(a.isImagine());
}

//write tests here

// ROOK 

//TEST(rookTest1,ChessTest) {
//
//
//
//}
//
//TEST(rookTest2,ChessTest) {
//	Chessboard board;
//	Rook* rookFig = new Rook(&board,WHITE,ChessboardPos(A,0) );
//	board.putFigureToPos(rookFig);
//	rookFig->calcNewAllowedMoves();
//	EXPECT_TRUE( rookFig->getAllowedMove().size() == 14 );
//}
//

// PAWN 