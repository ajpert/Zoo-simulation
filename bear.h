/***********************************************************************************
** Program: bear.h
** Author: Andy James
** Date: 5/9/2021
** Description: child of animals, header file for bear.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "animal.h"

using namespace std;

class Bear : public Animal {
    public:
    Bear();
    Bear(int); 
    void set_food_cost(double);

};

#endif


