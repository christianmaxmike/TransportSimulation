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
    // args/params for simulation
    int no_agents = 10;
    std::array<double, 3> probs = { 0.85, 0.1, 0.05 };

    // init simulation
    Environment env(ENV_HEIGHT, ENV_WIDTH);
    Scheduler scheduler(TIME_STEP);
    Model model(no_agents, probs, env, scheduler);

    // init model
    model.init();

    // start simulation model
    model.run();

    return 0;
}