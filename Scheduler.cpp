#include "scheduler.h"
#include <typeinfo>
#include <iostream>
#include <thread>
#include <chrono>
#include "constants.h"

Scheduler::Scheduler(int updateTime)
{
	this->simulationTime = updateTime;
}

void Scheduler::addVehicle(Vehicle *v)
{
	this->vehicles.insert(this->vehicles.end(), v);
}

void Scheduler::removeVehicle(Vehicle* v)
{
	this->vehicles.erase(std::remove(this->vehicles.begin(), this->vehicles.end(), v), this->vehicles.end());
}

void Scheduler::step(Environment env)
{
	for (const auto &pentity : this->vehicles) {
		if (VERBOSE == 1)
			pentity->printInfo();
		pentity->update(simulationTime, env);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(simulationTime));
}