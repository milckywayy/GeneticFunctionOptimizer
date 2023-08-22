#ifndef GAUSS_MUTATION_H_
#define GAUSS_MUTATION_H_

#include "mutation.h"


class GaussMutation : public Mutation {
public:
    GaussMutation(double mutationRate);
    void mutate(vector<Individual*> *children, Constraints *constraints, RandomNumberGenerator *rand);
};

#endif
