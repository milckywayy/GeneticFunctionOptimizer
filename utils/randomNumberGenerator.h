#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_


class randomNumberGenerator {
private:
    unsigned int seed;
public:
    randomNumberGenerator(unsigned int seed);
    double getRandomDouble(double min, double max);
    int getRandomInteger(int min, int max);
    int getSeed();
};

#endif
