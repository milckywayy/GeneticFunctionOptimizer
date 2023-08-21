#include <iostream>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"

using namespace std;


int main(int argc, char **argv) {
    Constraints constraints(-1, 1, -1, 1);
    Quadratic quadratic;

    Population population(10, &(constraints), &(quadratic));

    for (int i = 0; i < 5; i++) {
        population.evaluation();
        population.selection();
        population.crossover();
        population.mutation();
    }

    population.print();

    population.free();

    return 0;
}