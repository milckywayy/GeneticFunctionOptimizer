#include "randomNumberGenerator.h"


using namespace std;


RandomNumberGenerator::RandomNumberGenerator(unsigned int seed) : gen(seed) {}

int RandomNumberGenerator::getRandomInteger(int min, int max) {
    uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

double RandomNumberGenerator::getRandomDouble(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(gen);
}

double RandomNumberGenerator::getGaussDistribution(double mean, double deviation) {
    normal_distribution<double> distribution(mean, deviation);
    return distribution(gen);
}

double RandomNumberGenerator::getRealDistribution(double leftBound, double rightBound) {
    uniform_real_distribution<> distribution(leftBound, rightBound);
    return distribution(gen);
}
