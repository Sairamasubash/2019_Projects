/****************************************************************
 FILE:      Circle.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  May 1, 2019
 
 PURPOSE:   The purpose of the Circle.h header file is to have a
 class called Circle which is derived from the Shape class using
 public inheritance. There are also two other classes that are derived
 from the Shape class using public inheritance: the Rectangle class,
 and the Triangle class.
 ****************************************************************/

// Here are the beginning header guards for the Circle.h header file.
#ifndef CIRCLE_H
#define CIRCLE_H

// Here is the library, the header file, and the using statement that is required by the Circle.h header file.
#include <string>
#include "Shape.h"

using namespace std;

class Circle : public Shape     // Start of the Circle class (which derived from the Shape class using public inheritance).
{
    
private:     // Declaring the one private data member for the Circle class.
    
    int radius;
    
public:     // Declaring the public methods, and constructors for the Circle class (some are virtual/pure virtual).
    
    // Constructor
    Circle(const string&, int);
    
    // Method prototypes
    virtual void print() const;
    virtual double getArea() const;
    
};     // End of the Circle class.

#endif     // Here is the ending header guard for the Circle.h header file.
