/***********************************************************************************
** Program: animal.h
** Author: Andy James
** Date: 5/9/2021
** Description: header file for animal.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;


class Animal{
    protected:
        string name;
        int age;
        int cost;
        double food_cost;
        int revenue;
        int babies;
    public:
        Animal();
        void add_age(int);
        virtual void set_food_cost(double);
        void set_revenue(int);
        void set_babies(int);

        string get_name();
        int get_age();
        int get_cost();
        double get_food_cost();
        int get_revenue();
        int get_babies();
        
};

#endif
