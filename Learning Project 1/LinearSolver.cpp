#include <vector>
#include <cmath>
#include "LinearSolver.h"
#include "Matrix.h"




std::vector<double> GaussianEliminationSolver::solve(const Matrix& A, const std::vector<double>& b) const {

    const DenseMatrix& denseA = dynamic_cast<const DenseMatrix&>(A);
    int numRows = denseA.getNumRows();
    int numCols = denseA.getNumCols();

    // Perform Gaussian elimination using dense matrix
    DenseMatrix augmentedMatrix(numRows, numCols + 1);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            augmentedMatrix(i, j) = denseA(i, j);
        }
        augmentedMatrix(i, numCols) = b[i];
    }

    // Gaussian elimination
    for (int i = 0; i < numRows - 1; ++i) {
        // Pivot row selection and partial pivoting (if required) can be added here
        for (int k = i + 1; k < numRows; ++k) {
            double factor = augmentedMatrix(k, i) / augmentedMatrix(i, i);
            for (int j = i; j < numCols + 1; ++j) {
                augmentedMatrix(k, j) -= factor * augmentedMatrix(i, j);
            }
        }
    }

    // Back substitution to find the solution
    std::vector<double> solution(numRows);
    for (int i = numRows - 1; i >= 0; --i) {
        solution[i] = augmentedMatrix(i, numCols);
        for (int j = i + 1; j < numCols; ++j) {
            solution[i] -= augmentedMatrix(i, j) * solution[j];
        }
        solution[i] /= augmentedMatrix(i, i);
    }

    return solution;
}

std::vector<double> ConjugateGradientSolver::solve(const Matrix& A, const std::vector<double>& b) const {

    const SparseMatrix& sparseA = dynamic_cast<const SparseMatrix&>(A);
    int n = sparseA.getNumRows();

    std::vector<double> x(n, 0.0); // Initial guess for the solution vector x
    std::vector<double> r = b;    // Initial residual vector r0 = b - Ax0
    std::vector<double> p = r;    // Initial search direction p0 = r0
    double rsold = 0.0;           // Store the squared magnitude of the old residual

    // Calculate the initial squared magnitude of the residual
    for (int i = 0; i < n; ++i) {
        rsold += r[i] * r[i];
    }

    // Perform the Conjugate Gradient method using sparse matrix
    for (int iter = 0; iter < n; ++iter) {
        std::vector<double> Ap(n, 0.0);
        Ap = sparseA * p;

        double alpha = 0.0;
        double deno = 0.0;
        double rsnew = 0.0;

        for (int i = 0; i < n; ++i) {
            alpha += r[i] * r[i];
            deno += p[i]*Ap[i];
        }

        alpha /= deno;
        for (int i = 0; i < n; ++i) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }

        double rsnew_next = 0.0;
        for (int i = 0; i < n; ++i) {
            rsnew_next += r[i] * r[i];
        }

        // Stopping condition based on the norm of the residual
        if (std::sqrt(rsnew_next) < 1e-10)
            break;

        double beta = rsnew_next / rsold;
        rsold = rsnew_next;

        for (int i = 0; i < n; ++i) {
            p[i] = r[i] + beta * p[i];
        }
    }

    return x; // Return the solution vector

}