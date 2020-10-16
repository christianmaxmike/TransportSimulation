//
// vehicle.h
//
// @author: Christian Frey
//
// This header is used for the description of the general vehicle entity 
// within the simulation.
//
#pragma once
#include "environment.h"
#include <iostream>
#include <chrono>
#include <string>
#include "Utils.h"


class Vehicle
{
private: 

protected:
	int id = -1;				// unique id of vehicle
	int no_passengers = -1;		// number of passengers in vehicle
	double velocity = -1;		// velocity of vehicle
	double degree = 0;			// direction of vehicle
	double traveledDistance = 0;// total traveled distance [m]
	coordinates coords;			// coordinates of vehicle

	// point in time of creation in env
	std::chrono::time_point<std::chrono::high_resolution_clock> birthTimePoint;

	// update the position of the vehicle
	virtual void updatePosition(double timeStep, Environment env);

	// update travelled distance
	void updateTravelledDistance(double timeStep);

	// updatet the orientation/angle of the vehicle
	void updateDegree();

	// method called when the vehicles leaves the simulation
	virtual void dropVehicle() {};

public: 
	// Default Constructor
	Vehicle() {};

	// Constructor for an vehicle
	//
	// Parameters: 
	// id: unique id of the vehicle
	// no_passengers: number of passengers in the vehicle
	Vehicle(int id, int no_passengers);

	// place the vehicle within the environment (randomly)
	void placeInEnv(Environment env);

	// get the coordinates of the vehicle
	coordinates getCoords() const { return coords; }

	// get the total travel distance 
	double getTraveledDistance() { return traveledDistance; }

	// get the time when the vehicle has been created
	std::chrono::time_point<std::chrono::high_resolution_clock> getBirthTimePoint() { return birthTimePoint; }
	
	// public update method calling vehicle-dependent update fncs
	virtual void update(double timeStep, Environment env);

	// starts running time of vehicle in environment
	virtual void startLife();

	// print method used for info console output 
	virtual const void printInfo() const = 0;
};