#ifndef POPULATION_H_
#define POPULATION_H_


#include <vector>
#include "individuals/individual.h"
#include "constraints/constraints.h"
#include "objectives/objective.h"
#include "utils/randomNumberGenerator.h"

using namespace std;


class Population {
private:
    vector<Individual*> individuals;  
    Constraints *constraints;
    Objective *fitnessFunc;
 
public:
    Population();
    Population(int size, Constraints *constraints, RandomNumberGenerator *rand);
    void addIndividual(Individual *individual);
    Individual *getIndividual(int index);
    Individual *getBestIndividual();
    int getSize();
    double getAvegareFitness();
    void evaluate(Objective *fitnessFunc);
    void print();
    void copy(Population *population);
    void clear();
    ~Population();
};

#endif
