#ifndef Grid_H
#define Grid_H

#include "Element.h"

class Grid {
private:
    int numElements;
    std::vector<Element> elements;
    std::vector<double> nodeCoordinates;

public:
    Grid(int numElements, const std::vector<double>& nodeCoordinates,const std::vector<double>& constant);
    int getNumElements() const;
    const Element& getElement(int i) const;
    int getNumNodes() const;
    double getNodeCoordinate(int i) const;
};
#endif 

