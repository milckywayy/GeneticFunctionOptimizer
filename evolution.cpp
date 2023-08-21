#include <iostream>
#include <time.h>
#include "evolution.h"
#include "population.h"
#include "utils/randomNumberGenerator.h"


Evolution::Evolution(Population *population, Objective *fitnessFunc, Selection *selection, Crossover *crossover) {
    this->fitnessFunc = fitnessFunc;
    this->selection = selection;
    this->population = population;
    this->crossover = crossover;
}

void Evolution::run() {
    randomNumberGenerator rand((unsigned)time(NULL));

    Population *parents = new Population();
    Population *children = new Population();
    for (int i = 0; i < 1; i++) {
        population->evaluation(fitnessFunc);
        selection->select(population, parents);
        // crossover();
        // mutation();
    }

    population->print();
    cout << endl;
    parents->print();

    delete parents;
    delete children;
}
