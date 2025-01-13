// Here are all of the libraries and the header files that I need for the Matrix.cpp file.
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;


/***************************************************************
 Function: Matrix() - default constructor
 
 Use: We are using this Matrix constructor to set all of the elements
 that are in the main diagonal to 1 and to set all of the elements
 that are not in the main diagonal to 0 (setting the elements of the
 matrix array to the identity matrix).
 
 Parameters: None
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is the Matrix constructor that has no parameters, but
 there are times when you use parameters for constructors (below).
 ***************************************************************/
Matrix::Matrix()
{
    // Making matrixArray[0][0] and matrixArray[1][1] equal to 1,
    // and making matrixArray[0][1] and matrixArray[1][0] equal to 0.
    matrixArray[0][0] = 1;
    matrixArray[0][1] = 0;
    matrixArray[1][0] = 0;
    matrixArray[1][1] = 1;
}


/***************************************************************
 Function: Matrix() - not default constructor
 
 Use: We are using this Matrix constructor to set the elements in
 matrixArray to the corresponding elements  from the array passed in
 by this constructor (in this case, the passed in 2D array in the
 parameter named newArray).
 
 Parameters:
 1.) A two-dimensional array that contains integers with two rows
 and two columns (named newArray).
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is the Matrix constructor that has parameters, but
 there are times when you don't use parameters for constructors (above).
 ***************************************************************/
Matrix::Matrix(int newArray[2][2])
{
    // We are setting the elements from matrixArray to the elements in the newArray
    // (also getting in the habit of using the this pointer even though it is not required here).
    this-> matrixArray[0][0] = newArray[0][0];
    this-> matrixArray[0][1] = newArray[0][1];
    this-> matrixArray[1][0] = newArray[1][0];
    this-> matrixArray[1][1] = newArray[1][1];
}


/***************************************************************
 Function: determinant()
 
 Use: We are using this method to get the determinant of a 2-by-2
 matrix called matrixArray (to get this value, we are using simple
 math operations and making the final value equal to an integer
 called det).
 
 Parameters: None
 
 Returns:
 1.) The integer Determinant of the matrix object.
 
 Notes: This method declares an integer, does the math to get the
 value for the decleared integer, and returns the integer once the
 value is aqcquired.
 ***************************************************************/
int Matrix::determinant() const
{
    int det;     // Declaring an integer called det.

    det = matrixArray[0][0] *  matrixArray[1][1] - matrixArray[0][1] * matrixArray[1][0];   // Getting the Determinant.

    return det;     // Returning the final value of det.
}


/***************************************************************
 Function: operator+() (matrix addition)
 
 Use: We are using this method to get the sum of two different matrices.
 For example, the value located at [0][0] of one martix will be added to
 the value located [0][0] for a different matrix; this process is done
 to all the values in the matrices.
 
 Parameters:
 1.) A reference to a constant Matrix object, representing the right
 operand of the matrix addition expression (also, we are using the this
 pointer to refer to the left operand of the matrix addition).
 
 Returns:
 1.) This returns the result of the matrix addition of the left operand
 values and the rignt operand values (basically returns a new matrix object).
 
 Notes: This method declares a matrix object called result, then it
 makes result equal to the addition of the matrix represented by the
 left operand and the matrix represented by the right operand, finally
 it returns the new value of the matrix object.
 ***************************************************************/
Matrix Matrix::operator+(const Matrix & rightOperand) const
{
    Matrix result;     // Declaring the new matrix object (result)
    
    // Adding all of the values in the matrices and setting the sum equal to the new matrix object.
    result.matrixArray[0][0] = this-> matrixArray[0][0] + rightOperand.matrixArray[0][0];
    result.matrixArray[0][1] = this-> matrixArray[0][1] + rightOperand.matrixArray[0][1];
    result.matrixArray[1][0] = this-> matrixArray[1][0] + rightOperand.matrixArray[1][0];
    result.matrixArray[1][1] = this-> matrixArray[1][1] + rightOperand.matrixArray[1][1];

    return result;     // Returning the final value of the new matrix object called result.
}


