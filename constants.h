//
// constants.h
//
// @author: Christian Frey
//
// This header is used for the constants/intervals used for the simulation.
//
#pragma once
#include <array>

// *** GENERAL
const int NO_AGENTS = 20;
const std::array<double, 3> VEHICLES_PROBS = { 0.85, 0.1, 0.05 };

// *** VEHICLES VALUES ***
// BUS 
const int MIN_BUS_CAPACITY = 15;
const int MAX_BUS_CAPACITY = 50;
const double MIN_BUS_VELOCITY = 20;
const double MAX_BUS_VELOCITY = 30;
const int BOARDING_INTERVAL = 5;
// CAR
const double MIN_CAR_VELOCITY = 30;
const double MAX_CAR_VELOCITY = 50;
// TAXI
const double MIN_TAXI_VELOCITY = 40;
const double MAX_TAXI_VELOCITY = 60;
const int MAX_TAXI_TOURS = 3;

// *** ENV VALUES ***
const int ENV_WIDTH = 3000;
const int ENV_HEIGHT = 2000;

// *** SCHEDULER VALUES ***
const int TIME_STEP = 1000; // in ms

// *** MISC CONSTANTS ***
const double MATH_PI = 3.141592;

// *** DEBUG PRINT LEVEL ***
const int VERBOSE = 0;