#ifndef CUBIC_H_
#define CUBIC_H_


#include "objective.h"


class Cubic : public Objective {
public:
    Cubic();
    double value(vector<double> *position) override;
};

#endif
