#include <iostream>

#include "Exception.h"
using std::endl;
using std::cout;
/**********************************************************************
* Purpose: This function is the defualt c'tor
*
* Precondition:
*     nothing
*
* Postcondition:
*      message is base memberalized
*
************************************************************************/

Exception::Exception() : m_msg(0)
{
	//cout << "In default arg c'tor for Exception" << endl;
}
/**********************************************************************
* Purpose: This function is the one arg c'tor
*
* Precondition:
*     message is set to the other message
*
* Postcondition:
*      the message is set
*
************************************************************************/

Exception::Exception(char * msg) : m_msg(msg)
{
	//cout << "In one arg c'tor for Exception" << endl;
}
/**********************************************************************
* Purpose: This function is the copy c'tor
*
* Precondition:
*     the message is passed in
*
* Postcondition:
*      the copy is set to the private member
*
************************************************************************/

Exception::Exception(const Exception & copy) : m_msg(copy.m_msg)
{
}
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

Exception::~Exception()
{
	//cout << "In Exception destructor" << endl;
}
/**********************************************************************
* Purpose: This function is the operator =
*
* Precondition:
*     the rhs is passed in
*
* Postcondition:
*      the private member is equal to the message
*
************************************************************************/

Exception & Exception::operator = (const Exception & rhs)
{
	if (this != &rhs)
	{
		m_msg = rhs.m_msg;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function gets the message
*
* Precondition:
*     nothing
*
* Postcondition:
*      the message is returned
*
************************************************************************/

const char * Exception::getMessage()
{
	return m_msg;
}
/**********************************************************************
* Purpose: This function is the message setter
*
* Precondition:
*     the message is sent in
*
* Postcondition:
*      the message is set
*
************************************************************************/

void Exception::setMessage(char * msg)
{
	m_msg = msg;
}
/**********************************************************************
* Purpose: This function is the operator alligator that will return the stream or message
*
* Precondition:
*     the ostream is sent in and so is the message
*
* Postcondition:
*      return the stream which is the message sent in
*
************************************************************************/

ostream & operator << (ostream & stream, const Exception & except)
{
	stream << except.m_msg << endl;
	return stream;
}