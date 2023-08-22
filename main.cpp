#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "objectives/rosenbrock.h"
#include "selections/tournamentSelection.h"
#include "crossovers/onePointCrossover.h"
#include "mutations/singlePointMutation.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"

using namespace std;


#define GENERATIONS 100
#define POPULATION 1000
#define MUTATION_RATE 0.05


int main(int argc, char **argv) {
    RandomNumberGenerator rand((unsigned)time(NULL));

    Constraints constraints(-3, 3, -3, 3);
    // Quadratic fitnessFunc;
    Rosenbrock fitnessFunc;
    TournamentSelection selection(&rand);    
    OnePointCrossover crossover;
    SinglePointMutation mutation(MUTATION_RATE);

    Population *population = new Population(POPULATION, &constraints, &rand);

    Evolution evolution(GENERATIONS, population, &fitnessFunc, &constraints, &selection, &crossover, &mutation);
    evolution.run();

    delete population;

    return 0;
}
