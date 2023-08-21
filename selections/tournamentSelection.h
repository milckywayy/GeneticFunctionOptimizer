#ifndef TOURNAMENT_SELECTION_H_
#define TOURNAMENT_SELECTION_H_


#include "selection.h"

class TournamentSelection : public Selection {
public:
    void select(Population *population);
};

#endif
