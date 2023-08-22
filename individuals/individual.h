#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_


#include <vector>


using namespace std;


class Individual {
private:
    int dimension;
    vector<double> *position;
    double fitness;
public:
    Individual(vector<double> *position);
    int getDimension();
    vector<double> *getPosition();
    double getPositionAtAxis(int axis);
    double getFitness();
    void setFitness(double fitness);
    void setPositionAtAxis(int axis, double value);
    void print();
    Individual *copy();
    ~Individual();
};

#endif
