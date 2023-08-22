#include <iostream>
#include <time.h>
#include "population.h"
#include "constraints/constraints.h"
#include "objectives/quadratic.h"
#include "objectives/rosenbrock.h"
#include "objectives/cubic.h"
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

    vector<double> constraintsMin;
    vector<double> constraintsMax;
    constraintsMin.push_back(-2);
    constraintsMin.push_back(-2);
    constraintsMin.push_back(-2);
    constraintsMax.push_back(2);
    constraintsMax.push_back(2);
    constraintsMax.push_back(2);

    Constraints constraints(fitnessFunc.getDimension(), &constraintsMin, &constraintsMax);
    TournamentSelection selection;    
    OnePointCrossover crossover;
    GaussMutation mutation(MUTATION_RATE);

    Evolution evolution(GENERATIONS, POPULATION_SIZE, &fitnessFunc, &constraints, &selection, &crossover, &mutation, &rand);

    Individual *solution;
    solution = evolution.run();
    
    cout << "Solution: ( ";
    for (int axis = 0; axis < solution->getDimension(); axis++) {
        cout << round(solution->getPositionAtAxis(axis) * 1000) / 1000 << " ";
    }
    cout << ")" << endl;

    delete solution;

    return 0;
}
