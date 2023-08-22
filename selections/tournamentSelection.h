#ifndef TOURNAMENT_SELECTION_H_
#define TOURNAMENT_SELECTION_H_


#include "selection.h"
#include "../utils/randomNumberGenerator.h"


class TournamentSelection : public Selection {
private:
public:
    void select(Population *population, Individual **parents, RandomNumberGenerator *rand) override;
};

#endif
