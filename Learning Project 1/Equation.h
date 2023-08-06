#include "Element.h"
#include "Matrix.h" 
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
    void displayGlobalStiffnessMatrix() const;
    std::vector<double> solve();
};


