/************************************************************************
* Class: FreeArea
*
* Purpose: This class is the class for everything in the free area
*
* Manager functions:
* 	FreeArea();
	~FreeArea();
	FreeArea & operator = (const FreeArea & rhs);
	FreeArea(const FreeArea & copy);
	void Display();
	void Insert(Card card, int insert);
*
* Methods:
*		Array <Card> _freeareacells;

*		...
*************************************************************************/
#ifndef FreeArea_H
#define FreeArea_H
#include "Array.h"
#include "ArrayStack.h"
#include "Card.h"
#include "Area.h"
class FreeArea 
{
	friend class Board;
public:
	FreeArea();
	~FreeArea();
	FreeArea & operator = (const FreeArea & rhs);
	FreeArea(const FreeArea & copy);
	void Display();
	void Insert(Card card, int insert);

private:
	Array <Card> _freeareacells;
};
#endif