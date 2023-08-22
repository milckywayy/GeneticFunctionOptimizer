#ifndef QUADRATIC_H_
#define QUADRATIC_H_


#include "objective.h"


class Quadratic : public Objective {
public:
    Quadratic();
    double value(vector<double> *position) override;
};

#endif
