#include "FreeArea.h"
#include <Windows.h>
/**********************************************************************
* Purpose: This function is the free area and sets the length
*
* Precondition:
*     nothing
*
* Postcondition:
*      the length is set
*
************************************************************************/

FreeArea::FreeArea()
{
	_freeareacells.setLength(4);
}
/**********************************************************************
* Purpose: This function is the destructor
*
* Precondition:
*     nothing
*
* Postcondition:
*     nothing
*
************************************************************************/
FreeArea::~FreeArea()
{}
/**********************************************************************
* Purpose: This function is the operator = and will set the values
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are set 
*
************************************************************************/
FreeArea & FreeArea::operator = (const FreeArea & rhs)
{
	if (this != &rhs)
	{
		_freeareacells = rhs._freeareacells;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function is the copy c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are set to the copy
*
************************************************************************/
FreeArea::FreeArea(const FreeArea & copy) : _freeareacells(copy._freeareacells)
{}
/**********************************************************************
* Purpose: This function is the insert function to convert the free cells into a llinkedlist
*
* Precondition:
*     nothing
*
* Postcondition:
*      the ranks and suits are set
*
************************************************************************/
void FreeArea::Insert(Card card, int insert)
{
	_freeareacells[insert].SetRank(card.GetRank());
	_freeareacells[insert].SetSuit(card.GetSuit());
}
/**********************************************************************
* Purpose: This function is the display function for the free area
*
* Precondition:
*     nothing
*
* Postcondition:
*     evrything is outputted for the free area
*
************************************************************************/
void FreeArea::Display()
{
	int leftbotcorner = 200;
	int lefttopcorner = 201;
	int righttopcorner = 187;
	int rightbotcorner = 188;
	int side = 186;
	int topbot = 205;
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "--------FREE---PLAY---AREA-------" << endl;
	cout << char(lefttopcorner) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(righttopcorner);
	cout << char(lefttopcorner) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(righttopcorner);
	cout << char(lefttopcorner) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(righttopcorner);
	cout << char(lefttopcorner) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot) << char(righttopcorner) << endl;
	if (_freeareacells[0].GetRank() != NULLRANK)
	{
		_freeareacells[0].Display();
	}
	if (_freeareacells[1].GetRank() != NULLRANK)
	{
		_freeareacells[1].Display();
	}
	if (_freeareacells[2].GetRank() != NULLRANK)
	{
		_freeareacells[2].Display();
	}
	if (_freeareacells[3].GetRank() != NULLRANK)
	{
		_freeareacells[3].Display();
	}
	cout << endl;
	cout << char(leftbotcorner) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(rightbotcorner)
		<< char(leftbotcorner) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(rightbotcorner)
		<< char(leftbotcorner) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(rightbotcorner)
		<< char(leftbotcorner) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(topbot) << char(topbot)
		<< char(topbot) << char(topbot) << char(rightbotcorner) << endl;
}