/***********************************************************************************
** Program: sea_lion.h
** Author: Andy James
** Date: 5/9/2021
** Description: child of animals, header file for sea_lion.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef SEALION_H
#define SEALION_H

#include <iostream>
#include "animal.h"
using namespace std;

class Sea_Lion : public Animal {
    public:
    Sea_Lion();
    Sea_Lion(int); 
    void set_food_cost(double);
    Sea_Lion(const Sea_Lion&);
};

#endif


