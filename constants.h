//
// constants.h
//
// @author: Christian Frey
//
// This header is used for the constants/intervals used for the simulation.
//
#pragma once
#include <array>

// *** GENERAL ***
const int NO_AGENTS = 20;											// number of agents within the simulation
const std::array<double, 3> VEHICLES_PROBS = { 0.85, 0.1, 0.05 };	// vehicles distribution being creates (car,taxi,bus)

// *** VEHICLES VALUES ***
// BUS 
const int MIN_BUS_CAPACITY = 15;	// minimal capacity of the bus instances
const int MAX_BUS_CAPACITY = 50;	// maximal capacity of the bus instances
const double MIN_BUS_VELOCITY = 20;	// minimal velocity of the bus instances
const double MAX_BUS_VELOCITY = 30;	// maximal velocity of the bus instances 
const int BOARDING_INTERVAL = 5;	// time interval after which a bus stop is simulated [min]
// CAR
const double MIN_CAR_VELOCITY = 30;	// minimal velocity of the car instances
const double MAX_CAR_VELOCITY = 50;	// maximal velocity of the car instances
// TAXI
const double MIN_TAXI_VELOCITY = 40;// minimal velocity of the taxi instances
const double MAX_TAXI_VELOCITY = 60;// maximal velocity of the taxi instances
const int MAX_TAXI_TOURS = 3;		// maximal tour a taxi can drive

// *** ENV VALUES ***
const int ENV_WIDTH = 3000;	// the width of the 2D-environment 
const int ENV_HEIGHT = 2000;// the height of the 2D-environment

// *** SCHEDULER VALUES ***
const int TIME_STEP = 1000; // simulation time after which the vehicles within the environmen are updated [ms]

// *** MISC CONSTANTS ***
const double MATH_PI = 3.141592;// Constant pi

// *** DEBUG PRINT LEVEL ***
const int VERBOSE = 0; // used for print level