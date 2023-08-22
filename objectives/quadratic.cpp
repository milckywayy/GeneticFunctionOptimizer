#include "quadratic.h"
#include <cmath>


double Quadratic::value(double x, double y) {
    return -(pow(x + 1, 2) + pow(y - 1, 2) - 10);
}
