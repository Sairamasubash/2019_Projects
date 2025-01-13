// Here are the libraries, the header files, and the using statements that are required by this file.
#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;


/***************************************************************
 Function: Circle()
 
 Use: We are using this Circle() constructor to take the passed in
 arguments called circleColor, and circleRadius to initialize the
 circle's color and to initialize the circle's radius.
 
 Parameters:
 1.) circleColor - This is a reference to a constant string that
 will hold the color of each circle.
 2.) circleRadius - This is an integer that will hold the radius
 of each circle.
 
 Returns: Constructors do not have a return data type.
 
 Notes: This Circle() constructor is passed to the Shape constructor
 because the Circle class is derived from the Shape class using
 public inheritance.
 ***************************************************************/
Circle::Circle(const string& circleColor, int circleRadius) : Shape(circleColor)
{
    radius = circleRadius;     // Making circleRadius equal to radius.
}


/***************************************************************
 Function: print() - for the Circle class
 
 Use: We are using this print() method to simply call the base class
 print() method to print the color, then to print the word "circle"
 followed by the circle's radius and area.
 
 Parameters: None
 
 Returns: None
 
 Notes: This is the ovrridden version of the print() method from
 the Circle class; there are two other ovrridden versions of the
 print() method from the Rectangle class, and the Triangle class.
 ***************************************************************/
void Circle::print() const
{
    Shape::print();     // Calling the base class print() method.
    
    // Here we are printing the word "circle" followed by the circle's radius and area.
    cout << "circle, radius " << radius << ", area " << getArea() << endl;
}


/***************************************************************
 Function: getArea() - for the Circle class
 
 Use: We are using this getArea() method to simply compute/calculate
 the circle's area; and we are also using it to return the circle's
 area based on its radius.
 
 Parameters: None
 
 Returns: circleArea - This returns a double which is the area of
 each circle.
 
 Notes: This is the getArea() method that calculates the area of
 a circle, there are two other getArea() methods that calculate
 the area of a rectangle and the area of a triangle.
 ***************************************************************/
double Circle::getArea() const
{
    // Here are the two double values that we need to calculate the area of a circle.
    double circleArea = 0.0;
    const double Pi = 3.14159265359;
    
    // Calculating the area of a circle.
    circleArea = (Pi * (radius * radius));
    
    return circleArea;     // Returning the circleArea.
}
