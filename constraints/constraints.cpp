#include "constraints.h"


Constraints::Constraints(int dimension, double value) {
    this->dimension = dimension;

    this->min = new vector<double>;
    this->max = new vector<double>;

    for (int i = 0; i < dimension; i++) {
        this->min->push_back(-value);
        this->max->push_back(value);
    }
}

Constraints::Constraints(int dimension, vector<double> *min, vector<double> *max) {
    this->dimension = dimension;

    this->min = new vector<double>;
    this->max = new vector<double>;

    for (int i = 0; i < dimension; i++) {
        this->min->push_back(min->at(i));
        this->max->push_back(max->at(i));
    }
}

bool Constraints::isInside(vector<double> *point) {
    for (int axis = 0; axis < dimension; axis++) {
        if (min->at(axis) > point->at(axis) || point->at(axis) > max->at(axis)) {
            return false;
        }
    }

    return true;
}

bool Constraints::isInsideOnAxis(double position, int axis) {
    if (min->at(axis) <= position && position <= max->at(axis)) {
        return true;
    }

    return false;
}

int Constraints::getDimension() {
    return dimension;
}

double Constraints::getMin(int axis) {
    return min->at(axis);
}

double Constraints::getMax(int axis) {
    return max->at(axis);
}

Constraints::~Constraints() {
    delete min;
    delete max;
}
