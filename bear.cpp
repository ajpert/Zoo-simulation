/***********************************************************************************
** Program: bear.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: child of Animals class, contains functions for the bear class
** Input: none
** Output: none
************************************************************************************/
#include "bear.h"

using namespace std;

/****************************************************************************************
** Function: Bear::Bear()
** Description: default constructor, sets everything to a default bear object
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Bear::Bear() {
    name = "bear";
    age = 48;
    cost = 5000;
    food_cost = 80;
    revenue = 500;
    babies = 2;
}

/****************************************************************************************
** Function: Bear::Bear(int a)
** Description: para constructor, sets everything to a default bear object, and age to a
** Parameters: int a
** Pre-Condition: pass in an int
** Post-Condition: none
*****************************************************************************************/
Bear::Bear(int a) {
    name = "bear";
    age = a;
    cost = 5000;
    food_cost = 80;
    revenue = 500;
    babies = 2;
}

/****************************************************************************************
** Function: Bear::set_food_cost(double f)
** Description: sets food cost to 3 times doubel f, overides the animal class
** Parameters: double f
** Pre-Condition: pass in a double 
** Post-Condition: none
*****************************************************************************************/
void Bear::set_food_cost(double f) {
    food_cost = f*3;
}