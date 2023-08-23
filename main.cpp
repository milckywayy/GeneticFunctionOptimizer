#include <iostream>
#include <time.h>
#include <string>
#include <getopt.h>
#include "population.h"
#include "constraints/constraints.h"
#include "constraints/constraintsReader.h"
#include "objectives/quadratic.h"
#include "objectives/rosenbrock.h"
#include "objectives/cubic.h"
#include "selections/tournamentSelection.h"
#include "crossovers/onePointCrossover.h"
#include "mutations/gaussMutation.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"


using namespace std;


#define DEFAULT_GENERATIONS 500
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_MUTATION_RATE 0.01


int main(int argc, char **argv) {
    int generations = DEFAULT_GENERATIONS;
    int population_size = DEFAULT_POPULATION_SIZE;
    double mutation_rate = DEFAULT_MUTATION_RATE;

    Objective *fitnessFunc = NULL;
    Constraints *constraints = NULL;

    TournamentSelection selection;    
    OnePointCrossover crossover;
    GaussMutation mutation(mutation_rate);

    int option;
    while ((option = getopt(argc, argv, "f:c:g:p:m:e:")) != -1) {
        switch (option) {
            case 'f':
                cout << "Function: " << optarg << endl;
                break;
            case 'c':
                try {
                    constraints = readConstraintsFromFile(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: " << e.what() << endl;
                    return 2;
                }
                break;
            case 'g':
                try {
                    generations = stoi(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: Generations number must be an integer" << endl;
                    return 2;
                }
                break;
            case 'p':
                try {
                    population_size = stoi(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: Population size must be an integer" << endl;
                    return 2;
                }
                break;
            case 'm':
                try {
                    mutation_rate = stod(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: Mutation rate have be a float number" << endl;
                    return 2;
                }
                break;
            case 'e':
                break;
            case '?':
                if (optopt == 'f' || optopt == 'c' || optopt == 'g' || optopt == 'p' || optopt == 'm') {
                    cerr << "Error: No argument given for -" << (char)optopt << endl;
                }
                else {
                    cerr << "Error: Unknown option: " << argv[optind - 1] << endl;
                }
                return 1;
        }
    }

    if (constraints == NULL) {
        // Use default constraints
        constraints = new Constraints(2, 2.0);
    }

    if (fitnessFunc == NULL) {
        // Use default function to be optimised
        fitnessFunc = new Rosenbrock;
    }

    if (constraints->getDimension() != fitnessFunc->getDimension()) {
        delete fitnessFunc;
        delete constraints;
        cerr << "Error: Constraints don't match given function" << endl;
        return 3;
    }

    RandomNumberGenerator rand((unsigned)time(NULL));
    Evolution evolution(generations, population_size, fitnessFunc, constraints, &selection, &crossover, &mutation, &rand);
    Individual *solution;

    try {
        solution = evolution.run();
    }
    catch (exception &e) {
        delete fitnessFunc;
        delete constraints;
        delete solution;
        cerr << "Error: " << e.what() << endl;
        return 4;
    }
    
    // Print solution
    cout << "Solution: ( ";
    for (int axis = 0; axis < solution->getDimension(); axis++) {
        cout << round(solution->getPositionAtAxis(axis) * 1000) / 1000 << " ";
    }
    cout << ") in:" << endl;
    for (int axis = 0; axis < solution->getDimension(); axis++) {
        cout << "axis" << axis << " <" << constraints->getMin(axis) << ", " << constraints->getMax(axis) << ">" << endl;
    }

    delete fitnessFunc;
    delete constraints;
    delete solution;

    return 0;
}
