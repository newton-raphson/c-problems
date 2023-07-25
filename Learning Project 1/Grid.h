#ifndef Grid_H
#define Grid_H

#include "Element.h"

class Grid {
private:
    int numElements;
    std::vector<Element> elements;
    std::vector<double> nodeCoordinates;

public:
    Grid(int numElements, const std::vector<double>& nodeCoordinates);
    int getNumElements() const;
    const Element& getElement(int i) const;
    int getNumNodes() const;
    double getNodeCoordinate(int i) const;
};
#endif // ELEMENT_H

Grid::Grid(int numElements, const std::vector<double>& nodeCoordinates)
    : numElements(numElements), nodeCoordinates(nodeCoordinates) {
    for (int i = 0; i < numElements; ++i) {
        std::vector<double> localCoords;
        localCoords.push_back(nodeCoordinates[i]);
        localCoords.push_back(nodeCoordinates[i + 1]);
        Element element(2, localCoords);
        elements.push_back(element);
    }
}

int Grid::getNumElements() const {
    return numElements;
}

const Element& Grid::getElement(int i) const {
    return elements[i];
}

int Grid::getNumNodes() const {
    return numElements + 1; // For 1D with linear elements
}

double Grid::getNodeCoordinate(int i) const {
    return nodeCoordinates[i];
}
