#ifndef ARITHMETIC_CROSSOVER_H_
#define ARITHMETIC_CROSSOVER_H_


#include "crossover.h"
#include "../population.h"


class OnePointCrossover : public Crossover {
public:
    void cross(Population *parents, Population *children, RandomNumberGenerator *rand);
};

#endif
