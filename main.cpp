#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "selections/tournamentSelection.h"
#include "utils/randomNumberGenerator.h"

using namespace std;


int main(int argc, char **argv) {
    randomNumberGenerator rand((unsigned)time(NULL));
    TournamentSelection selection(&rand);
    Constraints constraints(-1, 1, -1, 1);
    Quadratic fitnessFunc;
    

    Population population(10, &constraints);

    for (int i = 0; i < 5; i++) {
        population.evaluation(&fitnessFunc);
        selection.select(&population);
        // crossover();
        // mutation();
    }

    population.print();

    population.free();

    return 0;
}