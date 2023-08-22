#include "individual.h"
#include <iostream>


Individual::Individual(vector<double> *position) {
    dimension = position->size();

    this->position = new vector<double>;

    for (int axis = 0; axis < dimension; axis++) {
        this->position->push_back(position->at(axis));
    }

    this->fitness = 0.0;
}

int Individual::getDimension() {
    return dimension;
}

vector<double> *Individual::getPosition() {
    return position;
}

double Individual::getPositionAtAxis(int axis) {
    return position->at(axis);
}

double Individual::getFitness() {
    return fitness;
}

void Individual::setFitness(double fitness) {
    this->fitness = fitness;
}

void Individual::setPositionAtAxis(int axis, double value) {
    position->at(axis) = value;
}

void Individual::print() {
    cout << "( ";
    for (int axis = 0; axis < dimension; axis++) {
        cout << position->at(axis) << " ";
    }
    cout << ") fitness = " << fitness << std::endl;
}

Individual *Individual::copy() {
    Individual *newIndividual = new Individual(position);
    newIndividual->setFitness(fitness);
    return newIndividual;
}

Individual::~Individual() {
    delete position;
}
