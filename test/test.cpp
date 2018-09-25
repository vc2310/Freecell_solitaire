#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <vector>
#include <time.h>
#include "../include/CardsADT.h"
#include "../include/CardsGame.h"
#include "../catch/catch.h"
using namespace std;

TEST_CASE( "tests for Solitaire" , "[CardsGame]" ){

	CardsDeck c;
    c.DealingCards();
	SECTION("invalid between columns"){
		REQUIRE_FALSE(c.checkValidMove(1,2));
		REQUIRE(c.checkValidMove(5,3));
	}

	SECTION("moving to free cell when one is available"){
		c.moveCardFreecell(3);
		REQUIRE(c.checkValidMoveFreecell());
		c.moveCardFreecell(2);
		REQUIRE(c.checkValidMoveFreecell());
	}

	SECTION("moving to free cell when none is available"){
		c.moveCardFreecell(1);
		c.moveCardFreecell(6);
		c.moveCardFreecell(4);
		c.moveCardFreecell(5);
		REQUIRE_FALSE(c.checkValidMoveFreecell());
	}

	SECTION("detecting winning game board"){
		REQUIRE_FALSE(c.winningSituation());
	}
}