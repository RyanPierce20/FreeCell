#include "Deck.h"
#include <iostream>
#include <ctime>
#include <random>
using std::cout;
using std::endl;
/**************************************************************
*	  Purpose:  This will assign the deck of arrays to one card with its rank and its suit for 52 times
*
*         Entry:  none
*
*          Exit:  the function will leave once the array is assigned witht he ammount of suits and ranks
****************************************************************/
Deck::Deck()
{
	m_current_card = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 13; ++j)
		{
		m_deck[m_current_card].SetRank(static_cast<Rank>(j + 1));

		m_deck[m_current_card].SetSuit(static_cast<Suit>(i));

		++m_current_card;
		}

	m_current_card = 0;
	//cout << "Deck Constructor" << endl;
}
/**************************************************************
*	  Purpose:  the destructor
*
*         Entry:  none
*
*          Exit:  the function will leave once deletes
****************************************************************/
Deck::~Deck()
{
	//cout << "Deck Destructor" << endl;
}
/**************************************************************
*	  Purpose:  the copy c'tor
*
*         Entry:  none
*
*          Exit:  the function passes in a copy and sets the value of private
****************************************************************/
Deck::Deck(const Deck & copy) : m_current_card(copy.m_current_card) //copy constructor
{}
/**************************************************************
*	  Purpose:  the operator equals
*
*         Entry:  none
*
*          Exit:  the function will set the current card number
****************************************************************/
Deck & Deck::operator = (const Deck & rhs)
{
	if (this != &rhs)
	{
		m_current_card = rhs.m_current_card;
	}
	return *this;
}
/**************************************************************
*	  Purpose:  this will choose a card in the deck randomly then will make sure it hasnt occured
*
*         Entry:  none
*
*          Exit:  the function will leave once it goes through every card
****************************************************************/
void Deck::Shuffle()
{
	Card temp;
	int rand1 = 0;
	m_current_card = 0;
	for (int i = 0; i < 52; ++i) // goes through all cards
	{
		srand(time(NULL) * (i + 1)); // random function line
		rand1 = (rand() % 52);

		temp = m_deck[rand1]; // put card picked into temp

		m_deck[rand1] = m_deck[i]; // make it equal to part of m_deck
		m_deck[i] = temp; // then stick that card into the deck
	}
}
/**************************************************************
*	  Purpose:  Implements the current card so it doesnt go out of bounds, then returns the card to display.
*
*         Entry:  none
*
*          Exit:  the function will leave once the card is returned.
****************************************************************/
Card Deck::Deal()
{
	++m_current_card;
	return m_deck[m_current_card - 1];
}