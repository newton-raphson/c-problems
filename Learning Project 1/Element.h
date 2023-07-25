#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>

class Element {
private:
    int numNodes;
    std::vector<double> localCoords;

public:
    Element(int numNodes, const std::vector<double>& localCoords);
    int getNumNodes() const;
    double getLocalCoordinate(int i) const;
    std::vector<double> getLocalCord() const;
    double evaluateBasisFunction(double xi) const;
    double evaluateBasisFunctionDerivative(double xi) const;
};
#endif // ELEMENT_H

Element::Element(int numNodes, const std::vector<double>& localCoords)
    : numNodes(numNodes), localCoords(localCoords) {}

int Element::getNumNodes() const {
    return numNodes;
}
std::vector<double> Element::getLocalCord() const
{
    return localCoords;
}

double Element::getLocalCoordinate(int i) const {
    return localCoords[i];
}

double Element::evaluateBasisFunction(double xi) const {
    // For a linear element, the basis function is a linear function of 'xi'
    // For example, the basis function for the first node is 1 - xi, and the basis function for the second node is xi.
    if (xi >= 0.0 && xi <= 1.0) {
        return 1.0 - xi;
    } else if (xi >= -1.0 && xi < 0.0) {
        return 1.0 + xi;
    } else {
        // Invalid range of 'xi'
        throw std::invalid_argument("Invalid value of 'xi' for LinearElement.");
    }
}

double Element::evaluateBasisFunctionDerivative(double xi) const {
    // For a linear element, the derivative of the basis function is constant.
    // The derivative is -1 for the first node and +1 for the second node.
    if (xi >= 0.0 && xi <= 1.0) {
        return -1.0;
    } else if (xi >= -1.0 && xi < 0.0) {
        return 1.0;
    } else {
        // Invalid range of 'xi'
        throw std::invalid_argument("Invalid value of 'xi' for LinearElement.");
    }
}
