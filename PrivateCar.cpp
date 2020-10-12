#include "privateCar.h"
#include <random>
#include <iostream>
#include <math.h>
#include <stdio.h>

PrivateCar::PrivateCar()
{
	type = privateCarType::SmartCar;
}

PrivateCar::PrivateCar(int id, int no_pass, privateCarType type)
	: Vehicle(id, no_pass), type{ type } {
	velocity = randnum(MIN_CAR_VELOCITY, MAX_CAR_VELOCITY);
};

const void PrivateCar::printInfo() const 
{
	printf("[%d] Private Car :\n"
		"\tposition (%.2f,%.2f)\n"
		"\tspeed: %.1f\n"
		"\tdirection: %.2f\n"
		"\ttraveled distance: %.2f\n",
		id, coords.pos_x, coords.pos_y, velocity, degree, traveledDistance);
}