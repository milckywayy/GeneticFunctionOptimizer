#ifndef MUTATION_H_
#define MUTATION_H_

#include "../utils/randomNumberGenerator.h"
#include "../constraints/constraints.h"
#include "../population.h"

#include <iostream>

class Mutation {
public:
    double mutationRate;

    Mutation (double mutationRate){
        this->mutationRate = mutationRate;
    }
    virtual void mutate(vector<Individual*> *children, Constraints *constraints, RandomNumberGenerator *rand) = 0;
};

#endif
