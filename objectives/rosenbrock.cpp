#include "rosenbrock.h"
#include <cmath>


Rosenbrock::Rosenbrock() : Objective(2) {
}


double Rosenbrock::value(vector<double> *position) {
    return -(pow(1 - position->at(0), 2) + (100 * pow(position->at(1) - pow(position->at(0), 2), 2)));
}
