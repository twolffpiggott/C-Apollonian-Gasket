//============================================================================
// Name        : AGasket.cpp
// Author      : Tim Wolff-Piggott
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "vector2d.h"
#include "point2d.h"
#include "circle.h"
#include "get_user_data.h"
#include "gasket_methods.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <plotter.h>
#include <math.h>
using namespace std;

int main() {

	//user input
	double rad_zero;
	int n_zero;
	int n_level;
	get_user_data(rad_zero,n_zero,n_level);

	//circles on level 0 according to user input
	vector<Circle> CircZero(n_zero);
    level_zero(CircZero,rad_zero,n_zero);

    //reference circles
    vector<Circle> CircRef(n_zero);
    refs(CircZero,CircRef);

	//plotting the Apollonian gasket

	// Create and initialize the output file stream
	ofstream svgfile;
	svgfile.open ("circle_ex.svg");
	SVGPlotter plotter(cin, svgfile, cerr);
	// Open the plotter
	plotter.openpl();

	//specifying the boundaries of the plotting space in R^2
	plotter.fspace(-10,-10,10,10);

	//setting the circles not to be filled
	plotter.pentype(1);
	plotter.pencolor(0,0,0);

	//plotting circles on level 0

	//plot 0th circle at level 0
	plotter.filltype(0); //set the circle not to be filled
	CircZero.at(0).plot(plotter);

	//plotting 1,...,n_level circles at level 0
	plotter.fillcolor(5000,5000,20000); //define colours
	plotter.filltype(1); //set circles to be filled
	for (unsigned int ii=1;ii<n_zero;ii++)
		CircZero.at(ii).plot(plotter);

	//Plot reference circles
//	plotter.filltype(0);
//	plotter.colorname("red"); //plotting the outlines of the reference circles in red
//	for (unsigned int ii=0;ii<n_zero;ii++)
//		CircRef.at(ii).plot(plotter); //plot reference circles

    //Create circles on level 1
    vector<Circle> Circ_current=populate(CircZero,CircRef);

	//Plot circles on level 1
    plotter.fillcolor(5000,10000,25000); //set colours
    plotter.pencolor(0,0,0); //set outline colour to black
    plotter.filltype(1); //set circles to be filled
	for (unsigned int ii=0;ii<Circ_current.size();ii++)
		Circ_current.at(ii).plot(plotter); //plot circles on level 1

	//Plot circles on following levels
	for (unsigned int ii=1;ii<n_level;ii++)
	{
		plotter.fillcolor(5000,10000+7500*ii,25000+2500*ii); //differentiate colours according to levels of gasket

		Circ_current=populate(Circ_current,CircRef); //create circles at level ii

		for (unsigned int jj=0;jj<Circ_current.size();jj++)
				Circ_current.at(jj).plot(plotter); //plot circles at level ii
	}

	plotter.flushpl();
	// Close the plotter
	plotter.closepl();
	// Save and close the .SVG file
	svgfile.close();

	return 0;
}
