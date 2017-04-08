/*
 * get_user_data.h
 *
 *  Created on: 26 Mar 2015
 *      Author: Tim
 */

#ifndef GET_USER_DATA_H_
#define GET_USER_DATA_H_

#include <iostream>
using namespace std;

/**
 * \brief Obtain input data necessary to plot an Apollonian gasket
 * @param rad_zero radius of Circle 0
 * @param n_zero number of Circles at level 0
 * @param n_level number of levels of the gasket to plot
 */
void get_user_data(double &rad_zero,int &n_zero, int &n_level);

#endif /* GET_USER_DATA_H_ */
