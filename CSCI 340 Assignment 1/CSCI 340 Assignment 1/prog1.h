/****************************************************************
 FILE:      prog1.h
 
 AUTHOR:    Sairamasubash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  Tuesday, September 10, 2019
 
 PURPOSE:   The purpose of the prog1.h file is to create two function
 prototypes. One prototype is for a function that generates random
 integers, and the other prototype is for a function that prints
 these randomly generated integers out to the standard output.
 ****************************************************************/

// Here are the beginning header guards for the prog1.h file.
#ifndef H_PROG1
#define H_PROG1

// Here are all the libraries and the using statements that are required by this header file.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int LOW = 1;
const int HIGH = 10000;


// Declaring the two function prototypes that are needed for this program.
void genRndNums(vector <int> &v);
void printVec(const vector <int> &v);

#endif     // Here is the ending header guard for the prog1.h file.
