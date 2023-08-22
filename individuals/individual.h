#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_


class Individual {
private:
    double x, y;
    double fitness;
public:
    Individual(double x, double y);
    double getFitness();
    double getX();
    double getY();
    void setFitness(double fitness);
    void setX(double x);
    void setY(double y);
    void print();
    Individual *copy();
    bool operator<(const Individual& other);
    bool operator==(const Individual& other);
};

#endif
