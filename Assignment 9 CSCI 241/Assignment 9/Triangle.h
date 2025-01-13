/****************************************************************
 FILE:      Triangle.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  May 1, 2019
 
 PURPOSE:   The purpose of the Triangle.h header file is to have a
 class called Triangle which is derived from the Shape class using
 public inheritance. There are also two other classes that are derived
 from the Shape class using public inheritance: the Circle class,
 and the Rectangle class.
 ****************************************************************/

// Here are the beginning header guards for the Triangle.h header file.
#ifndef TRIANGLE_H
#define TRIANGLE_H

// Here is the library, the header file, and the using statement that is required by the Triangle.h header file.
#include <string>
#include "Shape.h"

using namespace std;

class Triangle : public Shape     // Start of the Triangle class (which derived from the Shape class using public inheritance).
{

private:     // Declaring the two private data members for the Triangle class.

    int height;
    int base;

public:     // Declaring the public methods, and constructors for the Triangle class (some are virtual/pure virtual).
    
    // Constructor
    Triangle(const string&, int, int);

    // Method prototypes
    virtual void print() const;
    virtual double getArea() const;

};     // End of the Triangle class.

#endif     // Here is the ending header guard for the Triangle.h header file.
