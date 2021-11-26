/***********************************************************************************
** Program: animal.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: includes functions for the Animal class
** Input: none
** Output: none
************************************************************************************/
#include "animal.h"

/****************************************************************************************
** Function: Animal::Animal()
** Description: default constructor, sets every thing to 0 or blank for name
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Animal::Animal() {
    name = "";
    age = 0;
    cost = 0;
    food_cost = 0;
    revenue = 0;
    babies = 0;
}

/****************************************************************************************
** Function: Animal::add_age()
** Description: adds int a to the age of the Animal object
** Parameters: int a
** Pre-Condition: pass in a int
** Post-Condition: none
*****************************************************************************************/
void Animal::add_age(int a) {
    age += a;
}

/****************************************************************************************
** Function: Animal::set_food_cost(double f)
** Description: sets the food cost of the Animal object, meant to be over written
** Parameters: double f
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Animal::set_food_cost(double f) {
    food_cost = f;
}

/****************************************************************************************
** Function: Animal::set_revenue(int r)
** Description: sets revenue of the Animal object
** Parameters: int r
** Pre-Condition: pass in a int to set revenue
** Post-Condition: none
*****************************************************************************************/
void Animal::set_revenue(int r) {
    revenue = r;
}

/****************************************************************************************
** Function: Animal::set_babies()
** Description: sets babies of the Animal object
** Parameters: int b
** Pre-Condition: pass in a int
** Post-Condition: none
*****************************************************************************************/
void Animal::set_babies(int b) {
    babies = b;
}

/****************************************************************************************
** Function: Animal::get_name()
** Description: returns the name of the Animal object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return string name
*****************************************************************************************/
string Animal::get_name() {
    return name;
}

/****************************************************************************************
** Function: Animal::get_age()
** Description: returns the age of the Animal object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int age
*****************************************************************************************/
int Animal::get_age() {
    return age;
}

/****************************************************************************************
** Function: Animal::get_cost()
** Description: returns the cost of the Animal object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int cost
*****************************************************************************************/
int Animal::get_cost() {
    return cost;
}

/****************************************************************************************
** Function: Animal::get_food_cost()
** Description: returns the food cost of the animal, will be over written
** Parameters: none
** Pre-Condition: none
** Post-Condition: return food_cost
*****************************************************************************************/
double Animal::get_food_cost() {
    return food_cost;
}

/****************************************************************************************
** Function: Animal::get_revenue()
** Description: returns the revenue of the animal object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int revenue
*****************************************************************************************/
int Animal::get_revenue() {
    return revenue;
}

/****************************************************************************************
** Function: Animal::get_babies()
** Description: returns the num of babies the animal object can produce
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int babies
*****************************************************************************************/
int Animal::get_babies() {
    return babies;
}

