#ifndef OBJECTIVE_H_
#define OBJECTIVE_H_


#include <vector>
#include <string>


using namespace std;


class Objective {
private:
    bool reverse;
    int dimension;
    string equationString;

public:
    Objective (int dimension, string equationString) {
        this->dimension = dimension;
        this->reverse = false;
        this->equationString = equationString;
    }

    int getDimension(){
        return dimension;
    }

    string getEquation() {
        return equationString;
    }

    void setReverse(bool reverse) {
        this->reverse = reverse;
    }

    // Returns original function's value 
    virtual double getFunctionValue(vector<double> *position) = 0;

    // Returns reversed function's value if we're looking for global minimum  
    double value(vector<double> *position) {
        if (reverse) {
            return -getFunctionValue(position);
        }
        else {
            return getFunctionValue(position);
        }
    }

    virtual ~Objective() {};
};

#endif
