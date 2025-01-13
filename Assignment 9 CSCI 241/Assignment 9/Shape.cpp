// Here are the libraries, the header files, and the using statements that are required by this file.
#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;


/***************************************************************
 Function: Shape()
 
 Use: We are using this Shape() constructor to take the passed in
 argument called shapeColor, and we are using it to initialize the
 color of any given shape.
 
 Parameters:
 1.) shapeColor - This is a reference to a constant string that
 will hold the color of each shape.
 
 Returns: Constructors do not have a return data type.
 
 Notes: This Shape() constructor will only be invoked by a derived-
 class constructor; and this constructor does not require any additional
 code so it has an empty body.
 ***************************************************************/
Shape::Shape(const string& shapeColor) : color(shapeColor)
{
    // This constructor has an empty body.
}


/***************************************************************
 Function: ~Shape()
 
 Use: We are using this ~Shape() destructor to empty all of the
 shapes, but since it does not need to delete any dynamic storage,
 it can be empty.
 
 Parameters: Destructors do not have any parameters.
 
 Returns: Destructors do not have a return data type.
 
 Notes: This ~Shape() destructor needs to be a virtual destructor
 for an abstract base class because if it is not, the compiler may
 produce a warning message.
 ***************************************************************/
Shape::~Shape()
{
    // This destructor has an empty body.
}


/***************************************************************
 Function: print() - for the Shape class
 
 Use: We are using this print() method to simply print the color of
 each shape (and we are also adding an extra space for additional
 information form the other three classes).
 
 Parameters: None
 
 Returns: None
 
 Notes: This is the original print() method from the Shape class;
 there are three ovrridden versions of the print() method from the
 Circle class, the Rectangle class, and the Triangle class.
 ***************************************************************/
void Shape::print() const
{
    // Here we are printing out the color of each shape (followed by a space for additional information).
    cout << color << " ";
}
