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
    Population(vector<Individual*> individuals);
    Population(int size, Constraints *constraints, RandomNumberGenerator *rand);
    void addIndividual(Individual *individual);
    Individual *getIndividual(int index);
    Individual *getBestIndividual();
    void removeIndividual(int index);
    int getSize();
    void evaluation(Objective *fitnessFunc);
    void print();
    Population *copy();
    void clear();
    ~Population();
};

#endif
