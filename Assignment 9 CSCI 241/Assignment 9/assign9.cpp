/***********************************************************
 CSCI 241 - Assignment 9 - Spring 2019
 
 Progammer: Sairamasubash Muppalaneni
 My programming partner: Alenna Ahmad
 Z-ID: Z1844762
 My partners Z-ID: Z1858089
 Section: 1
 TA: Rahul Reddy Gopu
 Date Due: May 1, 2019
 
 Purpose: The purpose of this program is to get some exercise
 with inheritance and polymorphism by creating a series of classes
 to represent some simple geometric shapes; and by also creating
 a small program to test these classes that represent the geometric
 shapes.
 ************************************************************/

// Here are all of the libraries that are needed for this program.
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

// Here are all of the header files and the using statements that are needed for this program.
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;


/***************************************************************
 Function: main()
 
 Use: We are using this main() function to dynamically create the
 three shapes, to loop through the array or vector of Shape pointers
 and call the print() method for each of them, to loop through the array
 or vector of Shape pointers again and call the print() method for each
 of the Circle objects in the array or vector, and to loop through
 the list of Shape pointers one more time and delete each object.
 
 Parameters: none
 
 Returns:
 1.) return 0 - whenever we get the return value of 0 in
 the output, we can then confirm that our program ran successfully.
 
 Notes: We are doing a lot of cout/printing statements in this main
 function because all of the other code is done in the Shape.h,
 Shape.cpp, Circle.h, Circle.cpp, Rectangle.h, Rectangle.cpp,
 Triangle.h, and Triangle.cpp files.
 ***************************************************************/
int main()     // Start of the main function.
{
    
    // Creating the vector called shapes that can hold six items.
    vector <Shape *> shapes(6);
    
    // Initializing the vector called shapes with six shapes.
    shapes[0] = new Circle("green", 10);
    shapes[1] = new Rectangle("red", 8, 6);
    shapes[2] = new Triangle("yellow", 8, 4);
    shapes[3] = new Triangle("black", 4, 10);
    shapes[4] = new Circle("orange", 5);
    shapes[5] = new Rectangle("blue", 3, 7);
    
    cout << "\nPrinting all shapes..." << endl << endl;
    
    // We are processing each element in the vector called shapes and printing the shape information.
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        shapes[i]-> print();
    }
    
    cout << endl;     // Using endl for a new line.
    
    cout << "Printing only circles..." << endl << endl;
    
    // This is a for loop to just print all of the circles and nothing else.
    for (unsigned int i = 0; i < shapes.size(); ++i)
    {
        // Creating a downcast pointer and using dynamic_cast.
        Circle* circlePtr = dynamic_cast <Circle *> (shapes[i]);
        
        // Checking to see if the circlePtr is not equal to nullptr and printing the circle information.
        if (circlePtr != nullptr)
        {
            circlePtr-> print();
        }
    }
    
    // Deleting/releasing the memory held by the vector called shapes (using a for loop).
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        delete shapes[i];
    }
    
    cout << endl;     // Using endl for a new line.
    
    return 0;     // Returning 0 to see if the program ran successfully.

}     // End of the main function.
