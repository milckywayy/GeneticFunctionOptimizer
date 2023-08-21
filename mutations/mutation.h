#ifndef MUTATION_H_
#define MUTATION_H_

#include "../utils/randomNumberGenerator.h"
#include "../population.h"

#include <iostream>

class Mutation {
public:
    double mutationRate;

    Mutation (double mutationRate){
        this->mutationRate = mutationRate;
    }
    virtual void mutate(Population *children, RandomNumberGenerator *rand) = 0;
};

#endif
