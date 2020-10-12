#include <random>

double randnum(double a, double b)
{
	static std::mt19937 generator (123);
	std::uniform_real_distribution<float> distribution(a, b);
	return distribution(generator);
}