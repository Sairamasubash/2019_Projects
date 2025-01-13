/****************************************************************
 FILE:      Matrix.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  March 19, 2019
 
 PURPOSE:   The purpose of the Matrix.h file is to create a class
 called Matrix, that contains the data members, constructors, friend
 finctions and methods required for Matrix.cpp file.
 ****************************************************************/

// Here are the beginning header guards for the Matrix.h file.
#ifndef MATRIX_H
#define MATRIX_H

// Here is the library that is required by this header file.
#include <iostream>

using namespace std;

class Matrix     // Start of the Matrix class.
{
    
    // Declaring the two friend functions that are needed for this program.
    friend ostream & operator<<(ostream &, const Matrix &);
    friend Matrix operator*(int, const Matrix &);
    
private:      // Declaring the private 2D array data member for the Matrix class.
    
    int matrixArray[2][2];
    
public:     // Declaring the public methods and constructors for the Matrix class.
    
    // Constructors
    Matrix();
    Matrix(int[2][2]);
    
    // Method prototypes
    int determinant() const;
   
    Matrix operator+(const Matrix &) const;
    Matrix operator*(int) const;
    Matrix operator*(const Matrix &) const;
    
    bool operator==(const Matrix &) const;
    bool operator!=(const Matrix &) const;
    
    
};     // End of the Matrix class.

#endif     // Ending header guard for the Matrix.h file.
