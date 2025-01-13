/****************************************************************
 FILE:      quicksort.h
 
 AUTHOR:    Subash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  April 25, 2019
 
 PURPOSE:   The purpose of the quicksort.h header file is to write
 a number of C++ template functions to sort a list of items using
 the recursive quick sort algorithm. In this quicksort.h header file,
 we have 3 functions (with 3 function  prototypes, and with 3 function
 definitions). We also have included the appropriate header guards
 for the quicksort.h header file.
 ****************************************************************/

// Here are the beginning header guards for the quicksort.h header file.
#ifndef QUICKSORT_H
#define QUICKSORT_H

// Here are all of the function prototypes for all of the functions implemented in this quicksort.h header file.
template <class T> void quickSort(vector<T>&, bool (*)(const T&, const T&));
template <class T> void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));
template <class T> int partition(vector<T>&, int, int, bool (*)(const T&, const T&));


/***************************************************************
 Function: quickSort() - non-recursive
 
 Use: We are using this non-recursive quickSort() function to simply
 call the recursive quick sort function; while passing it the vector,
 the subscript of the first vector element (which is 0), the subscript
 of the last vector element (which is set.size() - 1), and the pointer
 to the comparison function (compare).
 
 Parameters:
 1.) set - This is a reference to a vector object containing the list
 of items to sort for the non-recursive quickSort() function.
 2.) compare - This is a pointer to a comparison function that can be
 used to compare two items of the template type for the non-recursive
 quickSort() function.
 
 Returns: none
 
 Notes: To make the recursive quick sort algorithm work, we need
 three finctions in total. We need the non-recursive quickSort()
 function, we need the recursive quickSort() function, and we need
 the partition() function (this is the first out of the three functions:
 the non-recursive quickSort() function.
 ***************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    quickSort(set, 0, set.size()-1, compare);     // Calling the recursive quickSort() function (by passing in appropriate values).
}


/***************************************************************
 Function: quickSort() - recursive
 
 Use: We are using this recursive quickSort() function for getting
 the pivot point, for sorting the first sublist, and for sorting
 the second sublist (but we are only doing this if the element at
 the start of the vector is less than the element at the end of the
 vector).
 
 Parameters:
 1.) set - This is a reference to a vector object containing the list
 of items to sort for the recursive quickSort() function.
 2.) start - This is an integer that holds the element at the start
 of the vector for the recursive quickSort() function.
 3.) end - This is an integer that holds the element at the end of
 the vector for the recursive quickSort() function.
 4.) compare - This is a pointer to a comparison function that can be
 used to compare two items of the template type for the recursive
 quickSort() function.
 
 Returns: none
 
 Notes: To make the recursive quick sort algorithm work, we need
 three finctions in total. We need the non-recursive quickSort()
 function, we need the recursive quickSort() function, and we need
 the partition() function (this is the second out of the three functions:
 the recursive quickSort() function.
 ***************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    
    int pivotPoint;     // Declaring an integer called pivotPoint.
    
    if (start < end)     // Checking to see if the element at the start of the vector is less than the element at the end of the vector.
    {
        pivotPoint = partition(set, start, end, compare);     // Here we are getting the pivot point (by calling the partition() function).
        quickSort(set, start, pivotPoint - 1, compare);       // Here we are sorting the first sublist (by using the recursive quickSort() function).
        quickSort(set, pivotPoint + 1, end, compare);         // Here we are sorting the second sublist (by using the recursive quickSort() function).
    }
    
}


/***************************************************************
 Function: partition()
 
 Use: We are using this partition() function to swap and to sort
 all of the elements in the vector called set (we are swapping the
 elements three times in this function). We are also using this
 partition() function to to get the pivotIndex of the vector
 (pivotIndex is what we are returning).
 
 Parameters:
 1.) set - This is a reference to a vector object containing the list
 of items to sort for the partition() function.
 2.) start - This is an integer that holds the element at the start
 of the vector for the partition() function.
 3.) end - This is an integer that holds the element at the end of
 the vector for the partition() function.
 4.) compare - This is a pointer to a comparison function that can be
 used to compare two items of the template type for the partition()
 function.
 
 Returns:
 1.) pivotIndex - This partition() function returns the pivotIndex
 after all of the swapping and after all of the sorting.
 
 Notes: To make the recursive quick sort algorithm work, we need
 three finctions in total. We need the non-recursive quickSort()
 function, we need the recursive quickSort() function, and we need
 the partition() function (this is the third out of the three functions:
 the partition() function.
 ***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    
    // Here we are declaring all of the variables that we need for this function.
    int pivotIndex, mid;
    T pivotValue, temp;
    
    // Making mid equal to start plus end divided by 2.
    mid = (start + end) / 2;
    
    // Here we are swapping the elements start and mid of the vector called set.
    temp = set[start];
    set[start] = set[mid];
    set[mid] = temp;
    
    pivotIndex = start;     // Setting start to pivotIndex.
    pivotValue = set[start];     // Setting set[start] to pivotValue.
    
    for (int scan = start + 1; scan <= end; scan++)
    {
        
        if (compare(set[scan], pivotValue))
        {
            ++pivotIndex;     // Incrementing the pivotIndex.
            
            // Here we are swapping the elements pivotIndex and scan of the vector called set.
            temp = set[pivotIndex];
            set[pivotIndex] = set[scan];
            set[scan] = temp;
        }
        
    }
    
    // Here we are swapping the elements start and pivotIndex of the vector called set.
    temp = set[start];
    set[start] = set[pivotIndex];
    set[pivotIndex] = temp;
    
    return pivotIndex;     // Returning the pivotIndex.
    
}

#endif     // Here is the ending header guard for the quicksort.h header file.
