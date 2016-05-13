/************************************************************************
* Class: doublelinkedlist
*
* Purpose: This class creates a doubly linked list ADT
*
* Manager functions:
* 	DoubleLinkedList(); //default ctor sets members to null
~DoubleLinkedList(); //destructor calls purge
DoubleLinkedList & operator = (const DoubleLinkedList<T> & rhs); //copies over linked list
DoubleLinkedList(const DoubleLinkedList<T> & copy); //copies over linked list
bool isEmpty(); //tests if linked list is empty
T & First() const; //returns first in data
T & Last() const; //returns last in data

void Prepend(T); //puts item in front
void Append(T); //puts item last
void Purge(); //deletes everything
void Extract(T); //deletes one list

void InsertAfter(const T & new_data, const T & existing_data); //inserts after a data in it
void InsertBefore(const T & new_data, const T & existing_data); //inserts before a data number in it

Node<T> * getHead() const; //returns the head of list
Node<T> * getTail() const; //returns the last of list

void PrintForwards(); //displays from beginning to end
void PrintBackwards(); //displays from end to beginning
*
* Methods:
*	Node<T> * m_head;
Node<T> * m_tail;
*		...
*************************************************************************/


#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include "Node.H"

#include <iostream>
using std::cout;


template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList(); //default ctor sets members to null
	~DoubleLinkedList(); //destructor calls purge
	DoubleLinkedList & operator = (const DoubleLinkedList<T> & rhs); //copies over linked list
	DoubleLinkedList(const DoubleLinkedList<T> & copy); //copies over linked list
	bool isEmpty(); //tests if linked list is empty
	T & First() const; //returns first in data
	T & Last() const; //returns last in data

	void Prepend(T); //puts item in front
	void Append(T); //puts item last
	void Purge(); //deletes everything
	void Extract(T); //deletes one list

	void InsertAfter(const T & new_data, const T & existing_data); //inserts after a data in it
	void InsertBefore(const T & new_data, const T & existing_data); //inserts before a data number in it

	Node<T> * getHead() const; //returns the head of list
	Node<T> * getTail() const; //returns the last of list

	void PrintForwards(); //displays from beginning to end
	void PrintBackwards(); //displays from end to beginning

private:
	Node<T> * m_head;
	Node<T> * m_tail;

};

/**********************************************************************
* Purpose: This function will determine
*
* Precondition:
*     if the list is empty then itll return the bool
*
* Postcondition:
*      Returns the bool if the list is empty or not.
*
************************************************************************/

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	bool empty = true;
	if (m_head != NULL) //checks if list is empty
	{
		empty = false;
	}
	return empty;
}
/**********************************************************************
* Purpose: This function returns the front element in the linked list
* Precondition:
*     nothing is passed in but checks if the head is empty
*
* Postcondition:
*      returns the data in the front of list
*
************************************************************************/

template <typename T>
T & DoubleLinkedList<T>::First() const
{
	if (m_head != nullptr)
	{
		return m_head->m_data; //returns the data of head
	}
	else
		throw Exception("No First");
		//cout << "No element in First" << endl;
}

/**********************************************************************
* Purpose: This function returns the last element in the linked list
* Precondition:
*     nothing is passed in but checks if the tail is empty
*
* Postcondition:
*      returns the data in the last of list
*
************************************************************************/
template <typename T>
T & DoubleLinkedList<T>::Last() const
{
	if (m_tail != nullptr)
	{
		return m_tail->m_data; //returns real data of tail
	}
	else
		throw Exception("No Element in Last");
}

