#ifndef TOURNAMENT_SELECTION_H_
#define TOURNAMENT_SELECTION_H_


#include "selection.h"
#include "../utils/randomNumberGenerator.h"


class TournamentSelection : public Selection {
private:
    RandomNumberGenerator *rand;
public:
    TournamentSelection(RandomNumberGenerator *rand);
    void select(Population *population, Population *parents) override;
};

#endif
