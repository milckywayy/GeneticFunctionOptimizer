#ifndef CONSTRAINTS_H_
#define CONSTRAINTS_H_


class Constraints {
private:
    int xMin;
    int xMax;
    int yMin;
    int yMax;
public:
    Constraints(int xMin, int xMax, int yMin, int yMax);
    bool isInside(double x, double y);
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
};

#endif
