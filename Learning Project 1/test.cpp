#include <iostream>
#include "Matrix.h"
#include "VectorNorm.h"
#include <vector>

int main() {
    // Create matrices
    DenseMatrix matrixA(2, 3);
    DenseMatrix matrixB(3, 2);

    // Initialize matrixA
    matrixA(0, 0) = 1.0;
    matrixA(0, 1) = 2.0; 
    matrixA(0, 2) = 3.0;
    matrixA(1, 0) = 4.0;
    matrixA(1, 1) = 5.0;
    matrixA(1, 2) = 6.0;

    // Initialize matrixB
    matrixB(0, 0) = 7.0;
    matrixB(0, 1) = 8.0;
    matrixB(1, 0) = 9.0;
    matrixB(1, 1) = 10.0;
    matrixB(2, 0) = 11.0;
    matrixB(2, 1) = 12.0;

    std::vector<double> vector;
    vector.push_back(1.0);
    vector.push_back(2.0);
    vector.push_back(3.0);

    // Perform matrix operations
    DenseMatrix matrixProduct = matrixA * matrixB;
    DenseMatrix vectorProduct = matrixA * vector.data();

    // Print results
    std::cout << "Matrix A:\n" << matrixA << std::endl;
    std::cout << "Matrix B:\n" << matrixB << std::endl;
    std::cout << "Matrix Product:\n" << matrixProduct << std::endl;
    std::cout << "Vector Product:\n" << vectorProduct << std::endl;



     // Calculate vector norms
    double l1Norm = VectorNorm::l1Norm(vector.data(), vector.size());
    double l2Norm = VectorNorm::l2Norm(vector.data(), vector.size());

    // Print vector norms
    std::cout << "L1 Norm: " << l1Norm << std::endl;
    std::cout << "L2 Norm: " << l2Norm << std::endl;

    std::cout << std::endl;

    // Test for  Compressed Sparse Matrix
    SparseMatrix sp_matrix(3, 3);

    // Set elements of the sparse matrix
    sp_matrix.setElement(0, 0, 1.0);
    sp_matrix.setElement(0, 2, 2.0);
    sp_matrix.setElement(1, 1, 3.0);
    sp_matrix.setElement(2, 0, 4.0);
    sp_matrix.setElement(2, 2, 5.0);

    // Perform sparse matrix-vector multiplication
    std::vector<double> result = sp_matrix * vector;
        // Print the result
    std::cout << " Sparse Matrix Result: ";
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
