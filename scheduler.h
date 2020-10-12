#pragma once
#include <vector>
#include "vehicle.h"
#include "environment.h"
#include <iostream>

class Scheduler
{
private:
	int simulationTime;
	std::vector<Vehicle*> vehicles;
public:
	Scheduler(int simulationTime = 100);

	int getSimulationTime() { return simulationTime; }
	std::vector<Vehicle*> getVehicles() { return vehicles; }

	void addVehicle(Vehicle *v);
	void removeVehicle(Vehicle *v);
	void step(Environment env);
};