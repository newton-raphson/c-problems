#include <iostream>
#include <vector>
#include "LinearSolver.h"
#include "Matrix.h"
#include <chrono>

int main() {
    // Create the sparse matrix
    SparseMatrix sparseMatrix(3, 3);
    sparseMatrix.setElement(0, 0, 4);
    sparseMatrix.setElement(0, 1, -1);
    sparseMatrix.setElement(1, 0, -1);
    sparseMatrix.setElement(1, 1, 4);
    sparseMatrix.setElement(1, 2, -1);
    sparseMatrix.setElement(2, 1, -1);
    sparseMatrix.setElement(2, 2, 4);

    int numRows = sparseMatrix.getNumRows();
    int numCols = sparseMatrix.getNumCols();

    for (int row = 0; row <= numRows; ++row) {
        for (int col = 0; col <= numCols; ++col) {
            double element = sparseMatrix.getElement(row, col);
            if (element != 0.0) {
                std::cout << "SparseMatrix[" << row << "][" << col << "] = " << element << std::endl;
            }
        }
    }
    // Create the dense matrix
    DenseMatrix denseMatrix(3, 3);
    denseMatrix(0, 0) = 4;
    denseMatrix(0, 1) = -1;
    denseMatrix(0, 2) = 0;
    denseMatrix(1, 0) = -1;
    denseMatrix(1, 1) = 4;
    denseMatrix(1, 2) = -1;
    denseMatrix(2, 0) = 0;
    denseMatrix(2, 1) = -1;
    denseMatrix(2, 2) = 4;

    // Create the right-hand side vector b
    std::vector<double> b;
    b.push_back(1.0);
    b.push_back(2.0);
    b.push_back(3.0);


    // Test Gaussian Elimination Solver
    GaussianEliminationSolver gaussianSolver;
    auto startTime1 = std::chrono::high_resolution_clock::now();
    std::vector<double> gaussianSolution = gaussianSolver.solve(denseMatrix, b);
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(endTime1 - startTime1).count();

    std::cout << "Gaussian Elimination Solver Solution:" << std::endl;
    for (double val : gaussianSolution) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test Conjugate Gradient Solver
    ConjugateGradientSolver conjugateSolver;
    auto startTime2 = std::chrono::high_resolution_clock::now();
    std::vector<double> conjugateSolution = conjugateSolver.solve(sparseMatrix, b);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(endTime2 - startTime2).count();

    std::cout << "Conjugate Gradient Solver Solution:" << std::endl;
    for (double val : conjugateSolution) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Compuational Time
    std::cout << "Time taken by Gaussian Elimination: " << duration1 << " microseconds." << std::endl;
    std::cout << "Time taken by Conjugate Gradient Descent: " << duration2 << " microseconds." << std::endl;

    return 0;
}
