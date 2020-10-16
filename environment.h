//
// environment.h
//
// @author: Christian Frey
//
// This header is used for the description of the (default) environment
// of the simulation described by a 2D plane.
//
#pragma once

class Environment
{
private:
	int height;		// environment's y-span
	int width;		// environment's x-span
public:
	// Constructor for the 2D environment
	//
	// Parameters:
	// height: height of the environment
	// widht: width of the environment
	Environment(int height, int width) : height{ height }, width{ width } {};

	// get the height of the environment
	int getHeight() { return height; }

	// get the width of the environment
	int getWidth() { return width; }
};