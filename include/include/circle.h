/*
 * circle.h
 *
 *  Created on: 29 Apr 2015
 *      Author: Tim
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <cmath>
#include "point2d.h"
#include "vector2d.h"
#include <vector>
#include <stdio.h>
#include <fstream>
#include <plotter.h>
using namespace std;

//functions

/**
 * \brief Obtain the center of the Circle passing through three Points through dot- and cross-products
 * @param p1 Vec \f$x_1,y_1\f$
 * @param p2 Vec \f$x_2,y_2\f$
 * @param p3 Vec \f$x_3,y_3\f$
 * @return Vec defining the center of the Circle
 */
Vec get_center(const Vec& p1, const Vec& p2, const Vec& p3);

/**
 * \brief Obtain the radius of the Circle passing through three Points through dot- and cross-products
 * @param p1 Vec \f$x_1,y_1\f$
 * @param p2 Vec \f$x_2,y_2\f$
 * @param p3 Vec \f$x_3,y_3\f$
 * @return radius of the Circle
 */
double get_radius(const Vec& p1, const Vec& p2, const Vec& p3);

//defining the circle class

/**
 * \brief A circle in \f$\mathbb{R}^2\f$
 */
class Circle
{

	//overloaded friend operators

	/**
	 * \brief Overloaded ostream operator
	 * @param out ostream object
	 * @param inCircle reference to a Circle
	 * @return ostream object displaying center \f$x,y\f$ and radius \f$r\f$ of Circle
	 */
	friend ostream& //output functionality
	operator<<(ostream& out, const Circle& inCircle);

	/**
	 * \brief Overloaded istream operator
	 * @param in istream operator
	 * @param inCircle reference to a circle
	 * @return istream object saving center \f$(x,y)\f$ and radius \f$r\f$ of Circle
	 */
	friend istream& //input functionality
	operator>>(istream& in, Circle& inCircle);

	/**
	 * \brief Overloaded equality operator
	 * @param lhs reference to left-hand-side Circle
	 * @param rhs reference to right-hand-side Circle
	 * @return boolean: true if \f$\text{lhs.p}=\text{rhs.p}\f$ and \f$\text{lhs.r}=\text{rhs.r}\f$; i.e. if circle centers and radii are equal
	 */
	friend bool //equality operator
	operator==(const Circle& lhs, const Circle& rhs);

	/**
	 * \brief Overloaded inequality operator
	 * @param lhs reference to left-hand side Circle
	 * @param rhs reference to right-hand-side Circle
	 * @return boolean: true if Circle centers or radii are not equal
	 */
	friend bool //inequality operator
	operator!=(const Circle& lhs, const Circle& rhs);

	//friend functions

	/**
	 * \brief Rotate a Circle through \f$\theta\f$ radians in the anticlockwise direction
	 * @param theta angle of rotation
	 * @param cRot Circle to be rotated through\f$\begin{bmatrix}
\cos(\theta)&-\sin(\theta)\\
\sin(\theta)&\cos(\theta)\\
\end{bmatrix}\f$
	 * @return Circle with center \f$(x',y')\f$
	 */
	friend Circle
	rotate(const double theta, const Circle& cRot);

	/**
	 *\brief Obtain three points on a given Circle
	 * @param circ Circle on which points are obtained
	 * @return vector of three points \f$\left[(x_1,y_1),(x_2,y_2),(x_3,y_3)\right]\f$
	 */
	friend vector<Vec>
	get_points(const Circle& circ);

	/**
	 * \brief Determine whether two circles \f$(a,r_a),\ (b,r_b)\f$ intersect i.e. if \f$\|c\|>r_a+r_b\f$
	 * @param c1 first circle
	 * @param c2 second circle
	 * @return boolean: 1 if intersection occurs
	 */
	friend bool
	intersect(const Circle& c1, const Circle& c2);

	/**
	 * \brief Generate the inverse circle relative to a reference circle
	 * @param ref reference circle
	 * @param real circle on current level on which three points are sampled
	 * @return inverse circle constructed from three inverse points \f$x'=x_0+\frac{r^2(x-x_0)}{|x-x_0|^2}\f$
	 */
	friend Circle
	inverse(const Circle& ref, const Circle& real);

public:

	/**
	 * \brief Default constructor for the Circle class
	 */
	Circle(): //default constructor
		p(0.0,0.0),r(0.0)
	{}

	/**
	 * \brief Constructor for the Circle class
	 * @param xIn x-coordinate of Circle center
	 * @param yIn y-coordinate of Circle center
	 * @param rIn radius of Circle
	 */
	Circle(const double xIn, const double yIn, const double rIn): //constructor using center and radius
		p(xIn,yIn),r(rIn)
	{}

	/**
	 * \brief Constructor for the Circle class
	 * @param p1 point \f$(x_1,y_1)\f$ on the Circle
	 * @param p2 point \f$(x_2,y_2)\f$ on the Circle
	 * @param p3 point \f$(x_3,y_3)\f$ on the Circle
	 */
	Circle(const Vec& p1, const Vec& p2, const Vec& p3) //constructor using three points
	{
		p=get_center(p1, p2, p3);
		r=get_radius(p1, p2, p3);
	}

	/**
	 * \brief Destructor for the Circle class
	 */
	~Circle() //class destructor
	{}

	  /**
	   * \brief Plot the Circle to the plotter passed in as an argument.
	   * @param plotter the modified plotter
	   */
	  void plot(Plotter &plotter)
	  {
	    plotter.fcircle(p[0],p[1],r); //plots circle
	  }

	  /**
	   * \brief Access center of Circle
	   * @return vector defining the center of the Circle
	   */
	  Vec
	  center(void) const; //access circle center

	  /**
	   * \brief Access radius of Circle
	   * @return double defining the radius of the Circle
	   */
	  double
	  radius(void) const; //access circle radius

		/**
		 * \brief Overloaded assignment operator
		 * @param rhs Circle to assign to the left hand side
		 * @return reference to Circle equal to right hand side
		 */
		Circle&
		operator=(const Circle& rhs); //assignment operator

private:
	Vec p; /**< center of Circle \f$(x,y)\f$ */
	double r; /**< radius of Circle */
};



#endif /* CIRCLE_H_ */
