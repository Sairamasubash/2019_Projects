//
//  Seller.cpp
//  Assignment 2 CSCI 241
//
//  Created by Sairamasubash Muppalaneni on 2/14/19.
//  Copyright © 2019 Sairamasubash Muppalaneni. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Seller.h"

using std::cout;
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;


Seller::Seller()
{
    strcpy(name," ");
    salesTotal = 0;
}

Seller::Seller(const char* newName, double newSalesTotal)
{
    strcpy(name, newName);
    salesTotal = newSalesTotal;
}

const char* Seller::getName() const
{
    return name;
}

double Seller::getSalesTotal() const
{
    return salesTotal;
}

void Seller::setSalesTotal(double newSalesTotal)
{
    salesTotal = newSalesTotal;
}

void Seller::print() const
{
    cout << left << setw(30) << name << right << setw(9) << fixed << setprecision(2) << salesTotal << endl;
}



