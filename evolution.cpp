#include <iostream>
#include <time.h>
#include "evolution.h"
#include "population.h"
#include "constraints/constraints.h"
#include "utils/randomNumberGenerator.h"


Evolution::Evolution(Population *population, Objective *fitnessFunc, Constraints *constraints, Selection *selection, Crossover *crossover, Mutation *mutation) {
    this->fitnessFunc = fitnessFunc;
    this->constraints = constraints;
    this->selection = selection;
    this->population = population;
    this->crossover = crossover;
    this->mutation = mutation;
}

void Evolution::run() {
    RandomNumberGenerator rand((unsigned)time(NULL));

    Population *parents = new Population();
    Population *children = new Population();
    for (int i = 0; i < 5; i++) {
        population->evaluation(fitnessFunc);
        selection->select(population, parents);
        crossover->cross(parents, children, &rand);
        mutation->mutate(children, constraints, &rand);
        population = children->copy();

        parents->clear();
        children->clear();
    }

    cout << round(population->getBestIndividual()->getX() * 100) / 100 << ", " << round(population->getBestIndividual()->getY() * 100) / 100 << endl;

    delete parents;
    delete children;
}