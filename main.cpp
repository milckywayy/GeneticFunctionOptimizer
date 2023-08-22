#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "selections/tournamentSelection.h"
#include "crossovers/onePointCrossover.h"
#include "mutations/singlePointMutation.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"

using namespace std;


int main(int argc, char **argv) {
    RandomNumberGenerator rand((unsigned)time(NULL));

    Constraints constraints(-1, 1, -1, 1);
    Quadratic fitnessFunc;
    TournamentSelection selection(&rand);    
    OnePointCrossover crossover;
    SinglePointMutation mutation(0.1);

    Population *population = new Population(10, &constraints, &rand);

    Evolution evolution(population, &fitnessFunc, &constraints, &selection, &crossover, &mutation);
    evolution.run();

    delete population;

    return 0;
}
