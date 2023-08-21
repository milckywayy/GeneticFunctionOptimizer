#include <iostream>
#include <time.h>
#include "evolution.h"
#include "population.h"
#include "utils/randomNumberGenerator.h"


Evolution::Evolution(Population *population, Objective *fitnessFunc, Selection *selection) {
    this->fitnessFunc = fitnessFunc;
    this->selection = selection;
    this->population = population;
}

void Evolution::run() {
    randomNumberGenerator rand((unsigned)time(NULL));

    Population *parents = new Population();
    for (int i = 0; i < 5; i++) {
        population->evaluation(fitnessFunc);
        selection->select(population, parents);
        // population->clear();
        // crossover();
        // mutation();
        parents->clear();
    }
    delete parents;

    population->print();

    cout << "best one: " << population->getBestIndividual()->getFitness() << endl;
}
