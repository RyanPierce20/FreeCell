/*************************************************************
*
* Lab/Assignment: Lab 3 – FreeCell
*
* Overview:
*	This program will let the user play the game FreeCell. In this
	we use stacks of linked list and arrays. It will display cards of a deck and you can
	play the rules of free cell.
*
* Input:
*	The input will consist of a deck of cards. And displays the
	areas of the board game.
*
* Output:
*	The output of this program will be the game board of cards and the
	areas of the game.
*
************************************************************/

#include <iostream>
using std::cout;
using std::endl;
#include "PlayArea.h"
#include "Card.h"
#include "FreeArea.h"
#include "HomeArea.h"
#include "Board.h"
#define _CRTDBG_MAP_ALLOC


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memory leaks
	Board board;
	board.Menu();
	return 0;
}