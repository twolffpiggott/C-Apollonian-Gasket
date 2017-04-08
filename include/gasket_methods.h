/*
 * gasket_methods.h
 *
 *  Created on: 07 May 2015
 *      Author: Tim
 */

#ifndef GASKET_METHODS_H_
#define GASKET_METHODS_H_

#include <iostream>
#include <vector>
#include "Circle.h"
using namespace std;

/**
 * \brief Create the circles at level zero of the gasket
 * @param CircZero vector of circles at level 0
 * @param rad_zero radius of the 0th circle at level 0
 * @param n_zero number of circles at level 0
 */
void level_zero(vector<Circle> &CircZero,const double &rad_zero, const int &n_zero); //Create the circles on level 0

/**
 * \brief Create the reference circles
 * @param CircZero vector of circles at level 0
 * @param CircRef vector of reference circles
 */
void refs(const vector<Circle> &CircZero, vector<Circle> &CircRef); //Create reference circles

/**
 * \brief Populate the next level of circles, given the reference circles and the current level of circles
 * @param CircLvl vector of circles on previous level
 * @param CircRef vector of reference circles
 * @return vector of circles on the current level
 */
vector<Circle> populate(const vector<Circle> &CircLvl, const vector<Circle> &CircRef); //Populate next level of circles, given reference circles and current level

#endif /* GASKET_METHODS_H_ */
