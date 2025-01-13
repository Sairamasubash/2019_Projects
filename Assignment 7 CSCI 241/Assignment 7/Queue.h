/****************************************************************
 FILE:      Queue.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  April 18, 2019
 
 PURPOSE:   The purpose of the Queue.h file is to create a class
 called Queue, and a structure called Node; these contains the data
 members, constructors, destructors, friend finctions, and methods
 requried by this program. Since this is a C++ template, we are also
 coding the definitions for all the methods, constructors, destructors,
 and friend finctions in this header file, instead of coding them in
 another source code file.
 ****************************************************************/

// Here are the beginning header guards for the Queue.h file.
#ifndef QUEUE_H
#define QUEUE_H

// Here are the libraries and the using statements that are required by this header file.
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>     // Start of the Node template structure.
struct Node
{
    // Declaring the two puplic data members for the Node template structure.
    T dataItem;
    Node<T>* next;
    
    Node(const T& = T(), Node<T>* next = nullptr);     // Node constructor prototype (only prototype needed for this structure).
};     // End of the Node template structure.


/***************************************************************
 Function: Node() - non-default constructor
 
 Use: We are using this Node constructor to set the newDataItem
 value as the original dataItem value; and to set the newNext value
 as the original next value.
 
 Parameters:
 1.) newDataItem - This is a reference to a const template parameter
 type (representing the the new data item passed in to the queue).
 2.) newNext - Basically, this is a pointer to a Node (representing
 the new next value inside of the queue).
 
 Returns: Constructors do not have a return data type.
 
 Notes: We are using the this pointer to represent the original
 dataItem and to represent the original next (also, this constructor
 basically works a copying tool for different values in the queue).
 ***************************************************************/
template <class T>
Node<T>::Node(const T& newDataItem, Node* newNext)
{
    this-> dataItem = newDataItem;     // Setting the newDataItem value as the original dataItem value.
    this-> next = newNext;     // Setting the newNext value as the original next value.
}

// Forward declaration of the Queue template class.
template <class T>
class Queue;

// Forward declaration of the operator<< template function.
template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>     // Start of the Queue template class.
class Queue
{
    // Declaring the template friend function that is needed for this program (with special syntax).
    friend ostream& operator<< <>(ostream&, const Queue<T>&);
    
private:     // Declaring the three private data members for the Queue template class.
    
    Node<T>* qFront;
    Node<T>* qBack;
    size_t qSize;
    
public:     // Declaring the public methods, destructors, and constructors for the Queue template class.
    
    // Constructors and destructors
    Queue();
    ~Queue();
    Queue(const Queue<T>&);
    
    // Method prototypes
    Queue<T>& operator=(const Queue<T>&);
    void clear();
    size_t size() const;
    
    bool empty() const;
    const T& front() const;
    const T& back() const;
    
    void push(const T&);
    void pop();
    
};     // End of the Queue template class.


/***************************************************************
 Function: Queue() - default constructor
 
 Use: We are using this Queue constructor to set the qFront pointer
 to the special value-nullptr, to set the qBack pointer to the special
 value-nullptr, and to set the qSize to 0.
 
 Parameters: None
 
 Returns: Constructors do not have a return data type.
 
 Notes: This is a Queue constructor that has no parameters, but
 there are many times when you use parameters for constructors
 (non-default constructors).
 ***************************************************************/
template <class T>
Queue<T>::Queue()
{
    qFront = nullptr;     // Setting qFront to nullptr.
    qBack = nullptr;     // Setting qBack to nullptr.
    qSize = 0;     // Setting qSize to 0.
}


/***************************************************************
 Function: ~Queue() - destructor
 
 Use: We are using this Queue destructor to call the clear() method
 which will properly set the queue back to an empty state (this time,
 we are calling the clear() method to do this process; but this
 process can also be done in the destructor).
 
 Parameters: Destructors do not have any parameters.
 
 Returns: Destructors do not have a return data type.
 
 Notes: This is the Queue destructor; and destructors are never const,
 they start with a tilde (~), and they never have any parameters or
 return data types.
 ***************************************************************/
template <class T>
Queue<T>::~Queue()
{
    clear();     // Calling the clear() method.
}


