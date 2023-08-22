#include "tournamentSelection.h"
#include <time.h>
#include <vector>
#include <iostream>


#define TOURNAMENT_SIZE 3


void TournamentSelection::select(Population *population, Individual **parents, RandomNumberGenerator *rand) {
    int max;
    int ids[TOURNAMENT_SIZE];

    for (int parent_id = 0; parent_id < 2; parent_id++) {
        // Get random individuals to take part in the tournament
        for (int i = 0; i < TOURNAMENT_SIZE; i++) {
            ids[i] = rand->getRandomInteger(0, population->getSize() - 1);
        }

        // One parent can't born children alone
        for (int i = 0; i < TOURNAMENT_SIZE - 1; i++) {
            for (int j = i + 1; j < TOURNAMENT_SIZE; j++) {
                if (ids[i] == ids[j]) {
                    ids[j] = (ids[j] + 1) % population->getSize();
                }
            }
        }

        // Find tournament winner
        max = 0;
        for (int i = 1; i < TOURNAMENT_SIZE; i++) {
            if (population->getIndividual(ids[i])->getFitness() > population->getIndividual(ids[max])->getFitness()) {
                max = i;
            }
        }

        // Tournament winner will be considered as a parent
        parents[parent_id] = population->getIndividual(ids[max]);
    }
}
