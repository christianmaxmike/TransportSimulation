//
// utils.h
//
// @author: Christian Frey
//
// This header is used for utility functions used throughout the simulation app.
//
#pragma once

// structure for coordinates
struct coordinates {
	double pos_x; // x-coordinate
	double pos_y; // y-coordinate

	coordinates() : pos_x(0), pos_y(0) {};
	coordinates(double x, double y) : pos_x(x), pos_y(y) {};
};

// random number generator within the interval [a,b]
// 
// Parameters:
// a: lower bound of the random generator
// b: upper bound of the random generator
double randnum(double a, double b);