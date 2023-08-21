#ifndef POPULATION_H_
#define POPULATION_H_


#include <vector>
#include "individuals/individual.h"
#include "constraints/constraints.h"
#include "objectives/objective.h"

using namespace std;


class Population {
private:
    int size;
    vector<Individual*> individuals;  
    Constraints *constraints;
    Objective *fitness;

public:
    Population(int size, Constraints *constraints, Objective *fitness);
    void evaluation();
    void selection();
    void crossover();
    void mutation();
    void print();
};

#endif
