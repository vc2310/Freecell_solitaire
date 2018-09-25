/**
 *  \file CardsADT.h
 *  \brief The ADT used to create a Card
 *  \author Vaibhav Chadha
 *  \date April 9,2018
 */
#include "../catch/catch.h"
#include <string>
#ifndef CARDSADT_H
#define CARDSADT_H
#include <iostream>
using namespace std;


/**
 *  \brief The class CardsT 
 *  \details Helps creating Cards
 */
class CardsT
{
    public:
        /**
         *  \brief An empty constructor
         */
        CardsT();

        /**
         *  \brief Takes in 2 inputs to return a Card 
         *  \param r The rank of the card to be contructed
         *  \param s The suit of the card to be contructed
         */
        CardsT(string r, string s);

        /**
         *  \brief Gets the Rank of the Card
         *  \return The rank (string) of the card
         */
        string getRank();

        /**
         *  \brief Gets the Suit of the Card
         *  \return The suit (string) of the card
         */
        string getSuit();
        //string print();

        /**
         *  \brief Gets the Colour of the Card
         *  \details red if the suit is hearts or diamonds and black if spade or clubs
         *  \return The colour (string) of the card
         */
        string getColour();



    private:

        ///The rank of card
        string ranks;
        ///The suit of card
        string suits;
};

#endif
