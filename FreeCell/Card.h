/************************************************************************
* Class: Card
*
* Constructors:
*	Card();
*		Hours, minutes, and seconds are initialized to 0.
*	Card(Rank Rank, Suit Suit);
*		Rank is set to m_rank and Suit is set to m_suit.
*
* Mutators:
*	void SetRank(Rank Rank);
*		this sets rank to m_rank.
*	void SetSuit(Suit Suit);
*		this sets suit to m_suit.
*	Rank GetRank();
*		this returns m_rank.
*	Suit GetSuit();
*		This returns m_suit.
*
* Methods:
void Display();
*		This displays the entire deck of cards.
*
*************************************************************************/

#ifndef CARD // if not defined
#define CARD // define it

// enum called rank for all the cards
enum Rank { Ace = 1, Deuce = 2, Trey = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13, NULLRANK = 14 };

// enum called suit for all the cards
enum Suit { Spades, Hearts, Clubs, Diamonds, NULLSUIT };
class Card// card name is Card
{
private:
	Rank m_rank; // value from enum
	Suit m_suit; // value from enum
public:
	Card(); // defualt constructor
	~Card(); // destructor
	Card(Rank Rank, Suit Suit); // constructor passed with Suit and Rank
	void Display(); // displays the cards one by one
	void SetRank(Rank Rank); // sets rank to m_rank
	void SetSuit(Suit Suit); // sets suit to m_suit
	Rank GetRank(); // returns m_rank
	Suit GetSuit(); // returns m_suit
	bool operator != (const Card & rhs);
};
#endif