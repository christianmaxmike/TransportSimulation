#include "vehicle.h"
#include "environment.h"
#include <iostream>
#include <random>
#include <functional>
#include <chrono>
#include "constants.h"
#include "Utils.h"

Vehicle::Vehicle(int id, int no_passengers)
{
	this->id = id;
	this->no_passengers = no_passengers;
	degree = randnum(0.0, 360);
}

void Vehicle::startLife() {
	birthTimePoint = std::chrono::high_resolution_clock::now();
}

void Vehicle::placeInEnv(Environment env)
{
	// set coordinates
	double coordx = randnum(0.0, env.getWidth());
	double coordy = randnum(0.0, env.getHeight());
	coords = coordinates{ coordx, coordy };

	// set start time (calc of vehicle's life span in env)
	startLife();
}

void Vehicle::updateTravelledDistance(double timeStep) {
	traveledDistance += velocity * timeStep / (3600);
}


void Vehicle::updatePosition(double timeStep, Environment env){
	// per default: no boundary check for a vehicles' movement
	// (per task description: cars and busses just drop out)
	double metre_ms = velocity * timeStep/ 3600;

	double radians = degree * (MATH_PI / 180.0);
	double delta_x = metre_ms * cos(radians);
	double delta_y = metre_ms * sin(radians);

	coords.pos_x += delta_x;
	coords.pos_y += delta_y;
}

void Vehicle::updateDegree() {
	double rand = randnum(0.0, 1.0);
	if (rand>= 0.95) 
		degree += randnum(-0.05 * 360, 0.05 * 360);
}

void Vehicle::update(double timeStep, Environment env) {
	updateTravelledDistance(timeStep);
	updatePosition(timeStep, env);
	updateDegree();
}