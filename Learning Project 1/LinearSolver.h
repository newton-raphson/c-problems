
#ifndef LS_H
#define LS_H

#include "Matrix.h"

class LinearSolver {
public:
    virtual ~LinearSolver() {}
    virtual std::vector<double> solve(const Matrix& A, const std::vector<double>& b) const = 0;
};

class GaussianEliminationSolver : public LinearSolver {
public:
    std::vector<double> solve(const Matrix& A, const std::vector<double>& b) const override;
};

class ConjugateGradientSolver : public LinearSolver {
public:
    std::vector<double> solve(const Matrix& A, const std::vector<double>& b) const override;
};

#endif //