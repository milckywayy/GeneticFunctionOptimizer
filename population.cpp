#include <iostream>
#include <time.h>
#include "population.h"
#include "utils/randomNumberGenerator.h"


Population::Population(int size, Constraints *constraints, Objective *fitness) {
    this->size = size;
    this->constraints = constraints;
    this->fitness = fitness;

    randomNumberGenerator rand((unsigned)time(NULL));

    double x;
    double y;
    for (int i = 0; i < size; i++) {
        x = rand.getRandomDouble((double)constraints->getMinX(), (double)constraints->getMaxX());
        y = rand.getRandomDouble(constraints->getMinY(), constraints->getMaxY());

        individuals.push_back(new Individual(x, y));
    }
}

void Population::evaluation() {
    for (Individual *i : individuals) {
        i->setFitness(fitness->value(i->getX(), i->getY()));
    }
}

void Population::selection() {

}

void Population::crossover() {

}

void Population::mutation() {

}

void Population::print() {
    for (Individual *i : individuals) {
        cout << "(" << i->getX() << ", " << i->getY() << ") fitness: " << i->getFitness() << endl;
    }
}
