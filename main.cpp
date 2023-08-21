#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "selections/tournamentSelection.h"
#include "crossovers/arithmeticCrossover.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"

using namespace std;


int main(int argc, char **argv) {
    randomNumberGenerator rand((unsigned)time(NULL));

    Constraints constraints(-1, 1, -1, 1);
    Quadratic fitnessFunc;
    TournamentSelection selection(&rand);    
    ArithmeticCrossover crossover;    

    Population *population = new Population(10, &constraints, &rand);

    Evolution evolution(population, &fitnessFunc, &selection, &crossover);
    evolution.run();

    delete population;

    return 0;
}