#include "tournamentSelection.h"
#include <time.h>
#include <vector>
#include <iostream>

#define TOURNAMENT_SIZE 2


TournamentSelection::TournamentSelection(randomNumberGenerator *rand) {
    this->rand = rand; 
}

void TournamentSelection::select(Population *population, Population *parents) {
    

    for (int i = 0; i < population->getSize() / 2; i++) {
        
    }
}
