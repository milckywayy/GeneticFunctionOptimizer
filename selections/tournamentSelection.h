#ifndef TOURNAMENT_SELECTION_H_
#define TOURNAMENT_SELECTION_H_


#include "selection.h"
#include "../utils/randomNumberGenerator.h"


class TournamentSelection : public Selection {
private:
    randomNumberGenerator *rand;
public:
    TournamentSelection(randomNumberGenerator *rand);
    void select(Population *population) override;
};

#endif
