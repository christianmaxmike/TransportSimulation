//
// model.h
//
// @author: Christian Frey
//
// This header is used for the descirption of the model for the simulation. 
// It holds the instances of the environment and scheduler.
//
#pragma once
#include "environment.h"
#include <array>
#include "scheduler.h"
#include <map>
#include <string>
#include <vector>

class Model {
private:
	int no_agents;		// number of agents running in the env
	Environment env;	// environment the agents live in
	Scheduler scheduler;// scheduling for the agents
	std::array<double, 3> vehicleDistribution; // distribution for vehicles type

	// summary including the vehicles information after they drop off the environment
	std::map<std::string, std::map<std::string, std::vector<double>>> summary;	

	// adds the vehicles information being attached as parameter to the summary recordings
	void addToSummary(Vehicle* v);

public:
	// Constructor a model holding the simulation's necessary instances
	// 
	// Parameter:
	// no_agents: number of agents within the simulation
	// probs: probability distribution of the various vehicles
	// env: 2D environment being used for the simulation
	// scheduler: Scheduler handling the ordering of the agents actions within the simulation
	Model (int no_agents, std::array<double, 3> probs, Environment env, Scheduler scheduler) 
		: no_agents{ no_agents }, vehicleDistribution{ probs }, 
		  env{ env }, scheduler{ scheduler } {}

	// initialize the model
	void init();

	// start the model 
	void run();

	// checks whether an agent still are within the env boundaries
	bool isAgentInEnvBoundaries(Vehicle &v, Environment &env);

	// check if agents fullfill validity check
	void checkAgentsValidity();

	//print summary (called at the end of the simulation)
	void printSummary();
};