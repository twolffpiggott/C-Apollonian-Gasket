/*
 * vector2d.cpp
 *
 *  Created on: 27 Apr 2015
 *      Author: Tim
 */

# include "vector2d.h"


//friend functions

double
dot(const Vec& v1, const Vec& v2) //dot product
{
	return v1.x*v2.x+v1.y*v2.y;
}

double
cross(const Vec& v1, const Vec& v2) //cross product
{
	return v1.norm()*v2.norm()*sin(acos(dot(v1,v2)/(v1.norm()*v2.norm())));
}

Vec
scalar(const double a, const Vec& vec) //scalar multiplication
{
	Vec cVec = Vec(vec);
	cVec.x=a*cVec.x;
	cVec.y=a*cVec.y;
	return cVec;
}

Vec
rotate(const double theta, const Vec& vRot) //rotate a circle theta radians anticlockwise
{
	Vec v1(cos(theta),-sin(theta)); //rotation matrix defined using two vectors
	Vec v2(sin(theta),cos(theta));
	double xprime=dot(v1,vRot); //matrix multiplication defined in two parts
	double yprime=dot(v2,vRot);
	Vec vNew(xprime,yprime);
	return vNew;
}

//overloaded operators

Vec&
Vec::operator+=(const Vec& rhs) //compound addition assignment
{
	x+=rhs.x;
	y+=rhs.y;
	return *this;
}

Vec&
Vec::operator-=(const Vec& rhs) //compound subtraction assignment
{
	x-=rhs.x;
	y-=rhs.y;
	return *this;
}

double&
Vec::operator[](const int n ) //lhs subscript operator
{
	switch(n)
	{
	case(0):
		return x;
		break;
	case (1):
		return y;
		break;
	default:
		cerr<<"Error: index out of bounds\n";
		break;
	}
}

const double &
Vec::operator[](const int n) const //rhs subscript operator
{
	switch(n)
	{
	case(0):
		return x;
		break;
	case(1):
		return y;
		break;
	default:
		cerr<<"Error: index out of bounds\n";
		break;
	}
}


//more overloaded operators

Vec
operator+(const Vec& aVec, const Vec& bVec) //vector addition
{
	Vec cVec(aVec);
	cVec+=(bVec);
	return cVec;

}

Vec
operator-(const Vec& aVec, const Vec& bVec) //vector subtraction
{
	Vec cVec(aVec);
	cVec-=bVec;
	return cVec;
}

//methods

double
Vec::norm(void) const//calculates norm of given vector
{
	return sqrt(dot(*this,*this));
}

double
Vec::max(void) const //returns the maximum element of given vector
{
	switch(1*(x>=y))
	{
	case(0):
		return y;
		break;
	case(1):
		return x;
		break;
	default:
		cerr<<"Error: problem with vector\n";
		break;
	}
}

double
Vec::min(void) const//returns the minimum element of given vector
{
	switch(1*(x<=y))
	{
	case(0):
		return y;
		break;
	case(1):
		return x;
		break;
	default:
		cerr<<"Error: problem with vector\n";
		break;
	}
}

