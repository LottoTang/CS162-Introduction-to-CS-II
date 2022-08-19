#include "Week7B_Player.h"

//ID: L00690656 Week7B_ver2

//Player.cpp

using std::string;

//function definition for Player

//constructor
Player:: Player(): person(new Person()){}
Player:: Player(string firstName, string lastName, int age) : person(new Person(firstName, lastName, age)){}

//Player's function getPlayerName (return the full name); getPlayerAge (get player's age)
string Player:: getPlayerName() const {return person->getFirstName() + " " + person->getLastName();}
int Player:: getPlayerAge() const {return person->getAge();}

//function definition for 4 Classes derived from Player

//Ranger overloaded constructor
Ranger:: Ranger(string firstName, string lastName, int age) : Player(firstName, lastName, age){}

//Ranger destructor
Ranger:: ~Ranger(){}

//functions for overriding (return respective class and action)
string Ranger:: getClassName() const {return "Ranger";}
string Ranger:: getAction() const {return "shoots arrow";}

Wizard:: Wizard(string firstName, string lastName, int age) : Player(firstName, lastName, age){}
Wizard:: ~Wizard(){}
string Wizard:: getClassName() const {return "Wizard";}
string Wizard:: getAction() const {return "casts fireballs";}

Rogue:: Rogue(string firstName, string lastName, int age) : Player(firstName, lastName, age){}
Rogue:: ~Rogue(){}
string Rogue:: getClassName() const {return "Rogue";}
string Rogue:: getAction() const {return "picks pockets";}

Priest:: Priest(string firstName, string lastName, int age) : Player(firstName, lastName, age){}
Priest:: ~Priest(){}
string Priest:: getClassName() const {return "Priest";}
string Priest:: getAction() const {return "heals";}
