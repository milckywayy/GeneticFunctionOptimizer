#ifndef CROSSOVER_H_
#define CROSSOVER_H_


#include "../population.h" 


class Crossover {
public:    
    virtual void cross(Individual **parents, vector<Individual*> *children, RandomNumberGenerator *rand) = 0;
};

#endif
