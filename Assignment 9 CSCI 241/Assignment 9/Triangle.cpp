// Here are the libraries, the header files, and the using statements that are required by this file.
#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;


/***************************************************************
 Function: Triangle()
 
 Use: We are using this Triangle() constructor to take the passed
 in arguments called triangleColor, triangleHeight, and triangleBase
 to initialize the triangle's color, to initialize triangle's
 height, and to initialize the triangle's base.
 
 Parameters:
 1.) triangleColor - This is a reference to a constant string that
 will hold the color of each triangle.
 2.) triangleHeight - This is an integer that will hold the height
 of each triangle.
 3.) triangleBase - This is an integer that will hold the base
 of each triangle.
 
 Returns: Constructors do not have a return data type.
 
 Notes: This Triangle() constructor is passed to the Shape constructor
 because the Triangle class is derived from the Shape class using
 public inheritance.
 ***************************************************************/
Triangle::Triangle(const string& triangleColor, int triangleHeight, int triangleBase) : Shape(triangleColor)
{
    height = triangleHeight;     // Making triangleHeight equal to height.
    base = triangleBase;     // Making triangleBase equal to base.
}


/***************************************************************
 Function: print() - for the Triangle class
 
 Use: We are using this print() method to simply call the base class
 print() method to print the color, then to print the word "triangle"
 followed by the triangle's height, base, and area.
 
 Parameters: None
 
 Returns: None
 
 Notes: This is the ovrridden version of the print() method from
 the Triangle class; there are two other ovrridden versions of the
 print() method from the Circle class, and the Rectangle class.
 ***************************************************************/
void Triangle::print() const
{
    Shape::print();     // Calling the base class print() method.
    
    // Here we are printing the word "triangle" followed by the triangle's height, base, and area.
    cout << "triangle, height " << height << ", base " << base << ", area " << getArea() << endl;
}


/***************************************************************
 Function: getArea() - for the Triangle class
 
 Use: We are using this getArea() method to simply compute/calculate
 the triangle's area; and we are also using it to return the triangle's
 area based on its height and base.
 
 Parameters: None
 
 Returns: triangleArea - This returns a double which is the area of
 each triangle.
 
 Notes: This is the getArea() method that calculates the area of
 a triangle, there are two other getArea() methods that calculate
 the area of a circle and the area of a rectangle.
 ***************************************************************/
double Triangle::getArea() const
{
    // Here is the double value that we need to calculate the area of a triangle.
    double triangleArea = 0.0;
    
    // Calculating the area of a triangle.
    triangleArea = (0.5 * (base * height));
    
    return triangleArea;     // Returning the triangleArea.
}

