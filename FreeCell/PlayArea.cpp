#include "PlayArea.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <Windows.h>
using std::cin;

/**********************************************************************
* Purpose: This function is the defualt c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are set
*
************************************************************************/
PlayArea::PlayArea() :_playareacells(0)
{}
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
PlayArea::~PlayArea()
{}
/**********************************************************************
* Purpose: This function is the operator =
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are sent in and the values are ste for the copy
*
************************************************************************/
PlayArea & PlayArea::operator = (const PlayArea & rhs)
{
	if (this != &rhs)
	{
		_playareacells = rhs._playareacells;
		m_deck = rhs.m_deck;
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
*      the values are set to the copy that was sent in
*
************************************************************************/
PlayArea::PlayArea(const PlayArea & copy) : m_deck(copy.m_deck), _playareacells(copy._playareacells)
{}
/**********************************************************************
* Purpose: This function is the display function for the play area
*
* Precondition:
*     nothing
*
* Postcondition:
*      everyting is displayed for the play area
*
************************************************************************/
void PlayArea::Display()
{
	Card card;
	LLStack<Card> temp[8];
	for (int i = 0; i < 8; i++)
	{
		int size = _playareacells[i].Size();
		for (int j = 0; j < size; j++)
		{
			temp[i] = _playareacells[i];
		}
	}
	int x = 0;
	int y = 5;
	cout << "---Top of Stack---" << endl;
	for (int i = 0; i < 8; i++)
	{
		int size = _playareacells[i].Size();
		for (int j = 0; j < size; j++)
		{
			COORD coord = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			card = temp[i].Pop();
			card.Display();
			y+= 1;
		}
		x += 15;
		y = 5;
	}
	COORD coord = { 0, 14 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/**********************************************************************
* Purpose: This function will deal the cards to a linked list
*
* Precondition:
*     nothing
*
* Postcondition:
*     the linked lsit is set and so are the values
*
************************************************************************/
void PlayArea::Deal()
{
	m_deck.Shuffle();
	_playareacells.setLength(8);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			_playareacells[i].Push(m_deck.Deal());
		}
	}
	for (int i = 4; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			_playareacells[i].Push(m_deck.Deal());
		}
	}	
}
/**********************************************************************
* Purpose: This function is the move function that will move all cells in the entire game
*
* Precondition:
*     nothing
*
* Postcondition:
*      the move function is called and the user is asked to see which cells they want to move
*
************************************************************************/
void PlayArea::Move()
{
	Card card;
	Card card2;
	int num = 0;
	do{
		cout << "What card would you like to move? \nEnter a column 0-7" << endl;
		cin >> num;
	} while (num < 0 || num > 7);
	int num2 = 0;
	do
	{
		cout << "Where would you like to move it? \nEnter a column 0-7" << endl;
		cin >> num2;
	} while (num2 < 0 || num > 7);
	int ammount = 0;
	do
	{
		cout << "How many cards would you like to move?" << endl;
		cin >> ammount;
	} while (ammount < 0); //need to make sure it checks for too large of number
	if (ammount < 2)
	{
		if (num != num2)
		{
			card = _playareacells[num].Pop();
			card2 = _playareacells[num2].Pop();
			if (card.GetSuit() != card2.GetSuit() && card.GetRank() == card2.GetRank() - 1) //need to compare for other suits
			{
				if (card.GetSuit() == 0)
				{
					if (card.GetSuit() + 2 != card2.GetSuit())
					{
						_playareacells[num2].Push(card2);
						_playareacells[num2].Push(card);
					}
					else
					{
						_playareacells[num].Push(card);
						_playareacells[num2].Push(card2);
					}
				}
				else if (card.GetSuit() == 1)
				{
					if (card.GetSuit() + 2 != card2.GetSuit())
					{
						_playareacells[num2].Push(card2);
						_playareacells[num2].Push(card);
					}
					else
					{
						_playareacells[num].Push(card);
						_playareacells[num2].Push(card2);
					}
				}
				else if (card.GetSuit() == 2)
				{
					if (card.GetSuit() - 2 != card2.GetSuit())
					{
						_playareacells[num2].Push(card2);
						_playareacells[num2].Push(card);
					}
					else
					{
						_playareacells[num].Push(card);
						_playareacells[num2].Push(card2);
					}
				}
				else if (card.GetSuit() == 3)
				{
					if (card.GetSuit() - 2 != card2.GetSuit())
					{
						_playareacells[num2].Push(card2);
						_playareacells[num2].Push(card);
					}
					else
					{
						_playareacells[num].Push(card);
						_playareacells[num2].Push(card2);
					}
				}
			}
			else
			{
				_playareacells[num].Push(card);
				_playareacells[num2].Push(card2);
			}
		}
	}
	else
	{
		bool checked = false;
		int count = 0;
		Card card[12];
		for (int i = 0; i < ammount; i++)
		{
			card[i] = _playareacells[num].Pop();
		}
		for (int i = ammount - 1; i >= 0; i--)
		{
			if (((card[i].GetSuit() % 2 == 0 && card[i - 1].GetSuit() % 2 != 0) || (card[i].GetSuit() % 2 != 0 && card[i - 1].GetSuit() % 2 == 0) && card[i].GetRank() == card[i - 1].GetRank() + 1))
			{
				count++;
			}
		}
		if (count == ammount - 1)
		{
			if (_playareacells[num2].isEmpty() == false)
			{
				if ((card[ammount - 1].GetSuit() % 2 == 0 && _playareacells[num2].Peek().GetSuit() % 2 != 0) || (card[ammount - 1].GetSuit() % 2 != 0 && (_playareacells[num2].Peek().GetSuit() % 2 == 0)) && card[ammount - 1].GetRank() == (_playareacells[num2].Peek().GetRank() - 1))
				{
					checked = true;
				}
			}
		}
		if (checked == true)
		{
			for (int i = ammount - 1; i >= 0; i--)
			{
				_playareacells[num2].Push(card[i]);
			}
		}
		else
		{
			for (int i = ammount-1; i >= 0; i--)
			{
				_playareacells[num].Push(card[i]);
			}
		}
	}
}