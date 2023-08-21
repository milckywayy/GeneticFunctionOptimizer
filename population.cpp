#include <random>
#include <time.h>
#include <iostream>
#include "population.h"


double generateRandomDouble(double minRange, double maxRange) {
    double f = (double)rand() / RAND_MAX;
    return minRange + (f * (maxRange - minRange));
}

Population::Population(int size, Constraints *constraints, Objective *fitness) {
    this->size = size;
    this->constraints = constraints;
    this->fitness = fitness;

    srand(time(NULL));

    double x;
    double y;
    for (int i = 0; i < size; i++) {
        x = generateRandomDouble(constraints->getMinX(), constraints->getMaxX());
        y = generateRandomDouble(constraints->getMinY(), constraints->getMaxY());

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
