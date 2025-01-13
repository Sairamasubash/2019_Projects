/***********************************************************
 CSCI 340 - Assignment 5 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Monday, October 21, 2019
 
 Purpose: The purpose of this computer assignment is to write
 and implement a C++ program that will simulate and solve the
 josephus problem. The program starts with a group of people
 of size N greater than or equal to 1 that are standing in a
 circle waiting to be eliminated/removed. Also, the counting
 starts at a certain point in the circle and goes around the
 circle in a certain direction (this process continues until
 only one person in the group remains).
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "prog5.h"


/* This main() function simply starts of by creating/initializing a list container called inputWords, a
   structure variable called inputValues, and an unsigned integer variable called cnt. Then, this main()
   function calls the init_vals() function by passing in the list container inputNames and the structure
   variable inputValues as arguments; and it also calls the print_list() function by passing in the list
   container inputNames and the unsigned integer variable cnt as arguments. Finally, this function does an
   algorithm to locate the M-th person in the list, and removes that person from the list by using the erase()
   function in STL; and this function calls the print_list() function again (in an if statement) by passing
   in the list container inputNames and the unsigned integer variable cnt as arguments to print out the
   current/new names in the list (this algorithm also requires some additional variables such as i, p, and j). */
int main()
{
    
    // Declaring a local list container called inputNames which will hold all the names that we will get after calling the init_vals() function.
    list <string> inputNames;
    
    // Declaring a local structure variable called inputValues which will hold all the vlaues that are passed in as command line arguments.
    args inputValues;
    
    // Creating a local variable of type unsigned integer called cnt (and initializing cnt to 0 for now) to act as a counter for the current number of removals.
    unsigned cnt = 0;
    
    init_vals(inputNames, inputValues);
    
    print_list(inputNames, cnt);
    
    // Creating a local variable of type integer called i to hold the position of a certain person in the list container called inputNames.
    int i = 0;
    
    while (inputNames.size() > 1)
    {
        cnt++;
        
        // Creating a local list iterator called p; we need this iterator p to hold the value of the first element of the list container called inputNames.
        auto p = inputNames.begin();
        
        // Creating a local variable of type integer called j to hold the position of the M-th person from the position i (which is initialized above).
        int j = (i + inputValues.M - 1) % inputNames.size();
        
        advance(p, j);
        
        inputNames.erase(p);
        
        i = j;
        
        if(cnt % inputValues.K == 0 || inputNames.size() == 1)
        {
            print_list(inputNames, cnt);
        }
    }
    
    return 0;
    
}


/* This init_vals() function starts of by reading the input values N, M and K of the structure variable
   (args in) when the program prompts/asks for them. Then this function prints these values out to the
   standard output. Finally, to store the names in an empty list, this init_vals() function resizes the
   list container L to in.N using the resize() function in STL; and then this function uses the generate()
   function in STL to generate the names in the list container L (with the last argument being the function
   object SEQ(N)). */
void init_vals(list <string> &L, args &in)
{
    
    cin >> in.N;
    cin >> in.M;
    cin >> in.K;
    
    cout << "Number of people? " << in.N << endl;
    
    cout << "Index for elimination? " << in.M << endl;
    
    cout << "Index for printing? " << in.K << endl << endl;
    
    L.resize(in.N);
    
    generate(L.begin(), L.end(), SEQ(in.N));
    
}


/* This print_list() function prints out the contents of the list container L at the beginning and after
   removing K names everytime from the list, until exactly one name remains in the list. Also, in this
   function the unsigned integer variable cnt has an initial value of 0 (cnt indicates the total number of
   removals so far); plus, this function prints the name of the last person in the list container L (at the
   very end). Finally, this print_list() function prints exactly 12 names (NO_ITEMS) on a single line
   (except maybe the last line), where the names are separated by single spaces. */
void print_list(const list <string> &L, const unsigned &cnt)
{
    
    // Declaring a local variable called count which acts as a counter for the number of names that are printed on a single line (in the output).
    int count = 1;
    
    if (cnt < 1)
    {
        cout << "Initial group of people" << endl << "-----------------------" << endl;
    }
    else
    {
        cout << endl;
        
        cout << "After eliminating " << cnt << "th person" << endl << "-----------------------------" << endl;
    }
    
    for (auto i = L.begin(); i != L.end(); i++)
    {
        cout << *i << ' ';
        
        if (count % NO_ITEMS == 0)
        {
            cout << endl;
        }
        
        count++;
    }
    
    cout << endl;
    
}
