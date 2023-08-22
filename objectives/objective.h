#ifndef OBJECTIVE_H_
#define OBJECTIVE_H_


#include <vector>


using namespace std;


class Objective {
    int dimension;
public:
    Objective (int dimension) {
        this->dimension = dimension;
    }

    int getDimension(){
        return dimension;
    }

    virtual double value(vector<double> *position) = 0;
};

#endif
