#include "VectorNorm.h"
#include <cmath>

double VectorNorm::l1Norm(const double* vector, int size) {
    double norm = 0.0;
    for (int i = 0; i < size; i++) {
        norm += std::abs(vector[i]);
    }
    return norm;
}

double VectorNorm::l2Norm(const double* vector, int size) {
    double normSquared = 0.0;
    for (int i = 0; i < size; i++) {
        normSquared += vector[i] * vector[i];
    }
    return std::sqrt(normSquared);
}
