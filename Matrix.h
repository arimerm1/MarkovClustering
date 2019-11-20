#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;


class Matrix {

public:
    
    //matrix constructor
    Matrix(int numRows, int numCols);
    
    Matrix(const Matrix& rhs);
    
    Matrix& operator = (const Matrix& rhs);
    
    //function to read and/or modify matrix cells
    double& operator() (int row, int col);
    
    //function to retrieve and/or modify a row
    vector<double>& operator[](int row);
    const vector<double>& operator[](int row) const;
    //matrix multiplication
    friend Matrix operator* (const Matrix& lhs, const Matrix& rhs);
    
    //scalar multiplication
    friend Matrix operator*(const Matrix& lhs, double scalar);
    friend Matrix operator*(double scalar, const Matrix& rhs);
    
    //equality of 2 matrices means terms are off by epsilon
    
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    //inflation method
    Matrix inflate()const;
    
    int getNumRows() const {
        return matrix.size();
    }
    int getNumCols() const{
        return matrix[0].size();
    }
    
    //printing method
    
    friend ostream& operator<<(ostream& os, const Matrix& matrix);

private:

    vector<vector<double> > matrix;
};

#endif