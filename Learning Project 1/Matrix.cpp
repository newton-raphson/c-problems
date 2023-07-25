#include "Matrix.h"
#include <iostream>
DenseMatrix::DenseMatrix(int rows, int cols)
    : numRows(rows), numCols(cols) {
    elements = new double*[numRows];
    for (int i = 0; i < numRows; i++) {
        elements[i] = new double[numCols];
    }
}

DenseMatrix::~DenseMatrix() {
    for (int i = 0; i < numRows; i++) {
        delete[] elements[i];
    }
    delete[] elements;
}

double& DenseMatrix::operator()(int row, int col) {
    return elements[row][col];
}

const double& DenseMatrix::operator()(int row, int col) const {
    return elements[row][col];
}

double DenseMatrix::getElement(int row, int col) const {
    return elements[row][col];
}

int DenseMatrix::getNumRows() const {
    return numRows;
}

int DenseMatrix::getNumCols() const {
    return numCols;
}

DenseMatrix DenseMatrix::operator*(const DenseMatrix& other) const {
    int numRowsA = numRows;
    int numColsA = numCols;
    int numRowsB = other.getNumRows();
    int numColsB = other.getNumCols();

    DenseMatrix result(numRowsA, numColsB);
    for (int i = 0; i < numRowsA; i++) {
        for (int j = 0; j < numColsB; j++) {
            double sum = 0.0;
            for (int k = 0; k < numColsA; k++) {
                sum += elements[i][k] * other.getElement(k, j);
            }
            result.elements[i][j] = sum;
        }
    }

    return result;
}

DenseMatrix DenseMatrix::operator*(const double* vector) const {
    int numRowsA = numRows;
    int numColsA = numCols;

    DenseMatrix result(numRowsA, 1);
    for (int i = 0; i < numRowsA; i++) {
        double sum = 0.0;
        for (int j = 0; j < numColsA; j++) {
            sum += elements[i][j] * vector[j];
        }
        result.elements[i][0] = sum;
    }

    return result;
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    int numRows = matrix.getNumRows();
    int numCols = matrix.getNumCols();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            os << matrix(i, j) << ' ';
        }
        os << '\n';
    }
    return os;
}

SparseMatrix::SparseMatrix(int rows, int cols)
    : numRows(rows), numCols(cols) {
    rowPtr.resize(numRows + 1, 0);
}

SparseMatrix::SparseMatrix()
    : numRows(0), numCols(0) {
    rowPtr.resize(1, 0);
}

SparseMatrix::~SparseMatrix() {}

double SparseMatrix::getElement(int row, int col) const {
    for (int i = rowPtr[row]; i < rowPtr[row + 1]; i++) {
        if (colIdx[i] == col) {
            return values[i];
        }
    }
    return 0.0;
}

int SparseMatrix::getNumRows() const {
    return numRows;
}

int SparseMatrix::getNumCols() const {
    return numCols;
}
int SparseMatrix::getRowPtr(int i) const {
    // Function to get the row pointer  of the sparse matrix
    return rowPtr[i];
}
double SparseMatrix::getValue(int i) const{
    return values[i];
}

int SparseMatrix::getColIdx(int i) const {
    // Function to get the column index  of the sparse matrix
    return colIdx[i];
}


std::vector<double> SparseMatrix::operator*(const std::vector<double>& vector) const {
    std::vector<double> result(numRows, 0.0);

    for (int i = 0; i < numRows; i++) {
        for (int j = rowPtr[i]; j < rowPtr[i + 1]; j++) {
            int col = colIdx[j];
            result[i] += values[j] * vector[col];
        }
    }

    return result;
}

void SparseMatrix::setElement(int row, int col, double value) {
    if (value != 0.0) {
        for (int i = rowPtr[row]; i < rowPtr[row + 1]; i++) {
            if (colIdx[i] == col) {
                values[i] = value;
                return;
            }
        }
        colIdx.push_back(col);
        values.push_back(value);
        for (int i = row + 1; i <= numRows; i++) {
            rowPtr[i]++;
        }
    }
}


const double& SparseMatrix::operator()(int row, int col) const {
    return SparseMatrix::getElement(row,col);
}
double& SparseMatrix::operator()(int row, int col) {
    // Overloaded () operator to access and modify elements of the sparse matrix
    for (int j = rowPtr[row]; j < rowPtr[row + 1]; ++j) {
        if (colIdx[j] == col) {
            return values[j];
        }
    }
    // If the element does not exist, add it as a new non-zero element with value 0.0
    colIdx.push_back(col);
    values.push_back(0.0);
    // Update the rowPtr vector for the new element
    rowPtr[row + 1]++;
    return values.back();
}