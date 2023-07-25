#include <iostream>
#include <vector>
#include "Element.h"
#include "Grid.h"
#include "Equation.h"



int main() {
    const int numElements = 100; // Number of elements in the mesh
    const double domainLength = 1.0; // Length of the 1D domain

    // Create the grid
    std::vector<double> nodeCoordinates;
    for (int i = 0; i <= numElements; ++i) {
        nodeCoordinates.push_back(i * domainLength / numElements);
    }

    Grid grid(numElements, nodeCoordinates);

    // Create the equation
    Equation equation(grid);

    // Assemble the global matrix and vector
    equation.assembleGlobalMatrix(grid);

    // Apply boundary conditions (Dirichlet boundary conditions)
    equation.applyBoundaryConditions(0, 25);       // u(0) = 0
    equation.applyBoundaryConditions(numElements, 40);   // u(L) = 0

    // Solve the linear system
    std::vector<double> temperatureDistribution = equation.solve();

    // Print the solution (temperature distribution)
    std::cout << "Temperature Distribution (u(x)):" << std::endl;
    for (int i = 0; i < grid.getNumNodes(); ++i) {
        std::cout << "u(" << grid.getNodeCoordinate(i) << ") = " << temperatureDistribution[i] << std::endl;
    }

    return 0;
}
