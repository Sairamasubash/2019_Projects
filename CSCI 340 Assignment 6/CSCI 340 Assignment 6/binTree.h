/***********************************************************
 CSCI 340 - Assignment 6 - Fall 2019
 
 File: binTree.h
 Progammer: Sairamasubash Muppalaneni
 Z-ID: Z1844762
 Section: 1
 TA: Pragna Bodipudi
 Date Due: Thursday, October 31, 2019
 
 Purpose: The purpose of this computer assignment is to write
 a C++ program that implements a template class called binTree
 which is created to work with binary trees. The template class
 binTree deals with one data type, one constructor, and six
 methods (plus two additional methods). This binTree class is
 implemented as a template so that we can deal with multiple
 data types. Also, this program needs to use the provided prog6.cc
 source code file and the provided Node.h header file for the
 binTree.h file (that we created) to successfully compile and run.
 ************************************************************/

// Here are the beginning header guards for the binTree.h file.
#ifndef H_BINTREE
#define H_BINTREE

// Inserting a different header file in this header file so that this header file has access to everything in the other header file.
#include "Node.h"

template <class T>     // Start of the binTree template class.
class binTree
{

public:     // Declaring the public constructor, and the methods for the binTree template class.
    
    binTree();
    unsigned height() const;
    virtual void insert(const T&);
    void inorder(void(*) (const T&));

protected:     // Declaring the protected data type (and some additional methods) for the binTree template class.

    Node <T> *root;     // This template Node object/data type is the actual root of the entire binary tree.
    
    typedef enum {left_side, right_side} SIDE;
    SIDE rnd() {return rand() % 2 ? right_side : left_side;}
    
private:     // Declaring the private methods for the binTree template class.

    unsigned height(Node <T> *) const;
    void insert(Node <T> *&, const T&);
    void inorder(Node <T> *, void(*) (const T&));

};     // End of the binTree template class.


/* This binTree() constructor simply sets the actual root of the entire binary tree equal to nullptr
   (which basically means nothing/NULL). This needs to be done because, in this program, the root of
   the binary tree always starts of as being nothing/NULL (it gets a fresh start every time and then
   some modifications can be done to it). */
template <class T>
binTree<T>::binTree()
{
    root = nullptr;
}


/* This public version of the height() method just calls the private version of the height() method by
   passing in the actual root of the entire binary tree (called root) as an argument. Then, this method
   returns the height of the binary tree which we got from calling the private version of the height()
   method (the height of the binary tree is the longest path in the entire binary tree). */
template <class T>
unsigned binTree<T>::height() const
{
    return height(root);
}


/* This public version of the insert() method simply calls the private version of the insert() method by
   passing in the actual root of the entire binary tree (called root) and the constant template variable
   (called x) as arguments (we need these insert() methods to insert new values into the binary tree).
   Also, this insert() method does not return any values (because of void). */
template <class T>
void binTree<T>::insert(const T& x)
{
    insert(root, x);
}


/* This public version of the inorder() method just calls the private version of the inorder() method by
   passing in the actual root of the entire binary tree (called root) and the unary function (called print())
   as arguments (we need these inorder() methods to perform an inorder traversal through the binary tree).
   Once again, this inorder() method does not return any values (because of void). */
template <class T>
void binTree<T>::inorder(void(*print) (const T& x))
{
    inorder(root, print);
}


/* This private version of the height() method checks to see if the heightRoot is equal to nullptr, if it
   is, then this method returns 0. Otherwise, this height() method gets the height of the left subtree of
   the binary tree and the height of the right subtree of the binary tree. Finally, this method calls the
   max() function in STL to determine which subtree has the biggest height; also, after adding one to the
   original value to count the root, this method returns the value of the subtree with the biggest height. */
template <class T>
unsigned binTree<T>::height(Node <T> *heightRoot) const
{
    
    // Creating a local variable of type unsigned integer called treeHeight which holds the height of the binary tree (the longest path in the binary tree).
    unsigned treeHeight;
    
    if (heightRoot == nullptr)
    {
        return 0;
    }
    
    // Creating a local variable of type unsigned integer called leftTree which holds the height of the left subtree of the binary tree.
    unsigned leftTree;
    // Creating a local variable of type unsigned integer called rightTree which holds the height of the right subtree of the binary tree.
    unsigned rightTree;
    
    leftTree = height(heightRoot->left);
    rightTree = height(heightRoot->right);
    
    treeHeight = max(leftTree, rightTree) + 1;
    
    return treeHeight;
    
}


/* This private version of the insert() method checks to see if the insertRoot is equal to nullptr, if it
   is, then this method sets the newNode as the root of the binary tree with the value x. Otherwise, this
   insert() method randomly selects the left subtree or the right subtree and the value x is inserted into
   the selected subtree. Finally, the random selection of the subtrees in this method is done by the RNG
   that is implemented in the protected section of the class declaration (above). */
template <class T>
void binTree<T>::insert(Node <T> *&insertRoot, const T& x)
{
    
    if (insertRoot == nullptr)
    {
        // Creating a local template Node object/data type called newNode to be the root of the binary tree with the value x (only if insertRoot is equal to nullptr).
        Node<T> *newNode;
        
        newNode = new Node<T>(x);
        
        insertRoot = newNode;
    }
    else
    {
        // Creating a local SIDE object/data type called s which holds the left subtree or the right subtree that is randomly selected (using rnd()).
        SIDE s = rnd();
        
        if(s == right_side)
        {
            insert(insertRoot->right, x);
        }
        else
        {
            insert(insertRoot->left, x);
        }
    }
    
}


/* This private version of the inorder() method checks to see if the inorderRoot is equal to nullptr, if it
   is, then this method returns nothing/NULL. Otherwise, this inorder() method performs an inorder traversal
   through the binary tree. First, this method prints the left values. Second, this method prints the root
   values. Finally, this method prints the right values. Plus, this inorder() method just prints these values
   out to the standard output, it does not return anything (because of void). */
template <class T>
void binTree<T>::inorder(Node <T> *inorderRoot, void(*print) (const T& x))
{
    
    if(inorderRoot == nullptr)
    {
        return;
    }
    
    inorder(inorderRoot->left,print);
    
    print(inorderRoot->data);
    
    inorder(inorderRoot->right,print);
        
}

#endif     // Here is the ending header guard for the binTree.h file.

