#include <iostream>
#include <time.h>
#include <string>
#include <getopt.h>
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


#define DEFAULT_GENERATIONS 500
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_MUTATION_RATE 0.01


int main(int argc, char **argv) {
    int generations = DEFAULT_GENERATIONS;
    int population_size = DEFAULT_POPULATION_SIZE;
    double mutation_rate = DEFAULT_MUTATION_RATE;
    
    int option;
    while ((option = getopt(argc, argv, "f:c:g:p:m:e:")) != -1) {
        switch (option) {
            case 'f':
                cout << "Function: " << optarg << endl;
                break;
            case 'c':
                cout << "Constraints file: " << optarg << endl;
                break;
            case 'g':
                generations = stoi(optarg);
                break;
            case 'p':
                population_size = stoi(optarg);
                break;
            case 'm':
                mutation_rate = stod(optarg);
                break;
            case 'e':
                break;
            case '?':
                if (optopt == 'l') {
                    cerr << "No argument given for -" << (char)optopt << endl;
                }
                else {
                    cerr << "Unknown option: " << argv[optind - 1] << endl;
                }
                return 1;
        }
    }

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
    GaussMutation mutation(mutation_rate);

    Evolution evolution(generations, population_size, &fitnessFunc, &constraints, &selection, &crossover, &mutation, &rand);

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
