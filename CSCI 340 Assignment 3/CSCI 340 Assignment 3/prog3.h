/****************************************************************
 FILE:      prog3.h
 
 AUTHOR:    Sairamasubash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  Monday, September 30, 2019
 
 PURPOSE:   The purpose of the prog3.h file is to create two function
 prototypes. One prototype is for a function that removes all nonprime
 numbers from the integers set. The other prototype is for a function
 that prints the prime numbers that are now in the integers set, out
 to the standard output.
 ****************************************************************/

// Here are the beginning header guards for the prog3.h file.
#ifndef H_PROG3
#define H_PROG3

// Here are all the libraries and the using statements that are required by this header file.
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

// Declaring the two constant variables that are needed for this program.
const int NO_ITEMS = 16;
const int ITEM_W = 4;

// Declaring the two function prototypes that are needed for this program.
void sieve(set <int> &s, int n);
void print_primes(const set <int> &s);

#endif     // Here is the ending header guard for the prog3.h file.
