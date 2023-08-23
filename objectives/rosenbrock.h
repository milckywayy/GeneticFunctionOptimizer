#ifndef ROSENBROCK_H_
#define ROSENBROCK_H_


#include "objective.h"


class Rosenbrock : public Objective {
public:
    Rosenbrock();
    double getFunctionValue(vector<double> *position) override;
};

#endif
