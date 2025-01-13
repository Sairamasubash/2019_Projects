// Here are all of the libraries and the header files that I need for the VectorN.cpp file.
#include <iostream>
#include <iomanip>
#include "VectorN.h"

// Here is the using statement that I need for the VectorN.cpp file.
using namespace std;


/***************************************************************
 Function: VectorN() - default constructor
 
 Use: We are using this VectorN constructor to set the vCapacity
 for the new object to 0; and to set the vArray pointer for the
 new object to the special value nullptr.
 
 Parameters: None
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is the VectorN constructor that has no parameters, but
 there are times when you use parameters for constructors (below).
 ***************************************************************/
VectorN::VectorN()
{
    vCapacity = 0;     // Setting vCapacity to 0.
    vArray = nullptr;     // Setting vArray to nullptr.
}


/***************************************************************
 Function: VectorN() - not default constructor
 
 Use: We are using this VectorN constructor to initialize a new
 VectorN object to the values stored in the array values. Also,
 we are allocating an array of type double (with the size of
 vCapacity).
 
 Parameters:
 1.) n - We have and unsigned integer value (using size_t).
 2.) values - We also have an array of type double (making it
 const).
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is the VectorN constructor that has parameters, but
 there are times when you don't use parameters for constructors (above).
 ***************************************************************/
VectorN::VectorN(const double values[], size_t n)
{
    vCapacity = n;     // Making vCapacity equal to n.
    
    if (vCapacity == 0)     // Checking to see if vCapacity is equal to 0.
    {
        vArray = nullptr;     // Setting vArray to nullptr.
    }
    else
    {
        vArray = new double[vCapacity];     // Allocating an array of type double.
    }
    
    for (size_t i = 0; i < n; i++)
    {
        vArray[i] = values[i];
    }
    
}


/***************************************************************
 Function: VectorN() - copy constructor
 
 Use: We are using this VectorN special constructor to initialize a
 new VectorN object to the same capacity and array contents as the
 existing VectorN object (other). Also, even in this constructor
 we are allocating an array of double (with the size of vCapacity).
 
 Parameters:
 1.) other - We have a reference to a constant VectorN object (used
 throughout the entire constructor).
 
 Returns: Constructors do no have a return data type.
 
 Notes: This is a special type of constructor: the copy constructor.
 There are many times that we can call a copy constructor, but one
 important time is when a new object is initialized with an existing
 object of the same class
 ***************************************************************/
VectorN::VectorN(const VectorN& other)
{
    vCapacity = other.vCapacity;     // Making vCapacity equal to the capacity of the object other.
    
    if (vCapacity == 0)     // Checking to see if vCapacity is equal to 0.
    {
        vArray = nullptr;     // Making vArray equal to nullptr.
    }
    else
    {
        vArray = new double[vCapacity];     // Once again, allocating an array of type double.
    }
    
    for (size_t i = 0; i < other.size(); i++)
    {
        
        if (other.vCapacity == 0)
        {
            break;     // Exiting loop if the capacity of the object other is 0;
        }
        
        vArray[i] = other.vArray[i];
    
    }
    
}


/***************************************************************
 Function: ~VectorN() - destructor
 
 Use: We are using this VectorN destructor to call the clear method
 which will deallocate any dynamic storage owned by the vectorN object.
 (also, destructors are always named after the class name).
 
 Parameters: Destructors do not have any parameters.
 
 Returns: Destructors do not have a return data type.
 
 Notes: This is the VectorN destructor and destructors are never
 const, they start with a tilde (~), and they never have any parameters
 and returns.
 ***************************************************************/
VectorN::~VectorN()
{
    clear();     // Calling the clear method.
}


