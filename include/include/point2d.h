/*
 * point2d.h
 *
 *  Created on: 27 Apr 2015
 *      Author: Tim
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#include <iostream>
#include <cmath>
using namespace std;

//defining the 2D point class

/**
 * \brief A point in \f$\mathbb{R}^2\f$
 */
class Point
{

	//overloaded friend operators

	/**
	 * \brief Overloaded ostream operator
	 * @param out ostream object
	 * @param inPoint reference to a Point
	 * @return ostream object displaying coordinates of Point \f$(x,y)\f$
	 */
	friend ostream& //output functionality
	operator<<(ostream& out, const Point& inPoint);

	/**
	 * \brief Overloaded istream operator
	 * @param in reference to an istream object
	 * @param inPoint reference to a Point
	 * @return istream object saving coordinates of Point \f$(x,y)\f$
	 */
	friend istream& //input functionality
	operator>>(istream& in, Point& inPoint);

	/**
	 * \brief Overloaded equality operator
	 * @param lhs reference to left-hand-side Point
	 * @param rhs reference to right-hand-side Point
	 * @return boolean: true if \f$\text{lhs}=\text{rhs}\f$
	 */
	friend bool //equality operator
	operator==(const Point& lhs, const Point& rhs);

	/**
	 * \brief Overloaded inequality operator
	 * @param lhs reference to left-hand-side Point
	 * @param rhs reference to right-hand-side Point
	 * @return boolean: true if \f$\text{lhs}\neq\text{rhs}\f$
	 */
	friend bool //inequality operator
	operator!=(const Point& lhs, const Point& rhs);

public:

	/**
	 * \brief Default constructor for the Point class
	 */
	Point(): //default constructor
		x(0.0),y(0.0)
	{}

	/**
	 * \brief Constructor for the Point class
	 * @param xIn x-coordinate of Point
	 * @param yIn y-coordinate of Point
	 */
	Point(const double xIn, const double yIn): //class constructor
		x(xIn),y(yIn)
	{}

	/**
	 * \brief Destructor for the Point class
	 */
	virtual ~Point() //class destructor
	{}

	//overloaded operators

	/**
	 * \brief Overloaded assignment operator
	 * @param rhs vector to assign to the left hand side
	 * @return reference to Point equal to right hand side
	 */
	Point&
	operator=(const Point& rhs); //assignment operator

protected:
	double x; /**< x-coordinate of Point */
	double y; /**< y-coordinate of Point */
};

#endif /* POINT2D_H_ */
