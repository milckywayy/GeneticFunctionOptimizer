#ifndef ARITHMETIC_CROSSOVER_H_
#define ARITHMETIC_CROSSOVER_H_


#include "crossover.h"
#include "../population.h"


class OnePointCrossover : public Crossover {
public:
    void cross(Individual **parents, vector<Individual*> *children, RandomNumberGenerator *rand);
};

#endif