/***************************************************************
 Function: operator=() - overloaded copy assignment operator
 
 Use: We are using this special overloaded operator to assign one
 VectorN object (the object called other) to another (the object
 that called the method, which is pointed to by this). In this
 operator, we are using delete[] to deallocate the array before
 the end of the program.
 
 Parameters:
 1.) other - We have a reference to a constant VectorN object (used
 throughout the entire method).
 
 Returns: The this pointer (*this) - which represents the left operand
 of the assignment statement.
 
 Notes: This is a special type of overloaded operator: overloaded copy
 assignment operator. This operator should be called when an existing
 object is assigned to another existing object of the same class.
 ***************************************************************/
VectorN& VectorN::operator=(const VectorN& other)
{
    
    if (this == &other)     // Checking for self-assignment
    {
        return *this;
    }
    
    delete[] this-> vArray;   // Deleting the vArray for the object pointed to by this.
    
    this-> vCapacity = other.vCapacity;
    
    if (vCapacity == 0)     // Checking to see if vCapacity is equal to 0.
    {
        this-> vArray = nullptr;     // Making the vArray pointed to by this equal to nullptr.
    }
    else
    {
        vArray = new double[vCapacity];
    }
    
    for (size_t i = 0; i < other.size(); i++)
    {
        this-> vArray[i] = other.vArray[i];
        
    }
    
    return *this;     // Returning the this pointer.
}


/***************************************************************
 Function: clear()
 
 Use: We are using this clear method to correctly set the instance back
 to a vector of zero elements, by deleting the vector array, setting the
 vector array pointer to nullptr, and setting the vector capacity to 0.
 
 Parameters: None
 
 Returns: none
 
 Notes: This method is called by the VectorN destructor (above).
 Also, this method is similer to the default constructor, except in
 this method we are deleting the vArray.
 ***************************************************************/
void VectorN::clear()
{
    delete[] vArray;     // Deleting the vArray.
    vArray = nullptr;     // Setting the vArray to nullptr.
    vCapacity = 0;     // Setting the vCapacity to 0.
}


/***************************************************************
 Function: size()
 
 Use: We are simply using this size method return the size of the
 vector, which is equal to the vCapacity. Plus, this method is a
 const so the vCapacity values will not change no matter what happens.
 
 Parameters: None
 
 Returns: vCapacity - which is basically returning the size of the
 vector (how many elements are in the vArray).
 
 Notes: This method is unique because it returns an unsigned
 integer value (labeled as size_t); and this method is called in
 insertion operator (below).
 ***************************************************************/
size_t VectorN::size() const
{
    return vCapacity;     // Returning the vCapacity.
}


/***************************************************************
 Function: operator+() (vector addition)
 
 Use: We are using this method to simply add the components of
 the left operand to the corresponding components of the right
 operand to get the final sum of both vectors (to return). We are
 also allocating an array of type double in this vector addition.
 
 Parameters:
 1.) rightOperand - A reference to a constant VectorN object,
 representing the right operand of the vector addition (also, we
 are using the this pointer concept to refer to the left operand
 of the vector addition).
 
 Returns:
 1.) result - This returns the result of the vector addition of the
 left operand values and the rignt operand values (basically returns
 a new VectorN object).
 
 Notes: We are using the unsigned integer (size_t) so that the
 comparison with vCapacity will be smooth (without any complaints
 or warnings).
 ***************************************************************/
VectorN VectorN::operator+(const VectorN& rightOperand) const
{
    VectorN result;     // Making a VectorN object called result.
    
    if (vCapacity < rightOperand.vCapacity)     // Checking to see if vCapacity is less than rightOperand's capacity.
    {
        result.vCapacity = vCapacity;
    }
    else
    {
        result.vCapacity = rightOperand.vCapacity;
    }
    
    result.vArray = new double[result.vCapacity];
    
    for (size_t i = 0; i < result.vCapacity; i++)
    {
        // Adding the leftOperand elements to their corresponding rightOperand elements.
        result.vArray[i] = vArray[i] + rightOperand.vArray[i];
    }
    
    return result;     // Returning result.
}


