#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_


#include <random>


using namespace std;


class RandomNumberGenerator {
private:
    mt19937 gen;
public:
    RandomNumberGenerator(unsigned int seed);
    double getRandomDouble(double min, double max);
    int getRandomInteger(int min, int max);
    double getGaussDistributionNumber(double mean, double deviation);
};

#endif
