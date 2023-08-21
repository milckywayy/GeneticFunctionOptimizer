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
    Objective *fitnessFunc;

public:
    Population(int size, Constraints *constraints);
    void evaluation(Objective *fitnessFunc);
    void print();
    void free();
};

#endif
