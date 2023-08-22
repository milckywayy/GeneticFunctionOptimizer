#include "gaussMutation.h"
#include <iostream>


GaussMutation::GaussMutation(double mutationRate) : Mutation(mutationRate) {
}

void GaussMutation::mutate(vector<Individual*> *children, Constraints *constraints, RandomNumberGenerator *rand) {
    double newX;
    double newY;
    double mutation;

    // Mutate all children using gaussian distribution 
    for (int i = 0; i < children->size(); i++) {
        mutation = rand->getGaussDistribution(0, mutationRate);

        newX = children->at(i)->getX() + mutation;
        newY = children->at(i)->getY() + mutation;

        children->at(i)->setX(newX);
        children->at(i)->setY(newY);
    }
}
