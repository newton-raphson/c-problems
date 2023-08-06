#include "Element.h"
#include "Grid.h"
Grid::Grid(int numElements, const std::vector<double>& nodeCoordinates,const std::vector<double>& constant)
    : numElements(numElements), nodeCoordinates(nodeCoordinates) {
    for (int i = 0; i < numElements; ++i) {
        std::vector<double> localCoords;
        localCoords.push_back(nodeCoordinates[i]);
        localCoords.push_back(nodeCoordinates[i + 1]);
        Element element(2, localCoords,constant[i]);
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
