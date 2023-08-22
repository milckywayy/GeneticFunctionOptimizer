#include "onePointCrossover.h"
#include "../utils/randomNumberGenerator.h"
#include <iostream>


void OnePointCrossover::cross(Population *parents, Population *children, RandomNumberGenerator *rand) {
    int mum_index;
    int dad_index;

    for (int i = 0 ; i < parents->getSize(); i++) {
        do {
            mum_index = rand->getRandomInteger(0, parents->getSize() - 1);
            dad_index = rand->getRandomInteger(0, parents->getSize() - 1);
        }
        while (mum_index != dad_index);

        children->addIndividual(new Individual(parents->getIndividual(mum_index)->getX(), parents->getIndividual(dad_index)->getY()));
        children->addIndividual(new Individual(parents->getIndividual(dad_index)->getX(), parents->getIndividual(mum_index)->getY()));
    }
}
