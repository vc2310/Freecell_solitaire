/**
 *  \file CardsADT.cpp
 *  \brief The ADT used to create a Card
 *  \author Vaibhav Chadha
 *  \date April 9,2018
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "../include/CardsADT.h"
#include "../catch/catch.h"
using namespace std;

CardsT::CardsT()
{


}

CardsT::CardsT(string r, string s)
{
	this->ranks = r;
  	this->suits = s;

}

string CardsT::getRank()
{
	return this->ranks;
}

string CardsT::getSuit()
{
	return this->suits;
}

/*string CardsT::print()
{
	return (getRank() + " of " + getSuit());
}*/

string CardsT::getColour()
{
	if (getSuit().compare("Heart") == 0 || getSuit().compare("Diamond") == 0)
	{
		return "Red";
	}
	else{
		return "Black";
	}
}
/*
int main(){
	CardsT ab("2","Club");
	cout << ab.getColour();
	cout << ab.getSuit();
	cout << ab.print();
	return 0;
}*/
