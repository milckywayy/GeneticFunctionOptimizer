#include <iostream>
#include <time.h>
#include "population.h"
#include "selections/tournamentSelection.h"


Population::Population() {
}

Population::Population(int size, Constraints *constraints, RandomNumberGenerator *rand) {
    this->constraints = constraints;

    for (int i = 0; i < size; i++) {
        vector<double> *position = new vector<double>;
        
        for (int axis = 0; axis < constraints->getDimension(); axis++) {
            position->push_back(rand->getRandomDouble(constraints->getMin(axis), constraints->getMax(axis)));
        }

        individuals.push_back(new Individual(position));
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

double Population::getAvegareFitness() {
    double avg;

    for (Individual *i : individuals) {
        avg += i->getFitness();
    }

    return avg / getSize();
}

void Population::evaluate(Objective *fitnessFunc) {
    for (Individual *i : individuals) {
        i->setFitness(fitnessFunc->value(i->getPosition()));
    }
}

void Population::print() {
    cout << "Population size: " << getSize() << endl;

    for (Individual *i : individuals) {
        i->print();
    }
    
    cout << "Average fitness: " << getAvegareFitness() << endl;
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
