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
	long hired_time = 0;			// time the taxi is in state HIRED 
	long free_time = 0;				// time the taxi is in state FREE

	// stopwatch being used for measuring the time the taxi is in state FREE/HIRED
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
	void update(int timeStep, Environment env) override;

	// used to print the taxis info
	const void printInfo() const override;

	// starts the taxi's stopwatch and records the point int time the vehicle has been created
	void startLife() override;

	// resets the stop watch
	void resetStopWatch();

	// drop the taxi (drops the passengers when leaving the env)
	void dropVehicle() override;

	// get the total amount of time the taxi is in state HIRED
	long getHiredTime() { return hired_time; }

	// get the total amount of time the taxi is in state FREE
	long getFreeTime() { return free_time; }

protected:
	// update the taxis position
	void updatePosition(double timeStep, Environment env) override;

	// update the orientation of the taxi
	void adjustDegree(int x_crossings, int y_crossings);

	// update the taximeter (update the vehicle's time in state FREE/HIRED)
	void updateTaxiMeter();
};