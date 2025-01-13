/***********************************************************
 CSCI 340 - Assignment 3 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Monday, September 30, 2019
 
 Purpose: The purpose of this computer assignment is to write
 and implement an interactive C++ program that will find all
 the prime numbers that are less than or equal to a certain value
 of n (which is an integer). This program will also print all
 the prime numbers that are less than or equal to a certain value
 of n, out to the standard output. All of this process is done
 by using an algorithm which is known as the Sieve of Eratosthenes.
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "prog3.h"


/* This main() function simply creates/initializes a set container called s and an integer variable called
   upperBound. Then this function gets the upperBound value for the prime numbers from the input (which is
   a file called prog3.d). This function also prints the upperBound value, on to the standard output.
   Finally, this main() function calls the sieve() function by passing in the set container s and the
   integer upperBound as arguments; and it calls the print_primes() function by passing in the integer
   upperBound as an argument. */
int main()
{
    
    // Declaring a local set container called s which will hold the prime numbers that we will get after calling the sieve() function.
    set <int> s;
    
    // Creating a local variable of type integer (called upperBound) to hold the upper limit for prime numbers from the input file.
    int upperBound;
    
    cout << "upper limit for the set of primes: ";
    cin >> upperBound;
    
    cout << upperBound << endl << endl;
    
    sieve(s, upperBound);
    
    print_primes(s);
    
    return 0;
    
}


/* This sieve() function starts of by creating and set iterator called p. Then this function uses a for loop
   to insert the values between the range of 2 to n (the value of n is given by the input file) in the set
   container called s by using the insert() function. Finally and most importantly, this sieve() function
   (with the help from the find() function and the erase() function) uses a for loop inside of a different
   for loop to go through the set container s, and to remove all the integers that are multiples of 2, except
   2 (for example: 4, 6, 8, and 10). After removing the multiples of 2, this process repeats itself to remove
   all the integers that are multiples of 3, except 3 (for example: 6, 9, 12, and 15); after this process is
   done, we are only left with prime numbers. */
void sieve(set <int> &s, int n)
{
    
    // Creating a local set iterator called p; we need this iterator p to use the find() function later on in this sieve() function.
    set <int>::iterator p;
    
    for (int i = 2; i <= n; i++)
    {
        s.insert(i);
    }
    
    for (int m = 2; m * m <= n; m++)
    {
        for (int k = m; k <= n; k++)
        {
            p = s.find(k * m);
            
            if(p != s.end())
            {
                s.erase(p);
            }
        }
    }
    
}


/* This print_primes() function prints/displays the prime numbers that are in the set container called s on
   the standard output. This function prints exactly 16 prime numbers (NO_ITEMS) on a single line (except
   maybe the last line). Lastly, this function also clearly aligns the prime numbers in the set container s,
   by keeping them to the right side of the output and by having exactly 4 spaces (ITEM_W) between each of them. */
void print_primes(const set <int> &s)
{
    
    // Declaring a local variable called count which acts as a counter for the number of prime integers that are on a single line (in the output).
    int count = 1;
    
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << right << setw(ITEM_W) << *i << ' ';
        
        if (count % NO_ITEMS == 0)
        {
            cout << endl;
        }
        
        count++;
    }
    
    cout << endl;
    
}
