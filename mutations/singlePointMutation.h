#ifndef SINGLE_POINT_MUTATION_H_
#define SINGLE_POINT_MUTATION_H_

#include "mutation.h"


class SinglePointMutation : public Mutation {
public:
    SinglePointMutation(double mutationRate);
    void mutate(Population *children, RandomNumberGenerator *rand);
};

#endif
