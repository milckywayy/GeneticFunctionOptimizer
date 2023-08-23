#include "constraintsReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;


Constraints *readConstraintsFromFile(string fileName) {
    fstream file(fileName);

    if (!file.is_open()) {
        throw runtime_error("Couldn't open " + fileName + " file");
    }

    vector<double> minVector;
    vector<double> maxVector;

    int dimension = 0;
    double minValue;
    double maxValue;

    string line;
    while (getline(file, line)) {
        std::istringstream iss(line);

        if (!(iss >> minValue >> maxValue)) {
            file.close();
            throw runtime_error("File " + fileName + " has invalid format");
        }

        dimension++;
        minVector.push_back(minValue);
        maxVector.push_back(maxValue);
    }

    file.close();

    return new Constraints(dimension, &minVector, &maxVector);
}

