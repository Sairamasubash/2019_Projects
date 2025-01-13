/****************************************************************
 FILE:      prog2.h
 
 AUTHOR:    Sairamasubash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  Thursday, September 19, 2019
 
 PURPOSE:   The purpose of the prog2.h file is to create seven
 different function prototypes, and to create eight different
 constant variables that are needed for this program. This prog2.h
 file also includes the four libraries, and the using statements
 that are required by this program.
 ****************************************************************/

// Here are the beginning header guards for the prog2.h file.
#ifndef H_PROG2
#define H_PROG2

// Here are all the libraries and the using statements that are required by this header file.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Declaring the eight constant variables that are needed for this program.
const int ARR_SIZE = 200;
const int TEST_ARR_SIZE = 100;
const int SEED1 = 1;
const int SEED2 = 3;
const int LOW = 1;
const int HIGH = 1000;
const int NO_ITEMS = 16;
const int ITEM_W = 4;

// Declaring the seven function prototypes that are needed for this program.
void Vectors(vector <int> &v1, vector <int> &v2, int s1, int s2);
bool linearSearch(const vector <int> &v, int x);
bool binarySearch(const vector <int> &v, int x);
int search(const vector <int> &v1, const vector <int> &v2, bool (*p) (const vector <int> &, int));
void sortVector(vector <int> &v);
void printVector(const vector <int> &v);
void printStat(int totalSucCnt, int vectorSz);

#endif     // Here is the ending header guard for the prog2.h file.
