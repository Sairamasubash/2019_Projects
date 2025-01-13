/****************************************************************
 FILE:      Stack.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  April 11, 2019
 
 PURPOSE:   The purpose of the Stack.h file is to create a class
 called Stack that contains the data members, constructors, destructors,
 friend finctions, and methods requried by this program. Since this is
 a C++ template, we are also coding the definitions for all the methods,
 constructors, destructors, and friend finctions in this header file,
 instead of coding them in another source code file.
 ****************************************************************/

// Here are the beginning header guards for the Stack.h file.
#ifndef STACK_H
#define STACK_H

// Here is the library and the using statement that is required by this header file.
#include <iostream>

using namespace std;

// Forward declaration of the Stack template class.
template <class T>
class Stack;

// Forward declaration of the operator<< template function.
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>     // Start of the Stack template class.
class Stack
{
    // Declaring the template friend function that is needed for this program (with special syntax).
    friend ostream& operator<< <>(ostream&, const Stack<T>&);
    
private:     // Declaring the three private data members for the Stack template class.
    
    T* stackArray;
    size_t stackCapacity,
           stackSize;
    
public:     // Declaring the public methods, destructors, and constructors for the Stack template class.
    
    // Constructors and destructors
    Stack();
    ~Stack();
    Stack(const Stack<T>&);
    
    // Method prototypes
    Stack<T>& operator=(const Stack<T>&);
    void clear();
    size_t size() const;
    
    size_t capacity() const;
    bool empty() const;
    const T& top() const;
    
    void push(const T&);
    void pop();
    void reserve(size_t);

};     // End of the Stack template class.


/***************************************************************
 Function: Stack() - default constructor
 
 Use: We are using this Stack constructor to set the stackCapacity
 to 0, to set the stackSize to 0, and to set the stackArray pointer
 to the special value nullptr.
 
 Parameters: None
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is the Stack constructor that has no parameters, but
 there are times when you use parameters for constructors (non-
 default constructors).
 ***************************************************************/
template <class T>
Stack<T>::Stack()
{
    stackCapacity = 0;     // Setting stackCapacity to 0.
    stackSize = 0;     // Setting stackSize to 0.
    stackArray = nullptr;     // Setting stackArray to nullptr.
}


/***************************************************************
 Function: ~Stack() - destructor
 
 Use: We are using this Stack destructor to delete or deallocate
 the dynamic memory storage for the stack array (this time, we are
 not calling the clear() method to do this process, but that can
 also be done).
 
 Parameters: Destructors do not have any parameters.
 
 Returns: Destructors do not have a return data type.
 
 Notes: This is the Stack destructor; destructors are never const,
 they always start with a tilde (~), and they never have any parameters
 and returns data types.
 ***************************************************************/
template <class T>
Stack<T>::~Stack()
{
    delete [] stackArray;     // Deallocating the dynamic memory storage for the stackArray.
}