/***************************************************************
 Function: operator-() (vector binary subtraction)
 
 Use: We are using this method to simply subtract the components
 of the left operand to the corresponding components of the right
 operand to get the final subtraction of both vectors (to return).
 Here also, we are allocating an array of type double in this
 vector subtraction.
 
 Parameters:
 1.) rightOperand - A reference to a constant VectorN object,
 representing the right operand of the vector subtraction (also,
 we are using the this pointer concept to refer to the left operand
 of the vector subtraction).
 
 Returns:
 1.) result - This returns the result of the vector subtraction of
 the left operand values and the rignt operand values (basically
 returns a new VectorN object).
 
 Notes: We are also using the unsigned integer (size_t) here so
 that the comparison with vCapacity will go very smoothly (without
 any complaints or warnings).
 ***************************************************************/
VectorN VectorN::operator-(const VectorN& rightOperand) const
{
    VectorN result;     // Making a VectorN object called result.
    
    if (vCapacity < rightOperand.vCapacity)     // Checking to see if vCapacity is less than rightOperand's capacity.
    {
        result.vCapacity = vCapacity;
    }
    else
    {
        result.vCapacity = rightOperand.vCapacity;
    }
    
    result.vArray = new double[result.vCapacity];
    
    for (size_t i = 0; i < result.vCapacity; i++)
    {
        // Subtracting the leftOperand elements to their corresponding rightOperand elements.
        result.vArray[i] = vArray[i] - rightOperand.vArray[i];
    }
    
    return result;     // Returning result.
}


/***************************************************************
 Function: operator*() (vector multiplication)
 
 Use: We are using this method to simply multiply the components
 of the left operand to the corresponding components of the right
 operand to get the final multiplication of both vectors (to return).
 Yet again, we are also allocating an array of type double in this
 vector multiplication.
 
 Parameters:
 1.) rightOperand - A reference to a constant VectorN object,
 representing the right operand of the vector multiplication (also,
 we are using the this pointer concept to refer to the left operand
 of the vector multiplication).
 
 Returns:
 1.) result - This returns the result of the vector multiplication
 of the left operand values and the rignt operand values (basically
 returns a new VectorN object).
 
 Notes: In this program we have a total of three multiplication
 operators to overload, and this is just the regular vector
 multiplication operator.
 ***************************************************************/
double VectorN::operator*(const VectorN& rightOperand) const
{
    double result = 0;     // Making a data member result of type double and setting it to 0.
    size_t size = 0;     // Making a unsigned integer size and setting it to 0.
    
    if (vCapacity < rightOperand.vCapacity)     // Checking to see if vCapacity is less than rightOperand's capacity.
    {
        size = vCapacity;
    }
    else
    {
        size = rightOperand.vCapacity;
    }
    
    for (size_t i = 0; i < size; i++)
    {
        // Multiplying the leftOperand elements to their corresponding rightOperand elements.
        result = result + (vArray[i] * rightOperand.vArray[i]);
    }
    
    return result;     // Returning result.
}


/***************************************************************
 Function: operator*() (scalar multiplication with double value as right operand)
 
 Use: We are using this method to multiply the vector representing the
 left operand with the double value representing the right operand (all
 of the values located in the vector representing the left operand are
 multiplied by the double value in right operand, not just one).
 
 Parameters:
 1.) rightOperand - An double vlaue representing the right operand of
 the scalar multiplication (also, we are using the this pointer
 concept to refer to the left operand of the scalar multiplication).
 
 Returns:
 1.) result - This returns the result of multiplying the elements of the
 vector left operand by the double value right operand (basically
 returns a new VectorN object).
 
 Notes: This method does the scalar multiplication with the double value
 being the right operand, later in this program, there is a method that
 does the scalar multiplication with the double value being the left
 operand.
 ***************************************************************/
VectorN VectorN::operator*(double rightOperand) const
{
    VectorN result = *this;     // Setting result to the this pointer (*this).
    
    for (size_t i = 0; i < result.vCapacity; i++)
    {
        // multiplying the rightOperand double value to all of the leftOperand elements.
        result.vArray[i] = result.vArray[i] * rightOperand;
    }
    
    return result;     // Returning result.
}


