/**
 *  \file CardsGame.cpp
 *  \brief The module to make the game using rules
 *  \author Vaibhav Chadha
 *  \date April 9,2018
 */
#include "CardsADT.h"
#include "../catch/catch.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <vector>
#include <time.h>
#ifndef CARDSGAME_H
#define CARDSGAME_H

/**
 *  \brief The class CardsDeck 
 *  \details Helps in playing the game Solitaire
 */
class CardsDeck
{
    public:

        /**
         *  \brief An empty constructor
         *  \details Creates 52 cards in order
         */
        CardsDeck();

        /**
         *  \brief A method to shuffle the deck
         *  \details Shuffles the targeted deck or the deck made in constructor
         */
        void ShufflingDeck();

        /**
         *  \brief A method to deal the cards
         *  \details deals the cards in 8 arrays with first 4 of 7 cards each and left over of 6 cards each
         */
     	void DealingCards();

        /**
         *  \brief A method to move card within columns
         *  \param from The column card is supposed to move from
         *  \param to The column card is supposed to move to
         *  \return the new updated column which is a vector of a vector of CardsT
         */
     	std::vector <std::vector <CardsT>> moveCard(int from, int to);

        /**
         *  \brief A method to move card to Freecell
         *  \param from The column card is supposed to move from
         *  \details Moves the card to freecell IF the cell is empty
         */
     	void moveCardFreecell(int from);

        /**
         *  \brief A method to move card to Foundation
         *  \param from The column card is supposed to move from
         *  \param to The foundation card is supposed to move to
         *  \details Moves the card to foundation IF the cell is of same suit and decreasing
         */
     	void moveCardFoundation(int from, int to);
     	
        /**
         *  \brief A method to check if the move is valid
         *  \param from The column card is supposed to move from
         *  \param to The column card is supposed to move to
         *  \details check if last card of both columns have different colors and are in dectreasing order
         *  \return a boolean which returns true if the move is valid
         */
     	bool checkValidMove(int from, int to);

        /**
         *  \brief A method to check if the move to freecell is valid
         *  \details check if there is any empty freecell 
         *  \return a boolean which returns true if an empty freecell is available
         */
     	bool checkValidMoveFreecell();

        /**
         *  \brief A method to check if the move to foundation is valid
         *  \param from The column card is supposed to move from
         *  \param to The foundation card is supposed to move to
         *  \details check if the cards belong to same suit and are in decreasing order
         *  \return a boolean which returns true if the move is valid
         */
     	bool checkValidMoveFoundation(int from, int to);

        /**
         *  \brief A method to check if the game is done (won)
         *  \details check if the foundation if full of right cards
         *  \return a boolean which returns true if the game is done
         */
        bool winningSituation();

    private:
        ///creating a private deck
    	CardsT deck[52];
        ///creating a private vector of vector of CardsT named column
    	std::vector <std::vector <CardsT>> columns;
        ///creating a vector named freecell 
    	std::vector <CardsT> freecell;
        ///creating a private vector of vector of CardsT named foundation
    	std::vector <std::vector <CardsT>> foundation;


};

#endif
