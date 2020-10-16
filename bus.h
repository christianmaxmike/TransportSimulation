//
// bus.h
//
// @author: Christian Frey
//
// This header is used for the description of the Bus entity within the simulation.
//
#pragma once
#include "vehicle.h"
#include "Utils.h"
#include "constants.h"

class Bus : public Vehicle
{
private: 
	int capacity = 0;						// total capacity of the bus entity
	std::chrono::milliseconds last_stop{ 0 };// aggregated time since last bus stop [ms]

public:
	// default constructor
	Bus() {};

	// Constructor for a bus instance
	//
	// Parameters:
	// id: unique id for bus instance
	// no_passengers: number of passengers traveling with the bus
	Bus(int id, int no_passengers);

	// returns the capactiy of the bus
	int getCapacity() { return capacity; }

	// updating all relevant infos for an bus instance according to 
	// the scheduler's simulation time 
	void update(int timeStep, Environment env) override;

	// simulates a bus stop
	void busStop(int simulationTime);

	// print the information of the bus instance
	const void printInfo() const override;
};