/***************************************************************
 Function: Queue() - copy constructor
 
 Use: We are using this Queue copy constructor to copy the dataItems
 of the queue object called other into the original queue object.
 Also, in this constructor, we are properly setting the queue back
 to an empty state (by setting the qFront and the qBack pointers
 to the special value-nullptr, and setting the qSize to 0).
 
 Parameters:
 1.) other - We have a reference to a constant Queue object (other
 is used inside of a for-loop in this constructor).
 
 Returns: Constructors do no have a return data type.
 
 Notes: This is a special type of constructor: the copy constructor.
 There are many times that we can call a copy constructor, but one
 important time is when a new object is initialized with an existing
 object of the same class
 ***************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
    qFront = nullptr;     // Setting qFront to nullptr.
    qBack = nullptr;     // Setting qBack to nullptr.
    qSize = 0;     // Setting qSize to 0.
    
    Node<T>* pointer;     // Declaring a new pointer to a Node (to point to different values).
    
    // Here is a unique for-loop that goes through the entire queue object.
    for (pointer = other.qFront; pointer != nullptr; pointer = pointer-> next)
    {
        push(pointer-> dataItem);     // Pushing the dataItems of the queue object other into original queue object.
    }
}


/***************************************************************
 Function: operator=() - overloaded copy assignment operator
 
 Use: We are using this Queue overloaded copy assignment operator to
 check and see if the left queue object is equal to the other queue
 object. If they are equal, then we just return the this pointer; and
 if they are not equal, then we empty the left Queue object and copy
 the other Queue objects dataItems into the left queue object.
 
 Parameters:
 1.) other - We have a reference to a constant Stack object (other
 is also used inside of a for-loop in this method).
 
 Returns:
 1.) The this pointer (*this) - which represents the left operand
 of the assignment statement.
 
 Notes: This is a special type of overloaded operator: overloaded copy
 assignment operator. This operator should be called when an existing
 object is assigned to another existing object of the same class.
 ***************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if(this != &other)     // Checking for self-assignment and returning the this pointer if they are equal.
    {
        clear();     // Calling the clear() method.
        
        Node<T>* pointer;     // Declaring a new pointer to a Node (to point to different values).
        
        // Here is a unique for-loop that goes through the entire queue object.
        for (pointer = other.qFront; pointer != nullptr; pointer = pointer-> next)
        {
            push(pointer-> dataItem);     // Pushing the dataItems of the queue object other into left queue object.
        }
    }
    
    return *this;     // Returning the this pointer.
}


/***************************************************************
 Function: operator<<() - stream insertion operator
 
 Use: We are using this friend function to print all of the elements
 of a queue (containing integer values) separated by a space. The
 for loop to print the queue values goes through the queue until it
 reaches the end of the queue (which is represented by the special
 value-nullptr).
 
 Parameters:
 1.) leftOperand - The first parameter for this function is a reference
 to an ostream object, representing the left operand of the stream
 insertion expression.
 2.) rightOperand - The second parameter for this function is a reference
 to a constant Queue object, representing the right operand of the stream
 insertion expression.
 
 Returns:
 1.) leftOperand - This function returns a reference to an ostream object
 (basically the first parameter).
 
 Notes: This is friend function, that means that it is not a method
 that is a part of the Queue class, but it can still access the
 private data members in the Queue class (that is allowed because
 of the keyword friend).
 ***************************************************************/
template <class T>
ostream& operator<<(ostream& leftOperand, const Queue<T>& rightOperand)
{
    
    Node<T>* pointer;     // Declaring a new pointer to a Node (to point to different values).
    
    // Here is a unique for-loop that goes through the entire queue object.
    for (pointer = rightOperand.qFront; pointer != nullptr; pointer = pointer-> next)
    {
        leftOperand << pointer-> dataItem << " ";     // Using the leftOperand as a regular cout statement.
    }
    
    return leftOperand;     // Returning the leftOperand.
}


/***************************************************************
 Function: clear()
 
 Use: We are using this clear method to delete all of the nodes
 in the queue (by calling the pop() method), setting the qFront
 and the qBack pointers to the special value-nullptr, and setting
 the qSize back to 0
 
 Parameters: None
 
 Returns: none
 
 Notes: In the previous assignment (assignment 6), the clear() was
 not called by the destructor. In this assignment (assignment 7),
 the clear() method is called by the destructor (two different ways
 of implementing the destructor).
 ***************************************************************/
template <class T>
void Queue<T>::clear()
{
    while(!empty())     // Checking to see if the queue is not empty.
    {
        pop();     // Calling the pop() method.
    }
    
    qFront = nullptr;     // Setting qFront to nullptr.
    qBack = nullptr;     // Setting qBack to nullptr.
    qSize = 0;     // Setting qSize to 0.
}


/***************************************************************
 Function: size()
 
 Use: We are simply using this size() method to return the number
 of elements or the number of integer values that are inside of a
 given queue, which is equal to the qSize. Plus, this method is a
 const so that the queue values will not change no matter what
 happens.
 
 Parameters: None
 
 Returns:
 1.) qSize - which is basically returning the number of elements
 or the number of values that are contained inside the queue.
 
 Notes: This method is unique because it returns an unsigned
 integer value (labeled as size_t); an unsigned integer value is
 not known and it cannot be a negative integer.
 ***************************************************************/
