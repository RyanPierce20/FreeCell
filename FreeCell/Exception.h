/************************************************************************
* Class: Exception
*
* Purpose: This class will display any error messsages
*
* Manager functions:
* 	Exception();
Exception(char * msg);
Exception(const Exception & copy);
~Exception();
Exception & operator = (const Exception & rhs);
const char * getMessage();
void setMessage(char * msg);
friend ostream & operator << (ostream & stream, const Exception & except);
*
* Methods:
*	char * m_msg;
*		...
*************************************************************************/
#ifndef Exception_H
#define Exception_H

#include <iostream>
using std::endl;
using std::cout;
#include <iostream>
using std::ostream;

class Exception
{
public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator = (const Exception & rhs);
	const char * getMessage();
	void setMessage(char * msg);
	friend ostream & operator << (ostream & stream, const Exception & except);
private:
	char * m_msg;
};
#endif