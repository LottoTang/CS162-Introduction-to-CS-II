#ifndef WEEK7A_PLAYER_H_INCLUDED
#define WEEK7A_PLAYER_H_INCLUDED
#include "Week7A_Person.h"
#include <iostream>

//ID: L00690656 Week7A

using std::string;

//create the class Player
class Player

{
    public :
        //create an instance of Person person in class Player
        Person person;

        //default and overloaded constructor
        Player() : person(){}
        Player(string firstName, string lastName, int age) : person(firstName, lastName, age){}

        //getter
        string getPlayerName() const {return person.getFirstName() + " " + person.getLastName();}
        int getPlayerAge() const {return person.getAge();}
};

#endif // WEEK7A_PLAYER_H_INCLUDED
