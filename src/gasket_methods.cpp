/*
 * gasket_methods.cpp
 *
 *  Created on: 07 May 2015
 *      Author: Tim
 */

#include "gasket_methods.h"

//Create the circles on level 0
void
level_zero(vector<Circle> &CircZero,const double &rad_zero, const int &n_zero)
{
	//circle 0
	Circle C0(0,0,rad_zero);
	CircZero.at(0)=C0;

	//circle 1
	double alpha=M_PI/(n_zero-1); //angle between two lines from center of circle 0 tangent to each consecutive circle on level 0
	double r=rad_zero*sin(alpha)/(1+sin(alpha)); //radius of circles 1,..,n_zero-1 on level 0
	Circle C(0,rad_zero-r,r); //circle 1 on level 0
	CircZero.at(1)=C;

	//rest of circles at level 0
	for (unsigned int ii=2; ii<n_zero;ii++)
	{
		C=rotate(2*alpha,CircZero.at(ii-1)); //rotate circle 1 by 2*alpha to obtain rest of the circles on level 0
		CircZero.at(ii)=C;
	}
}

//Create reference circles
void refs(const vector<Circle> &CircZero, vector<Circle> &CircRef)
{
	//inner reference circle
	if (CircZero.size()==4)
	{
		Vec v1=(CircZero.at(1).center()+CircZero.at(2).center()); //obtain 2*(point where circle 1 and circle 2 are tangent)
		Vec v2=(CircZero.at(2).center()+CircZero.at(3).center()); // "                    circle 2 and circle 3 are tangent
		Vec v3=(CircZero.at(3).center()+CircZero.at(1).center()); //and so on
		Circle C0(scalar(0.5,v1),scalar(0.5,v2),scalar(0.5,v3));
		CircRef.at(0)=C0;
	}
	else
	{
		Vec v1=(CircZero.at(1).center()+CircZero.at(2).center()); //consecutive points of tangency for circles \neq 0 on level 0
		Vec v2=(CircZero.at(2).center()+CircZero.at(3).center());
		Vec v3=(CircZero.at(3).center()+CircZero.at(4).center());
		Circle C0(scalar(0.5,v1),scalar(0.5,v2),scalar(0.5,v3));
		CircRef.at(0)=C0;
	}

	//defining the outer reference circles in a pairwise fashion
	double alpha=M_PI/(CircZero.size()-1); //as before defined
	double rad_zero=(CircZero.at(0)).radius();
	Vec p(0,rad_zero);

	for (unsigned int ii=0;ii<(CircZero.size()-2);ii++)
	{
		Vec v1=rotate(2*ii*alpha,p);
		Vec v2=rotate(2*(ii+1)*alpha,p);
		Vec v3=(CircZero.at(ii+1).center()+CircZero.at(ii+2).center());
		Circle C0(v1,v2,scalar(0.5,v3));
		CircRef.at(ii+1)=C0;
	}

	//defining the final outer reference circle
	Vec v1=rotate(2*(CircZero.size()-2)*alpha,p);
	Vec v2=rotate(2*(CircZero.size()-1)*alpha,p);
	Vec v3=(CircZero.at((CircZero.size()-1)).center()+CircZero.at(1).center());
	Circle C0(v1,v2,scalar(0.5,v3));
	CircRef.at((CircZero.size()-1))=C0;
}

//Populate next level of circles, given reference circles and current level
vector<Circle>
populate(const vector<Circle> &CircLvl, const vector<Circle> &CircRef)
{
	//static counter
	static unsigned int counter=0; //keep track of number of times function is called
	counter++;

	vector<Circle> in_out(0);
	for (unsigned int ii=0;ii<CircRef.size();ii++) //reference circles
	{
		for (unsigned int jj=0;jj<CircLvl.size();jj++) //real circles
		{
			if (ii==0&&jj==0&&counter==1) // deal with case on first call of function (level 1) where the 0th circle on level 0 completely contains the 0th reference circle
			{
				Circle C=inverse(CircRef.at(ii),CircLvl.at(jj));
				in_out.push_back(C);
			}
			else
			{
				if (intersect(CircRef.at(ii), CircLvl.at(jj))==0) // when a reference circle and ordinary circle do not intersect, define an inverse circle
				{
					Circle C=inverse(CircRef.at(ii),CircLvl.at(jj));
					in_out.push_back(C);
				}
			}
		}
	}
	return in_out;
}

