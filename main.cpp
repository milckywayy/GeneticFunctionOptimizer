#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "objectives/rosenbrock.h"
#include "selections/tournamentSelection.h"
#include "crossovers/onePointCrossover.h"
#include "mutations/gaussMutation.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"


using namespace std;


#define GENERATIONS 500
#define POPULATION_SIZE 50
#define MUTATION_RATE 0.01


int main(int argc, char **argv) {
    RandomNumberGenerator rand((unsigned)time(NULL));

    // Function to be optimized
    Rosenbrock fitnessFunc;

    Constraints constraints(-3, 3, -3, 3);
    TournamentSelection selection;    
    OnePointCrossover crossover;
    GaussMutation mutation(MUTATION_RATE);

    Evolution evolution(GENERATIONS, POPULATION_SIZE, &fitnessFunc, &constraints, &selection, &crossover, &mutation, &rand);

    Individual *solution;
    solution = evolution.run();
    solution->print();
    delete solution;

    return 0;
}
