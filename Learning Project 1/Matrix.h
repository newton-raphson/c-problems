#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
class Matrix {
public:
    virtual ~Matrix() {}
    virtual double& operator()(int row, int col) = 0;
    virtual const double& operator()(int row, int col) const = 0;
    virtual double getElement(int row, int col) const = 0;
    virtual int getNumRows() const = 0;
    virtual int getNumCols() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

class DenseMatrix : public Matrix {
private:
    int numRows;
    int numCols;
    double** elements;

public:
    DenseMatrix(int rows, int cols);
    ~DenseMatrix();
    double& operator()(int row, int col) override;
    const double& operator()(int row, int col) const override;
    double getElement(int row, int col) const override;
    int getNumRows() const override;
    int getNumCols() const override;

    DenseMatrix operator * (const DenseMatrix& other) const;
    DenseMatrix operator * (const double* vector) const;
};
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

class SparseMatrix : public Matrix{
private:
    int numRows;
    int numCols;
    std::vector<int> rowPtr;
    std::vector<int> colIdx;
    std::vector<double> values;

public:
    SparseMatrix(int rows, int cols);
    SparseMatrix();
    ~SparseMatrix();

    int getRowPtr(int i) const;
    int getColIdx(int i) const;
    double getValue(int i) const;

    double getElement(int row, int col) const override;
    int getNumRows() const override;
    int getNumCols() const override;
    std::vector<double> operator * (const std::vector<double>& vector) const ;

    void setElement(int row, int col, double value);
    double& operator()(int row, int col) override;
    const double& operator()(int row, int col) const override;

};
#endif // MATRIX_HPP
