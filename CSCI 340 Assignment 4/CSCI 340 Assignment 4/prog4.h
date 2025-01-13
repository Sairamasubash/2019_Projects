/****************************************************************
 FILE:      prog4.h
 
 AUTHOR:    Sairamasubash Muppalaneni
 
 LOGON ID:  Z1844762
 
 DUE DATE:  Thursday, October 10, 2019
 
 PURPOSE:   The purpose of the prog4.h file is to create six different
 function prototypes, and to create two different constant variables
 that are needed for this program. This prog4.h file also includes
 the four libraries, and the using statements that are required by
 this program (plus, this header file starts and ends with header guards).
 ****************************************************************/

// Here are the beginning header guards for the prog4.h file.
#ifndef H_PROG4
#define H_PROG4

// Here are all the libraries and the using statements that are required by this header file.
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

// Declaring the two constant variables that are needed for this program.
const int NO_ITEMS = 3;
const int ITEM_W = 16;

// Declaring the six function prototypes that are needed for this program.
void get_words(map <string, int> &);
void print_words(const map <string, int> &);
bool alphanumeric(const char &);
bool nonAlphanumeric(const char &);
void changeToLower(char &);
void clean_entry(const string &, string &);

#endif     // Here is the ending header guard for the prog4.h file.
