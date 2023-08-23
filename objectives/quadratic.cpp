#include "quadratic.h"
#include <cmath>


Quadratic::Quadratic() : Objective(1, "Quadratic function") {
}


double Quadratic::getFunctionValue(vector<double> *position) {
    return pow(position->at(0), 2);
}
