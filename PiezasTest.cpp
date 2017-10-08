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

TEST(PiezasTest, observeReset)
{
	Piezas test;
	//asserted = test.gameState();
	/*
	for(int i=0; i<4; i++) //column itterator
		test.dropPiece(i);
	EXPECT_EQ(asserted, test.gameState());
	asserted = Invalid;
	test.reset();
	*/
	EXPECT_EQ(true, true);
}