#include <vector>
#include "Element.h"

Element::Element(int numNodes, const std::vector<double>& localCoords,double constant)
    : numNodes(numNodes), localCoords(localCoords),constant(constant) {}

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

double Element::giveConstant() const
{
    return constant;
}