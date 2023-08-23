#ifndef CUSTOM_FUNCTION_H_
#define CUSTOM_FUNCTION_H_


#include "../functionparser/reversePolishNotation.h"
#include "objective.h"
#include <string>


class CustomFunction : public Objective {
private:
    string equation;
    ReversePolishNotation function;
    int checkWhatDimension(string equation);
public:
    CustomFunction(string equation);
    double getFunctionValue(vector<double> *position);
};

#endif
