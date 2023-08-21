#ifndef SELECTION_H_
#define SELECTION_H_


#include "../population.h" 


class Selection {
public:
    virtual void select(Population *population);
};

#endif
