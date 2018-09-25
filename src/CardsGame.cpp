/**
 *  \file CardsGame.cpp
 *  \brief The module to make the game using rules
 *  \author Vaibhav Chadha
 *  \date April 9,2018
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <vector>
#include <time.h>
#include "../catch/catch.h"
#include "../include/CardsADT.h"
#include "../include/CardsGame.h"
using namespace std;

int SIZE = 52;

CardsDeck::CardsDeck(){


	string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	string suits[] = {"Heart" ,"Spade" ,"Club" ,"Diamond"};

	for(int i = 0; i < SIZE; i++)
	{
		deck[i] = CardsT(ranks[i % 13], suits[i / 13]);
		//cout << deck[i].print() << endl; //TESTING PURPOSE
	}

}

void CardsDeck::ShufflingDeck(){

	for(int i = 0; i < SIZE; i++)
	{
		int j = (rand() + time(0)) % SIZE;
		CardsT temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void CardsDeck::DealingCards(){
	std::vector<CardsT> tempCol;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tempCol.push_back(deck[(i*7)+j]);
		}

		/*//TESTING PURPOSE
		cout << "COLUMN " << i << "==> " ;
		for (int k = 0; k < tempCol.size(); k++)
		{
			//tempCol.clear();

			std::cout << tempCol.at(k).print() << "  ";

		}*/

		//cout << "\n";
		columns.push_back(tempCol);
		tempCol.clear();
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			tempCol.push_back(deck[28+(i*6)+j]);
		}

		/*cout << "COLUMN " << i+4  << "==> ";
		//TESTING PURPOSE
		for (int k = 0; k < tempCol.size(); k++)
		{
			std::cout << tempCol.at(k).print() << "  ";
		}*/

		//cout << "\n";
		columns.push_back(tempCol);
		tempCol.clear();
	}
}

std::vector <std::vector <CardsT>> CardsDeck::moveCard(int from, int to){
	if (checkValidMove(from,to) == true){
		columns.at(to).push_back(columns.at(from).back());
		columns.at(from).pop_back();
		return columns;
	}

	else{
		cout << "move not valid";

	}
}

void CardsDeck::moveCardFreecell(int from){
	if (checkValidMoveFreecell() == true){
		freecell.push_back(columns.at(from).back());
		columns.at(from).pop_back();
	}

	else{
		cout << "move not valid";

	}
}

void CardsDeck::moveCardFoundation(int from, int to){
	if (checkValidMoveFoundation(from, to) == true){
		foundation.at(to).push_back(columns.at(from).back());
		columns.at(from).pop_back();
	}

	else{
		cout << "move not valid";

	}
}

bool CardsDeck::winningSituation(){
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (foundation.size() != 4)
		{
			break;
		}
		else{
			if (foundation.at(i).size() != 13)
			{
			count += 0;
			}
			else{
				count += 1;
			}
		}
	}
	if (count  == 4)
	{
		return true;
	}
	else{
		return false;
	}
	
}

bool CardsDeck::checkValidMove(int from, int to){

	if (columns.at(from).back().getColour().compare(columns.at(to).back().getColour()) != 0)
	{
		string rankFrom = columns.at(from).back().getRank();
		string rankTo = columns.at(to).back().getRank();
		string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
		int fromIndex = 0;
		int toIndex = 0;
		for (int i = 0; i < 14; i++)
		{
			if (rankFrom.compare(ranks[i]) == 0)
			{
				fromIndex = i;
			}
			else if (rankTo.compare(ranks[i]) == 0)
			{
				toIndex = i;
			}
			else{
				fromIndex = fromIndex;
				toIndex = toIndex;
			}

        }
		
		if (toIndex - fromIndex == 1)
			{
				return true;
			}
		else
			{
				return false;
			}
	}
	else{
		return false;
	}
}

bool CardsDeck::checkValidMoveFreecell(){
	if (freecell.size()<4)
	{
		return true;
	}

	else{
		return false;
	}
}

bool CardsDeck::checkValidMoveFoundation(int from, int to){
	string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	if (columns.at(from).back().getSuit() == foundation.at(to).back().getSuit())
	{
		string rankFrom = columns.at(from).back().getRank();
		string rankTo = foundation.at(to).back().getRank();
		int fromIndex = 0;
		int toIndex = 0;
		for (int i = 0; i < 14; i++)
		{
			if (rankFrom.compare(ranks[i]) == 0)
			{
				fromIndex = i;
			}
			else if (rankTo.compare(ranks[i]) == 0)
			{
				toIndex = i;
			}
			else{
				fromIndex = fromIndex;
				toIndex = toIndex;
			}

        }

        if (toIndex - fromIndex == 1)
			{
				return true;
			}
		else
			{
				return false;
			}
	}

	else{
		return false;
	}


}
/*
int main(){
    cout << "hi" << endl;
    CardsDeck c;
    //c.ShufflingDeck();
    c.DealingCards();
    //c.checkValidMove(1,2);
    c.winningSituation();

	return 0;
}*/
