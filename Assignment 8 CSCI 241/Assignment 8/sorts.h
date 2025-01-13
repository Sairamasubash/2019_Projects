/****************************************************************
 FILE:      sorts.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  April 25, 2019
 
 PURPOSE:   The purpose of the sorts.h header file is to write a
 number of C++ template functions to read a series of items from an
 input file, and then to print these items in/for the output. In
 this sorts.h header file, we have 4 functions (with 4 function
 prototypes, and with 4 function definitions). We also have included
 the appropriate header guards for the sorts.h header file.
 ****************************************************************/

// Here are the beginning header guards for the sorts.h header file.
#ifndef SORTS_H
#define SORTS_H

// Here is the library and the using statement that is required by this sorts.h header file.
#include <fstream>

using namespace std;

// Here are all of the function prototypes for all of the functions implemented in this sorts.h header file.
template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);


/***************************************************************
 Function: buildList()
 
 Use: We are using this builtList() function to open the data files
 for input, then to read the items from the files using the >> operator
 one at a time until the end of file (also, inserting them into the
 vector), and finally, we are closing the input file (after everything
 has been read).
 
 Parameters:
 1.) set - This is a reference to a vector object that will be used
 to store the data items.
 2.) fileName - This is a C-style string containing the full pathname
 of the input files (files that are passed in).
 
 Returns: none
 
 Notes: This buildList() function requires us to use the fstream
 library function because in this function, we are declaring an
 fstream variable called inFile to do the opening, reading, and
 closing of the input files.
 ***************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
    
    // Declaring all the variables required for this buildList() function.
    T item;
    ifstream inFile;
    
    inFile.open(fileName);     // Opening the input file.
    
    // Checking to see if the file opened successfully, if not, we are printing an error message and exiting.
    if (!inFile)
    {
        cout << "Unable to open the input file: " << fileName << endl;
        exit(1);
    }
    
    inFile >> item;     // Reading the data items from the input file.
    
    while (inFile)     // Here is a loop that will continue until there are no items in the input file.
    {
        set.push_back(item);
        
        inFile >> item;     // Reading the data items from the input file.
    }
    
    inFile.close();     // Closing the input file.
    
}


/***************************************************************
 Function: printList()
 
 Use: We are using this printList() function to print the list of
 items stored in a vector. The items stored in the vector are the
 the items that we got from reading the input files using the
 buildList() function (above).
 
 Parameters:
 1.) set - This is a reference to a constant vector object that will
 contain the items to print.
 2.) itemWidth - This is an integer specifying the width an individual
 item should occupy when printed.
 3.) numPerLine - is an integer specifying the maximum number of items
 that should be printed in a single line of output.
 
 Returns: none
 
 Notes: So basically this printList() function is like a formatting
 tool for the data items that we will be printing in the outout
 because we are setting the width of the output data and we are
 also setting the number of data items per line.
 ***************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    
    int i = 0;     // Setting the integer i to 0;
    
    // Here is the loop that specifies the width an individual item should occupy when printed.
    while (i < (int) set.size())
    {
        cout << setw(itemWidth) << set[i] << ' ';     // Using setw to set the width of a data item.
        
        i++;     // Incrementing the integer i by 1;
        
        if (i % numPerLine == 0)     // Checking to see if the integer i divided by numPerLine is equal to 0.
        {
            cout << endl;
        }
    }
    
    if (i % numPerLine != 0)     // Checking to see if the integer i divided by numPerLine is not equal to 0.
    {
        cout << endl;
    }
    
}


/***************************************************************
 Function: lessThan()
 
 Use: We are using this lessThan() function to return true if item1
 is less than item2, and false if it is not (this is a lessThan()
 function, there is also a greaterThan() function that we will be
 implementing in this program (below)).
 
 Parameters:
 1.) item1 - This is a reference to a constant item of the template
 parameter type for the lessThan() function.
 2.) item2 - This is also a reference to a constant item of the
 template parameter type for the lessThan() function.
 
 Returns:
 1.) true - This lessThan() function returns true if item1 is less
 than item 2.
 2.) false - This lessThan() function returns false if item1 is not
 less than item2.
 
 Notes: This lessThan() function returns a boolean value - of either
 true or false. True is returned if what we are checking for is
 correct; and false is returned if what we are checking for is
 incorrect
 ***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
    
    if (item1 < item2)     // Checking to see if item1 is less than item2.
    {
        return true;     // Returning true
    }
    else
    {
        return false;     // Returning false
    }
    
}


/***************************************************************
 Function: greaterThan()
 
 Use: We are using this greaterThan() function to return true if
 item1 is greater than item2, and false if not (this is a greaterThan()
 function, there is also a lessThan() function that we had already
 implemented in this program (above)).
 
 Parameters:
 1.) item1 - This is a reference to a constant item of the template
 parameter type for the greaterThan() function.
 2.) item2 - This is also a reference to a constant item of the
 template parameter type for the greaterThan() function.
 
 Returns:
 1.) true - This greaterThan() function returns true if item1 is greater
 than item 2.
 2.) false - This greaterThan() function returns false if item1 is not
 greater than item2.
 
 Notes: This greaterThan() function returns a boolean value - of either
 true or false. True is returned if what we are checking for is
 correct; and false is returned if what we are checking for is
 incorrect
 ***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
    
    if (item1 > item2)     // Checking to see if item1 is greater than item2.
    {
        return true;     // Returning true
    }
    else
    {
        return false;     // Returning false
    }
    
}

#endif     // Here is the ending header guard for the sorts.h header file.
