/***********************************************************************************
** Program: tiger.h
** Author: Andy James
** Date: 5/9/2021
** Description: child of animals, header file for tiger.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "animal.h"

using namespace std;

class Tiger : public Animal {
    public:
    Tiger();
    Tiger(int); 
    void set_food_cost(double);
};

#endif


