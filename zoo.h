/***********************************************************************************
** Program: zoo.h
** Author: Andy James
** Date: 5/9/2021
** Description: header file for zoo.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "sea_lion.h"
#include "tiger.h"
#include "bear.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Zoo {
    private:
        Animal** animals;
        int num_animals;
        double money;
        double food_cost;
    public:
        Zoo();
        ~Zoo();
        void add_animal(Animal*);
        void remove_animal(int);
        void set_num_animals(int);
        void subtract_money(double);
        void add_money(double);
        void set_money(double);
        void change_food_cost();
        void random_event();
        void sick_event();
        void birth_event();
        void boom_event();
        void display_zoo();

        Animal* get_animal(int);
        int get_num_animals();
        double get_money();
        double get_food_cost();

};

#endif