/****************************************************************
 FILE:      Shape.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  May 1, 2019
 
 PURPOSE:   The purpose of the Shape.h header file is to have a
 class called Shape which will serve as an abstract base class for
 the Circle class, for the Rectangle class, and for the Triangle
 class (the Circle class, the Rectangle class, and the Triangle
 class are derived from the Shape class using public inheritance).
 ****************************************************************/

// Here are the beginning header guards for the Shape.h header file.
#ifndef SHAPE_H
#define SHAPE_H

// Here is the library and the using statement that is required by the Shape.h header file.
#include <string>

using namespace std;

class Shape     // Start of the Shape class (which is an abstract base class).
{
    
private:     // Declaring the one private data member for the Shape class.
    
    string color;
    
public:     // Declaring the public methods, destructors, and constructors for the Shape class (some are virtual/pure virtual).
 
    // Constructors and destructors
    Shape(const string&);
    virtual ~Shape();
    
    // Method prototypes
    virtual void print() const;
    virtual double getArea() const = 0;
    
};     // End of the Shape class.

#endif     // Here is the ending header guard for the Shape.h header file.
