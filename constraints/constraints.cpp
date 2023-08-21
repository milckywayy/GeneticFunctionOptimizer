#include "constraints.h"


Constraints::Constraints(int xMin, int xMax, int yMin, int yMax) {
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
}

bool Constraints::isInside(double x, double y) {
    return xMin <= x <= xMax && yMin <= y <= yMax;
}

int Constraints::getMinX() {
    return xMin;
}

int Constraints::getMaxX() {
    return xMax;
}

int Constraints::getMinY() {
    return yMin;
}

int Constraints::getMaxY() {
    return yMax;
}
