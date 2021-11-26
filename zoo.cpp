/***********************************************************************************
** Program: zoo.cpp
** Author: Andy James
** Date: 5/9/2021
** Description: contains functions for the Zoo class
** Input: none
** Output: none
************************************************************************************/
#include "zoo.h"
using namespace std;

/****************************************************************************************
** Function: Animal::Animal()
** Description: default constructor, sets values to default gamestart values
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Zoo::Zoo() {
    animals = NULL;
    num_animals = 0;
    money = 100000;
    food_cost = 80;
}

/****************************************************************************************
** Function: Animal::~Animal()
** Description: destructor, deletes all new pointers in array animals and the animals array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Zoo::~Zoo() {
    for(int i = 0; i < num_animals; i++) {
        delete animals[i];
    }
   delete[] animals;
}    

/****************************************************************************************
** Function: Animal::add_animal(Animal* a)
** Description: adds a animal pointer to the Animal object pointer array
** Parameters: Animal* a
** Pre-Condition: pass in an animal pointer to add to the array
** Post-Condition: none
*****************************************************************************************/
void Zoo::add_animal(Animal *a) {
    if(animals == NULL) { //if the array has not been created yet
        animals = new Animal*[0];
        num_animals++;
        animals[0] = a;
    }
    else {
        Animal** temp = new Animal*[num_animals + 1]; //makes temp of one size bigger    
        for(int i = 0; i < num_animals; i++) { //sets old array to the temp array
            temp[i] = animals[i];
        }
        delete[] animals;
        animals = temp;
        animals[num_animals++] = a;
    }
}

/****************************************************************************************
** Function: Animal::remove_animal(int index)
** Description: removes a animal pointer to the Animal object pointer array
** Parameters: int index
** Pre-Condition: pass in int index of pointer to be removed
** Post-Condition: none
*****************************************************************************************/
void Zoo::remove_animal(int index) {
    Animal** temp = new Animal*[num_animals - 1]; //creates array of 1 size smaller
    int k = 0;
    for(int i = 0; i < num_animals; i++) { //sets every pointer except for the index
        if(i == index) {
            continue;
        }
        temp[k] = animals[i];
        k++;
    }
    delete animals[index]; //clearing memory
    delete [] animals;
    num_animals--;
    animals = temp;
}

/****************************************************************************************
** Function: Animal::set_num_animals(int num_a)
** Description: sets int num_animals
** Parameters: int num_a
** Pre-Condition: pass in an int
** Post-Condition: none
*****************************************************************************************/
void Zoo::set_num_animals(int num_a) {
    num_animals = num_a;
}

/****************************************************************************************
** Function: Animal::add_money(double m)
** Description: adds double m to double money
** Parameters: double m
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Zoo::add_money(double m) {
    money += m;
}

/****************************************************************************************
** Function: Animal::subtract_money(double m)
** Description: subtracts double m from double money
** Parameters: double m
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Zoo::subtract_money(double m) {
    money -= m;
}

/****************************************************************************************
** Function: Animal::set_money(double m)
** Description: sets double money to m
** Parameters: double m
** Pre-Condition: pass in a double
** Post-Condition: none
*****************************************************************************************/
void Zoo::set_money(double m) {
    money = m;
}

