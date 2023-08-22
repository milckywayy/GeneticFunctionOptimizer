#include <iostream>
#include <time.h>
#include "population.h"
#include "selections/tournamentSelection.h"


Population::Population() {
}

Population::Population(vector<Individual*> individuals) {
    this->individuals = individuals;
}

Population::Population(int size, Constraints *constraints, RandomNumberGenerator *rand) {
    this->constraints = constraints;

    double x;
    double y;
    for (int i = 0; i < size; i++) {
        x = rand->getRandomDouble((double)constraints->getMinX(), (double)constraints->getMaxX());
        y = rand->getRandomDouble(constraints->getMinY(), constraints->getMaxY());

        individuals.push_back(new Individual(x, y));
    }
}

void Population::addIndividual(Individual *individual) {
    individuals.push_back(individual);
}

Individual *Population::getIndividual(int index) {
    return individuals[index];
}

Individual *Population::getBestIndividual() {
    Individual *bestOne = individuals[0];

    for (int i = 1; i < individuals.size(); i++) {
        if (individuals[i]->getFitness() > bestOne->getFitness()) {
            bestOne = individuals[i];
        }
    }

    return bestOne;
}

void Population::removeIndividual(int index) {
    individuals.erase(individuals.begin() + index);
}

int Population::getSize() {
    return individuals.size();
}

void Population::evaluation(Objective *fitnessFunc) {
    for (Individual *i : individuals) {
        i->setFitness(fitnessFunc->value(i->getX(), i->getY()));
    }
}

void Population::print() {
    for (Individual *i : individuals) {
        cout << "(" << i->getX() << ", " << i->getY() << ") fitness: " << i->getFitness() << endl;
    }
}

void Population::copy(Population *population) {
    for (Individual *i : individuals) {
        population->addIndividual(i->copy());
    }
}

void Population::clear() {
    for (Individual *i : individuals) {
        delete i;
    }
    
    individuals.clear();
}

Population::~Population() {
    clear();
}
