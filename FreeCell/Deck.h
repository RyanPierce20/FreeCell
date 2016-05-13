/************************************************************************
* Class: Deck
*
* Constructors:
*	Deck();
*		This is a defualt constructor
*
* Methods:
*	void Shuffle();
*		This will shuffle the deck by choosing a card at random 52 times and make sure it wont print the same card twice.
*	Card Deal();
*		This will return each card single handed.
*
*
*
*************************************************************************/
#ifndef DECK // if not defined 
#define DECK // define it
#include "Card.h"

class Deck // class name Deck
{
private:
	int m_current_card = 0; // current card its on
	Card m_deck[52]; // the deck of cards
public:
	Deck(); // default constructor
	~Deck(); // destrucor
	Deck(const Deck & copy); //copy constructor
	Deck & operator = (const Deck & rhs); //op equals c'tor
	void Shuffle(); // chooses cards randomly then returns it
	Card Deal(); // returns a card to deal
};
#endif // end of defining