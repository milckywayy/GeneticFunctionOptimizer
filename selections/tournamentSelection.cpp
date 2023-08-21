#include "tournamentSelection.h"
#include <time.h>
#include <vector>
#include <iostream>

#define TOURNAMENT_SIZE 2


TournamentSelection::TournamentSelection(randomNumberGenerator *rand) {
    this->rand = rand; 
}

void TournamentSelection::select(Population *population, Population *parents) {
    int max;
    int ids[TOURNAMENT_SIZE];

    for (int i = 0; i < population->getSize() / 2; i++) {
        for (int i = 0; i < TOURNAMENT_SIZE; i++) {
            ids[i] = rand->getRandomInteger(0, population->getSize() - 1);
        }

        max = 0;
        for (int i = 1; i < TOURNAMENT_SIZE; i++) {
            if (population->getIndividual(ids[i])->getFitness() > population->getIndividual(ids[max])->getFitness()) {
                max = i;
            }
        }

        parents->addIndividual(population->getIndividual(ids[max])->copy());
    }
}
