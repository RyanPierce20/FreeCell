/*************************************************************
* Author:		Ryan Pierce
* Filename:		Assignment2.cpp
* Date Created:	1/5/2016
* Modifications:	1/5/01 -started
*					1/6/16	added more
1/7/16
1/8/16	finished
**************************************************************/
/************************************************************************
* Class: Node
*
* Purpose: This class creates Node pointers and is a template for the Doubly linked list.
*
* Manager functions:
* 	Node(); //default ctor
~Node(); //destructor sets things to nullptr
Node(T); //copy ctor
Node * GetNext() const; //returns m_next
Node * GetPrevious() const; //returns m_previous
T GetData() const; //returns get data
void SetNext(Node * setter); //sets next node
void SetPrevious(Node * setter); //sets previous
void SetData(Node * setter); //sets data
*
* Methods:
*	T m_data;
Node<T> * m_next;
Node<T> * m_previous;
*		...
*************************************************************************/


#ifndef Node_H
#define Node_h

#include "doublelinkedlist.h"

template <typename T> class DoubleLinkedList;

template <typename T>
class Node
{
	friend class DoubleLinkedList < T >;
public:
	Node();
	~Node();
	Node(T);
	Node * GetNext() const;
	Node * GetPrevious() const;
	T GetData() const;
	void SetNext(Node * setter);
	void SetPrevious(Node * setter);
	void SetData(Node * setter);

private:
	T m_data;
	Node<T> * m_next;
	Node<T> * m_previous;
};

template <typename T>
Node<T>::Node() : m_next(nullptr), m_previous(nullptr)
{
	//cout << "In Node Construct" << endl;
}

template <typename T>
Node<T>::Node(T data)
{
	m_data = data;
}

template <typename T>
Node<T>::~Node()
{
	m_next = nullptr;
	m_previous = nullptr;
	//cout << "In Node Destruct" << endl;
}

template <typename T>
Node<T> * Node<T>::GetNext() const
{
	return m_next;
}

template <typename T>
T Node<T>::GetData() const
{
	return m_data;
}

template <typename T>
Node<T> * Node<T>::GetPrevious() const
{
	return m_previous;
}
template <typename T>
void Node<T>::SetNext(Node * setter)
{
	m_next = setter;
}
template <typename T>
void Node<T>::SetPrevious(Node * setter)
{
	m_previous = setter;
}
template <typename T>
void Node<T>::SetData(Node * setter)
{
	m_data = setter;
}

#endif