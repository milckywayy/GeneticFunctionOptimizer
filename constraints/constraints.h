#ifndef CONSTRAINTS_H_
#define CONSTRAINTS_H_


#include <vector>


using namespace std;


class Constraints {
private:
    int dimension; 
    vector<double> *min;
    vector<double> *max;
public:
    Constraints(int dimension, double value);
    Constraints(int dimension, vector<double> *min, vector<double> *max);
    bool isInside(vector<double> *point);
    bool isInsideOnAxis(double position, int axis);
    int getDimension();
    double getMin(int axis);
    double getMax(int axis);
    ~Constraints();
};

#endif