/***************************************************************
 Function: Stack() - copy constructor
 
 Use: We are using this Stack copy constructor to initialize a
 new Stack object to the same capacity, size, and array contents
 as the existing Stack object (called other). Also, in this constructor,
 we are allocating an array of items of the template parameter type
 (with the size of stackCapacity).
 
 Parameters:
 1.) other - We have a reference to a constant Stack object (other
 is used throughout this entire constructor).
 
 Returns: Constructors do no have a return data type.
 
 Notes: This is a special type of constructor: the copy constructor.
 There are many times that we can call a copy constructor, but one
 important time is when a new object is initialized with an existing
 object of the same class
 ***************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    stackCapacity = other.stackCapacity;     // Making stackCapacity equal to the capacity of the object other.
    stackSize = other.stackSize;     // Making stackSize equal to the size of the object other.
    
    if (stackCapacity == 0)     // Checking to see if stackCapacity is equal to 0.
    {
        stackArray = nullptr;     // Making stackArray equal to nullptr.
    }
    else
    {
        stackArray = new T[stackCapacity];     // Allocating an array of items of the template parameter type.
    }
    
    for (size_t i = 0; i < stackSize; ++i)
    {
        stackArray[i] = other.stackArray[i];     // Copying the contents of the object other into the stackArray.
    }
}


/***************************************************************
 Function: operator=() - overloaded copy assignment operator
 
 Use: We are using this Stack overloaded operator to assign one
 Stack object (the object called other) to another (the object
 that called the method, which is pointed to by this). In this
 operator, we are also using delete[] to deallocate the stackArray
 before the end of the program.
 
 Parameters:
 1.) other - We have a reference to a constant Stack object (other
 is used throughout this entire method).
 
 Returns:
 1.) The this pointer (*this) - which represents the left operand
 of the assignment statement.
 
 Notes: This is a special type of overloaded operator: overloaded copy
 assignment operator. This operator should be called when an existing
 object is assigned to another existing object of the same class.
 ***************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this == &other)     // Checking for self-assignment and returning the this pointer if they are equal.
    {
        return *this;
    }
    
    delete [] stackArray;     // Deallocating the dynamic memory storage for the stackArray.
    
    stackCapacity = other.stackCapacity;     // Making stackCapacity equal to the capacity of the object other.
    stackSize = other.stackSize;     // Making stackSize equal to the size of the object other.
    
    if (stackCapacity == 0)     // Checking to see if stackCapacity is equal to 0.
    {
        stackArray = nullptr;     // Making stackArray equal to nullptr.
    }
    else
    {
        stackArray = new T[stackCapacity];     // Once again, allocating an array of items of the template parameter type.
    }
    
    for (size_t i = 0; i < stackSize; ++i)
    {
        stackArray[i] = other.stackArray[i];     // Copying the contents of the object other into the stackArray.
    }
    
    return *this;     // Returning the this pointer.
}


/***************************************************************
 Function: operator<<() - stream insertion operator
 
 Use: We are using this friend function to print all of the elements
 of a stack (stackArray) separated by a space. The for loop to print
 the stackArray elements is being done inside of an if statement
 because we don't print out anything (just blank white space) if the
 stackSize is equal to 0 (or empty).
 
 Parameters:
 1.) leftOperand - The first parameter for this function is a reference
 to an ostream object, representing the left operand of the stream
 insertion expression.
 2.) rightOperand - The second parameter for this function is a reference
 to a constant Stack object, representing the right operand of the stream
 insertion expression.
 
 Returns:
 1.) leftOperand - This function returns a reference to an ostream object
 (basically the first parameter).
 
 Notes: This is friend function, that means that it is not a method
 that is a part of the Stack class, but it can still access the
 private data members in the Stack class (that is allowed because
 of the keyword friend).
 ***************************************************************/
template <class T>
ostream& operator<<(ostream& leftOperand, const Stack<T>& rightOperand)
{
    // Checking to see if the stackSize (of the rightOperand) is equal to 0; and not printing anything if it is.
    if (rightOperand.stackSize == 0)
    {
        
    }
    else
    {
        // Printing the elements of the stackArray if the stackSize (of the rightOperand) is not equal to 0 (separated by a space).
        for (size_t i = 0; i <= (rightOperand.stackSize - 1); i++)
        {
            leftOperand << rightOperand.stackArray[i] << " ";     // Using the leftOperand as a regular cout statement.
        }
    }
    
    return leftOperand;     // Returning the leftOperand.
}


/***************************************************************
 Function: clear()
 
 Use: We are using this clear method to set the stackSize back to
 0. Also, we are not using this method to change the stackCapacity,
 or the stackArray (just the stackSize).
 
 Parameters: None
 
 Returns: none
 
 Notes: In the previous assignment (assignment 5), the clear method
 was called by the destructor. In this assignment, this method is
 used differently and it is not called by the destructor.
 ***************************************************************/
template <class T>
void Stack<T>::clear()
{
    stackSize = 0;     // Setting the stackSize back to 0.
}


/***************************************************************
 Function: size()
 
 Use: We are simply using this size method to return the number of
 elements that are in a given stack (number of elements in the
 stackArray), which is equal to the stackSize. Plus, this method
 is a const so that the stack values will not change no matter what
 happens.
 
 Parameters: None
 
 Returns:
 1.) stackSize - which is basically returning the number of
 elements that are contained in the stack (or the stackArray).
 
 Notes: This method is unique because it returns an unsigned
 integer value (labeled as size_t); an unsigned integer value is
 not known and it cannot be a negative integer.
 ***************************************************************/
template <class T>
size_t Stack<T>::size() const
{
    return stackSize;     // Returning the stackSize.
}


/***************************************************************
 Function: capacity()
 
 Use: We are simply using this capacity method to return the number
 of elements that a given stack can hold (number of elements that
 the stackArray can hold), which is equal to the stackCapacity. Plus,
 this method is a const so that the stack values will not change no
 matter what happens.
 
 Parameters: None
 
 Returns:
 1.) stackCapacity - which is basically returning the number of
 elements that a stack (or the stackArray) can hold.
 
 Notes: This method is also unique because it also returns an unsigned
 integer value (labeled as size_t); an unsigned integer value is
 not known and it cannot be a negative integer (also stated above).
 ***************************************************************/
template <class T>
size_t Stack<T>::capacity() const
{
    return stackCapacity;     // Returning the stackCapacity.
}


