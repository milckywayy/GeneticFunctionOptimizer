#ifndef QUADRATIC_H_
#define QUADRATIC_H_


#include "objective.h"


class Quadratic : public Objective {
public:
    double value(double x, double y) override;
};

#endif
