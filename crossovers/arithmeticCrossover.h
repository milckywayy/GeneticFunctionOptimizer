#ifndef ARITHMETIC_CROSSOVER_H_
#define ARITHMETIC_CROSSOVER_H_


#include "crossover.h"


class ArithmeticCrossover : public Crossover {
public:
    void cross(Population *parents, Population *children);
};

#endif