/**********************************************************************
* Purpose: This function will put the item at the end of the list
*
* Precondition:
*     m_data is passed in and will be put at the end of the list once
*	it checks the tail of the list and will set the previous and next for the nodes
*
* Postcondition:
*      it will put the data at the end of the list
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::Append(T m_data)
{
	Node<T> * later = m_tail; //new node set tail
	m_tail = new Node<T>(m_data);
	if (m_tail != nullptr) //if not empty
	{
		m_tail->SetPrevious(later); //sets the previous
		m_tail->SetNext(nullptr); //sets the next ptr
	}
	if (later != nullptr)
	{
		later->SetNext(m_tail); //if its not empty then sets next
	}
	if (m_head == nullptr)
	{
		m_head = m_tail; //sets equal
	}
}

/**********************************************************************
* Purpose: This function will put the incoming data at the beginning of the list
*
* Precondition:
*     the new data is passed in and will check the head of the linked list then it will set
*	the next and previous pointers
*
* Postcondition:
*      all the values are set and the new data is in the front
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::Prepend(T m_data)
{
	Node<T> * previous = m_head; // sets the new pointer to the head
	m_head = new Node<T>(m_data); //head gets the new data
	if (previous != nullptr)
	{
		previous->SetPrevious(m_head); // if its not empty then it sets the right previous
	}
	m_head->SetNext(previous); //sets the next ptr
	m_head->SetPrevious(nullptr);
	if (m_tail == nullptr)
	{
		m_tail = m_head; //sets equal 
	}
}

template <typename T>
Node<T> * DoubleLinkedList<T>::getHead() const
{
	return m_head; //returns the head of the list
}

template <typename T>
Node<T> * DoubleLinkedList<T>::getTail() const
{
	return m_tail; //returns the tail of the list
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) //sets the values to nullptr
{

}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge(); //calls the purge to delete all the elements
}

/**********************************************************************
* Purpose: This function calls the delete function and will copy over the
*	linked list
*
* Precondition:
*     the linked list is passed in
*
* Postcondition:
*      this will return the this pointer of all the elements
*
************************************************************************/

