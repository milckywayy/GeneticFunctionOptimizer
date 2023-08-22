#include "gaussMutation.h"
#include <iostream>


GaussMutation::GaussMutation(double mutationRate) : Mutation(mutationRate) {
}

void GaussMutation::mutate(vector<Individual*> *children, Constraints *constraints, RandomNumberGenerator *rand) {
    double mutation;
    double newPos;

    // Mutate all children using gaussian distribution 
    for (int i = 0; i < children->size(); i++) {
        for (int axis = 0; axis < constraints->getDimension(); axis++) {
            do {
                mutation = rand->getGaussDistribution(0, mutationRate);
                newPos = children->at(i)->getPositionAtAxis(axis) + mutation;
            }
            while (!constraints->isInsideOnAxis(newPos, axis));

            children->at(i)->setPositionAtAxis(axis, newPos);
        }
    }
}
