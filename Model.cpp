#include "model.h"
#include "environment.h"
#include "privateCar.h"
#include "taxi.h"
#include "bus.h"
#include "Utils.h"
#include <chrono>
#include <iostream>
#include <typeinfo>
#include <iterator>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <algorithm>

void Model::init() {
	for (std::pair<int, int> p(0, 0); p.first < vehicleDistribution.size(); ++p.first) {
		for (int j = 0; j < vehicleDistribution[p.first] * no_agents; j++, p.second++) {
			Vehicle* v;
			if (p.first == 0)
				v = new PrivateCar{ p.second, 1, privateCarType::SUV };
			else if (p.first == 1)
				v = new Taxi{ p.second, 1 };
			else
				v = new Bus{ p.second, 1 };

			v->placeInEnv(env);
			scheduler.addVehicle(v);
		}
	}
	std::cout << "Total vehicles created: " << scheduler.getVehicles().size() << std::endl;
}

bool Model::isAgentInEnvBoundaries(Vehicle& v, Environment& env) {
	if (v.getCoords().pos_x > 0 && v.getCoords().pos_x < env.getWidth() &&
		v.getCoords().pos_y > 0 && v.getCoords().pos_y < env.getHeight())
		return true;
	else
		return false;
}


template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

void Model::addToSummary(Vehicle* pEntity) {
	auto lifetime = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::high_resolution_clock::now() - pEntity->getBirthTimePoint()).count();
	std::cout << "\tTotal Lifetime: " << lifetime << "ms" << std::endl;

	if (instanceof<PrivateCar>(pEntity)) {
		summary["privateCar"]["traveledDistance"].push_back(pEntity->getTraveledDistance());
		summary["privateCar"]["lifetime"].push_back(lifetime);
	}
	else if (instanceof<Taxi>(pEntity)) {
		Taxi* taxi = dynamic_cast<Taxi*>(pEntity);
		summary["Taxi"]["traveledDistance"].push_back(taxi->getTraveledDistance());
		summary["Taxi"]["lifetime"].push_back(lifetime);
		summary["Taxi"]["FREETime"].push_back(taxi->getFreeTime());
		summary["Taxi"]["HIREDTIme"].push_back(taxi->getHiredTime());
	}
	else if (instanceof<Bus>(pEntity)) {
		summary["Bus"]["traveledDistance"].push_back(pEntity->getTraveledDistance());
		summary["Bus"]["lifetime"].push_back(lifetime);
	}

}

void Model::checkAgentsValidity()
{
	for (Vehicle* pEntity : this->scheduler.getVehicles())
	{
		if (!this->isAgentInEnvBoundaries(*pEntity, env)) {
			std::cout << "[!] Agent out of bounds." << std::endl;
			pEntity->printInfo();
			addToSummary(pEntity);
			this->scheduler.removeVehicle(pEntity);
		}
	}
}

void Model::run() {
	while (scheduler.getVehicles().size() > 0)
	{
		scheduler.step(env);
		checkAgentsValidity();
	}

	printf("SUMMARY\n=======\n");
	for (auto const& key : summary) {
		std::cout << "Car Type: " << key.first << std::endl;
		for (auto const innerKey : key.second) {

			double sum = std::accumulate(innerKey.second.begin(), innerKey.second.end(), 0);
			double mean = sum / innerKey.second.size();

			double squaredSum = std::inner_product(
				innerKey.second.begin(), innerKey.second.end(), innerKey.second.begin(), 0.0);
			double stdev = std::sqrt(squaredSum / innerKey.second.size() - std::pow(mean,2));

			double min_value = *std::min_element(innerKey.second.begin(), innerKey.second.end());
			double max_value = *std::max_element(innerKey.second.begin(), innerKey.second.end());

			std::cout << "Attribute: " << innerKey.first << std::endl;
			std::cout << "----------\n";
			std::cout << "Average: " << mean << std::endl;
			std::cout << "Std Dev: " << stdev << std::endl;
			std::cout << "Min Val: " << min_value << std::endl;
			std::cout << "Max Val: " << max_value << std::endl;
			std::cout << "====================\n";
		}
		std::cout << std::endl;
	}

}