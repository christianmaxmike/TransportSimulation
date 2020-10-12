//
// taxi.h
//
// @author: Christian Frey
//
// This header is used for the description of the Taxi entity within the simulation.
//
#pragma once
#include "vehicle.h"
#include "constants.h"

class Taxi : public Vehicle
{
private:
	bool hired = false;				// State HIRED or FREE
	int numberOfTours = 0;			// number of tours; maximal 3 (afterwards die)
	int maxTours = MAX_TAXI_TOURS;	// predefined maximal number of tours
	long hired_time = 0;
	long free_time = 0;
	std::chrono::time_point<std::chrono::high_resolution_clock> stopWatch;

public:
	// default Constructor
	Taxi() {};

	// Constructor for Taxi instance
	//
	// Parameters:
	//	id: unique id for entity
	//	no_passengers: number of passengers within the taxi
	Taxi(int id, int no_passengers);

	// indicates whether the taxi is in state free/hired
	bool isHired();

	// drops the passengers (resets passengers and set state to free)
	void dropPassenger();

	// set the taxis state to the hired state and gathers passengers
	void callTaxi();

	// calls vehicle specific update methods
	void update(double timeStep, Environment env) override;

	// used to print the taxis info
	const void printInfo() const override;

	void startLife() override;

	void resetStopWatch();

	void dropVehicle() override;

	long getHiredTime() { return hired_time; }

	long getFreeTime() { return free_time; }

protected:
	// update the taxis position
	void updatePosition(double timeStep, Environment env) override;

	// update the orientation of the taxi
	void adjustDegree(int x_crossings, int y_crossings);

	void updateTaxiMeter();
};