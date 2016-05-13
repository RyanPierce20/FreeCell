#include "Board.h"

/**********************************************************************
* Purpose: This function is the defualt c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      nothing
*
************************************************************************/

Board::Board()
{}
/**********************************************************************
* Purpose: This function is the destructor
*
* Precondition:
*     Lnothing
*
* Postcondition:
*     nothing
*
************************************************************************/

Board::~Board()
{}
/**********************************************************************
* Purpose: This function is the operator = function
*
* Precondition:
*     the copy sent in is then setting the old data
*
* Postcondition:
*      the new data is set to the old data
*
************************************************************************/

Board & Board::operator = (const Board & rhs)
{
	if (this != &rhs)
	{
		_homecells = rhs._homecells;
		_freecells = rhs._freecells;
		_playcells = rhs._playcells;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function is the copy c;tor
*
* Precondition:
*     the copy is sent in
*
* Postcondition:
*      then use base memberalization to set the values to the copy
*
************************************************************************/

Board::Board(const Board & copy) : _playcells(copy._playcells), _freecells(copy._freecells), _homecells(copy._homecells)
{}
/**********************************************************************
* Purpose: This function is the menu function which will choose to quit or shuffle cards
*
* Precondition:
*     nothing
*
* Postcondition:
*      shuffles the deck and displays the entire board
*
************************************************************************/

void Board::Menu()
{
	int option = 0;
	do
	{
		cout << "Choose you're option." << endl;
		cout << "1. Shuffle Cards \n2. Quit" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> option;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (option > 2 || option < 0);

	switch (option)
	{
	case 1:
	{
		system("cls");
		Deck deck;
		deck.Shuffle();
		deck.Deal();
		DisplayBoard();
		break;
	}
	case 2:
		cout << "Bye" << endl;
		break;
	}
}
/**********************************************************************
* Purpose: This function will display everything on the board
*
* Precondition:
*     nothing
*
* Postcondition:
*      everything is displayed
*
************************************************************************/

void Board::DisplayBoard()
{
	_homecells.Display();
	_freecells.Display();
	_playcells.Deal();
	_playcells.Display();
	do
	{
		Move();
		CheckGame();
	}while (GameOver == false);
	if (GameOver == true)
	cout << "YOU WIN" << endl;
}
/**********************************************************************
* Purpose: This function is called move and will let the user move any cell of their
choice to certain locations on the board
*
* Precondition:
*    nbothing
*
* Postcondition:
*      the menu keeps displaying until the game is over,
and the user keeps choosing whether what cell to move.
It'll check for anything that will hurt the rules.
*
************************************************************************/

void Board::Move()
{
	int source = 0;
	int destination = 0;
	cout << "Enter what area you would like to move. Ex: Source\nFreeCell = 1, PlayCell = 2, HomeCell =3" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> source;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Enter what area you would like to move to. Ex: Destination\nFreeCell = 1, PlayCell = 2, HomeCell =3" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> destination;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (source == 1)//freecell
	{
		//move freecells
		if (destination == 1)
		{
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
			cout << "No need to move a card to the same spot!" << endl;
		}
		if (destination == 2)//playcell
		{
			int col = 0;
			int free = 0;
			do
			{
				cout << "What card would you like to move?\n0-3" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> free;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (free > 3 || free < 0);
			do{
				cout << "What column would you like to move it to?" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> col;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (col > 7 || col < 0);
			if (_freecells._freeareacells[free].GetRank() != NULLRANK && _playcells._playareacells[col].Peek().GetRank() - 1 == _freecells._freeareacells[free].GetRank())
			{
				if (_freecells._freeareacells[free].GetSuit() == 0)
				{
					if (_freecells._freeareacells[free].GetSuit() + 2 != _playcells._playareacells[col].Peek().GetSuit())
					{
						_playcells._playareacells[col].Push(_freecells._freeareacells[free]);
						_freecells._freeareacells[free].SetRank(NULLRANK);
						_freecells._freeareacells[free].SetSuit(NULLSUIT);
					}
				}
				else if (_freecells._freeareacells[free].GetSuit() == 1)
				{
					if (_freecells._freeareacells[free].GetSuit() + 2 != _playcells._playareacells[col].Peek().GetSuit())
					{
						_playcells._playareacells[col].Push(_freecells._freeareacells[free]);
						_freecells._freeareacells[free].SetRank(NULLRANK);
						_freecells._freeareacells[free].SetSuit(NULLSUIT);
					}
				}
				else if (_freecells._freeareacells[free].GetSuit() == 2)
				{
					if (_freecells._freeareacells[free].GetSuit() - 2 != _playcells._playareacells[col].Peek().GetSuit())
					{
						_playcells._playareacells[col].Push(_freecells._freeareacells[free]);
						_freecells._freeareacells[free].SetRank(NULLRANK);
						_freecells._freeareacells[free].SetSuit(NULLSUIT);
					}
				}
				else if (_freecells._freeareacells[free].GetSuit() == 3)
				{
					if (_freecells._freeareacells[free].GetSuit() - 2 != _playcells._playareacells[col].Peek().GetSuit())
					{
						_playcells._playareacells[col].Push(_freecells._freeareacells[free]);
						_freecells._freeareacells[free].SetRank(NULLRANK);
						_freecells._freeareacells[free].SetSuit(NULLSUIT);
					}
				}
			}
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
		}
		if (destination == 3)//homecell
		{
			int col = 0;
			int free = 0;
			do
			{
				cout << "What card would you like to move?\n0-3" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> free;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (free > 3 || free < 0);
			do
			{
				cout << "What column would you like to move it to?\n0-3" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> col;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (col > 3 || col < 0);
			if (_homecells._homeareacells[free].isEmpty() == false)
			{
				if (_homecells._homeareacells[free].Peek().GetSuit() == 0)
				{
					if (_homecells._homeareacells[free].Peek().GetSuit() == _freecells._freeareacells[col].GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _freecells._freeareacells[col].GetRank() - 1)
					{
						_homecells._homeareacells[free].Push(_freecells._freeareacells[col]);
					}
				}
				else if (_homecells._homeareacells[free].Peek().GetSuit() == 1)
				{
					if (_homecells._homeareacells[free].Peek().GetSuit() == _freecells._freeareacells[col].GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _freecells._freeareacells[col].GetRank() - 1)
					{
						_homecells._homeareacells[free].Push(_freecells._freeareacells[col]);
					}
				}
				else if (_homecells._homeareacells[free].Peek().GetSuit() == 2)
				{
					if (_homecells._homeareacells[free].Peek().GetSuit() == _freecells._freeareacells[col].GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _freecells._freeareacells[col].GetRank() - 1)
					{
						_homecells._homeareacells[free].Push(_freecells._freeareacells[col]);
					}
				}
				else if (_homecells._homeareacells[free].Peek().GetSuit() == 3)
				{
					if (_homecells._homeareacells[free].Peek().GetSuit() == _freecells._freeareacells[col].GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _freecells._freeareacells[col].GetRank() - 1)
					{
						_homecells._homeareacells[free].Push(_freecells._freeareacells[col]);
					}
				}
			}
			else
			{
				if (_freecells._freeareacells[col].GetRank() == Ace)
					_homecells._homeareacells[free].Push(_freecells._freeareacells[col]);
			}
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
		}
	}
	else if (source == 2)
	{
		//move playcells
		if (destination == 1)//freecell
		{
			int col = 0;
			int free = 0;
			do
			{
				cout << "What column is the card in that you would like to move?" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> free;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (free > 7 || free < 0);
			do
			{
				cout << "What column would you like to move it to?\n0-3" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> col;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (col > 3 || col < 0);
			if (_freecells._freeareacells[col].GetRank() == NULLRANK)
				_freecells.Insert(_playcells._playareacells[free].Pop(), col);
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
		}
		if (destination == 2)
		{
			_playcells.Move();
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
		}
		if (destination == 3)//homecell
		{
			int col = 0;
			int free = 0;
			do
			{
				cout << "What column is the card you would like to move?" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> col;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (col > 7 || col < 0);
			do
			{
				cout << "What home cell would you like to move it to?\n0-3" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> free;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			} while (free > 3 || free < 0);
			if (_playcells._playareacells[col].isEmpty() == false)
			{
				if (_homecells._homeareacells[free].isEmpty() == false)
				{
					if (_homecells._homeareacells[free].Peek().GetSuit() == 0)
					{
						if (_homecells._homeareacells[free].Peek().GetSuit() == _playcells._playareacells[col].Peek().GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _playcells._playareacells[col].Peek().GetRank() - 1)
						{
							_homecells._homeareacells[free].Push(_playcells._playareacells[col].Pop());
						}
					}
					else if (_homecells._homeareacells[free].Peek().GetSuit() == 1)
					{
						if (_homecells._homeareacells[free].Peek().GetSuit() == _playcells._playareacells[col].Peek().GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _playcells._playareacells[col].Peek().GetRank() - 1)
						{
							_homecells._homeareacells[free].Push(_playcells._playareacells[col].Pop());
						}
					}
					else if (_homecells._homeareacells[free].Peek().GetSuit() == 2)
					{
						if (_homecells._homeareacells[free].Peek().GetSuit() == _playcells._playareacells[col].Peek().GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _playcells._playareacells[col].Peek().GetRank() - 1)
						{
							_homecells._homeareacells[free].Push(_playcells._playareacells[col].Pop());
						}
					}
					else if (_homecells._homeareacells[free].Peek().GetSuit() == 3)
					{
						if (_homecells._homeareacells[free].Peek().GetSuit() == _playcells._playareacells[col].Peek().GetSuit() && _homecells._homeareacells[free].Peek().GetRank() == _playcells._playareacells[col].Peek().GetRank() - 1)
						{
							_homecells._homeareacells[free].Push(_playcells._playareacells[col].Pop());
						}
					}
				}
				else
				{
					if (_playcells._playareacells[col].Peek().GetRank() == Ace)
					_homecells._homeareacells[free].Push(_playcells._playareacells[col].Pop());
				}
			}
			system("cls");
			_homecells.Display();
			_freecells.Display();
			_playcells.Display();
		}
	}
	else if (source == 3)
	{
		cout << "You can't move from the Home Cells!!" << endl;
	}
}
/**********************************************************************
* Purpose: This function will check to see if the game is over
*
* Precondition:
*    nbothing
*
* Postcondition:
*      if the bool is true, then the game is officially over
*
************************************************************************/
bool Board::CheckGame()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		GameOver = _homecells._homeareacells[i].isFull();
		if (GameOver == true)
		{
			count++;
		}
	}
	if (count == 4)
		return GameOver = true;
	else
		return GameOver = false;
}