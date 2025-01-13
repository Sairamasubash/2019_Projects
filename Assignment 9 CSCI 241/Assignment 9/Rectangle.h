/****************************************************************
 FILE:      Rectangle.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  May 1, 2019
 
 PURPOSE:   The purpose of the Rectangle.h header file is to have a
 class called Rectangle which is derived from the Shape class using
 public inheritance. There are also two other classes that are derived
 from the Shape class using public inheritance: the Circle class,
 and the Triangle class.
 ****************************************************************/

// Here are the beginning header guards for the Rectangle.h header file.
#ifndef RECTANGLE_H
#define RECTANGLE_H

// Here is the library, the header file, and the using statement that is required by the Rectangle.h header file.
#include <string>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape     // Start of the Rectangle class (which derived from the Shape class using public inheritance).
{

private:     // Declaring the two private data members for the Rectangle class.

    int height;
    int width;

public:     // Declaring the public methods, and constructors for the Rectangle class (some are virtual/pure virtual).

    // Constructor
    Rectangle(const string&, int, int);
    
    // Method prototypes
    virtual void print() const;
    virtual double getArea() const;

};     // End of the Rectangle class.

#endif     // Here is the ending header guard for the Rectangle.h header file.
