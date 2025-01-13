// Here are the libraries, the header files, and the using statements that are required by this file.
#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;


/***************************************************************
 Function: Rectangle()
 
 Use: We are using this Rectangle() constructor to take the passed
 in arguments called rectangleColor, rectangleHeight, and rectangleWidth
 to initialize the rectangle's color, to initialize rectangle's
 height, and to initialize the rectangle's width.
 
 Parameters:
 1.) rectangleColor - This is a reference to a constant string that
 will hold the color of each rectangle.
 2.) rectangleHeight - This is an integer that will hold the height
 of each rectangle.
 3.) rectangleWidth - This is an integer that will hold the width
 of each rectangle.
 
 Returns: Constructors do not have a return data type.
 
 Notes: This Rectangle() constructor is passed to the Shape constructor
 because the Rectangle class is derived from the Shape class using
 public inheritance.
 ***************************************************************/
Rectangle::Rectangle(const string& rectangleColor, int rectangleHeight, int rectangleWidth) : Shape(rectangleColor)
{
    height = rectangleHeight;     // Making rectangleHeight equal to height.
    width = rectangleWidth;     // Making rectangleWidth equal to width.
}


/***************************************************************
 Function: print() - for the Rectangle class
 
 Use: We are using this print() method to simply call the base class
 print() method to print the color, then to print the word "rectangle"
 followed by the rectangle's height, width, and area.
 
 Parameters: None
 
 Returns: None
 
 Notes: This is the ovrridden version of the print() method from
 the Rectangle class; there are two other ovrridden versions of the
 print() method from the Circle class, and the Triangle class.
 ***************************************************************/
void Rectangle::print() const
{
    Shape::print();     // Calling the base class print() method.
    
     // Here we are printing the word "rectangle" followed by the rectangle's height, width, and area
    cout << "rectangle, height " << height << ", width " << width << ", area " << getArea() << endl;
}


/***************************************************************
 Function: getArea() - for the Rectangle class
 
 Use: We are using this getArea() method to simply compute/calculate
 the rectangle's area; and we are also using it to return the rectangle's
 area based on its height and width.
 
 Parameters: None
 
 Returns: rectangleArea - This returns a double which is the area of
 each rectangle.
 
 Notes: This is the getArea() method that calculates the area of
 a rectangle, there are two other getArea() methods that calculate
 the area of a circle and the area of a triangle.
 ***************************************************************/
double Rectangle::getArea() const
{
    // Here is the double value that we need to calculate the area of a rectangle.
    double rectangleArea = 0.0;
    
    // Calculating the area of a rectangle.
    rectangleArea = height * width;
    
    return rectangleArea;     // Returning the rectangleArea.
}
