

/************************************************************************
* Class: board
*
* Purpose: This class displays the board and game and plays the game
*
* Manager functions:
* 	Board();
	~Board();
	Board & operator = (const Board & rhs);
	Board(const Board & copy);
	void DisplayBoard();
	void Menu();
	void Move();
*
* Methods:
*	FreeArea _freecells;
	HomeArea _homecells;
	PlayArea _playcells;
	bool GameOver = false;
*		...
*************************************************************************/
#include "Array.h"
#include "FreeArea.h"
#include "HomeArea.h"
#include "PlayArea.h"
#include <iostream>
using std::cin;
class Board
{
public:
	Board();
	~Board();
	Board & operator = (const Board & rhs);
	Board(const Board & copy);
	void DisplayBoard();
	void Menu();
	void Move();
	bool CheckGame();
private:
	FreeArea _freecells;
	HomeArea _homecells;
	PlayArea _playcells;
	bool GameOver = false;
};