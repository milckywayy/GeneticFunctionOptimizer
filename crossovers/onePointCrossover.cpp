#include "onePointCrossover.h"
#include "../utils/randomNumberGenerator.h"
#include <iostream>


void OnePointCrossover::cross(Population *parents, Population *children, RandomNumberGenerator *rand) {
    int mum;
    int dad;
    double weight;

    for (int i = 0 ; i < parents->getSize(); i++) {
        mum = rand->getRandomInteger(0, parents->getSize() - 1);
        dad = rand->getRandomInteger(0, parents->getSize() - 1);

        weight = rand->getRandomDouble(0, 1);

        children->addIndividual(new Individual(parents->getIndividual(mum)->getX() * weight, parents->getIndividual(dad)->getY() * (1 - weight)));
        children->addIndividual(new Individual(parents->getIndividual(dad)->getX() * weight, parents->getIndividual(mum)->getY() * (1 - weight)));
    }
}
