#include "taxi.h"
#include <stdlib.h>
#include <cmath>
#include "Utils.h"

Taxi::Taxi(int id, int no_passengers)
	: Vehicle(id, no_passengers) {
	velocity = randnum(MIN_TAXI_VELOCITY, MAX_TAXI_VELOCITY);
};

void Taxi::updateTaxiMeter() {
	if (hired) 
		hired_time += std::chrono::duration_cast<std::chrono::seconds> (std::chrono::high_resolution_clock::now() - stopWatch).count();
	else 
		free_time += std::chrono::duration_cast<std::chrono::seconds> (std::chrono::high_resolution_clock::now() - stopWatch).count();
	resetStopWatch();
}

void Taxi::dropPassenger() {
	printf("[%d] Taxi : %d Passengers dropped.\n", id, no_passengers);
	hired = false;
	no_passengers = 0;
}

void Taxi::startLife() {
	birthTimePoint = std::chrono::high_resolution_clock::now();
	stopWatch = std::chrono::high_resolution_clock::now();
}

void Taxi::dropVehicle() {
	dropPassenger();
}

void Taxi::resetStopWatch() {
	stopWatch = std::chrono::high_resolution_clock::now();
}

void Taxi::callTaxi() {
	if (!hired) {
		double randCaller = randnum(0.0, 1.0);
		if (randCaller >= 0.90) {
			hired = true;
			no_passengers = (int)randnum(1, 4);
			numberOfTours++;
			printf("[%d] Taxi : %d passengers gathered at (%.2f,%.2f)\n", id, no_passengers, coords.pos_x, coords.pos_y);
		}
	}
}

void Taxi::updatePosition(double timeStep, Environment env)
{
	double metre_ms = velocity * timeStep / 3600;

	double radians = degree * (MATH_PI / 180.0);
	double delta_x = metre_ms * cos(radians);
	double delta_y = metre_ms * sin(radians);

	double predX = getCoords().pos_x + delta_x;
	double predY = getCoords().pos_y + delta_y;

	if (numberOfTours >= maxTours) {
		coords.pos_x += delta_x;
		coords.pos_y += delta_y;
		return;
	}

	// *** handle multiple reflections from boundaries of env
	bool boundContact = false;
	int width_crossing = 0;
	int height_crossing = 0;
	
	if (predX < 0 || predX > env.getWidth()) {
		boundContact = true;
		width_crossing = (predX < 0 ? 1: 0) + (int)(predX / env.getWidth());
		
		// compute new x position
		double x_bouncedDist = abs(fmod(predX, env.getWidth()));
		int x_reflections = (int)(predX / env.getWidth());
		predX = pow(-1, x_reflections) > 0 ? (x_bouncedDist) : (env.getWidth() - x_bouncedDist);
	} 
	if (predY < 0 || predY > env.getHeight()) {
		boundContact = true;
		height_crossing = (predY < 0 ? 1 : 0) + (int)(predY / env.getHeight());

		double y_bouncedDist = abs(fmod(predY, env.getHeight()));
		int y_reflections = (int)(predY / env.getHeight());

		predY = pow(-1, y_reflections) > 0 ? (y_bouncedDist) : (env.getHeight() - y_bouncedDist);
	}

	if (boundContact)
		adjustDegree(width_crossing, height_crossing);
	if (boundContact && hired) 
		dropPassenger();
	
	// update position 
	coords.pos_x = predX;
	coords.pos_y = predY;
}

void Taxi::adjustDegree(int width_crossing, int height_crossing) {
	if (width_crossing & 1 && height_crossing & 1)
		degree += 180;
	if (degree > 0 && degree < 90) {
		if (!(width_crossing & 1) && height_crossing & 1)
			degree = 360 - fmod(degree, 90);
		else if (width_crossing & 1 && !(height_crossing & 1))
			degree = 180 - fmod(degree, 90);
	}
	else if (degree >= 90 && degree < 180) {
		if (!(width_crossing & 1) && height_crossing & 1)
			degree = 270 - fmod(degree, 90);
		else if (width_crossing & 1 && !(height_crossing & 1))
			degree = 90 - fmod(degree, 90);
	}
	else if (degree > 180 && degree < 270) {
		if (!(width_crossing & 1) && (height_crossing & 1))
			degree = 180 - fmod(degree, 90);
		else if (width_crossing & 1 && !(height_crossing & 1))
			degree = 360 - fmod(degree, 90);
	}
	else if (degree >= 270 && degree < 360) {
		if (!(width_crossing & 1) && height_crossing & 1)
			degree = 90 - fmod(degree, 90);
		else if (width_crossing & 1 && !(height_crossing & 1))
			degree = 270 - fmod(degree, 90);
	}
}


void Taxi::update(double timeStep, Environment env) {
	updateTaxiMeter();
	updateTravelledDistance(timeStep);
	updatePosition(timeStep, env);
	updateDegree();
	callTaxi();
}

const void Taxi::printInfo() const 
{
	printf("[%d] Taxi :\n"
		"\tposition (%.2f,%.2f)\n"
		"\tspeed: %.1f\n"
		"\tdirection: %.2f\n"
		"\tTours: (%d/%d)\n"
		"\tstate: %s\n"
		"\ttraveled distance: %.2f\n"
		"\tTime in state FREE: %d [s]\n"
		"\tTime in state HIRED: %d [s]\n",
		id, coords.pos_x, coords.pos_y, velocity, degree, numberOfTours, maxTours, hired ? "HIRED" : "FREE", traveledDistance, free_time, hired_time);
}