/***********************************************************************************
** Program: prog.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: Program to play Zoo Tycoon
** Input: none
** Output: none
************************************************************************************/
#include <iostream>
#include "animal.h"
#include "sea_lion.h"
#include "tiger.h"
#include "zoo.h"
#include <limits>

using namespace std;

void buy_stage(Zoo&);
bool feed_stage(Zoo&);
void revenue_stage(Zoo&);
void age_stage(Zoo&);
Animal* choose_animal(int);
int input_check(int);

/****************************************************************************************
** Function: int main()
** Description: runs the random events and continues until user wants or game is over
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
int main() {
    cout << "\033[2J\033[1;1H"; //clear screen
    srand(time(NULL));
    Zoo zoo;
    string cont = "y";

    cout << "welcome to da zoo" << endl;

    while(cont == "y") {
        buy_stage(zoo); //user buys animals
        if(feed_stage(zoo)) { //if it returns true, user has less the 0 dollars
            cout << "you ran outa money, game over" << endl;
            break;
        }
        zoo.random_event(); //sick, boom, birth, or nothing
        revenue_stage(zoo); //user gets money from animals
        age_stage(zoo); //each animals ages up
        zoo.display_zoo();

        cout << "you have " << zoo.get_money() << " dollars" << endl;
        cout << "would you like to continue? enter y for yes, else for no: ";
        getline(cin,cont);
        
        cout << "\033[2J\033[1;1H"; //clear screen
    }
}

/****************************************************************************************
** Function: buy_stage(Zoo& zoo)
** Description: allows for user to buy 2 of a certain species each turn
** Parameters: Zoo& zoo
** Pre-Condition: pass in a Zoo pointer
** Post-Condition: none
*****************************************************************************************/
void buy_stage(Zoo& zoo) {
    Animal* a;

    while(true) { //keeps going until purchase or skip
        cout << "you have " << zoo.get_money() << " dollars" << endl;
        cout << "Buy Stage: 1 for sea lions, 2 for tigers, 3 for bears, 4 to skip: ";
        int animal = input_check(4);

        if(animal == 4) {
            break;
        }
        else {
            a = choose_animal(animal);
        }

        cout << "how many do you want to buy 1 or 2: ";
        int num = input_check(2);

        if((zoo.get_money() - a->get_cost() * num) < 0) { //if they cant afford
            cout << "you do not have enough money for this" << endl;
            delete a;
        }
        else { //if they can afford
            delete a;
            for(int i = 0; i < num; i++) { //runs by the amount of certain species
                a = choose_animal(animal);
                zoo.add_animal(a);
                zoo.subtract_money(a->get_cost());
            }
            cout << "that costed " << a->get_cost() * num << " dollars" << endl;
            break;
        }
    }
}

/****************************************************************************************
** Function: feed_stage(Zoo& zoo)
** Description: deducts the amount of money it costs for each animals food cost
** Parameters: Zoo& zoo
** Pre-Condition: pass in a Zoo pointer
** Post-Condition: none
*****************************************************************************************/
bool feed_stage(Zoo& zoo) {
    double cost = 0;
    zoo.change_food_cost();
    cout << "food cost is " << zoo.get_food_cost();

    for(int i = 0; i < zoo.get_num_animals(); i++) { //sets new cost for each animal
        zoo.get_animal(i)->set_food_cost(zoo.get_food_cost());
    }
    for(int i = 0; i < zoo.get_num_animals(); i++) { //subtracts for each animal
        cost += zoo.get_animal(i)->get_food_cost();
        zoo.subtract_money(zoo.get_animal(i)->get_food_cost());
    }
    cout << ", for a total of " << cost << " dollars" << endl;
    
    if(zoo.get_money() < 0) {
        return true;
    }
    return false;
}

/****************************************************************************************
** Function: buy_stage(Zoo& zoo)
** Description: adds money for each animal and their revenue
** Parameters: Zoo& zoo
** Pre-Condition: pass in a Zoo pointer
** Post-Condition: none
*****************************************************************************************/
void revenue_stage(Zoo& zoo) {
    int total = 0;
    for(int i = 0; i < zoo.get_num_animals(); i++) { //adds revenue of each animal
        if(zoo.get_animal(i)->get_age() < 6) { //if it is a baby, revenue *2
            zoo.add_money(zoo.get_animal(i)->get_revenue() * 2);
            total += zoo.get_animal(i)->get_revenue() * 2;
        }
        else { // if not a baby
            zoo.add_money(zoo.get_animal(i)->get_revenue());
            total += zoo.get_animal(i)->get_revenue();
        }
    }
    cout << "you made " << total << " dollars in revenue" << endl;
}

/****************************************************************************************
** Function: void age_stage(Zoo&zoo)
** Description: increases each animals age by 1 month
** Parameters: Zoo& zoo
** Pre-Condition: pass in a Zoo pointer
** Post-Condition: none
*****************************************************************************************/
void age_stage(Zoo& zoo) {
    for(int i = 0; i < zoo.get_num_animals(); i++) {
        zoo.get_animal(i)->add_age(1);
    }
}

/****************************************************************************************
** Function: Animal* choose_animal(int n)
** Description: sub function for choosing which animal to buy, returns a new instance of that class
** Parameters: int n
** Pre-Condition: pass in an int refering to which new class
** Post-Condition: return a Animal pointer of that chosen class
*****************************************************************************************/
Animal* choose_animal(int n) {
    Animal* a;
    if(n == 1) {
        a = new Sea_Lion();
    }
    else if(n == 2) {
        a = new Tiger();
    }
    else {
        a = new Bear();
    }
    return a;
}

/****************************************************************************************
** Function: int input_check(int boundary)
** Description: checks for user input for a certain range of numbers
** Parameters: int boundary
** Pre-Condition: pass in a int refering to the end boundary (starts at 1)
** Post-Condition: pass back the value given by the user
*****************************************************************************************/
int input_check(int boundary) {
    int n;
    cin >> n;
    while(true) {
        if(cin.fail() || n < 1 || n > boundary) { // goes from 1 to boundary
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "invalid input, please try again: ";
            cin >> n;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return n;
        }
    }
}
