/***********************************************************
 CSCI 241 - Assignment 6 - Spring 2019
 
 Progammer: Sairamasubash Muppalaneni
 My programming partner: Alenna Ahmad
 Z-ID: Z1844762
 My partners Z-ID: Z1858089
 Section: 1
 TA: Rahul Reddy Gopu
 Date Due: April 11, 2019
 
 Purpose: The purpose of this program is to get some exercise
 with implementing/using the Stack ADT with a dynamically-allocated
 array (using templates). Also, in this program, we are gaining
 more exercise on managing dynamically-allocated storage in C++.
 ************************************************************/

// Here are all of the libraries and header files that are needed for this program.
#include <iostream>
#include "Stack.h"

// Here are all of the using statements that are needed for this file.
using std::cout;
using std::endl;


/***************************************************************
 Function: main
 
 Use: We are using this function to declare all the stacks (arrays
 of type integer) that we need for this program; and also to call
 all the methods, constructors, destructors, and friend functions
 that are in the Stack.h file (in total, there are 13 of these in
 the Stack.h file).
 
 Parameters: none
 
 Returns: (1.) return 0 - whenever we get the return value of 0 in
 the output, we can then confirm that our program was successful.
 
 Notes: We are doing a lot of cout statements in this main function
 because all of the other code is done in the Stack.h file. Also,
 these cout statements contain a lot of sizes and capacities of
 multiple different stacks used in this program.
 ***************************************************************/
int main()     // Start of the main finction.
{
    cout << "Testing default constructor\n\n";
    
    Stack<int> s1;
    
    cout << "s1: " << s1 << endl;
    cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
    cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing push()\n\n";
    
    for (int i = 10; i < 80; i+= 10)
        s1.push(i);
    
    cout << "s1: " << s1 << endl;
    cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
    cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    for (int i = 15; i < 85; i+= 10)
        s1.push(i);
    
    cout << "s1: " << s1 << endl;
    cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
    cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing copy constructor()\n\n";
    
    Stack<int> s2 = s1;
    
    cout << "s1: " << s1 << endl;
    cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
    cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing top()\n\n";
    
    cout << "Top item of s1: " << s1.top() << endl << endl;
    
    cout << "Testing pop()\n\nTop item of s1: ";
    
    while (!s1.empty())
    {
        cout << s1.top() << ' ';
        s1.pop();
    }
    
    cout << endl << endl;
    cout << "s1: " << s1 << endl;
    cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
    cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing assignment operator\n\n";
    
    Stack<int> s3;
    
    s3 = s2;
    
    cout << "s2 (size " << s2.size() << "): " << s2 << endl;
    cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
    cout << "Testing clear()\n\n";
    
    s2.clear();
    
    cout << "s2: " << s2 << endl;
    cout << "s2 size: " << s2.size() << ", capacity: " << s2.capacity() << endl;
    cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "s3: " << s3 << endl;
    cout << "s3 size: " << s3.size() << ", capacity: " << s3.capacity() << endl;
    cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing assignment to self and swap\n\n";
    
    s3 = s3;
    s2 = s3;
    s3.clear();
    
    cout << "s2 (size " << s2.size() << "): " << s2 << endl;
    cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
    cout << "Testing chained assignment\n\n";
    
    Stack<int> s4;
    
    s4 = s3 = s2;
    
    cout << "s2 (size " << s2.size() << "): " << s2 << endl;
    cout << "s3 (size " << s3.size() << "): " << s3 << endl;
    cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;
    
    Stack<int> s5 = s4;
    
    cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;
    
    
    cout << "Testing other data type\n\n";
    
    Stack<char> s6;
    
    for (char c = 'a'; c < 'k'; c++)
        s6.push(c);
    
    cout << "s6 (size " << s6.size() << "): " << s6 << endl << endl;
    
    cout << "Testing const correctness\n\n";
    
    const Stack<char>& r6 = s6;
    
    cout << "s6: " << r6 << endl;
    cout << "s6 size: " << r6.size() << ", capacity: " << r6.capacity() << endl;
    cout << "s6 is " << ((r6.empty()) ? "empty\n" : "not empty\n");
    cout << "Top item of s6: " << r6.top() << endl;
    
    Stack<char> s7 = r6;
    
    cout << "s7: " << s7 << endl;
    
    s7.clear();
    
    cout << "s7: " << s7 << endl;
    
    s7 = r6;
    
    cout << "s7: " << s7 << endl;
    
    return 0;     // Returning 0 to see if the program ran successfully.
    }     // End of the main function.
