/************************************************************************
* Class: PLayArea
*
* Purpose: This class is the class for everything in the play area
*
* Manager functions:
* 	PlayArea();
	~PlayArea();
	PlayArea & operator = (const PlayArea & rhs);
	PlayArea(const PlayArea & copy);
	void Display();
	void Deal();
	void Remove();
	void Move();
	
* Methods:
*			Array <LLStack<Card>> _playareacells;
	Deck m_deck;

*		...
*************************************************************************/
#ifndef PlayArea_H
#define PlayArea_H
#include "LLStack.h"
#include "Array.h"
//#include "Card.h"
#include "Area.h"
#include "Deck.h"
class PlayArea : Area
{
	friend class Board;
public:
	PlayArea();
	~PlayArea();
	PlayArea & operator = (const PlayArea & rhs);
	PlayArea(const PlayArea & copy);
	void Display();
	void Deal();
	void Move();
	

private:
	Array <LLStack<Card>> _playareacells;
	Deck m_deck;
};
#endif