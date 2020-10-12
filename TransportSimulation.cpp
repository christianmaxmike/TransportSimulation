// TransportSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include "model.h"
#include "environment.h"
#include "scheduler.h"
#include "constants.h"

int main(int argc, char* argv[])
{
    // init modules for simulation
    Environment env(ENV_HEIGHT, ENV_WIDTH);
    Scheduler scheduler(TIME_STEP);

    // init model
    Model model(NO_AGENTS, VEHICLES_PROBS, env, scheduler);
    model.init();

    // start simulation model
    model.run();

    return 0;
}