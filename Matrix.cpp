#include "Matrix.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const double epsilon = 0.001;

//matrix constructor
Matrix::Matrix(int numRows, int numCols): matrix(numRows, vector<double>(numCols)) {
    
    for(int i=0; i<numRows; i++)
        for (int j=0; j<numCols; j++)
            matrix[i][j] = 0;
    
}


Matrix::Matrix(const Matrix& rhs):matrix(rhs.getNumRows(),
                                                vector<double>(rhs.getNumCols()))
{
    for(int i=0; i<getNumRows(); i++)
        for(int j=0; i<getNumCols(); j++)
            matrix[i][j] = rhs[i][j];
}
                                         

Matrix& Matrix::operator = (const Matrix& rhs) {
    
    for(int i=0; i<getNumRows(); i++)
        for(int j=0; j<getNumCols(); j++)
            matrix[i][j] = rhs[i][j];
    
    return *this;
}

//function to read and/or modify matrix cells
double& Matrix::operator() (int row, int col) {
    return matrix[row][col];
}
    
//function to retrieve and/or modify a row
vector<double>& Matrix::operator[](int row) {
    return matrix[row];
}

const vector<double>& Matrix::operator[](int row)const {
    return matrix[row];
}
//matrix multiplication
Matrix operator* (const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs.getNumRows(), rhs.getNumCols());
    
    for(int i=0; i<lhs.getNumRows(); i++) {
        for(int j = 0; j<rhs.getNumCols(); j++) {
            result[i][j] = 0.0;
            for(int k = 0; k< lhs.getNumCols(); k++) {
    
                result[i][j]+= lhs[i][k] * rhs[k][j];
            }
        }
    }
    
    return result;
    
    
}
    
//scalar multiplication
Matrix operator*(const Matrix& lhs, double scalar) {
    
    Matrix result(lhs.getNumRows(), lhs.getNumCols());

    for(int i=0; i<lhs.getNumRows(); i++)
        for (int j=0; j<lhs.getNumCols(); j++)
            result[i][j]*= scalar;
    
    return result;
    
}

Matrix operator*(double scalar, const Matrix& rhs) {
    return rhs * scalar;
}

//inflation method
Matrix Matrix::inflate()const {
    
    Matrix result(getNumRows(), getNumCols());
    
    for(int i=0; i<getNumRows(); i++)
        for(int j=0; j<getNumCols(); j++)
            result[i][j] = (*this)[i][j];
    
    
    for(int j=0; j<result.getNumCols(); j++) {
        double inflationFactor = 0.0;
        
        for(int i=0; i<result.getNumRows(); i++) {
            inflationFactor+= pow(result[i][j], 2);
        }
        for(int i=0; i<result.getNumRows(); i++)
            result[i][j] = pow(result[i][j], 2) / inflationFactor;
    }
    
    return result;
    
}


//equality method

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    
    if(lhs.getNumCols() != rhs.getNumCols() || lhs.getNumRows() != rhs.getNumRows())
        return false;
    
    for(int i=0; i<lhs.getNumRows(); i++) {
        for(int j = 0; j<lhs.getNumCols(); j++) {
            if(abs(lhs[i][j] - rhs[i][j]) > epsilon)
                return false;
        }
    }
    return true;
    
}
//printing method

ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i=0; i<matrix.getNumRows(); i++) {
        
        for(int j = 0; j<matrix.getNumCols(); j++)
            os<<matrix[i][j]<<" ";
        os<<endl;
        
    }
    return os;
}