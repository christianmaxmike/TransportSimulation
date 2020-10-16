//
// scheduler.h
//
// @author: Christian Frey
//
// This header is used for the descirption of the scheduler used for the simulation. 
// It holds the vehicles instances.
//
#pragma once
#include <vector>
#include "vehicle.h"
#include "environment.h"
#include <iostream>

class Scheduler
{
private:
	int simulationTime;				// scheduler's time after which the simulation is updated 
	std::vector<Vehicle*> vehicles; // vehicles within the simulation
public:
	// Constructor for a Scheduler
	// 
	// Parameter:
	// simulationTime: update time
	Scheduler(int simulationTime = 100);

	// get the simulation time being used for the scheduler
	int getSimulationTime() { return simulationTime; }

	// get the vehicles being handled by the scheduler
	std::vector<Vehicle*> getVehicles() { return vehicles; }

	// add a vehicle to the scheduler
	void addVehicle(Vehicle *v);

	// remove a vehicle from the scheduler 
	void removeVehicle(Vehicle *v);

	// take a step, i.e., the scheduler calls the vehicles update fnc according to its policy
	void step(Environment env);
};