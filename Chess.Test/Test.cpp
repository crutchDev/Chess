#include <gtest/gtest.h>

#include "../Chess/chessInclude.h"

TEST(testOne, ChessTest) {
	ChessboardPos a;
	EXPECT_TRUE(a.isImagine());
}

//write tests here