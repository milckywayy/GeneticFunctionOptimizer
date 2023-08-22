#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_


#include <random>


using namespace std;


class RandomNumberGenerator {
private:
    mt19937 gen;
public:
    RandomNumberGenerator(unsigned int seed);
    int getRandomInteger(int min, int max);
    double getRandomDouble(double min, double max);
    double getGaussDistribution(double mean, double deviation);
    double getRealDistribution(double leftBound, double rightBound);
};

#endif
