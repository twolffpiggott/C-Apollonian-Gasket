/*
 * get_user_data.cpp
 *
 *  Created on: 26 Mar 2015
 *      Author: Tim
 */

#include "get_user_data.h"
#include "math.h"
//function definition

//function that accepts the specifications for the gasket
void
get_user_data(double &rad_zero, int &n_zero, int &n_level)
{
	//routine to obtain a valid radius for circle 0
	cout<<"Please enter the radius of circle 0"<<endl;
	cin>>rad_zero;

		while (rad_zero<=0)
		{
			cout<<"Please enter a positive real radius for circle 0:"<<endl;
			cin>>rad_zero;
		}

	//routine to obtain a valid number of circles at level 0
	cout<<"Please enter the number of circles at level 0"<<endl;
	cin>>n_zero;

	while (n_zero<4)
	{
		cout<<"Please enter a positive integer number of circles >=4 for level 0:"<<endl;
		cin>>n_zero;
	}

	//routine to obtain a valid number of gasket levels to display
	cout<<"Please enter the number of levels of the gasket to display:"<<endl;
	cin>>n_level;

	while (n_level<=0)
	{
		cout<<"Please please enter a non-negative integer number of levels for the gasket to display:"<<endl;
		cin>>n_level;
	}
}


