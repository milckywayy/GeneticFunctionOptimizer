#include "cubic.h"
#include <cmath>


Cubic::Cubic() : Objective(3) {
}


double Cubic::value(vector<double> *position) {
    return -(pow(position->at(0), 2) + pow(position->at(1), 2) + pow(position->at(2), 2));
}
