#include "singlePointMutation.h"
#include <iostream>


SinglePointMutation::SinglePointMutation(double mutationRate) : Mutation(mutationRate) {
}

void SinglePointMutation::mutate(Population *children, Constraints *constraints, RandomNumberGenerator *rand) {
    double newX;
    double newY;
    double weight;

    for (int i = 0; i < children->getSize(); i++) {
        if (rand->getRandomDouble(0, 1) <= mutationRate) {
            do {
                weight = rand->getGaussDistributionNumber(0.0, 1.0);

                newX = children->getIndividual(i)->getX() * weight;
                newY = children->getIndividual(i)->getY() * weight;
            }
            while (!constraints->isInside(newX, newY));

            children->getIndividual(i)->setX(newX);
            children->getIndividual(i)->setY(newY);
        }
    }
}
