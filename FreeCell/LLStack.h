/************************************************************************
* Class: LLstack
*
* Purpose: This class is the class for the linked list stack
*
* Manager functions:
* 	LLStack();
	~LLStack();
	LLStack(int current);
	LLStack(const LLStack & copy); //copy constructor
	LLStack & operator = (const LLStack & rhs); //op equals c'tor
	void Push(T push);
	T & Pop();
	T & Peek();
	int Size();
	bool isEmpty();

* Methods:
*		DoubleLinkedList<T> m_list;
	int m_current;

*		...
*************************************************************************/
#ifndef LLStack_H
#define LLStack_H
#include <iostream>
#include "doublelinkedlist.h"

template <typename T>
class LLStack
{
public:
	LLStack();
	~LLStack();
	LLStack(int current);
	LLStack(const LLStack & copy); //copy constructor
	LLStack & operator = (const LLStack & rhs); //op equals c'tor
	void Push(T push);
	T & Pop();
	T & Peek();
	int Size();
	bool isEmpty();

	/*Canonical functions – The constructor should take a single parameter that indicates the stacks size.
	Canonical functions

	Push - Pushes its parameter onto the top of the stack.
	Pop  - Removes and returns the data from the top of the stack.
	Peek - Returns the element on the top of the stack.
	Size – Returns the number of items currently on the stack.
	isEmpty – Returns true if the stack is empty.*/

private:
	DoubleLinkedList<T> m_list;
	int m_current;
};
/**********************************************************************
* Purpose: This is the defualt c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are set
*
************************************************************************/
template <typename T>
LLStack<T>::LLStack() : m_current(0)
{}

/**********************************************************************
* Purpose: This is the destructor
*
* Precondition:
*     nothing
*
* Postcondition:
*      nothing
*
************************************************************************/
template <typename T>
LLStack<T>::~LLStack()
{}

/**********************************************************************
* Purpose: This is the copy c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are copied over
*
************************************************************************/
template <typename T>
LLStack<T>::LLStack(const LLStack & copy) : m_current(copy.m_current), m_list(copy.m_list)  //copy constructor
{}
/**********************************************************************
* Purpose: This is the operator = c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are set and copied
*
************************************************************************/
template <typename T>
LLStack<T> & LLStack<T>::operator = (const LLStack & rhs)//op equals c'tor
{
	if (this != &rhs)
	{
		m_current = rhs.m_current;
		m_list = rhs.m_list;
	}
	return *this;
}
/**********************************************************************
* Purpose: This is the push function to push new data onto the stack
*
* Precondition:
*     nothing
*
* Postcondition:
*      the data is pushed onto the stack
*
************************************************************************/
template <typename T>
void LLStack<T>::Push(T push)
{
	m_list.Prepend(push);
	m_current++;
}
/**********************************************************************
* Purpose: This is the pop function
*
* Precondition:
*     nothing
*
* Postcondition:
*      the data is popped off the stack
*
************************************************************************/
template <typename T>
T & LLStack<T>::Pop()
{
	T data;
	if (m_list.getHead() != 0)
	{
		data = m_list.First();
		m_list.Extract(m_list.First());
		m_current--;
		return data;
	}
	else
		throw Exception("UNDERFLOWWWWW You're stack is Empty!");
}
/**********************************************************************
* Purpose: This is the peek function that can return the first data
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are returned or error thrown
*
************************************************************************/
template <typename T>
T & LLStack<T>::Peek()
{
	if (m_list.isEmpty() == true)
		throw Exception("It's Empty cant do that");
	else
		return m_list.First();
}
/**********************************************************************
* Purpose: This is the size function that returns the current size
*
* Precondition:
*     nothing
*
* Postcondition:
*      the size is returned
*
************************************************************************/
template <typename T>
int LLStack<T>::Size()
{
	return m_current;
}
/**********************************************************************
* Purpose: This is the empty functin that will say if the stack is empty
*
* Precondition:
*     nothing
*
* Postcondition:
*      the true or false statment is returned to determine if its empty
*
************************************************************************/
template <typename T>
bool LLStack<T>::isEmpty()
{
	bool empty = false;
	if (m_list.isEmpty() == true)
	{
		return true;
	}
	else
		return false;
}

#endif