/***************************************************************
 Function: operator*() (scalar multiplication with double value as left operand)
 
 Use: We are using this method to multiply the vector representing
 the right operand with the double value representing the left operand
 (all of the values located in the vector representing the right operand
 are multiplied by the double value in left operand, not just one).
 
 Parameters:
 1.) An double value representing the left operand of the scalar
 multiplication
 2.) A reference to a constant VectorN object, representing the
 right operand of the scalar multiplication.
 
 Returns:
 1.) This returns the result of multiplying the elements of the
 vector right operand by the double value left operand (basically
 returns a new VectorN object).
 
 Notes: This method does the scalar multiplication with the double
 value being the left operand, earlier in this program there is
 a method that did the scalar multiplication with the double value
 being the right operand.
 ***************************************************************/
VectorN operator*(double leftOperand, const VectorN& rightOperand)
{
    VectorN result = rightOperand;     // Making result equal to the rightOperand.
    
    for (size_t i = 0; i < result.vCapacity; i++)
    {
        // multiplying the leftOperand double value to all of the rightOperand elements.
        result.vArray[i] = leftOperand * result.vArray[i];
    }
    
    return result;     // Returning result.
}


/***************************************************************
 Function: operator<<() (stream insertion operator)
 
 Use: We are using this friend function to print all the elements of
 a vector (vArray) separated by a few commas. We are also using
 parentheses to make the vector look more understandable (these
 parentheses are around each listing of the vector elements (vArray)).
 
 Parameters:
 1.) The first parameter for this function is a reference to an ostream
 object, representing the left operand of the stream insertion expression.
 2.) The second parameter for this function is a reference to a constant
 VectorN object, representing the right operand of the expression.
 
 Returns:
 1.) leftOperand - This function returns a reference to an ostream object
 (basically the first parameter).
 
 Notes: This is friend function, that means that is not a method
 that is a part of the VectorN class, but it can still access the
 private data member in the VectorN class (that is allowed because
 of the keyword friend).
 ***************************************************************/
ostream& operator<<(ostream& leftOperand, const VectorN& rightOperand)
{
    leftOperand << "(";     // Using leftOperand as a cout statement for the opening parentheses.
    
    if (rightOperand.size() > 0)
    {
        leftOperand << rightOperand.vArray[0];
    
        for (size_t i = 1; i < rightOperand.size(); i++)     // Start of the for loop that prints the vArray elements.
        {
            leftOperand << ", " << rightOperand.vArray[i];
        }
        
    }

    leftOperand << ")";     // Using leftOperand as a cout statement for the closing parentheses.
    
    return leftOperand;     // Returning leftOperand.
}


/***************************************************************
 Function: operator[]() (constant subscript operator)
 
 Use: We are using the constant subscript operator to provide an
 accessor method for the VectorN class. This is a constant subscript
 operator, which means that this is a read-only version.
 
 Parameters:
 1.) sub - This is sub, which is basically representing the interger
 subscript for all the vArray elements in the vector (for the constant
 subscript operator).
 
 Returns:
 1.) vArray[sub] - returns the element sub of the vArray data
 member (for the constant subscript operator).
 
 Notes: In this method, we are writing code for a constant subscript
 operator, later in this program we will also be writing code for
 a regular/non-constant subscript operator (below).
 ***************************************************************/
double VectorN::operator[](int sub) const
{
    return vArray[sub];     // Return element sub of the array data member.
}


/***************************************************************
 Function: operator[]() (regular/non-constant subscript operator)
 
 Use: We are using the regular/non-constant subscript operator to
 also provide an accessor method for the VectorN class. This is a
 regular/non-constant subscript operator, which means that this is
 a read and write version.
 
 Parameters:
 1.) sub - This is sub, which is basically representing the interger
 subscript for all the vArray elements in the vector (for the regular/
 non-constant subscript operator).
 
 Returns:
 1.) vArray[sub] - returns the element sub of the vArray data
 member (for the regular/non-constant subscript operator).
 
 Notes: In this method, we are writing code for a regular/non-constant
 subscript operator, earlier in this program, we wrote code for a
 constant subscript operator (above).
 ***************************************************************/
