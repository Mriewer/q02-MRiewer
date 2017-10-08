/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/**
 * This test places in an Invalid column
 *	It then uses checks for proper response
**/
TEST(PiezasTest, improperInput)
{
	Piezas test;
	EXPECT_EQ(Invalid, test.dropPiece(-1));
	EXPECT_EQ(Invalid, test.dropPiece(5));
}

/**
 * This test takes one turn and expects a turn toggle
**/
TEST(PiezasTest, willToggle)
{
	Piezas test;
	test.dropPiece(0);
	EXPECT_EQ(O, test.dropPiece(0));
}

/**
 * This test generates a cats game and expects a proper
 *	response from gameState
**/
TEST(PiezasTest, observeCatGame)
{
	Piezas test;
	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++) //column itterator
			test.dropPiece(j);
	EXPECT_EQ(Blank, test.gameState());
}

/**
 * This test observes functionality of pieceAt
**/
TEST(PiezasTest, observePieceAt)
{
	Piezas test;
	test.dropPiece(0);
	EXPECT_EQ(X, test.pieceAt(0,0)); // runs through as X turn
	test.dropPiece(0);
	EXPECT_EQ(O, test.pieceAt(1,0)); // runs through as O turn
	EXPECT_EQ(Invalid, test.pieceAt(-1,0));
	EXPECT_EQ(Invalid, test.pieceAt(1,5));
}


/**
 * This test generates a full column and then places another piece
 *  this will toggle dropPiece to return Blank
**/
TEST(PiezasTest, observeDropOverflow)
{
	Piezas test;
	for(int i=0; i<3; i++)
		test.dropPiece(0);
	EXPECT_EQ(Blank, test.dropPiece(0)); // runs through as O turn
	EXPECT_EQ(Blank, test.dropPiece(0)); // runs through as X turn
}

/**
 * This test generates a cats game which is tested in gameState
 *	the first test on gameState returns there is a cat game
 * Then there is a reset and the gameState checks once again, but
 *	for an invalid, incompleted game
**/
TEST(PiezasTest, observeReset)
{
	Piezas test;
	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++) //column itterator
			test.dropPiece(j);
	EXPECT_EQ(Blank, test.gameState());
	test.reset();
	EXPECT_EQ(Invalid, test.gameState());
}
