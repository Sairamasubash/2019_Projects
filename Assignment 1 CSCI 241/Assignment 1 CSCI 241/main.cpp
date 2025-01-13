/***********************************************************
 CSCI 241 - Assignment 1 - Spring 2019
 
 Progammer: Sairamasubash Muppalaneni
 My programming partner: Aleena Ahmad
 Z-ID: Z1844762
 M
 Section: 1
 TA: Rahul Reddy Gopu
 Date Due: February 11, 2019
 
 Purpose: The purpose of this program is to get some practice
 with the manipulation of C strings; and to get some exercise
 on writing, compiling, and executing a C++ program on our
 schools departmental UNIX servers.
 ************************************************************/

// This is the list of all the libraries that we need for this program.
#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// This is the list of the 5 function prototypes that we will use in this program.
char* copy(char* destination, const char* source, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
void read(char* destination, int num);


/***************************************************************
 Function: main
 
 Use: We are using this main function to call the other functions
 that we have created throughout the entire program. This is also
 where we are are creating, declaring, and initializing all the C
 strings that we need for this program
 
 Parameters: none
 
 Returns: (1.) return 0 - whenever we get the return value of 0 in
 the output, we can then confirm that our program was successful.
 
 Notes: We are calling exactly 5 finctions in this main finction,
 and we are manipulating C strings from the code written in these
 5 functions.
 ***************************************************************/

int main()     // Start of the main function.
{
    // This is the list of variables and variable declarations that we need for the main finction.
    const int WORDSIZE = 15;
    char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""};
    char word[WORDSIZE];
    
    // Testing the copy function
    cout << "Copy \"sprightful\", should see \"sprightful\".\n";
    copy(word, words[0], sizeof(word) - 1);
    cout << word << endl << endl;
    
    // Testing the limit on the copy function
    cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
    copy(word, "Supercalifragilisticexpialidocious", 5);
    cout << word << endl << endl;
    
    // Testing the replaceCopy function
    cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
    replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
    cout << word << endl << endl;
    
    // Testing the limit on the replaceCopy function
    cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
    replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
    cout << word << endl << endl;
    
    // Testing the caseChangeCopy function
    cout << "Case change \"New York\", should see \"nEW yORK\".\n";
    caseChangeCopy(word, words[2], sizeof(word) - 1);
    cout << word << endl << endl;
    
    // Testing the limit on the caseChangeCopy function
    cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
    caseChangeCopy(word, "Supercalifragilistic", 5);
    cout << word << endl << endl;
    
    // Testing the reverseCopy function
    cout << "Reverse \"Bolton\", should see \"notloB\"\n";
    reverseCopy(word, words[3], sizeof(word) - 1);;
    cout << word << endl << endl;
    
    // Testing the limit on the reverseCopy function
    cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
    reverseCopy(word, "cytogeneticists", sizeof(word) - 1);;
    cout << word << endl << endl;
    
    // Testing the replaceCopy, caseChangeCopy, and reverseCopy functions at once.
    cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
    replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
    cout << word << endl << endl;
    
    // Asking the user to enter his name.
    cout << "Enter your entire name: ";
    read(words[5], sizeof(words[5]));
    cout << words[5] << endl << endl;
    
    // Testing the caseChangeCopy, and reverseCopy on the entered name of the user.
    cout << "Reverse your name and change case.\n";
    cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;
    
    return 0;
}     // End of the main finction.


/***************************************************************
 Function: copy
 
 Use: We are simply using this function to copy a certain length
 of a string that is contained in source to the destination array.
 
 Parameters:
 (1.) unsigned integer num - this value represents the specific
 length of the the string, from source, that we will copy.
 
 (2.) address specified by source - this is where the orginal string
 that we are going to copy is located.
 
 (3.) address specified by destination - this is where the new copied
 string will be be moved to.
 
 Returns: (1.) return destination - returns the new/copied string
 from source into the output.
 
 Notes: we use the default strncpy function to copy a certain length
 of a string located in source, into destination.
 ***************************************************************/

char* copy(char* destination, const char* source, size_t num)     // Start of the copy function.
{
    strncpy(destination, source, num);     // This is the strncpy function that we are using to copy.

    destination[num]='\0';
    
    return destination;
}                           // End of the copy function.


