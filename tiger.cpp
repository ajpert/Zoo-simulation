/***********************************************************************************
** Program: tiger.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: child of Animals class, contains functions for the tiger class
** Input: none
** Output: none
************************************************************************************/
#include "tiger.h"

using namespace std;

/****************************************************************************************
** Function: Tiger::Tiger()
** Description: default constructor, sets everything to a default tiger
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Tiger::Tiger() {
    name = "tiger";
    age = 48;
    cost = 10000;
    food_cost = 80;
    revenue = 1000;
    babies = 3;
}

/****************************************************************************************
** Function: Tiger::Tiger(int a)
** Description: para constructor, sets age of the tiger class to int a
** Parameters: int a
** Pre-Condition: pass in an int
** Post-Condition: none
*****************************************************************************************/
Tiger::Tiger(int a) {
    name = "tiger";
    age = a;
    cost = 10000;
    food_cost = 80;
    revenue = 500;
    babies = 3;
}

/****************************************************************************************
** Function: Tiger::set_food_cost()
** Description: sets food cost to 5 times the passed in double, overides class animal
** Parameters: double f
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Tiger::set_food_cost(double f) {
    food_cost = (f*5);
}