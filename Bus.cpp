#include "bus.h"
#include <stdio.h>
#include "Utils.h"
#include "constants.h"


Bus::Bus(int id, int no_passengers)
	: Vehicle(id, no_passengers)
{
	capacity = (int)randnum(MIN_BUS_CAPACITY, MAX_BUS_CAPACITY);
	velocity = randnum(MIN_BUS_VELOCITY, MAX_BUS_VELOCITY);
	last_stop = std::chrono::milliseconds(0);
};

void Bus::busStop(int simulationtime) {
	last_stop += std::chrono::milliseconds(simulationtime);
	if (std::chrono::duration_cast<std::chrono::minutes> (last_stop).count() >= BOARDING_INTERVAL) {
		// alighting of passengers
		int alighting = (int)randnum(0.0, no_passengers);
		no_passengers -= alighting;
		printf("Alightinig passengers : %d\n", alighting);
		// load passengers;
		int boarding = (int)randnum(0.0, (double) capacity-no_passengers);
		no_passengers += boarding;
		printf("Boarding passengersS: %d\n", boarding);

		last_stop = std::chrono::milliseconds(0);
	}
}

void Bus::update(int timeStep, Environment env) {
	updateTravelledDistance(timeStep);
	updatePosition(timeStep, env);
	updateDegree();
	busStop(timeStep);
}

const void Bus::printInfo() const
{
	printf("[%d] BUS :\n"
		"\tposition (%.2f,%.2f)\n"
		"\tspeed: %.1f\n"
		"\tdirection: %.2f\n"
		"\tcapacity: (%d/%d)\n"
		"\ttraveled distance: %.2f\n",
		id, coords.pos_x, coords.pos_y, velocity, degree, no_passengers, capacity, traveledDistance);
}
