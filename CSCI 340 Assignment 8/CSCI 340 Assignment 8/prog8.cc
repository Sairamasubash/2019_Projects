/***********************************************************
 CSCI 340 - Assignment 8 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Monday, November 18, 2019
 
 Purpose: The purpose of this computer assignment is to write
 a C++ program that sorts items in several input files, using
 the heapsort technique. This program first reads some items
 from the input files and builds a heap structure for those
 items. Then, it retrieves those items from the heap structure
 in a certain order and prints them out on the standard output.
 Also, the full path names of the input files, certain constant
 definitions, and the prototypes of the template functions are
 included in the header file prog8.h (which is provided to us
 by the instructor).
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "prog8.h"


/* This main() function simply starts of by creating/initializing three vector containers called
   v1 (of type integers), v2 (of type floating-point numbers), and v3 (of type strings). Then, this
   function also creates three heaps (in both ascending order, and descending order) using the help
   of the four functions that are implemented just under this main() function. Two of these functions
   are actual stand alone functions, and the other two functions are public methods of the print_list
   template class. Finally, the prog8.h header file and this main() function are not implementd by me,
   they are both provided to us by the instructor. */
int main()
{
    
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings
    
    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";
    
    // first heap
    
    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    // second heap
    
    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    // third heap
    
    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;

}


/* This get_list() finction simply starts of by creating/declaring a template variable called
   inputFileItems and an ifstream variable called inputFiles. Then this get_list() finction opens
   one of the files and clears the vector v. Also, this function reads the items from the input file
   and inserts them into the vector v. Finally, this get_list() finction finishes of by closing the
   previously opened input file. */
template <typename T>
void get_list(vector <T> &v, const char *path)
{
    
    // Creating a local template variable called inputFileItems which represents the items/values in the three input files.
    T inputFileItems;
    
    // Declaring a local ifstream variable called inputFiles which is used to open, work with, and close the three input files.
    ifstream inputFiles;
    
    inputFiles.open(path);
    
    v.clear();
    
    while (inputFiles >> inputFileItems)
    {
        v.push_back(inputFileItems);
    }
    
    inputFiles.close();
    
}


/* This construct_heap() finction simply starts of by calling the make_heap() function from the STL
   by passing in the beginning position of the vector (called v), the ending position of the vector
   (called v), and the predicate (called pred) as arguments. Then, this construct_heap() function
   finishes of by calling the sort_heap() function from the STL by passing in the beginning position
   of the vector (called v), the ending position of the vector (called v), and the predicate (called
   pred) as arguments. */
template <typename T, typename P>
void construct_heap(vector <T> &v, P pred)
{
    
    make_heap(v.begin(), v.end(), pred);
    
    sort_heap(v.begin(), v.end(), pred);
    
}


/* This print_list() constructor simply does four things. First, this print_list() constructor sets
   the actual heap size (sz) equal to s. Then, this print_list() constructor sets the minimum number
   of characters written in printout (wid) equal to w. After that, this print_list() constructor sets
   the maximum number of items printed in a single line (len) equal to l. Finally, this print_list()
   constructor sets the counter for the number of items per line (cnt) equal to c. */
template <typename T>
print_list<T>::print_list(const unsigned &s, const unsigned &w, const unsigned &l, const unsigned &c)
{
    
    sz = s;
    wid = w;
    len = l;
    cnt = c;
    
}


/* This public operator() method simply prints the item x of a heap on to the standard output. Also,
   this operator() method prints the amount of items per line where cnt % len != 0 (except maybe the
   last line). Finally, to get the correct formatting in the standard output, this operator() method
   inserts statements at the beginning to declare things such as the width, and the precision (using
   the keywords fixed, and showpoint as well). */
template <typename T>
void print_list<T>::operator() (const T& x)
{
    
    cout.width(wid);
    cout.precision(2);
    cout << fixed << showpoint;
    
    cout << x << ' ';
    
    cnt++;
    
    if(cnt % len == 0 || cnt == sz)
    {
        cout << endl;
    }
    
    if (cnt == sz)
    {
        cout << endl;
    }

}

