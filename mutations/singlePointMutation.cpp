#include "singlePointMutation.h"
#include <iostream>


SinglePointMutation::SinglePointMutation(double mutationRate) : Mutation(mutationRate) {
}

void SinglePointMutation::mutate(Population *children, RandomNumberGenerator *rand) {
    double weight;

    for (int i = 0; i < children->getSize(); i++) {
        if (rand->getRandomDouble(0, 1) <= mutationRate) {
            weight = rand->getGaussDistributionNumber(0.0, 1.0);

            cout << children->getIndividual(i)->getX() << ", " << weight << endl;

            children->getIndividual(i)->setX(children->getIndividual(i)->getX() * weight);
            children->getIndividual(i)->setY(children->getIndividual(i)->getY() * weight);

            cout << children->getIndividual(i)->getX() << endl;
            cout << endl;
        }
    }
}
