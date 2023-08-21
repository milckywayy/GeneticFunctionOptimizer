#ifndef EVOLUTION_H_
#define EVOLUTION_H_


#include "constraints/constraints.h"
#include "objectives/objective.h"
#include "selections/tournamentSelection.h"


class Evolution {
private:
    Objective *fitnessFunc;
    Selection *selection;
    Population *population;
public:
    Evolution(Population *population, Objective *fitnessFunc, Selection *selection);
    void run();
};

#endif
