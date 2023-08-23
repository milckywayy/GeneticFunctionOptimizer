#include <iostream>
#include <time.h>
#include <string>
#include <cstring>
#include <getopt.h>
#include "population.h"
#include "constraints/constraints.h"
#include "constraints/constraintsReader.h"
#include "objectives/quadratic.h"
#include "objectives/rosenbrock.h"
#include "objectives/cubic.h"
#include "objectives/customFunction.h"
#include "selections/tournamentSelection.h"
#include "crossovers/onePointCrossover.h"
#include "mutations/gaussMutation.h"
#include "utils/randomNumberGenerator.h"
#include "evolution.h"


using namespace std;


#define SOLUTION_PRECISION 1000

#define DEFAULT_GENERATIONS 500
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_MUTATION_RATE 0.01
#define DEFAULT_CONSTRAINTS_VALUE 2.0
#define DEFAULT_FUNCTION_REVERSE false


void help() {
    cout << "Evolutionary algorithm for function optimization.\n\n"
         << "Usage: ./program_name [OPTIONS]\n"
         << "Options:\n"
         << "\t-f <function>   Specify the custom function to be optimized. Default: Rosenbrock.\n"
         << "\t-c <constraints_file>  Read constraints from the specified file.\n"
         << "\t-g <generations>  Specify the number of generations. Default: 500.\n"
         << "\t-p <population>   Specify the population size. Default: 50.\n"
         << "\t-m <mutation-rate>   Specify the mutation rate. Default: 0.01.\n"
         << "\t-e <min/max>   Specify whether to find the function minimum or maximum. Default: maximum.\n"
         << "\t-h   Display this help message.\n";
}

int main(int argc, char **argv) {
    // Basic algorithm parameters
    int generations = DEFAULT_GENERATIONS;
    int populationSize = DEFAULT_POPULATION_SIZE;
    double mutationRate = DEFAULT_MUTATION_RATE;

    // false if we're looking for function maximum, true - minimum
    bool functionReverse = DEFAULT_FUNCTION_REVERSE;

    Objective *fitnessFunc = NULL;
    Constraints *constraints = NULL;

    int option;
    while ((option = getopt(argc, argv, "hf:c:g:p:m:e:")) != -1) {
        switch (option) {
            case 'h':
                help();
                return 0;
                break;
            case 'f':
                try {
                    fitnessFunc = new CustomFunction(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: " << e.what() << endl;
                    return 2;
                }
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
                    populationSize = stoi(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: Population size must be an integer" << endl;
                    return 2;
                }
                break;
            case 'm':
                try {
                    mutationRate = stod(optarg);
                }
                catch (exception &e) {
                    cerr << "Error: Mutation rate have be a float number" << endl;
                    return 2;
                }
                break;
            case 'e':
                try {
                    if (strcmp(optarg, "min") == 0) {
                        functionReverse = true;
                    }
                    else if (strcmp(optarg, "max") == 0) {
                        functionReverse = false;
                    }
                    else {
                        cerr << "Error: Argument " << optarg << " is not supported" << endl;
                        return 2;
                    }
                }
                catch (exception &e) {
                    cerr << "Error: Mutation rate have be a float number" << endl;
                    return 2;
                }
                break;
            case '?':
                if (optopt == 'f' || optopt == 'c' || optopt == 'g' || optopt == 'p' || optopt == 'm' || optopt == 'e') {
                    cerr << "Error: No argument given for -" << (char)optopt << endl;
                }
                else {
                    cerr << "Error: Unknown option: " << argv[optind - 1] << endl;
                }
                cout << endl;
                help();
                return 1;
        }
    }

    if (fitnessFunc == NULL) {
        // Use default function to be optimised
        fitnessFunc = new Rosenbrock;
    }
    fitnessFunc->setReverse(functionReverse);

    if (constraints == NULL) {
        // Use default constraints
        constraints = new Constraints(fitnessFunc->getDimension(), DEFAULT_CONSTRAINTS_VALUE);
    }

    // Check if function and constraints are matched
    if (constraints->getDimension() != fitnessFunc->getDimension()) {
        delete fitnessFunc;
        delete constraints;
        cerr << "Error: Constraints don't match given function" << endl;
        return 3;
    }

    RandomNumberGenerator rand((unsigned)time(NULL));
    TournamentSelection selection;    
    OnePointCrossover crossover;
    GaussMutation mutation(mutationRate);
    Evolution evolution(generations, populationSize, fitnessFunc, constraints, &selection, &crossover, &mutation, &rand);
    Individual *solution;

    try {
        // Starting main algorithm
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
    cout << "Solution:\nvalue = " << round(solution->getFitness() * SOLUTION_PRECISION) / SOLUTION_PRECISION << " at ( ";
    for (int axis = 0; axis < solution->getDimension(); axis++) {
        cout << round(solution->getPositionAtAxis(axis) * SOLUTION_PRECISION) / SOLUTION_PRECISION << " ";
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