double& VectorN::operator[](int sub)
{
    return vArray[sub];     // Return element sub of the array data member.
}


/***************************************************************
 Function: operator==() (boolean equals to operator)
 
 Use: We are using this method to return false if any element of
 the left operand is not equal to it's corresponding element in the
 right operand; and if all elements of the left operand are equal to
 their corresponding right operand elements, then we are going to
 return true.
 
 Parameters:
 1.) The one and only parameter for this method is a reference to
 a constant VectorN object, representing the right operand of the
 vector relational expression (also, we are using the this pointer
 concept to refer to the left operand of the relational expression).
 
 Returns:
 1.) This method returns a boolean value of either true or false
 (so basically 3 return (2 false and 1 true) statements based on
 the things that we are trying to search for from the vectors and
 their capacities).
 
 Notes: This boolean method returns true if all elements of the
 left operand are equal to their corresponding right operand elements.
 We could have coded this in many different ways by switching the
 return values around.
 ***************************************************************/
bool VectorN::operator==(const VectorN& rightOperand) const
{
    if (this-> vCapacity != rightOperand.vCapacity)
    {
        return false;     // Returning false if the left and the right operand capacities are not equal.
    }
    else
    {
    
        for (size_t i = 0; i < this-> vCapacity; i++)
        {
            
            if (this-> vArray[i] != rightOperand.vArray[i])
            {
        // Returning false if any element of the left operand is not equal to it's corresponding element in the right operand.
                return false;
            }
        
        }
        // Returning true if all elements of the left operand are equal to their corresponding right operand elements.
        return true;
    }
}


/***************************************************************
 Function: at() (constant exception handler)
 
 Use: We are using the constant exception handler as a different
 variant of the read-only version of operator[] that provides some
 simple error checking (for all the elements).
 
 Parameters:
 1.) sub - This is sub, which is basically representing the interger
 subscript for all of the vArray elements in the vector (for the
 constant exception handler).
 
 Returns:
 1.) vArray[sub] - returns the element sub of the vArray data
 member (for the constant exception handler).
 
 Notes: In this method, we are writing code for a constant exception
 handler, later in this program we will also be writing code for
 a regular/non-constant exception handler (below).
 ***************************************************************/
double VectorN::at(int sub) const
{
    if (sub < 0 || sub >= (int)vCapacity)     // Type casting vCapacity so it compares well with sub.
    {
        throw out_of_range("subscript out of range");     // We are throwing an out_of_range exception (const).
    }
    else
    {
        return vArray[sub];     // Return element sub of the array data member.
    }
}


/***************************************************************
 Function: at() (regular/non-constant exception handler)
 
 Use: We are using the regular/non-constant exception handler as
 a different variant of the read and write version of operator[]
 that provides some simple error checking (for all the elements).
 
 Parameters:
 1.) sub - This is sub, which is basically representing the interger
 subscript for all of the vArray elements in the vector (for the
 regular/non-constant exception handler).
 
 Returns:
 1.) vArray[sub] - returns the element sub of the vArray data
 member (for the regular/non-constant exception handler).
 
 Notes: In this method, we are writing code for a regular/non-constant
 exception handler, earlier in this program, we wrote code for
 a constant exception handler (above).
 ***************************************************************/
double& VectorN::at(int sub)
{
    if (sub < 0 || sub >= (int)vCapacity)     // Type casting vCapacity so it compares well with sub.
    {
        throw out_of_range("subscript out of range");     // We are throwing an out_of_range exception (non-const).
    }
    else
    {
        return vArray[sub];     // Return element sub of the array data member.
    }
}
