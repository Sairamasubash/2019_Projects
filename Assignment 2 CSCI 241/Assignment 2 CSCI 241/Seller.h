#ifndef SELLER_H
#define SELLER_H

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

const int ARRAY_SIZE = 31;

class Seller
{
private:
    
    // Data members for the Seller class go here
    
    char name[ARRAY_SIZE];
    double salesTotal;
    
public:
    
    // Method prototypes for the Seller class
    
    Seller();
    Seller(const char*, double);
    
    const char* getName() const;
    double getSalesTotal() const;
    void setSalesTotal(double);
    void print() const;
};

#endif