/***************************************************************
 Function: operator*() (scalar multiplication with integer as right operand)
 
 Use: We are using this method to multiply the matrix representing the
 left operand with the integer representing the right operand (all of the
 values located in the matrix representing the left operand are multiplied by
 the integer in right operand, not just one).
 
 Parameters:
 1.) An integer representing the right operand of the scalar multiplication
 (also, we are using the this pointer to refer to the left operand of the
 scalar multiplication).
 
 Returns:
 1.) This returns the result of multiplying the elements of the matrix
 left operand by the integer rignt operand (basically returns a new
 matrix object).
 
 Notes: This method does the scalar multiplication with the integer
 being the right operand, later in this file there is a method that does
 the scalar multiplication with the integer being the left operand.
 ***************************************************************/
Matrix Matrix::operator*(int rightOperand) const
{
    Matrix result; // Declaring the new matrix object (result)

    // Here is where the multiplication process is happening to all the values.
    result.matrixArray[0][0] = this-> matrixArray[0][0] * rightOperand;
    result.matrixArray[0][1] = this-> matrixArray[0][1] * rightOperand;
    result.matrixArray[1][0] = this-> matrixArray[1][0] * rightOperand;
    result.matrixArray[1][1] = this-> matrixArray[1][1] * rightOperand;
    
    return result;  // Returning the final value of the new matrix object called result.
}


/***************************************************************
 Function: operator*() (matrix multiplication)
 
 Use: We are using this method to multiply the elements in the
 matrix representing the left operand and mantrix representing the
 right operand; but in different order. For example, the matrixArray[0][0]
 could be multiplied by the matrixArray[1][0] (which makes it tougher).
 
 Parameters:
 1.) The only parameter is a reference to a constant Matrix object,
 representing the right operand of the matrix multiplication expression
 (also, we are using the this pointer to refer to the left operand of
 the multiplication expression).
 
 Returns:
 1.) This returns the result of the matrix multiplication of the left
 operand elements and the rignt operand elements (basically returns a
 new matrix object).
 
 Notes: This method uses a for loop that contains 2 other for loops
 in it because, in this matrix multiplication expression, we have to
 multiply the matrices in a different order.
 ***************************************************************/
Matrix Matrix::operator*(const Matrix & rightOperand) const
{
    Matrix result;     // Creating a new matrix object.
    
    int row, col, i;

    for (row = 0; row < 2; row++)     // Start of the for loop that contains 2 other for loops.
    {
        
        for (col = 0; col < 2; col++)
        {
            result.matrixArray[row][col] = 0;     // Setting the final result matrix to 0 for now.
            
            for (i = 0; i < 2; i++)
            {
                
                // This is where the matrix multiplication process is taking place.
                result.matrixArray[row][col] = result.matrixArray[row][col] + (this-> matrixArray[row][i] * rightOperand.matrixArray[i][col]);

            }
        }

    }
   
    return result;     // Returing the final multiplied elements to the output
}


/***************************************************************
 Function: operator==()
 
 Use: We are using this method to return true if all elements of
 the left operand are equal to the corresponding right operand
 elements; and if all elements of the left operand are not equal to
 the corresponding right operand elements we should return false.
 
 Parameters:
 1.) The one and only parameter for this method is a reference to
 a constant Matrix object, representing the right operand of the matrix
 relational expression (also, we are using the this pointer to refer
 to the left operand of the relational expression).
 
 Returns:
 1.) This method returns a boolean value of either true or false
 (so basically 2 return statements based on the things that we are
 trying to search for from the matrices).
 
 Notes: This boolean method returns true if all elements of the
 left operand are equal to the corresponding right operand elements.
 Later in this program, there is another boolean method that returns
 false if all elements of the left operand are equal to the corresponding
 right operand elements.
 ***************************************************************/
bool Matrix::operator==(const Matrix & rightOperand) const
{
    
    int row, col;     // Declaring the variables that we need for this method.
    
    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            // This is where we are checking to see if both matrices are equal to one another to return true.
            if (this-> matrixArray[row][col] == rightOperand.matrixArray[row][col])
            {
                return true; // Returning true (first return statement).
            }
        }
    }
    
    return false; // Returning false (second return statement).
}


