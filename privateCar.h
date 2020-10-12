//
// taxi.h
//
// @author: Christian Frey
//
// This header is used for the description of the Private car entity within the simulation.
//
#pragma once
#include "vehicle.h"
#include "constants.h"
#include "Utils.h"
enum class privateCarType { SmartCar, SUV };

class PrivateCar : public Vehicle
{
public:
	PrivateCar();
	PrivateCar(int id, int no_pass, privateCarType type);

	const void printInfo() const override;

private:
	privateCarType type;
};