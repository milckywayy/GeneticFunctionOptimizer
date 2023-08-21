#ifndef CROSSOVER_H_
#define CROSSOVER_H_


#include "../population.h" 


class Crossover {
public:    
    virtual void cross(Population *parents, Population *children) = 0;
};

#endif
