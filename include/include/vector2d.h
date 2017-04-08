/*
 * vector2d.h
 *
 *  Created on: 27 Apr 2015
 *      Author: Tim
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>
#include <cmath>
# include "point2d.h"
#include <stdio.h>
#include <fstream>
#include <plotter.h>
using namespace std;

//defining the 2D vector class

/**
 * \brief A vector in \f$\mathbb{R}^2\f$
 */
class Vec : public Point
{

	//friend functions

	/**
	 * \brief Obtain the dot product of two vectors \f$v_1=(x_1,y_1)\f$ and \f$v_2=(x_2,y_2)\f$ in \f$\mathbb{R}^2\f$
	 * @param v1 Vec
	 * @param v2 Vec
	 * @return dot product \f$v_1\cdot v_2=x_1.x_2+y_1.y_2\f$
	 */
	friend double
	dot(const Vec& v1, const Vec& v2);

	/**
	 * \brief Obtain the cross product of two vectors \f$v_1=(x_1,y_1)\f$ and \f$v_2=(x_2,y_2)\f$ in \f$\mathbb{R}^2\f$
	 * @param v1 Vec
	 * @param v2 Vec
	 * @return cross product \f$v_1\times v_2=\|v_1\|\|v_2\|\sin(\theta)\f$
	 */
	friend double
	cross(const Vec& v1, const Vec& v2);

	/**
	 * \brief Perform scalar multiplication of a vector \f$v=(x,y)\f$ by a scalar \f$a\f$
	 * @param a scalar value
	 * @param vec Vec
	 * @return scalar multiple of vector \f$a.v=(a.x,\;x.y)\f$
	 */
	friend Vec
	scalar(const double a,const Vec& vec);

	/**
	 * \brief Rotate a vector through \f$\theta\f$ radians in the anticlockwise direction
	 * @param theta angle of rotation
	 * @param vRot Vec to be rotated through\f$\begin{bmatrix}
\cos(\theta)&-\sin(\theta)\\
\sin(\theta)&\cos(\theta)\\
\end{bmatrix}\f$
	 * @return Vec given by \f$(x',y')\f$
	 */
	friend Vec
	rotate(const double theta, const Vec& vRot);

public:

	/**
	 * \brief Default constructor for the Vec class
	 */
	Vec(): //default constructor
		Point(0.0,0.0)
	{}

	/**
	 * \brief Constructor for the Vec class
	 * @param xIn x-coordinate of Point defining the Vec
	 * @param yIn y-coordinate of Point defining the Vec
	 */
	Vec(const double xIn, const double yIn): //class constructor
		Point(xIn,yIn)
	{}

	/**
	 * \brief Destructor for the Vec class
	 */
	virtual ~Vec() //class destructor
	{}

	//overloaded operators

	/**
	 * \brief Overloaded compound addition operator
	 * @param rhs Vec
	 * @return Vec \f$(x',y')\f$ incremented by rhs Vec
	 */
	Vec&
	operator+=(const Vec& rhs); //compound addition operator

	/**
	 * \brief Overloaded compound subtraction operator
	 * @param rhs Vec
	 * @return Vec \f$(x',y')\f$ decremented by rhs Vec
	 */
	Vec&
	operator -=(const Vec& rhs); //compound subtraction operator

	/**
	 * \brief Overloaded lhs subscript operator
	 * @param n coordinate index
	 * @return reference to \f$x\f$ or \f$y\f$ coordinate of Vec for modification
	 */
	double&
	operator[](const int n); //lhs subscript operator

	/**
	 * \brief Overloaded rhs subscript operator
	 * @param n coordinate index
	 * @return reference to \f$x\f$ or \f$y\f$ coordinate of Vec for assignment
	 */
	const double&
	operator[](const int n) const; //rhs subscript operator

	  /**
	   * \brief Plot the Vec to the plotter passed in as an argument.
	   * @param plotter the modified plotter
	   */
	  void plot(Plotter &plotter)
	  {
	    plotter.fmarker(x,y,18,2); //plots plus symbols to mark the point characterising the vector
	  }

	//methods

	/**
	 * \brief Obtain the norm of a vector \f$v=(x,y)\f$ in \f$\mathbb{R}^2\f$
	 * @return norm \f$||v||=\sqrt{v\cdot v}=\sqrt{x^2+y^2}\f$
	 */
	double
	norm(void) const; //calculates norm of given vector

	/**
	 * \brief Obtain the maximum element of a vector \f$v=(x,y)\f$ in \f$\mathbb{R}^2\f$
	 * @return \f$\max\{x,y\}\f$
	 */
	double
	max(void) const; //returns the maximum element of given vector

	/**
	 * \brief Obtain the minimum element of a vector \f$v=(x,y)\f$ in \f$\mathbb{R}^2\f$
	 * @return \f$\min\{x,y\}\f$
	 */
	double
	min(void) const; //returns the minimum element of given vector

private:
};

//overloaded operators

/**
 * \brief Overloaded addition operator
 * @param aVec Vec \f$v_1=(x_1,y_1)\f$ in summation
 * @param bVec Vec \f$v_2=(x_2,y_2)\f$ in summation
 * @return Vec \f$v_3=(x_1+x_2,y_1+y_2)\f$
 */
Vec
operator+(const Vec& aVec, const Vec& bVec); //vector addition

/**
 * \brief Overloaded subtraction operator
 * @param aVec Vec \f$v_1=(x_1,y_1)\f$ in subtraction
 * @param bVec Vec \f$v_2=(x_2,y_2)\f$ in subtraction
 * @return Vec \f$v_3=(x_1-x_2,y_1-y_2)\f$
 */
Vec
operator-(const Vec& aVec, const Vec& bVec); //vector subtraction


#endif /* VECTOR2D_H_ */
