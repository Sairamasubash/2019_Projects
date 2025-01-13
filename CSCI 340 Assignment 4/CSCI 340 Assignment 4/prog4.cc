/***********************************************************
 CSCI 340 - Assignment 4 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Thursday, October 10, 2019
 
 Purpose: The purpose of this computer assignment is to write
 and implement an interactive C++ program that will scan and
 process a stream of words from a plain text. The program starts
 with an empty list of words filled with blanks, new line characters,
 and tabs (which will be used to separate all the given words).
 Also, this program uses an input file called prog4.d to get the
 list of all the words that will be modified later on in the program
 by multiple functions.
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "prog4.h"


/* This main() function simply starts of by creating/initializing a map container called inputWords. Then,
   this main() function calls the get_words() function by passing in the map container inputWords as an
   argument; and it also calls the print_words() function by passing in the map container inputWords as an
   argument. Finally, this function returns a 0 to make sure that the program ran perfectly without any
   errors showing up in the output. */
int main()
{
    
    // Declaring a local map container called inputWords which will hold the new/cleaned words that we will get after calling the get_words() function.
    map <string, int> inputWords;
    
    get_words(inputWords);
    
    print_words(inputWords);
    
    return 0;
    
}


/* This get_words() function starts of by creating two strings called oldWord and cleanWord. Then this function
   uses a while loop to get the original word (oldWord) from the input file called prog4.d. Inside the while
   loop, this get_words() function calls the clean_entry() function by passing in the string oldWord and the
   string cleanWord as arguments. Also inside the while loop, this function uses an if statement to check if the
   lenghth of cleanWord is not equal to 0, and if the lenghth of cleanWord is not equal to 0, the values inside
   cleanWord, and their frequencies will be stored in the map container called m. */
void get_words(map <string, int> &m)
{
    
    // Creating a local string called oldWord, this will hold the original word from the input file (before removing the punctuation marks).
    string oldWord;
    
    // Creating a local string called cleanWord, this will hold the new/modified word from the input file (after removing the punctuation marks).
    string cleanWord;
    
    while (cin >> oldWord)
    {
        clean_entry(oldWord, cleanWord);
        
        if (cleanWord.length() != 0)
        {
            m[cleanWord]++;
        }
    }
    
}


/* This print_words() function prints/displays the final list of words (including their frequencies) that are in
   the map container called m on the standard output. This function prints exactly 3 words and their frequencies
   (NO_ITEMS) on a single line (except maybe the last line); and this function also clearly aligns the words and
   their frequencies in the map container m, by keeping them to the left side of the output and by having exactly
   16 spaces (ITEM_W) allocated for each of them. Finally, this print_words() function prints the number of original
   words that are in the input file (before modifications), out to the standard output; and it also prints the number
   of modified words, out to the standard output (after modifications). */
void print_words(const map <string, int> &m)
{
    
    // Creating a local variable called numberOfWords which counts all the words that are in the input file called prog4.d (before any modifications).
    int numberOfWords = 0;
    
    // Declaring a local variable called count which acts as a counter for the number of words and their frequencies that are on a single line (in the output).
    int count = 1;
    
    for (auto p = m.cbegin(); p != m.cend(); p++)
    {
        numberOfWords += p->second;
        
        cout << left << setw(ITEM_W) << p->first << " : " << setw(4) << p->second << ' ';
        
        if (count % NO_ITEMS == 0)
        {
            cout << endl;
        }
        
        count++;
    }
    
    cout << endl;
    
    cout << "no of words in input stream  : " << numberOfWords << endl;
    cout << "no of words in output stream : " << m.size() << endl;
    
}


/* This alphanumeric() function simply goes through all the characters that are passed in as arguments to this
   function, and checks to see if those characters are alphanumeric. If the characters are alphanumeric, then
   this function returns true; and if the characters are not alphanumeric, then this function returns false
   (this is the exact opposite of the function below). */
bool alphanumeric(const char &alphaLetters)
{
    return isalnum(alphaLetters);
}


/* This nonAlphanumeric() function simply goes through all the characters that are passed in as arguments to this
   function, and checks to see if those characters are not alphanumeric. If the characters are not alphanumeric,
   then this function returns true; and if the characters are alphanumeric, then this function returns false (this
   is the exact opposite of the function above). */
bool nonAlphanumeric(const char &nonAlphaLetters)
{
    return !isalnum(nonAlphaLetters);
}


/* This changeToLower() function just simply goes through all the characters that are passed in as arguments to this
   function, and checks to see if those characters are not lowercase letters. If the characters are not lowercase
   letters, then this function calls another (built in) function called tolower() to change these non-lowercase letters
   into lowercase letters. */
void changeToLower(char &lowerCase)
{
    lowerCase = tolower(lowerCase);
}


/* This clean_entry() function starts of by creating two string iterators called firstIndex, and secondIndex. The
   firstIndex iterator holds the value of the first alphanumeric character found in string1; The secondIndex iterator
   holds the value of the first non-alphanumeric character found in string1. This function also converts these two
   iterators into regular integer values called i, and j (so they can be used in the substr() function later on). Then,
   this function calls the substr() function to move the modified/cleaned word from string1 into string2. Finally, this
   clean_entry() function calls the for_each() function to convert all the capital letters in string2 (the cleaned word)
   to lowercase letters. */
void clean_entry(const string &string1, string &string2)
{
    
    // Creating a local string iterator called firstIndex; this firstIndex iterator will hold the value of the first alphanumeric character found in string1.
    auto firstIndex = find_if(string1.cbegin(), string1.cend(), alphanumeric);
    
    // Creating a local string iterator called secondIndex; this secondIndex iterator will hold the value of the first non-alphanumeric character found in string1.
    auto secondIndex = find_if(firstIndex, string1.cend(), nonAlphanumeric);
    
    // Declaring a local integer called i, to convert the firstIndex iterator into a regular integer value (so it can be used in the substr() function later on).
    int i = firstIndex - string1.cbegin();
    
    // Declaring a local integer called j, to convert the secondIndex iterator into a regular integer value (so it can be used in the substr() function later on).
    int j = secondIndex - string1.cbegin();
    
    string2 = string1.substr(i, j - i);
    
    for_each(string2.begin(), string2.end(), changeToLower);
    
}


