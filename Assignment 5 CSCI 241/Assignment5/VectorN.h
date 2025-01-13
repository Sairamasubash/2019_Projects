/****************************************************************
 FILE:      VectorN.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  March 28, 2019
 
 PURPOSE:   The purpose of the VectorN.h file is to create a class
 called VectorN, that contains the data members, constructors, destructors,
 friend finctions, and methods required for the VectorN.cpp file.
 ****************************************************************/

// Here are the beginning header guards for the VectorN.h file.
#ifndef VECTORN_H
#define VECTORN_H

// Here is the library and the using statement that is required by this header file.
#include <iostream>

using namespace std;

class  VectorN     // Start of the VectorN class.
{
    
    // Declaring the two friend functions that are needed for this program.
    friend VectorN operator*(double, const VectorN&);
    friend ostream& operator<<(ostream&, const VectorN&);
    
private:     // Declaring the two private data members for the VectorN class.
    
    double* vArray;
    size_t vCapacity;
    
public:     // Declaring the public methods, destructors, and constructors for the VectorN class.
    
    // Constructors and destructors
    VectorN();
    VectorN(const double[], size_t);
    VectorN(const VectorN&);
    ~VectorN();
    
    // Method prototypes
    VectorN& operator=(const VectorN&);
    void clear();
    size_t size() const;
    
    VectorN operator+(const VectorN&) const;
    VectorN operator-(const VectorN&) const;
    double operator*(const VectorN&) const;
    VectorN operator*(double) const;
    
    double operator[](int) const;
    double& operator[](int);
    bool operator==(const VectorN&) const;
    
    // Extra credit method prototypes.
    double at(int) const;
    double& at(int);
    
};     // End of the VectorN class.

#endif     // Ending header guard for the VectorN.h file.
