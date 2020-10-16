//
// privateCar.h
//
// @author: Christian Frey
//
// This header is used for the description of the private car entity within the simulation.
//
#pragma once
#include "vehicle.h"
#include "constants.h"
#include "Utils.h"
enum class privateCarType { SmartCar, SUV };

class PrivateCar : public Vehicle
{
public:
	// default constructor
	PrivateCar();

	// Constructor for the private car vehicle
	// 
	// Parameter:
	// id: unique id for the private car
	// no_pass: number of passengers within the car
	// type: vehicles typ (SMARTCar, SUV)
	PrivateCar(int id, int no_pass, privateCarType type);

	// print the information fo the private car instance
	const void printInfo() const override;

private:
	privateCarType type;	// type of the private car (SMARTCar, SUV)
};