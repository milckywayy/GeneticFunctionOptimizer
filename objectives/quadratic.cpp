#include "quadratic.h"
#include <cmath>


Quadratic::Quadratic() : Objective(1) {
}


double Quadratic::value(vector<double> *position) {
    return -pow(position->at(0), 2);
}
