/************************************************************************
* Class: Area
*
* Purpose: This class is just an abstract class 
*
* Manager functions:
* 	virtual void Display() = 0;
	virtual void Move() = 0;
*
* Methods:
*	
*		...
*************************************************************************/
#include <iostream>
#ifndef AREA_H
#define AREA_H
class Area
{
public:
	virtual void Display() = 0;
	virtual void Move() = 0;
private:
	
};
#endif