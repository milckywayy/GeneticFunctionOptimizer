#ifndef ONE_POINT_CROSSOVER_H_
#define ONE_POINT_CROSSOVER_H_


#include "crossover.h"
#include "../population.h"


class OnePointCrossover : public Crossover {
public:
    void cross(Individual **parents, vector<Individual*> *children, RandomNumberGenerator *rand);
};

#endif
