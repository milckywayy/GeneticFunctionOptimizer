#ifndef ROSENBROCK_H_
#define ROSENBROCK_H_


#include "objective.h"


class Rosenbrock : public Objective {
public:
    double value(double x, double y) override;
};

#endif
