#include "rosenbrock.h"
#include <cmath>


double Rosenbrock::value(double x, double y) {
    return -(pow(1 - x, 2) + 100 * pow(y - x * x, 2));
}