/***************************************************************
 Function: empty()
 
 Use: We are using this empty method to check and see if the stackSize
 is equal to 0; and returning either true (if it is equal to 0) or false
 (if it is not equal to 0).
 
 Parameters: None
 
 Returns:
 1.) true - returns true if the stackSize is equal to 0.
 2.) flase - returns false if the stackSize is not equal to 0.
 
 Notes: This empty method returns a boolean value - of either true
 or false. True is returned if what we are checking for is correct;
 and false is returned if what we are checking for is incorrect
 ***************************************************************/
template <class T>
bool Stack<T>::empty() const
{
    if (stackSize == 0)     // Checking to see if stackSize is equal to 0.
    {
        return true;     // Returning true if it is.
    }
    else
    {
        return false;     // Returning false if it is not.
    }
}


/***************************************************************
 Function: top()
 
 Use: We are using this top method to return the top element of
 the stackArray (the one at the subscript stackSize - 1). We are
 also assuming that this method will not be called if the stack
 is empty (has no elements).
 
 Parameters: None
 
 Returns:
 1.) stackArray[stackSize -1] - returns the top element of the stack
 (or the stackArray).
 
 Notes: This method is useful when we just want to see what the
 top element of the stackArray is, and when we don't really care
 about all the other elements in the stackArray.
 ***************************************************************/
template <class T>
const T& Stack<T>::top() const
{
    return stackArray[stackSize - 1];
}


/***************************************************************
 Function: push()
 
 Use: We are using this push method to increase the capacity of the
 stackArray and to make room for more values to be inserted. We are
 doing this by calling the reserve method multiple times inside of
 an if statement.
 
 Parameters:
 1.) value - which is basically a reference to a constant item of
 the template parameter type.
 
 Returns: none
 
 Notes: This push method is very different from the pop method
 (below) because this method increments/increases the stackCapacity
 when necessary, and the pop method decrements the stackSize by 1.
 ***************************************************************/
template <class T>
void Stack<T>::push(const T& value)
{
    if (stackSize == stackCapacity)     // Checking to see if stackSize is equal to stackCapacity.
    {
        if (stackCapacity == 0)     // Checking to see if stackCapacity is equal to 0.
        {
            // Passing a new capacity of 1 to the reserve method if the stackCapacity is equal to 0.
            reserve(1);
        }
        else
        {
            // Passing a new capacity of twice the current stackCapacity to the reserve method if stackCapacity is not equal to 0.
            reserve(stackCapacity * 2);
        }
    }
    
    // copying the value to be inserted into the stackArray (while incrementing the stackArray[stackSize] by 1).
    stackArray[stackSize++] = value;
}


/***************************************************************
 Function: pop()
 
 Use: We are using this pop method to decrement the stackSize by
 1, which basically removes the top (or last) value from the stackArray.
 Once again, we are assuming that this method will not be called if
 the stack is empty (has no elements).
 
 Parameters: None
 
 Returns: none
 
 Notes: This pop method is very different from the push method
 (above) because this method decrements the stackSize by 1, and
 the push method increments/increases the stackCapacity when necessary.
 ***************************************************************/
template <class T>
void Stack<T>::pop()
{
    --stackSize;     // Decrementing the stackSize by one.
}


/***************************************************************
 Function: reserve()
 
 Use: We are using this reserve method to increase the capacity
 of the stackArray (so basically, this method serves as a helper
 method that will be used/called two times in the push method; and
 most of the code is written in this method).
 
 Parameters:
 1.) newCapacity - which is basically the new capacity of the stack
 (or the stackArray).
 
 Returns: none - we never return any data member (or anything in general),
 but we do use the keyword return.
 
 Notes: This method is vary important because it is needed for the
 push method. The push method (above) called this reserve method
 two times inside of an if statement to increase the capacity of
 the stackArray.
 ***************************************************************/
template <class T>
void Stack<T>::reserve(size_t newCapacity)
{
    // Checking to see if newCapacity is less than stackSize or equal to stackCapacity.
    if (newCapacity < stackSize || newCapacity == stackCapacity)
    {
        return;     // Using the keyword return just as itself.
    }
    
    stackCapacity = newCapacity;     // Setting stackCapacity equal to newCapacity.
    
    T* tempArray;     // Declaring a temporary array pointer.
    
    if (stackCapacity == 0)     // Checking to see if stackCapacity is equal to 0.
    {
        tempArray = nullptr;     // Setting tempArray to nullptr.
    }
    else
    {
        tempArray = new T[newCapacity];     // Allocating an array of items of the template parameter type (using tempArray).
    }
    
    for (size_t i = 0; i < stackSize; ++i)
    {
        tempArray[i] = stackArray[i];     // Copying the contents of stackArray into the tempArray.
    }
    
    delete [] stackArray;     // Deleting the stack array.
    stackArray = tempArray;     // Setting stackArray equal to tempArray.
}

#endif      // Ending header guard for the Stack.h file.
