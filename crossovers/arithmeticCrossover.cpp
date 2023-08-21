#include "arithmeticCrossover.h"


void ArithmeticCrossover::cross(Population *parents, Population *children) {
    for (int i = 0 ; i < parents->getSize() - 1; i++) {
        double newX = (parents->getIndividual(i)->getX() + parents->getIndividual(i + 1)->getX()) / 2;
        double newY = (parents->getIndividual(i)->getY() + parents->getIndividual(i + 1)->getY()) / 2;
        children->addIndividual(new Individual(newX, newY));
    }
}
