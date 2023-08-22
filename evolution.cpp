#include <iostream>
#include <time.h>
#include <vector>
#include "evolution.h"
#include "population.h"
#include "constraints/constraints.h"
#include "utils/randomNumberGenerator.h"


Evolution::Evolution(int generations, int populationSize, Objective *fitnessFunc, Constraints *constraints, Selection *selection, Crossover *crossover, Mutation *mutation, RandomNumberGenerator *rand) {
    this->generations = generations;
    this->populationSize = populationSize;
    this->fitnessFunc = fitnessFunc;
    this->constraints = constraints;
    this->selection = selection;
    this->crossover = crossover;
    this->mutation = mutation;
    this->rand = rand;
}

Individual *Evolution::run() {
    Population *population = new Population(populationSize, constraints, rand);
    Individual **parents = new Individual*[2];
    vector<Individual*> *born_children = new vector<Individual*>;
    Population *children = new Population();

    Individual *solution;

    for (int generation = 0; generation < generations; generation++) {
        population->evaluate(fitnessFunc);

        // Always add best individual to the next generation
        children->addIndividual(population->getBestIndividual()->copy());

        // Creating new generation
        while (children->getSize() < population->getSize()) {
            selection->select(population, parents, rand);
            crossover->cross(parents, born_children, rand);
            mutation->mutate(born_children, constraints, rand);

            // Add born children to children population
            for (int child_i = 0; child_i < born_children->size(); child_i++) {
                children->addIndividual(born_children->at(child_i));
            }

            born_children->clear();
        }

        // Replace old gen with new gen
        population->clear();
        children->copy(population);
        children->clear();
    }

    population->evaluate(fitnessFunc);
    solution = population->getBestIndividual()->copy();

    delete born_children;
    delete children;
    delete parents;
    delete population;

    return solution;
}
