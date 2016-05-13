/************************************************************************
* Class: HomeArea
*
* Purpose: This class is the class for everything in the home area
*
* Manager functions:
* 	HomeArea();
	~HomeArea();
	HomeArea & operator = (const HomeArea & rhs);
	HomeArea(const HomeArea & copy);
	void Display();
* Methods:
*			Array <ArrayStack<Card>> _homeareacells;

*		...
*************************************************************************/
#ifndef HomeArea_H
#define HomeArea_H
#include "Array.h"
#include "Card.h"
#include "ArrayStack.h"
#include "Area.h"
class HomeArea
{
	friend class Board;
public:
	HomeArea();
	~HomeArea();
	HomeArea & operator = (const HomeArea & rhs);
	HomeArea(const HomeArea & copy);
	void Display();

private:
	Array <ArrayStack<Card>> _homeareacells;
};
#endif