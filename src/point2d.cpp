/*
 * point2d.cpp
 *
 *  Created on: 27 Apr 2015
 *      Author: Tim
 */

# include "point2d.h"

//overloaded friend operators

ostream&
operator<<(ostream& out, const Point& inPoint) //vector output to stream
{
	out<<"\t"<<inPoint.x<<"\t"<<inPoint.y;
	return out;
}

istream&
operator>>(istream& in, Point& inPoint) //vector input from stream
{
	in>>inPoint.x>>inPoint.y;
	if (!in)
	{
		cout<<"Error reading data for Vec"<<endl;
		inPoint=Point();
	}
	return in;
}

bool
operator==(const Point& lhs, const Point& rhs) //equality operator
{
	return lhs.x==rhs.x && lhs.y==rhs.y;
}

bool
operator!=(const Point& lhs, const Point& rhs) //inequality operator
{
	return !(lhs==rhs);
}

//overloaded member operators

Point&
Point::operator=(const Point& rhs) //assignment operator
{
	x=rhs.x;
	y=rhs.y;
	return *this;
}