/***************************************************************
 Function: operator!=()
 
 Use: We are using this method to return false if all elements of
 the left operand are equal to the corresponding right operand
 elements; and if all elements of the left operand are not equal to
 the corresponding right operand elements we should return true.
 
 Parameters:
 1.) There is only one parameter for this method and it is a reference to
 a constant Matrix object, representing the right operand of the matrix
 relational expression (also, we are using the this pointer to refer
 to the left operand of the relational expression).
 
 Returns:
 1.) This method returns a boolean value of either true or false
 (so basically two return statements based on the things that we
 are trying to search for from the matrices).
 
 Notes: This boolean method returns false if all elements of the
 left operand are equal to the corresponding right operand elements.
 earlier in this program, there was another boolean method that returns
 true if all elements of the left operand are equal to the corresponding
 right operand elements.
 ***************************************************************/
bool Matrix::operator!=(const Matrix & rightOperand) const
{
    int row, col;
    
    for (row = 0; row < 2; row++)     // Start of the for loop that lets us perform the boolean statement.
    {
        for (col = 0; col < 2; col++)
        {
            // This is where we are checking to see if both matrices are equal to one another to return false.
            if (this-> matrixArray[row][col] == rightOperand.matrixArray[row][col])
            {
                return false;     // Returning false (first return statement).
            }
        }
    }
    
    return true;     // Returning true (second return statement).
}


/***************************************************************
 Function: operator<<()
 
 Use: We are using this friend function to print the elements of
 a 2-dimensional matrixArray separated by a few commas. We are also
 using square brackets to make the matrix look more understandable
 (these square brackets are around each row of the matrix and they
 are also around the entire matrix itself).
 
 Parameters:
 1.) The first parameter for this function is a reference to an ostream
 object, representing the left operand of the stream insertion expression.
 2.) The second parameter for this function is a reference to a constant
 Matrix object, representing the right operand of the expression.
 
 Returns:
 1.) This function returns a reference to an ostream object (basically
 the first parameter)
 
 Notes: This is friend function, that means that is not a method
 that is a part of the Matrix class, but it can still access the
 private data member in the matrix class (that is allowed because
 of the keyword friend).
 ***************************************************************/
ostream & operator<<(ostream & leftOperand, const Matrix & rightOperand)
{
    // This is where we are printing the the output for the left operand (we will use this function
    // for every other method/constuctor in this program).
    leftOperand << "[[" << rightOperand.matrixArray[0][0] << ", " << rightOperand.matrixArray[0][1] <<
    "]" << ", " << "[" << rightOperand.matrixArray[1][0] << ", " << rightOperand.matrixArray[1][1] << "]]";
    
    return leftOperand;     // Returning the left operand that works as if it is a cout statement.
}


/***************************************************************
 Function: operator*() (scalar multiplication with integer as left operand)
 
 Use: We are using this method to multiply the matrix representing the
 right operand with the integer representing the left operand (all of the
 values located in the matrix representing the right operand are multiplied by
 the integer in left operand, not just one).
 
 Parameters:
 1.) An integer representing the left operand of the scalar multiplication
 2.) A reference to a constant Matrix object, representing the right operand
 of the scalar multiplication.
 
 Returns:
 1.) This returns the result of multiplying the elements of the matrix
 right operand by the integer left operand (basically returns a new
 matrix object).
 
 Notes: This method does the scalar multiplication with the integer
 being the left operand, earlier in this file there is a method that did
 the scalar multiplication with the integer being the right operand.
 ***************************************************************/
Matrix operator*(int leftOperand, const Matrix & rightOperand)
{
    Matrix result;     // Declaring the new matrix object (result)
    
    // Here is where the multiplication process is happening to all the values.
    result.matrixArray[0][0] = leftOperand * rightOperand.matrixArray[0][0];
    result.matrixArray[0][1] = leftOperand * rightOperand.matrixArray[0][1];
    result.matrixArray[1][0] = leftOperand * rightOperand.matrixArray[1][0];
    result.matrixArray[1][1] = leftOperand * rightOperand.matrixArray[1][1];
    
    return result;     // Returning the final value of the new matrix object called result.
}