/***************************************************************
 Function: replaceCopy
 
 Use: we are using this function to replace certain characters of
 a string contained in source; and then copying the new string to
 the destination array.
 
 Parameters:
 (1.) unsigned integer num - this value represents the specific
 length of the the string, from source, that we will replace the
 characters of.
 
 (2.) address specified by source - this is where the orginal string
 that we are going to replace the characters of is located.
 
 (3.) address specified by destination - this is where the new
 modified/replaced string will be be moved to.
 
 (4.) target - this is where the old characters that we will be
 replacing are located.
 
 (5.) replace - this is where the new characters that we will be
 using to replace are located.
 
 Returns: (1.) return destination - returns the new/replaced string,
 cpoied from source into the output.
 
 Notes: To replace the old/target characters with the new/replace
 characters, we will be using an if statement inside of a for loop.
 ***************************************************************/

char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)     // Start of the replaceCopy function.
{
    size_t numSize;
    
    for (numSize = 0; source[numSize] != '\0' && numSize < num; numSize++)
    {
        if(source[numSize] == target)
        {
            destination[numSize] = replace;     // This is where we are replacing the targetted old characters with the new characters.
        }
        else
        {
            destination[numSize] = source[numSize];     // This else statement is there to not bother with the non targetted characters.
        }
    }
    
    destination[num]='\0';
    
    return destination;
}                           // End of the replaceCopy function.


/***************************************************************
 Function: caseChangeCopy
 
 Use: We are using this function to change the cases for all the
 characters in a string contained in source; and then copying the
 new string into the destination array (upper case letters to lower
 case, and lower case letters to upper case).
 
 Parameters:
 (1.) unsigned integer num - this value represents the specific
 length of the the string, from source, that we will change the
 cases for.
 
 (2.) address specified by source - this is where the orginal string
 that we are going to change the cases for is located.
 
 (3.) address specified by destination - this is where the new/case
 changed string will be placed in.
 
 Returns: (1.) return destination - returns the new/case changed
 string, copied from source into the output.
 
 Notes: We had to use three default functions, in side of a for
 loop for this function to work: isupper, tolower, toupper.
 ***************************************************************/

char* caseChangeCopy(char* destination, const char* source, size_t num)     // Start of the caseChangeCopy function.
{
    size_t i;
    
    for (i = 0; source[i] != '\0' && i < num; i++)
    {
        
        if (isupper(source[i]))     // First we are checking if the digit is upper case (isupper).
        {
            destination[i] = tolower(source[i]);     // If the digit is upper case, then we are changing it to lower case (tolower).
        }
        else
        {
            destination[i] = toupper(source[i]);     // If the digit is not upper case, then we are making it upper case (toupper).
        }
        
    }
    destination[i]='\0';
    
    return destination;
}                              // End of the caseChangeCopy function.


/***************************************************************
 Function: reverseCopy
 
 Use: we are using this function to reverse a certain length of a
 string contained in source; and then copying the new string to
 the destination array.
 
 Parameters:
 (1.) unsigned integer num - this value represents the specific
 length of the the string, from source, that we will be reversing.
 
 (2.) address specified by source - this is where the orginal string
 that we are going to reverse is located.
 
 (3.) address specified by destination - this is where the new/reversed
 string will be be moved to.
 
 Returns: (1.) return destination - returns the new and reversed
 string, copied from source into the output.
 
 Notes: first, we are using the strlen function to find the length
 of the string contained in source; and then we are using an if
 statement to make sure that the length of the string is at or under
 the num limit.
 ***************************************************************/

char* reverseCopy(char* destination, const char* source, size_t num)     // Start of the reverseCopy function.
{
    int numSize;
    
    size_t i, length;
    length = strlen(source);
    
    if (length < num)
    {
        numSize = (int) length - 1;     // If the length of source is less than num, make the string (numSize) equal to one less then length.
    }
    else
    {
        numSize = (int) num - 1;     // If the length of source is not less than num, make the string (numSize) equal to one less than num.
    }
    
    
    for (i = 0; numSize >= 0 && i < num; numSize--, i++)     // While numSize which represents source keeps decreasing, i which represents destination keeps increasing.
    {
        destination[i] = source[numSize];
    }
    
    destination[i]='\0';     // Indicates that we stop at the null character and we do not count the null character as part of the string.
    
    return destination;
}                              // End of the reverseCopy function.


/***************************************************************
 Function: read
 
 Use: We are using this function to get the full name of the user,
 so we can try out/test the other functions on the users name (string).
 
 Parameters:
 (1.) unsigned integer num - this represents the number of characters
 out of the entered name, that will be used.
 
 (2.) address specified by destination - this is where the entered
 name will be placed.
 
 Returns: nothing
 
 Notes: We are using the getline finction instead of just cin because
 we want the full line of text, not just one word.
 ***************************************************************/

void read(char* destination, int num)     // Start of the read function.
{
    cin.getline(destination, num);     // The user entered name will be placed in the destination array (the entered name characters are limited due to num).
}                                 // End of the read function.
