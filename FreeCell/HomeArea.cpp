#include "HomeArea.h"
#include <Windows.h>

/**********************************************************************
* Purpose: This function is the defualt c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the length is set to 4 and the size is also set
*
************************************************************************/
HomeArea::HomeArea()
{
	_homeareacells.setLength(4);
	for (int i = 0; i < 4; i++)
	{
		_homeareacells[i].setstacksize(13);
	}
}
/**********************************************************************
* Purpose: This function is the destructor
*
* Precondition:
*     nothing
*
* Postcondition:
*      nothing
*
************************************************************************/
HomeArea::~HomeArea()
{}
/**********************************************************************
* Purpose: This function is the operator equals functrion
*
* Precondition:
*     nothing
*
* Postcondition:
*      the copy is sent in and the values are set
*
************************************************************************/
HomeArea & HomeArea::operator = (const HomeArea & rhs)
{
	if (this != &rhs)
	{
		_homeareacells = rhs._homeareacells;
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
*      the values are set once the copy is sent in
*
************************************************************************/
HomeArea::HomeArea(const HomeArea & copy) : _homeareacells(copy._homeareacells)
{}
/**********************************************************************
* Purpose: This function display is to display the entire home area
*
* Precondition:
*     nothing
*
* Postcondition:
*      everything is displayed for the home area
*
************************************************************************/
void HomeArea::Display()
{
	COORD coord = { 62,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	int leftbotcorner = 200;
	int lefttopcorner = 201;
	int righttopcorner = 187;
	int rightbotcorner = 188;
	int side = 186;
	int topbot = 205;
	cout << "--------HOME---PLAY---AREA-------" << endl;
	COORD coord4 = { 62, 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord4);

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
	COORD coord1 = { 62, 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
	if (_homeareacells[0].isEmpty() == false)
	{
		_homeareacells[0].Peek().Display();
	}
	if (_homeareacells[1].isEmpty() == false)
	{
		_homeareacells[1].Peek().Display();
	}
	if (_homeareacells[2].isEmpty() == false)
	{
		_homeareacells[2].Peek().Display();
	}
	if (_homeareacells[3].isEmpty() == false)
	{
		_homeareacells[3].Peek().Display();
	}
	COORD coord2 = { 62, 3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
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