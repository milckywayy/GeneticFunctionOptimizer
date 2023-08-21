#ifndef EVOLUTION_H_
#define EVOLUTION_H_


#include "constraints/constraints.h"
#include "objectives/objective.h"
#include "selections/tournamentSelection.h"
#include "crossovers/crossover.h"


class Evolution {
private:
    Objective *fitnessFunc;
    Selection *selection;
    Population *population;
    Crossover *crossover;
public:
    Evolution(Population *population, Objective *fitnessFunc, Selection *selection, Crossover *crossover);
    void run();
};

#endif
