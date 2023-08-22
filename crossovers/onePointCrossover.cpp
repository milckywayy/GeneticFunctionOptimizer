#include "onePointCrossover.h"
#include "../utils/randomNumberGenerator.h"
#include <iostream>


void OnePointCrossover::cross(Individual **parents, vector<Individual*> *children, RandomNumberGenerator *rand) {
    children->push_back(new Individual(parents[0]->getX(), parents[1]->getY()));
    children->push_back(new Individual(parents[1]->getX(), parents[0]->getY()));
}
