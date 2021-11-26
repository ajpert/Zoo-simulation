/***********************************************************************************
** Program: sea_lion.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: child of Animals class, contains functions for the sea_lion class
** Input: none
** Output: none
************************************************************************************/
#include "sea_lion.h"

/****************************************************************************************
** Function: Sea_Lion::Sea_Lion()
** Description: default constructor, sets everything to a default sea_lion
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Sea_Lion::Sea_Lion() {
    name = "sea lion";
    age = 48;
    cost = 800;
    food_cost = 80;
    revenue = 160;
    babies = 1;
}
/****************************************************************************************
** Function: Sea_Lion::Sea_Lion(int a)
** Description: para contructor, sets age of the sea_lion object to int a
** Parameters: int a
** Pre-Condition: pass in int a to set int age
** Post-Condition: none
*****************************************************************************************/
Sea_Lion::Sea_Lion(int a) {
    name = "sea lion";
    age = a;
    cost = 800;
    food_cost = 80;
    revenue = 160;
    babies = 1;
}

/****************************************************************************************
** Function: Sea_Lion::set_food_cost(double f)
** Description: sets food_cost of the Sea_Lion object to f, overwrites the Animal class
** Parameters: double f
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Sea_Lion::set_food_cost(double f) {
    food_cost = f;
}

