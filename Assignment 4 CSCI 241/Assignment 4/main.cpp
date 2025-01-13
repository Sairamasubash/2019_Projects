/***********************************************************
 CSCI 241 - Assignment 4 - Spring 2019
 
 Progammer: Sairamasubash Muppalaneni
 My programming partner: Alenna Ahmad
 Z-ID: Z1844762
 My partners Z-ID: Z1858089
 Section: 1
 TA: Rahul Reddy Gopu
 Date Due: March 19, 2019
 
 Purpose: The purpose of this program is to introduce operator
 overloding, to use the keyword "friend" for functions, to use
 2D arrays, and to continue on with the practice of using multiple
 files in a c++ program (we use 2 source code files and 1 header
 file in this program).
 ************************************************************/

// Here are all of the libraries and header files that are needed for this program.
#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;


/***************************************************************
 Function: main
 
 Use: We are using this function to declare the multiple 2D arrays
 that we need for this program, and we are also calling all of the
 methods, constructors, and friend functions from the Matrix.cpp
 file ( in total, there are 10 of these in the Matrix.cpp file).
 
 Parameters: none
 
 Returns: (1.) return 0 - whenever we get the return value of 0 in
 the output, we can then confirm that our program was successful.
 
 Notes: We are doing a lot of cout statements in this main function
 because all of the other code is done in the Matrix.cpp file. Also,
 these cout statements contain a lot of Matrix objects and a lot of
 2D array in them (BTW: 2D arrays stands for 2-Dimensional arrays).
 ***************************************************************/
int main()     // Start of the main function.
{
    int array1[2][2] = {{5, 7}, {3, 2}};
    int array2[2][2] = {{2, 3}, {1, 4}};
    
    // Test identity matrix constructor
    
    cout << "1. Testing identity matrix constructor\n\n";
    
    const Matrix m1;
    cout << "m1 = " << m1 << endl << endl;
    
    // Test array initialization constructor
    
    cout << "2. Testing array initialization constructor\n\n";
    
    Matrix m2(array1);
    cout << "m2 = " << m2 << endl;
    
    const Matrix m3(array2);
    cout << "m3 = " << m3 << endl << endl;
    
    // Test determinant
    
    cout << "3. Testing determinant\n\n";

    cout << "det" << m2 << " = " << m2.determinant() << endl;
    cout << "det" << m3 << " = " << m3.determinant() << endl << endl;

    // Test matrix addition

    cout << "4. Testing matrix addition\n\n";

    cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
    cout << m3 << " + " << m2 << " = " << m3 + m2 << endl << endl;

    // Test scalar multiplication

    cout << "5. Testing scalar multiplication\n\n";

    cout << m2 << " * 2 = " << m2 * 2 << endl;
    cout << "4 * " << m2 << " = " << 4 * m2 << endl << endl;

    // Test matrix multiplication

    cout << "6. Testing matrix multiplication\n\n";

    cout << m2 << " * " << m3 << " = " << m2 * m3 << endl;
    cout << m3 << " * " << m2 << " = " << m3 * m2 << endl;
    cout << m3 << " * " << m1 << " = " << m3 * m1 << endl;
    cout << m1 << " * " << m3 << " = " << m1 * m3 << endl << endl;

    cout << "det(m2 * m3) and det(m2) * det(m3) are ";
    cout << (((m2 * m3).determinant() == m2.determinant() * m3.determinant()) ?
             "equal\n\n" : "not equal\n\n");

    // Test relational operators

    cout << "7. Testing relational operators\n\n";

    const Matrix m4(array1);

    cout << m2 << " and " << m4;
    cout << ((m2 == m4) ? " are equal\n" : " are not equal\n");

    cout << m2 << " and " << m3;
    cout << ((m2 != m3) ? " are not equal\n" : " are equal\n");
    
    return 0;     // Returning 0 to test for success.
}     // End of the main function.
