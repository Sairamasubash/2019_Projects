/*********************************************************** 
 CSCI 340 - Assignment 9 - Fall 2019
 
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Monday, December 2, 2019
 
 Purpose: The purpose of this computer assignment is to write
 a C++ program that creates, searchs, prints, and sorts an
 inventory of items. The information about the inventory of
 items will be stored in a sequentially allocated table, with
 the given size of the table being equal to 31 (TBL_SZ = 31).
 The table has three important features: Key (item identifier),
 desc (item description), and num (number of copies of an item
 in the inventory). Finally, The item table will be accessed
 directly, using the separate chaining technique (to fix/solve
 all the collisions).
 ************************************************************/

// Inserting the header file in the source code file so that the source code file has access to everything in the header file.
#include "hTable.h"
// #include "/home/cs340/progs/19f/p9/hTable.h"

// Declaring the prototype for the cmp() predicate function which will be used in the pTable_print() method later on.
bool cmp(Entry *, Entry *);


/* This HT() constructor just does two things. First, this HT() constructor resizes the hash
   Table (hTable) to the size that is contained in the hs variable (resizing is done using the
   resize() function in the STL). Then, this HT() constructor sets the hsize variable equal to
   the hs variable. Also, we do not need to resize the pointer table (pTable) in this constructor
   because its initial size is zero or empty, but it will increase dynamically after inserting a
   new Entry item in this table. */
HT::HT(const unsigned &hs)
{
    
    hTable.resize(hs);
    hsize = hs;
    
}


/* This ~HT() destructor simply starts of by freeing up all of the memory for the list container
   hTable (hash table) by using the clear() function in the STL inside of a for loop. Then, this
   destructor uses the clear() function once again to free up all of the memory for the vector
   container hTable (hash table). Finally, this ~HT() destructor uses the clear() function one
   last time to free up all of the memory for the vector container pTable (pointer table). */
HT::~HT()
{
    
    for (unsigned i = 0; i < hsize; i++)
    {
        hTable[i].clear();
    }
    
    hTable.clear();
    
    pTable.clear();
    
}


/* This public insert() method just inserts the record (item e which contains key, num, and desc)
   in the hash table (hTable). If the key already exists in the hTable, then this function prints
   an error message in the standard output; otherwise, this function prints the index value of the
   inserted record in the hTable. Also, this insert() method inserts the address of the record in
   the hTable, into the pointer table (pTable). Finally, in the case of a collision, this insert()
   method will simply insert the new record at the beginning of the corresponding list container. */
void HT::insert(const Entry &e)
{
    
    // Declaring a local integer variable called indexValue to hold the key value for the new record that we will be inserting in the hTable.
    int indexValue = hash(e.key);
    
    // Creating a local list container called l to compare the key of the record e with the keys of the elements in the list container.
    list <Entry> &l = hTable[indexValue];

    // Declaring a local list iterator called it; this it iterator will hold the key value that is returned when e.key is equal to e2.key.
    auto it = find_if(l.cbegin(), l.cend(), [e] (const Entry &e2) {return e.key == e2.key;});
    
    if (it != l.cend())
    {
        cout << " not inserted - duplicate Key!!!" << endl;
    }
    else
    {
        cout << " entry = " << setw(2) << indexValue << endl;
        
        l.push_front(e);
        
        pTable.push_back(&l.front());
    }

}


/* This public search() method simply searches the hash table (hTable) for a record, using the key
   value (of that record). Just like the insert() function above, the find_if() function in the STL
   is being used to search for a record in the hTable. If the search is successful, then this search()
   function prints the information of the record that is found in the standard output; otherwise, this
   search() function prints an error message in the standard output. Finally, in both the insert()
   function and the search() function, a lambda is used as the compare component of the find_if() function */
void HT::search(const string &key)
{
    
    // Creating a local auto variable called indexValue to hold a given key value that we will use to search for a certain record in the hTable.
    auto indexValue = hash(key);
    
    // Creating a local list container called l to help search for a certain record in the hash table (using a given key value).
    list <Entry> &l = hTable[indexValue];
    
    // Declaring a local list iterator called it; this it iterator will hold the key value that is returned when key is equal to key2.key.
    auto it = find_if(l.cbegin(), l.cend(), [key] (Entry key2) {return key == key2.key;});
    
    if (it != l.cend())
    {
        cout << " ==> number: " << setw(4) << it->num << " - item: " << it->desc;
    }
    else
    {
        cout << " not in table!!";
    }
    
    cout << endl;
    
}


/* This public hTable_print() method simply starts of by creating a boolean variable called lastElementIsEmpty
   and sets this variable equal to false. Then, inside of two for loops, this hTable_print() method uses an if
   statement to check if the boolean variable lastElementIsEmpty is equal to true, if it is, then it prints a
   new line in the standard output. Otherwise, it prints the subscript and the contents of all the active
   records in the hash table (and only the active records in the hash table); it also sets the boolean variable
   lastElementIsEmpty equal to false once again. Finally, this method sets the boolean variable lastElementIsEmpty
   equal to true inside the for loop. */
void HT::hTable_print()
{
    
    // Creating a local boolean variable called lastElementIsEmpty to hold either true or false based on the last element inside the hTable.
    bool lastElementIsEmpty = false;
    
    for (unsigned i = 0; i < hsize; i++)
    {
        for (auto x : hTable[i])
        {
            if (lastElementIsEmpty)
            {
                cout << endl;
            }
            
            cout << setw(4) << i << ":  " << x.key << "  - " << setw(5) << x.num << "  -  " << x.desc << endl;
            
            lastElementIsEmpty = false;
        }
        
        lastElementIsEmpty = true;
    }
    
    cout << endl;
    
}


/* This cmp() function just contains an if statement that returns true if the key value of the
   item in location p is less than (or comes before) the key value of the item in location q
   (in alphabetical order); otherwise, it returns false. Also, this cmp() function will be used
   as the last argument/parameter in the sort() function in the STL (which will be called in the
   pTable_print() method just below this cmp() function). */
bool cmp(Entry *p, Entry *q)
{
    
    if (p->key < q->key)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


/* This public pTable_print() method simply starts of by calling the sort() function in the STL,
   using the cmp() function as the third argument or the third parameter (the cmp() function is
   declared and initialized just above this pTable_print() method). Then, this pTable_print()
   method prints the contents of all the active records in the pointer table (and only the active
   records in the pointer table). Starting of with the key value, then the num value, and finally
   the desc value (with correct spacing). */
void HT::pTable_print()
{
    
    sort(pTable.begin(), pTable.end(), cmp);
    
    for (unsigned i = 0; i < pTable.size(); i++)
    {
        cout << "   " << pTable[i]->key << "  -  " << right << setw(4) << pTable[i]->num << "  -  " << left << pTable[i]->desc << endl;
    }
    
}


