//
//  Header.h
//  Assignment 2 CSCI 241
//
//  Created by Sairamasubash Muppalaneni on 2/16/19.
//  Copyright © 2019 Sairamasubash Muppalaneni. All rights reserved.
//

#ifndef SELLERLIST_H
#define SELLERLIST_H
#include "Seller.h"

/**
 *
 * Seller.h
 *
 * Author:    your name
 * z-ID:      your z-ID
 * Date:      due date of assignment
 *
 * Contains the declaration for the Seller class.
 */

class SellerList
{
private:
    
    // Data members for the Seller class go here
    
    Seller objects[30];
    int numSellers;
    
public:
    
    // Method prototypes for the Seller class
    
    SellerList();
    SellerList(const string& fileName);
    
    void print() const;
    
};

#endif 
