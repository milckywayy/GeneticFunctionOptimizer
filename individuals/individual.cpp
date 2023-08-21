#include "individual.h"


Individual::Individual(double x, double y) {
    this->x = x;
    this->y = y;
    this->fitness = 0.0;
}

double Individual::getFitness() {
    return fitness;
}

double Individual::getX() {
    return x;
}

double Individual::getY() {
    return y;
}

void Individual::setFitness(double fitness) {
    this->fitness = fitness;
}

void Individual::setX(double x) {
    this->x = x;
}

void Individual::setY(double y) {
    this->y = y;
}

bool Individual::operator<(const Individual& other) {
    return this->fitness > other.fitness;
}

bool Individual::operator==(const Individual& other) {
    return this->fitness == other.fitness;
}
