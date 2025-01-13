/*********************************************************** 
 CSCI 340 - Assignment 7 - Fall 2019
 
 File: binSTree.h
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Friday, November 8, 2019
 
 Purpose: The purpose of this computer assignment is to write
 a C++ program that implements a derived class called binSTree
 (as a template) to represent a binary search tree. Since a binary
 search tree is a binary tree, I am implementing my binary search
 tree class from the base class of the binary tree called binTree
 that I implemented in my previous assignment (Assignment 6). Also,
 the template class binSTree deals with seven methods (three public,
 and four private). Finally, this program needs to use the provided
 prog7.cc source code file and the provided Node.h header file for the
 binSTree.h file (that we created) to successfully compile and run.
 ************************************************************/

// Inserting a different header file in this header file so that this header file has access to everything in the other header file.
#include "binTree.h"

// Here are the beginning header guards for the binSTree.h file.
#ifndef H_BINSTREE
#define H_BINSTREE

template <typename T>     // Start of the binSTree template class.
class binSTree : public binTree <T>
{

public:     // Declaring the public methods for the binSTree template class.
    
    void insert(const T& x);
    bool search(const T& x) const;
    bool remove(const T& x);
    
private:     // Declaring the private methods for the binSTree template class.
    
    void insert(Node <T> *&, const T&);
    bool search(Node <T> *, const T&) const;
    void remove(Node <T> *&, const T&);
    bool leaf(Node <T> *node) const;
    
};     // End of the binSTree template class.


/* This public version of the insert() method simply calls the private version of the insert() method by
   passing in the actual root of the entire binary search tree (called root) and the constant template
   variable (called x) as arguments (we need these insert() methods to insert new values into the binary
   search tree). Also, this insert() method does not return any values (because of void). */
template <typename T>
void binSTree<T>::insert(const T& x)
{
    insert(this->root, x);
}


/* This public version of the search() method just calls the private version of the search() method by
   passing in the actual root of the entire binary search tree (called root) and the constant template
   variable (called x) as arguments (we need these search() methods to search for specific values in
   the binary search tree). Also, this search() method returns the value that we searched for if it is
   found. */
template <typename T>
bool binSTree<T>::search(const T& x) const
{
    return search(this->root, x);
}


/* This public version of the remove() method simply calls the private version search() method to determine the
   result of the search for a leaf with the data value x, and if the search is successful, this method calls the
   private version of the remove() method to remove the corresponding leaf from the tree and returns true;
   otherwise, this method returns false. */
template <typename T>
bool binSTree<T>::remove(const T& x)
{
    
    if (search(this->root, x))
    {
        remove(this->root, x);
        return true;
    }
    else
    {
        return false;
    }
    
}


/* This private version of the insert() method checks to see if the insertRoot is equal to nullptr, if it
   is, then this method sets the newNode as the root of the binary search tree with the value x. Otherwise,
   this insert() method inserts a node with the data value x in either the left subtree of the binary search
   tree or the right subtree of the binary search tree. */
template <typename T>
void binSTree<T>::insert(Node <T> *&insertRoot, const T& x)
{
    
    if (insertRoot == nullptr)
    {
        // Creating a local template Node object/data type called newNode to be the root of the binary tree with the value x (only if insertRoot is equal to nullptr).
        Node <T> * newNode;
        
        newNode = new Node<T>(x);
        
        insertRoot = newNode;
    }
    else if (x < insertRoot->data)
    {
        insert(insertRoot->left, x);
    }
    else if (x > insertRoot->data)
    {
        insert(insertRoot->right, x);
    }
    
}


/* This private version of the search() method starts of by checking to see if the searchRoot is equal to
   nullptr, if it is, this search() method returns false. Then, this search () method searches for a leaf with
   the data value x (by calling the leaf() method). If the search is successful, this search() method returns
   true; otherwise, this search() method returns false. */
template <typename T>
bool binSTree<T>::search(Node <T> *searchRoot, const T& x) const
{
    
    if (searchRoot == nullptr)
    {
        return false;
    }
    
    if (searchRoot->data == x)
    {
        return leaf(searchRoot);;
    }
    else if (searchRoot->data > x)
    {
        return search(searchRoot->left, x);
    }
    else
    {
        return  search(searchRoot->right, x);
    }

}


/* This private version of the remove() method starts of by checking to see if the removeRoot is a leaf (by
   calling the leaf() method), if removeRoot is a leaf then this method removes the data value inside that node
   (which is represented as x). Otherwise, this remove() method traverses through the entire binary search tree
   and removes all the nodes that are leafs.*/
template <typename T>
void binSTree<T>::remove(Node <T> *&removeRoot, const T& x)
{
    
    if (leaf(removeRoot))
    {
        if(removeRoot->data == x)
        {
            removeRoot = nullptr;
            delete removeRoot;
        }
    }
    else if ((x < removeRoot->data) && (removeRoot->left != nullptr))
    {
        remove(removeRoot->left, x);
    }
    else if (removeRoot->right != nullptr)
    {
        remove(removeRoot->right, x);
    }
    
}


/* This private version of the leaf() method starts of by checking to see if the node is equal to nullptr, if it
   is, this leaf() method returns false. Then, this leaf() method checks to see if the left side of the node is
   equal to nullptr, and also checks to see if the right side of the node is equal to nullptr. If they are both
   equal to nullptr, then this method returns true, otherwise, this method returns false. */
template <typename T>
bool binSTree<T>::leaf(Node <T> *node) const
{
    
    if (node == nullptr)
    {
        return false;
    }
    else if (node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

#endif     // Here is the ending header guard for the binSTree.h file.
