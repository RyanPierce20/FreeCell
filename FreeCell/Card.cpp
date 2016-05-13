#include "Card.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
using std::setw;

#include <ctime>
#include <random>
using std::cout;
using std::endl;
using std::cin;

const char * rank[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "NullRank" };

const char * suit[] { "Spades", "Hearts", "Clubs", "Diamond", "NullSuit" };
/**************************************************************
*	  Purpose:  Assigns the m_rank to Ace and m_suit to Spades
*
*         Entry:  none
*
*          Exit:  the function will leave once there both assigned.
****************************************************************/
Card::Card()
{
	//cout << "Card Constructor 1" << endl;
	m_rank = NULLRANK;
	m_suit = NULLSUIT;
}
/**************************************************************
*	  Purpose:  Destrucot
*
*         Entry:  none
*
*          Exit:  the function will delete the constructor once program ends
****************************************************************/
Card::~Card()
{
	//cout << "Card Destructor" << endl;
}
/**************************************************************
*	  Purpose:  Assigns the m_rank to rank and m_suit to suit
*
*         Entry:  rank and suit
*
*          Exit:  the function will leave once there both assigned.
****************************************************************/
Card::Card(Rank rank, Suit suit)
{
	//cout << "Card Constructor 2 " << endl;
	m_rank = rank;
	m_suit = suit;
}
/**************************************************************
*	  Purpose:  Displays a card: its rank and its suit
*
*         Entry:  none
*
*          Exit:  the function will leave once it displays the card
****************************************************************/
void Card::Display()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //sets the color
	const int DEFAULT = 7;
	if (m_suit == Hearts || m_suit == Diamonds)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_RED );
		cout << rank[m_rank - 1] << "of" << suit[m_suit] << " \t";
	}
	else
	{
		SetConsoleTextAttribute(handle, DEFAULT);
		cout << rank[m_rank - 1] << "of" << suit[m_suit] << " \t";
	}
	SetConsoleTextAttribute(handle, DEFAULT);

}
/**************************************************************
*	  Purpose:  Assigns the m_rank to rank
*
*         Entry:  none
*
*          Exit:  the function will leave once assigned.
****************************************************************/
void Card::SetRank(Rank Rank)
{
	m_rank = Rank;
}
/**************************************************************
*	  Purpose:  Assigns the m_suit to Spades
*
*         Entry:  none
*
*          Exit:  the function will leave once assigned.
****************************************************************/
void Card::SetSuit(Suit Suit)
{
	m_suit = Suit;
}
/**************************************************************
*	  Purpose:  returns the m_rank
*
*         Entry:  none
*
*          Exit:  the function will leave once its returned
****************************************************************/
Rank Card::GetRank()
{
	return m_rank;
}
/**************************************************************
*	  Purpose:  returns m_suit
*
*         Entry:  none
*
*          Exit:  the function will leave once its returned
****************************************************************/
Suit Card::GetSuit()
{
	return m_suit;
}
bool Card::operator != (const Card & rhs)
{
	bool notequal = false;
	if (m_rank != rhs.m_rank)
	{
		notequal = true;
		return notequal;
	}
	return notequal;
}