/****************************************************************************************
** Function: Animal::change_food_cost()
** Description: sets food cost to 80-120% of the last time change food cost was called
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::change_food_cost() {
    double random = (80.0+rand()%41)/100; //sets between .8 to 1.2 
    food_cost = food_cost*random;
}

/****************************************************************************************
** Function: Animal::random_event()
** Description: runs the random events, sick_event(), birth_event(), and boom_event()
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::random_event() {
    int random = rand()%4; //random num between 0 and 3,
    if(random == 0) {
        sick_event();
    }
    else if(random == 1) {
        birth_event();
    }
    else if(random == 2) {
        boom_event();
    }
    else {
        cout << "ah a normal day has passed, how nice" << endl;
    }
}

/****************************************************************************************
** Function: Animal::sick_event()
** Description: sets a random animal to sick, pays if can, removes if cant pay for it
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::sick_event() {
    if(num_animals == 0) {//if there are no animals
        cout << "germs were in the air but you had no animals, lucky you" << endl;
    }
    else {
        int cost;
        int random = rand()%(num_animals); 
        if(animals[random]->get_age() < 6) {  // if it is a baby, it costs the amount of that animal    
            cout << "a baby " << animals[random]->get_name() << " got sick" << endl;
            cost = animals[random]->get_cost();
        }
        else {  //if it is an adult
            cout << "a " << animals[random]->get_name() << " got sick" << endl;
            cost = animals[random]->get_cost()/2;
        }
        
        if(money - cost > 0) { //if you can afford it
            cout << "it costed " << cost << " dollars,";
            money = money - cost;
            cout << "you have " << money << " dollars now" << endl;
        }
        else { //dies if you cant, removes from array
            cout << "the " << animals[random]->get_name() << " died" << endl;
            remove_animal(random);
        }
    }
}

/****************************************************************************************
** Function: Animal::birth_event()
** Description: has a random animal give birth, and add those babies to the animals array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::birth_event() {
    int num_adults = 0;
    int arr[num_animals];
    Animal* a;
    for(int i = 0; i < num_animals; i++) { //gets the indexes of the adults
        if(animals[i]->get_age() >= 48) {
            arr[num_adults] = i;
            num_adults++;
        }
    }
    if(num_adults == 0) { //if there are no adults
        cout << "the air was ready for birth but sadly there were no adults" << endl;
    }
    else {
    int random = rand()%(num_adults);
        random = arr[random];
        cout << "woot you have stumbled across the miracle of birth" << endl;
        cout << "a " << animals[random]->get_name() << " gave birth";
        cout << " to " << animals[random]->get_babies() << " baby " << animals[random]->get_name() << "s" << endl;
        for(int i = 0; i < animals[random]->get_babies(); i++) { //adds the babies of that adult
            if(animals[random]->get_name() == "sea lion") {
                a = new Sea_Lion(0);
            }
            else if(animals[random]->get_name() == "bear") {
                a = new Bear(0);
            }
            else if(animals[random]->get_name() == "tiger") {
                a = new Tiger(0);
            }
            add_animal(a);
        }
    }
}

/****************************************************************************************
** Function: Animal::boom_event()
** Description: adds extra revenue based on how many seals the animals array has
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::boom_event() {
    int num_seals = 0;
    int num_baby_seals = 0;
    int random = rand()%251 + 150; //num between 150 and 400

    cout << "wowza alot of people came to the zoo" << endl;

    for(int i = 0; i < num_animals; i++) { //adds num baby seals and regular seals   
        if(animals[i]->get_name() == "sea lion") {
            (animals[i]->get_age() < 6) ? num_baby_seals++ : num_seals++;
        }
    }

    if(num_seals == 0) { // if there are no sea lions
        cout << "sadly you had no sea lions, perhaps it would be wise to purchase one" << endl;
    }
    else {
        cout << "you got " << random << " dollars more for each of your ";
        cout << num_seals << " sea lions";
        if(num_baby_seals != 0) { // baby seals will add twice the amount
            cout << ", and " << random*2 << " for your " << num_baby_seals << " baby sea lions";
        }
        cout << endl;
        cout << "You made an extra ";
        cout << (num_seals*random+num_baby_seals*random*2) << " dollars" << endl;
        money = (money + num_seals * random + num_baby_seals * random * 2);
    }
}

/****************************************************************************************
** Function: Animal::display_zoo()
** Description: displays number of animals, babies of those animals, and total money
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Zoo::display_zoo() {
    int seals = 0;
    int baby_seal = 0;
    int tigers = 0;
    int baby_tiger = 0;
    int bears = 0;
    int baby_bear = 0;
    for(int i = 0; i < num_animals; i++) { //adds amount of animals and baby animals
        if(animals[i]->get_name() == "sea lion") {
            (animals[i]->get_age() < 6) ? baby_seal++ : seals++;
        }
        else if(animals[i]->get_name() == "tiger") {
            (animals[i]->get_age() < 6) ? baby_tiger++ : tigers++;
        }
        else if(animals[i]->get_name() == "bear") {
            (animals[i]->get_age() < 6) ? baby_bear++ : bears++;
        }
        else {
            cout << "error in the print" << endl;
        }
    }
    cout << "you have: " << endl;
    cout << seals << " sea lions, " << bears << " bears, and " << tigers << " tigers" << endl;
    cout << baby_seal << " baby sea lions," << baby_bear << " baby bears, and " << baby_tiger << " baby tigers" << endl;
    
}

/****************************************************************************************
** Function: Animal::get_animal(int index)
** Description: returns animal pointer from index of animals array
** Parameters: int index
** Pre-Condition: input index of desired spot in array
** Post-Condition: return animal pointer
*****************************************************************************************/
Animal* Zoo::get_animal(int index) {
    return animals[index];
}

/****************************************************************************************
** Function: Animal::get_num_animals()
** Description: returns num animals from the Zoo class
** Parameters: none
** Pre-Condition: none
** Post-Condition: return in num animals
*****************************************************************************************/
int Zoo::get_num_animals() {
    return num_animals;
}

/****************************************************************************************
** Function: Animal::get_money()
** Description: returns money from the Zoo class
** Parameters: none
** Pre-Condition: none
** Post-Condition: return double money
*****************************************************************************************/
double Zoo::get_money() {
    return money;
}

/****************************************************************************************
** Function: Animal::get_food_cost()
** Description: returns food_cost from the Zoo class
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int food_cost
*****************************************************************************************/
double Zoo::get_food_cost() {
    return food_cost;
}

