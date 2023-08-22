#ifndef EVOLUTION_H_
#define EVOLUTION_H_


#include "constraints/constraints.h"
#include "objectives/objective.h"
#include "selections/tournamentSelection.h"
#include "crossovers/crossover.h"
#include "mutations/mutation.h"


class Evolution {
private:
    int generations;
    Objective *fitnessFunc;
    Constraints *constraints;
    Selection *selection;
    Population *population;
    Crossover *crossover;
    Mutation *mutation;
public:
    Evolution(int generations, Population *population, Objective *fitnessFunc, Constraints *constraints, Selection *selection, Crossover *crossover, Mutation *mutation);
    void run();
};

#endif
