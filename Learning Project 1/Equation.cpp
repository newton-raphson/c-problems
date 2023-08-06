#include "Equation.h"
#include <vector>
#include <cmath>
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
    std::vector<double> gaussPoints;
    gaussPoints.push_back(-(1.0 / sqrt(3.0)));
    gaussPoints.push_back(1.0 / sqrt(3.0));
    std::vector<int> gaussWeights;
    gaussWeights.push_back(1);
    gaussWeights.push_back(1);

    for (int i = 0; i < numGaussPoints; ++i) {
        double xi = gaussPoints[i];
        double weight = gaussWeights[i];

        // Evaluate basis functions and their derivatives at the current Gauss point
        std::vector<double> basisFunctions;
        std::vector<double> basisFunctionDerivatives;

        for (int k = 0; k < numNodes; ++k) {
            basisFunctions.push_back(element.evaluateBasisFunction(xi));
            basisFunctionDerivatives.push_back(element.evaluateBasisFunctionDerivative(xi));
        }

        // Construct the local matrix using numerical integration
        for (int k = 0; k < numNodes; ++k) {
            for (int l = 0; l < numNodes; ++l) {

                double value = element.giveConstant()*basisFunctionDerivatives[k] * basisFunctionDerivatives[l] * weight * jacobian;
                if(k==l)
                {
                    localMatrix.setElement(k,l,value);
                }
                else
                {
                    localMatrix.setElement(k,l,-value);
                }
                
            }
        }
    }
}

void Equation::assembleGlobalMatrix(const Grid& grid) {
    int numNodes = grid.getNumNodes();
    globalStiffnessMatrix = SparseMatrix(numNodes, numNodes);

    for (int i = 0; i < grid.getNumElements(); ++i) {
        const Element& element = grid.getElement(i);
        SparseMatrix localMatrix(element.getNumNodes(), element.getNumNodes());
        assembleLocalMatrix(element, localMatrix);
        // Calculate the global node indices for this element
        std::vector<int> nodeIndices;
        nodeIndices.push_back(i);
        nodeIndices.push_back(i+1);
        // Add the local stiffness matrix contributions to the global stiffness matrix
        for (int k = 0; k < 2; ++k) {
            int row = nodeIndices[k];
            for (int l = 0; l < 2; ++l) {
                int col = nodeIndices[l];
                double value = localMatrix.getElement(k,l)+ globalStiffnessMatrix.getElement(row,col);
                globalStiffnessMatrix.setElement(row, col,value);
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
void Equation::displayGlobalStiffnessMatrix() const {
    std::cout << "Global Stiffness Matrix:" << std::endl;
    globalStiffnessMatrix.display();
}
