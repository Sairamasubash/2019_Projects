/***********************************************************
 CSCI 340 - Assignment 1 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Tuesday, September 10, 2019
 
 Purpose: The purpose of this computer assignment is to write
 a C++ program that generates random integers; the range of the
 random integers is between 1 and 10,000. Then, the randomly
 generated integers will be stored in a vector of size 200 (vector
 of integers). Finally, the randomly generated integers will be
 sorted in ascending order and they will be printed out to the
 standard output.
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "prog1.h"

const int VEC_SIZE = 200;     // Creating a global variable of type integer called VEC_SIZE (it is equal to 200).


/* This main() function is used to call the two functions (or subroutines) that are declared in the prog1.h file and
   initialized in the prog1.cc file. It is also used to sort out the randomly generated integers (in vector v) in
   ascending order using the sort() function. */
int main()
{
    
    vector <int> v;     // Creating a vector called v that can contain integers.
    
    genRndNums(v);     // Calling the genRndNums() function and passing the vector v in as an argument.
    
    sort(v.begin(), v.end());     // Using the sort() function to sort the vector v in ascending order.
    
    printVec(v);     // Calling the printVec() function and passing the vector v in as an argument.
    
    cout << endl;
    
    return 0;     // Returning a 0 to the output to make sure that the program ran perfectly (without any errors).

}


/* This genRndNums() function randomly generates 200 integers by calling the rand() function, and then it stores the randomly generated
   integers in the vector called v. This function also Initializes the random number generator (or the rand() function) by calling
   the srand() function with the seed value of 1 (SEED). */
void genRndNums(vector <int> &v)
{
    
    // Declaring are all the variables that are needed for this genRndNums() function.
//    const int LOW = 1;
//    const int HIGH = 10000;
    const int SEED = 1;
    
    // Calling the srand() function with the seed value of 1 (SEED).
    srand(SEED);
    
    // Using a for loop to store the 200 randomly generated integers in the vector called v by using the push_back() function.
    for (int i = 0; i < VEC_SIZE; i++)
    {
        // Using the rand() function and some mathematics to randomly generate the integers with the range being 1 (LOW) to 10,000 (HIGH).
        v.push_back(rand() % (HIGH - LOW + 1) + LOW);
    }
    
}


/* This printVec() function prints/displays the contents of vector v (which has the randomly generated integers in ascending order) on the
   standard output. This function prints exactly 12 numbers (NO_ITEMS) on a single line (except maybe the last line). Lastly, this function
   also properly aligns the sorted integers by keeping them to the right of the output and by having exactly 5 spaces (ITEM_W) between them. */
void printVec(const vector <int> &v)
{
    
    // Declaring are all the variables that are needed for this printVec() function.
    const int NO_ITEMS = 12;
    const int ITEM_W = 5;
    int count = 1;
    
    // Creating a for loop to print the 200 randomly generated integers in vector v on to the output.
    for (int i = 0; i < VEC_SIZE; i++)
    {
        // Printing the randomly generated integers in vector v to the right of the output, and using setw() to allow 5 spaces between each integer.
        cout << right << setw(ITEM_W) << v[i];
        
        // Using an if statement to make sure that there are exactly 12 numbers on a single line in the output (except maybe the last line).
        if (count % NO_ITEMS == 0)
        {
            cout << endl;
        }
        
        count++;     // Incrementing the value of count by one.
    }
    
}
