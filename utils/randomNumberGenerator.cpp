#include <random>
#include <time.h>
#include "randomNumberGenerator.h"


randomNumberGenerator::randomNumberGenerator(unsigned int seed) {
    this->seed = seed;

    srand(seed);
}

double randomNumberGenerator::getRandomDouble(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + (f * (max - min));
}

int randomNumberGenerator::getRandomInteger(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int randomNumberGenerator::getSeed() {
    return seed;
}
