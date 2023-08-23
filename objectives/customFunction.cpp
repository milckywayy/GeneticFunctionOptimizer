#include <iostream>
#include "customFunction.h"


int CustomFunction::checkWhatDimension(string equation) {
    int dimension = 0;

    size_t pos = 0;
    while (pos < equation.length()) {
        if (equation[pos] == 'x') {
            size_t endPos = pos + 1;

            while (endPos < equation.length() && equation[endPos] >= '0' && equation[endPos] <= '9') {
                endPos++;
            }

            if (endPos - pos < 2) {
                throw invalid_argument("Equation " + equation + " has invalid format");
            }

            if (stoi(equation.substr(pos + 1, endPos - pos)) > dimension) {
                dimension = stoi(equation.substr(pos + 1, endPos - pos));
            }

            pos = endPos;
        }
        else {
            pos++;
        }
    }

    return dimension + 1;
}

CustomFunction::CustomFunction(string equation) : Objective(checkWhatDimension(equation), equation) {
    this->equation = equation;

    function = new ReversePolishNotation;
    function->parseEquation(this->equation);
}

double CustomFunction::getFunctionValue(vector<double> *position) {
    return function->evaluate(position);
}

CustomFunction::~CustomFunction() {
    cout << "test" << endl;
    delete function;
}
