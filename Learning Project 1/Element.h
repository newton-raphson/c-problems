#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>

class Element {
private:
    int numNodes;
    std::vector<double> localCoords;
    double constant;

public:
    Element(int numNodes, const std::vector<double>& localCoords,double constant);
    int getNumNodes() const;
    double getLocalCoordinate(int i) const;
    std::vector<double> getLocalCord() const;
    double evaluateBasisFunction(double xi) const;
    double evaluateBasisFunctionDerivative(double xi) const;
    double giveConstant() const;
};
#endif // ELEMENT_H