template <class T>
size_t Queue<T>::size() const
{
    return qSize;     // Returning the qSize.
}


/***************************************************************
 Function: empty()
 
 Use: We are using this empty() method to check and see if the
 qSize is equal to 0; and returning either true (if it is equal to
 0) or false (if it is not equal to 0).
 
 Parameters: None
 
 Returns:
 1.) true - returns true if the qSize is equal to 0.
 2.) flase - returns false if the qSize is not equal to 0.
 
 Notes: This empty() method returns a boolean value - of either
 true or false. True is returned if what we are checking for is
 correct; and false is returned if what we are checking for is
 incorrect
 ***************************************************************/
template <class T>
bool Queue<T>::empty() const
{
    if (qSize == 0)     // Checking to see if the qSize is equal to 0.
    {
        return true;     // Returning true if it is.
    }
    else
    {
        return false;     // Returning false if it is not.
    }
}


/***************************************************************
 Function: front()
 
 Use: We are using this front() method to throw an underflow_error
 exception if the queue is empty; and if the queue is not empty, we
 are just returning the dataItem stored at the front of the queue.
 
 Parameters: None
 
 Returns:
 1.) qFront-> dataItem - which is basically the front dataItem
 of the queue object.
 
 Notes: This method is vary useful when we just want to see what
 the front value of the queue is, and when we don't really care
 about all the other elements in the queue.
 ***************************************************************/
template <class T>
const T& Queue<T>::front() const
{
    if (empty())     // Checking to see if the queue is empty.
    {
        // Throwing an underflow_error exception if the queue is empty.
        throw underflow_error("Queue underflow on front()");
    }
    else
    {
        return qFront-> dataItem;     // Returning the dataItem at the front of the queue.
    }
}


/***************************************************************
 Function: back()
 
 Use: We are using this back() method to throw an underflow_error
 exception if the queue is empty; and if the queue is not empty, we
 are just returning the dataItem stored at the back of the queue.
 
 Parameters: None
 
 Returns:
 1.) qBack-> dataItem - which is basically the back dataItem
 of the queue object.
 
 Notes: This method is vary useful when we just want to see what
 the back value of the queue is, and when we don't really care
 about all the other elements in the queue.
 ***************************************************************/
template <class T>
const T& Queue<T>::back() const
{
    if (empty())     // Checking to see if the queue is empty.
    {
        // Throwing an underflow_error exception if the queue is empty.
        throw underflow_error("Queue underflow on back()");
    }
    else
    {
        return qBack-> dataItem;     // Returning the dataItem at the back of the queue.
    }
}


/***************************************************************
 Function: push()
 
 Use: We are using this push() method to insert an dataItem to the
 back of the queue, and to increment the qSize by 1. Also, in this
 push() method, we are checking to see if the queue is empty or not
 by using an if statement.
 
 Parameters:
 1.) value - which is basically a reference to a constant item of
 the template parameter type.
 
 Returns: none
 
 Notes: This push() method is very different from the pop() method
 (below) because this method increments/increases the qSize by 1,
 and the pop() method decrements/decreases the qSize by 1.
 ***************************************************************/
template <class T>
void Queue<T>::push(const T& value)
{
    Node<T>* newNode;     // Creating a new newNode pointer.
    
    newNode = new Node<T>(value);
    
    if (empty())     // Checking to see if the queue is empty.
    {
        qFront = newNode;     // Setting the newNode pointer to qFront.
    }
    else
    {
        qBack-> next = newNode;     // Setting the newNode pointer to qBack, which is now the next value in the queue.
    }
    
    qBack = newNode;     // Setting the newNode pointer to qBack.
    
    ++qSize;     // incrementing the qSize by 1.
}


/***************************************************************
 Function: pop()
 
 Use: We are using this pop() method to throw an underflow_error
 exception if the queue is empty; and if the queue is not empty,
 we are removing a dataItem at the front of the queue and decrementing
 the qSize by 1.
 
 Parameters: None
 
 Returns: none
 
 Notes: This pop() method is very different from the push() method
 (above) because this method decrements/decreases the qSize by 1,
 and the push() method increments/increases the qSize by 1.
 ***************************************************************/
template <class T>
void Queue<T>::pop()
{
    if (empty())     // Checking to see if the queue is empty.
    {
        // Throwing an underflow_error exception if the queue is empty.
        throw underflow_error("Queue underflow on pop()");
    }
    else
    {
        Node<T>* deleteNode;     // Creating a new deleteNode pointer.
        
        deleteNode = qFront;     // Setting the deleteNode pointer to qFront.
        qFront = qFront-> next;     // Setting qFront as the next value in the queue.
        
        delete deleteNode;     // Deleting the deleteNode pointer.
       
        --qSize;     // decrementing the qSize by 1.
    }
}

#endif     // Ending header guard for the Queue.h file.
