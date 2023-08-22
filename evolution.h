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
    int populationSize;
    Objective *fitnessFunc;
    Constraints *constraints;
    Selection *selection;
    Crossover *crossover;
    Mutation *mutation;
    RandomNumberGenerator *rand;
public:
    Evolution(int generations, int populationSize, Objective *fitnessFunc, Constraints *constraints, Selection *selection, Crossover *crossover, Mutation *mutation, RandomNumberGenerator *rand);
    Individual * run();
};

#endif
