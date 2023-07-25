#ifndef VECTOR_NORM_H
#define VECTOR_NORM_H

class VectorNorm {
public:
    static double l1Norm(const double* vector, int size);
    static double l2Norm(const double* vector, int size);
};

#endif // VECTOR_NORM_HPP
