#include <iostream>
#include <time.h>
#include "population.h"
#include "selections/tournamentSelection.h"
#include "utils/randomNumberGenerator.h"


Population::Population(int size, Constraints *constraints) {
    this->size = size;
    this->constraints = constraints;

    randomNumberGenerator rand((unsigned)time(NULL));

    double x;
    double y;
    for (int i = 0; i < size; i++) {
        x = rand.getRandomDouble((double)constraints->getMinX(), (double)constraints->getMaxX());
        y = rand.getRandomDouble(constraints->getMinY(), constraints->getMaxY());

        individuals.push_back(new Individual(x, y));
    }
}

void Population::evaluation(Objective *fitnessFunc) {
    for (Individual *i : individuals) {
        i->setFitness(fitnessFunc->value(i->getX(), i->getY()));
    }
}

void Population::print() {
    for (Individual *i : individuals) {
        cout << "(" << i->getX() << ", " << i->getY() << ") fitness: " << i->getFitness() << endl;
    }
}

void Population::free() {
    for (Individual *i : individuals) {
        delete i;
    }
}
