
/************************************************************************
* Class: ArrayStack
*
* Purpose: This class is the stack class for the array
*
* Manager functions:
* 	ArrayStack();
	~ArrayStack();
	ArrayStack(const ArrayStack & copy); //copy constructor
	ArrayStack & operator = (const ArrayStack & rhs); //op equals c'tor
	void Push(T data);
	T & Pop();
	T & Peek();
	int Size();
	bool isEmpty();
	bool isFull();
	void setstacksize(int size);
	int getStackSize();
*
* Methods:
*	Array<T> m_stack;
	int m_stacksize; //max
	int m_current; //current
*		...
*************************************************************************/
#ifndef ArrayStack_H
#define ArrayStack_H

#include <iostream>
#include "Array.h"
#include "Exception.h"

template <typename T>
class ArrayStack
{
public:
	ArrayStack();
	~ArrayStack();
	ArrayStack(const ArrayStack & copy); //copy constructor
	ArrayStack & operator = (const ArrayStack & rhs); //op equals c'tor
	void Push(T data);
	T & Pop();
	T & Peek();
	int Size();
	bool isEmpty();
	bool isFull();
	void setstacksize(int size);
	int getStackSize();

	/*Canonical functions – The constructor should take a single parameter that indicates the stacks size.
	Push - Pushes its parameter onto the top of the stack.
	Pop - Removes and returns the data from the top of the stack
	Peek - Returns the element on the top of the stack but does not remove it.
	Size – Returns the number of items currently on the stack.
	isEmpty – Returns true if the stack is empty.
	isFull – Returns true if the stack is full.*/


private:
	Array<T> m_stack;
	int m_stacksize; //max
	int m_current; //current
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
ArrayStack<T>::ArrayStack() : m_stack(0), m_stacksize(0), m_current(0)
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
template <typename T>
ArrayStack<T>::~ArrayStack()
{}
/**********************************************************************
* Purpose: This function is the copy c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the values are copied over
*
************************************************************************/
template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack & copy) : m_stacksize(copy.m_stacksize), m_current(copy.m_current), m_stack(copy.m_stack) //copy constructor
{}
/**********************************************************************
* Purpose: This function is the operator equals
*
* Precondition:
*     rhs is passed in
*
* Postcondition:
*      the values are set to the values
*
************************************************************************/
template <typename T>
ArrayStack<T> & ArrayStack<T>::operator = (const ArrayStack & rhs)
{
	if (this != &rhs)
	{
		m_current = rhs.m_current;
		m_stacksize = rhs.m_stacksize;
		m_stack = rhs.m_stack;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function will set the stack size of the array
*
* Precondition:
*    size is passed in
*
* Postcondition:
*      the size is set and so is the length of the stack
*
************************************************************************/
template <typename T>
void ArrayStack<T>::setstacksize(int size)
{
	if (size > 0)
	{
		m_stacksize = size;
		m_stack.setLength(size);
	}
}
/**********************************************************************
* Purpose: This function returns the stack size
*
* Precondition:
*     nothing
*
* Postcondition:
*      the stacksize is returned
*
************************************************************************/
template <typename T>
int ArrayStack<T>::getStackSize()
{
	return m_stacksize;
}
/**********************************************************************
* Purpose: This function will push data onto the stack
*
* Precondition:
*     the data is passed in
*
* Postcondition:
*      the stack has another value passed on
*
************************************************************************/
template <typename T>
void ArrayStack<T>::Push(T data)
{
	if (m_current + 1 <= m_stacksize)
	{
		m_stack[m_current] = data;
		m_current++;
	}
	else
		throw Exception("OVERFLOOWWWWWW Can't push above the stack size");
}
/**********************************************************************
* Purpose: This function will pop the data off of the stack
*
* Precondition:
*     nothing
*
* Postcondition:
*      the stack pops an item off the list
*
************************************************************************/
template <typename T>
T & ArrayStack<T>::Pop()
{
	if (m_current <= m_stacksize && m_current - 1 > 0)
	{
		T item = m_stack[m_current - 1];
		m_current--;
		return item;
	}
	else
		throw Exception("UNDERFLOWWWWW You're stack is Empty!");
}
/**********************************************************************
* Purpose: This function will return the current value on the stack
*
* Precondition:
*     nothing
*
* Postcondition:
*      the top of stack is returned
*
************************************************************************/
template <typename T>
T & ArrayStack<T>::Peek()
{
	if (isEmpty() == true)
		throw Exception("Empty can't do that");
	else
		return m_stack[m_current-1];
}
/**********************************************************************
* Purpose: This function will return the current size
*
* Precondition:
*     nothing
*
* Postcondition:
*      the size of stack is returned
*
************************************************************************/
template <typename T>
int ArrayStack<T>::Size()
{
	return m_current;
}
/**********************************************************************
* Purpose: This function will say if the stack is empty
*
* Precondition:
*     nothing
*
* Postcondition:
*      the stack returns true or false if empty
*
************************************************************************/
template <typename T>
bool ArrayStack<T>::isEmpty()
{
	//return m_current < 0;
	bool empty = false;
	if (m_current - 1 < 0)
	{
		return true;
	}
	else
		return false;
}
/**********************************************************************
* Purpose: This function will return a bool that says if the stack is full
*
* Precondition:
*     nothing
*
* Postcondition:
*      the size of stack is returned
*
************************************************************************/
template <typename T>
bool ArrayStack<T>::isFull()
{
	//return m_stacksize == (m_current + 1);
	bool empty = false;
	if (m_stacksize == m_current)
	{
		return true;
	}
	else
		return false;
}
#endif