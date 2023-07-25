#include "Element.h"
#include "Matrix.h" // Assuming you have the SparseMatrix implementation
#include "Grid.h"
#include <cmath>
#include "LinearSolver.h"
class Equation {
private:
    SparseMatrix globalStiffnessMatrix;
    std::vector<double> globalLoadVector;

public:
    Equation(const Grid& grid);
    void assembleLocalMatrix(const Element& element, SparseMatrix& localMatrix) const;
    void assembleGlobalMatrix(const Grid& grid);
    void applyBoundaryConditions(int nodeIndex, double prescribedValue);
    std::vector<double> solve();
};

Equation::Equation(const Grid& grid) {
    int numNodes = grid.getNumNodes();
    globalStiffnessMatrix = SparseMatrix(numNodes, numNodes);
    globalLoadVector = std::vector<double>(numNodes, 0.0);
}

void Equation::assembleLocalMatrix(const Element& element, SparseMatrix& localMatrix) const {
    int numNodes = element.getNumNodes();
    const std::vector<double>& localCoords = element.getLocalCord();

    // Calculate the Jacobian of the transformation from the local to global coordinates
    double jacobian = (localCoords[1] - localCoords[0]) / 2.0;

    // Gauss quadrature points and weights for numerical integration (assuming linear elements)
    const int numGaussPoints = 2;
    const double gaussPoints[numGaussPoints] = {-1.0 / sqrt(3.0), 1.0 / sqrt(3.0)};
    const double gaussWeights[numGaussPoints] = {1.0, 1.0};

    for (int i = 0; i < numGaussPoints; ++i) {
        double xi = gaussPoints[i];
        double weight = gaussWeights[i];

        // Evaluate basis functions and their derivatives at the current Gauss point
        double basisFunctions[numNodes];
        double basisFunctionDerivatives[numNodes];
        for (int k = 0; k < numNodes; ++k) {
            basisFunctions[k] = element.evaluateBasisFunction(xi);
            basisFunctionDerivatives[k] = element.evaluateBasisFunctionDerivative(xi);
        }

        // Construct the local matrix using numerical integration
        for (int k = 0; k < numNodes; ++k) {
            for (int l = 0; l < numNodes; ++l) {
                double value = basisFunctionDerivatives[k] * basisFunctionDerivatives[l] * weight * jacobian;
                localMatrix(k, l) += value;
            }
        }
    }
}

void Equation::assembleGlobalMatrix(const Grid& grid) {
    int numNodes = grid.getNumNodes();
    globalStiffnessMatrix = SparseMatrix(numNodes, numNodes);

    for (int i = 0; i < grid.getNumElements(); ++i) {
        const Element& element = grid.getElement(i);
        SparseMatrix localMatrix(numNodes, numNodes);
        assembleLocalMatrix(element, localMatrix);

        // Calculate the global node indices for this element
        int nodeIndices[2] = {i, i + 1};

        // Add the local stiffness matrix contributions to the global stiffness matrix
        for (int k = 0; k < 2; ++k) {
            int row = nodeIndices[k];
            for (int l = 0; l < 2; ++l) {
                int col = nodeIndices[l];
                double value = localMatrix(k, l);
                globalStiffnessMatrix(row, col) += value;
            }
        }
    }
}

void Equation::applyBoundaryConditions(int nodeIndex, double prescribedValue) {
    // Apply the prescribed value at the specified node index
    globalStiffnessMatrix(nodeIndex, nodeIndex) = 1.0;
    globalLoadVector[nodeIndex] = prescribedValue;
}

std::vector<double> Equation::solve() {

    ConjugateGradientSolver conjugateSolver;
    std::vector<double> solution = conjugateSolver.solve(globalStiffnessMatrix, globalLoadVector);
    return solution;
}
