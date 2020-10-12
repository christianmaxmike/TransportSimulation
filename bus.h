//
// taxi.h
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
	int capacity;
	std::chrono::milliseconds last_stop;

public:
	Bus() {};
	Bus(int id, int no_passengers);

	int getCapacity() { return capacity; }
	void update(double timeStep, Environment env) override;
	void busStop(int simulationTime);
	const void printInfo() const override;
};