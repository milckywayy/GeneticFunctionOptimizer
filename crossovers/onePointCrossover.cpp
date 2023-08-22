#include "onePointCrossover.h"
#include "../utils/randomNumberGenerator.h"
#include <iostream>


#include <vector>


void OnePointCrossover::cross(Individual **parents, vector<Individual*> *children, RandomNumberGenerator *rand) {
    int crossoverPoint = rand->getRandomInteger(1, parents[0]->getDimension());

    vector<double> *newChildPosition = new vector<double>;

    for (int axis = 0; axis < crossoverPoint; axis++) {
        newChildPosition->push_back(parents[0]->getPositionAtAxis(axis));
    }

    for (int axis = crossoverPoint; axis < parents[0]->getDimension(); axis++) {
        newChildPosition->push_back(parents[1]->getPositionAtAxis(axis));
    }

    children->push_back(new Individual(newChildPosition));
}
