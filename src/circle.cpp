/*
 * circle.cpp
 *
 *  Created on: 29 Apr 2015
 *      Author: Tim
 */

#include "circle.h"

//constructor from three points

Vec get_center(const Vec& p1, const Vec& p2, const Vec& p3) //according to method using dot-products and cross-products
{
	Vec cVec;
	double alpha=(pow((p2-p3).norm(),2)*dot(p1-p2,p1-p3))/(2*pow(cross(p1-p2,p2-p3),2));
	double beta=(pow((p1-p3).norm(),2)*dot(p2-p1,p2-p3))/(2*pow(cross(p1-p2,p2-p3),2));
	double gamma=(pow((p1-p2).norm(),2)*dot(p3-p1,p3-p2))/(2*pow(cross(p1-p2,p2-p3),2));
	cVec=scalar(alpha,p1)+scalar(beta,p2)+scalar(gamma,p3);
	return cVec;
}

double get_radius(const Vec& p1, const Vec& p2, const Vec& p3) //according to method using dot-products and cross-products
{
	double c;
	c=(p1-p2).norm()*(p2-p3).norm()*(p3-p1).norm()/(2*(cross(p1-p2,p2-p3)));
	return c;
}

//overloaded friend operators

ostream&
operator<<(ostream& out, const Circle& inCircle) //circle output to stream
{
	out<<"center: "<<inCircle.p<<"\n"<<"radius: "<<inCircle.r<<endl;
	return out;
}

istream&
operator>>(istream& in, Circle& inCircle) //circle input from stream
{
	cout<<"Enter the coordinates followed by the radius of the circle:"<<endl;
	in>>inCircle.p>>inCircle.r;
	if (!in)
	{
		cout<<"Error reading data for Circle"<<endl;
		inCircle=Circle();
	}
	return in;
}

bool
operator==(const Circle& lhs, const Circle& rhs) //equality operator
{
	return lhs.p==rhs.p	&& lhs.r==rhs.r;
}

bool
operator!=(const Circle& lhs, const Circle& rhs) //inequality operator
{
	return !(lhs==rhs);
}

//methods

Vec
Circle::center(void) const //access center of circle
{
	return p;
}

double
Circle::radius(void) const //access radius of circle
{
	return r;
}

Circle&
Circle::operator=(const Circle& rhs) //assignment operator
{
	p=rhs.p;
	r=rhs.r;
	return *this;
}

//friend functions

Circle
rotate(const double theta, const Circle& cRot) //rotate a circle theta radians anticlockwise
{
	Vec v1(cos(theta),-sin(theta)); //vectors defining a rotation matrix
	Vec v2(sin(theta),cos(theta));
	double xprime=dot(v1,cRot.p); //matrix multiplication definied in two steps
	double yprime=dot(v2,cRot.p);
	Circle cNew(xprime,yprime,cRot.r);
	return cNew;
}

vector<Vec>
get_points(const Circle& circ) //get three points on a circle
{
	Vec d1=Vec(1,0);
	Vec d2=Vec(0,1);
	Vec d3=Vec(-1,0);
	Vec v1(circ.p+scalar(circ.r,d1));
	Vec v2(circ.p+scalar(circ.r,d2));
	Vec v3(circ.p+scalar(circ.r,d3));
	vector<Vec> point_vec(3);
	point_vec[0]=v1;
	point_vec[1]=v2;
	point_vec[2]=v3;
	return(point_vec);
}

bool
intersect(const Circle& c1, const Circle& c2) //check whether two circles intersect
{
	if ((c1.p-c2.p).norm()<=c1.r+c2.r) //intersection if norm of distance between centers is less than or equal to the sum of the radii
		return 1;
	else
		return 0;
}

Circle
inverse(const Circle& ref, const Circle& real) //calculate inverse circle, given a reference circle and circle at the current level
{
	vector<Vec> points=get_points(real); //get three points in real circle
	double d1=pow(ref.r,2)/pow((points.at(0)-ref.p).norm(),2); //scalar to obtain an inverse point
	double d2=pow(ref.r,2)/pow((points.at(1)-ref.p).norm(),2);
	double d3=pow(ref.r,2)/pow((points.at(2)-ref.p).norm(),2);

	Vec pt1=scalar(d1,(points.at(0)-ref.p))+ref.p; //inverse point with respect to given reference circle, for the first point on the real circle
	Vec pt2=scalar(d2,(points.at(1)-ref.p))+ref.p;
	Vec pt3=scalar(d3,(points.at(2)-ref.p))+ref.p;

	Circle c(pt1,pt2,pt3); //construct an inverse circle given three inverse points
	return c;
}