template <typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator = (const DoubleLinkedList<T> & rhs)
{
	if (this != &rhs)
	{
		Purge(); //deletes  all orevious elements
		Node<T> * travel = rhs.m_head; //copies into travel
		while (travel != nullptr)
		{
			Append(travel->GetData()); //puts at end of list
			travel = travel->GetNext(); //goes to the list until empty
		}
	}
	return *this; //return the information of linked list
}
/**********************************************************************
* Purpose: This function will pass in the the copier of lists
*
* Precondition:
*     the linked list is passed in and will copy to the list by using append
*
* Postcondition:
*      the list is copied over until its empty
*
************************************************************************/

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & copy)
{
	m_head = nullptr;
	m_tail = nullptr;
	Node<T> * travel = copy.m_head; //copies into travel
	while (travel != nullptr)
	{
		Append(travel->GetData()); //puts at end of list
		travel = travel->GetNext(); //goes to the list until empty
	}
}
/**********************************************************************
* Purpose: This function will print all elements from the front to end
*
* Precondition:
*     nothing is passed in but it will display alll elements in list
*
* Postcondition:
*      front to last of list is displayed
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::PrintForwards()
{
	Node<T> * og_head = m_head; //copied over 
	while (m_head != nullptr)
	{
		cout << m_head->GetData() << endl; //displays the data
		m_head = m_head->GetNext(); //goes to next element
	}
	m_head = og_head;
}
/**********************************************************************
* Purpose: This function displays the info from last to front
*
* Precondition:
*     nothing is passed in and will display all elements
*
* Postcondition:
*      nothing is changed except will display everything
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::PrintBackwards()
{
	Node<T> * og_tail = m_tail;
	while (m_tail != nullptr)
	{
		cout << m_tail->GetData() << endl; //displays elements
		m_tail = m_tail->GetPrevious(); //goes to next element
	}
	m_tail = og_tail; //set back
}

/**********************************************************************
* Purpose: This function deletes everything so no memeory leaks in linked list
*
* Precondition:
*     this is called from the destructor and will delete all elements
*
* Postcondition:
*      deletes everything and sets the last elements to nullptr
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::Purge()
{
	while (m_head != nullptr)
	{
		Node<T> * travel = m_head; //sets to list
		m_head = m_head->m_next; //goes to next element
		delete travel; //deletes info
	}
	m_head = nullptr; //sets to nullptr so not random number
	m_tail = nullptr;
}
/**********************************************************************
* Purpose: This function will insert the data after the existing data
*
* Precondition:
*     two const referenced data members are passed in to enter the new data
*
* Postcondition:
*      wont return anything and will put info after the existing data
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::InsertAfter(const T & new_data, const T & existing_data)
{
	Node<T> * travel = m_head;
	while (travel != nullptr && travel->GetData() != existing_data)//search through the node until its equal
	{
		travel = travel->GetNext();
	}
	if (travel)
	{
		if (travel == m_tail)//if its the last in the list then append it
		{
			Append(new_data);
		}
		else if (travel == m_head) //if its the first in the list then do this
		{
			Node<T> * before = new Node<T>(new_data); //make new data into Node *
			before->SetPrevious(m_head); //set previous to the front of new data
			before->m_next = m_head->m_next; //set the next to the last of data
			m_head->m_next->m_previous = before; //set the entire thing of m_head to new data
			m_head->SetNext(before); //set next data to before
		}
		else
		{
			Node<T> * before = new Node<T>(new_data); //if its in the middle then do this
			before->SetNext(travel->GetNext());//set the next to the last of the list
			before->SetPrevious(travel); //set the previous to the front 
			travel->m_next->m_previous = before; //the new data to the right location
			travel->SetNext(before); //have everything set to travels next
		}
	}
	else
	{
		throw "InsertBefore but existing_data doesn't exist";
	}
}
/**********************************************************************
* Purpose: This function will insert before existing data and will insert new data
*
* Precondition:
*     new data to be enetered and enter it at existing data and it will insert in the list
*
* Postcondition:
*      the new data will be entered after the ecisting data
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::InsertBefore(const T & new_data, const T & existing_data)
{
	Node<T> * travel = nullptr;
	Node<T> * trail = nullptr;

	if (m_head == 0)
		throw "Error Can't InsertAfter with Empty List";
	if (existing_data == m_head->GetData())//(_stricmp(insert->data->GetLName(), m_head->data->GetLName()) <= 0)
	{
		Prepend(new_data); //if its in the front then prepend
	}
	else
	{
		travel = m_head;
		trail = nullptr;

		while (travel != nullptr && travel->GetData() != existing_data)//_stricmp(travel->data->GetLName(), insert->data->GetLName()) < 0)
		{
			trail = travel; //search for the data
			travel = travel->GetNext();
		}
		if (travel != nullptr)
		{
			Node<T> * before = new Node<T>(new_data);
			before->SetPrevious(travel->GetPrevious());
			before->SetNext(travel);
			trail->SetNext(before);
			travel->SetPrevious(before); //sets all data to correctness
		}
		else
		{
			throw "Error InsertAfter but existing_data doesn't exist";
		}
	}
}
/**********************************************************************
* Purpose: This function will delete one specific node in the list
*
* Precondition:
*     the one they want to delete will be dleted in the list
*
* Postcondition:
*      nothing returned but the existing data has one deleted from the list
*
************************************************************************/

template <typename T>
void DoubleLinkedList<T>::Extract(T delet)
{
	Node<T> * travel = m_head;
	while (travel != nullptr && travel->GetData() != delet)
	{
		travel = travel->GetNext(); //searches until its found
	}
	if (travel)//if its empty then leave
	{
		if (travel == m_head)
		{
			m_head = travel->GetNext();//if its the front then get next and delete front
		}
		if (travel == m_tail)
		{
			m_tail = travel->GetPrevious(); //if its the last then get previous and delete last
		}
		else if (travel->GetPrevious() != nullptr)
		{
			travel->m_previous->m_next = travel->GetNext(); //if nothing then search for it
			travel->m_next->m_previous = travel->GetPrevious();
		}
		if (m_head)
			m_head->m_previous = nullptr;
		if (m_tail)
			m_tail->m_next = nullptr;
		delete travel;
//delete once found
	}
	else
		throw "No Data in List";
}

#endif