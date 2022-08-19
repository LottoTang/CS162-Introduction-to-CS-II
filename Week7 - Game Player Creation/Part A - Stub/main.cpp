#include <iostream>
#include "Week7A_Person.h"
#include "Week7A_Player.h"

//ID: L00690656 Week7A

using std::endl;
using std::cout;

int main()
{
    //create default per1 from class Person
    Person per1;

    //test default constructor for Person
    cout << "Default Person - per1 (first name): " << per1.getFirstName() << endl;
    cout << "Default Person - per1 (last name): " << per1.getLastName() << endl;
    cout << "Default Person - per1 (age): " << per1.getAge() << endl;
    cout << endl;

    //test setters and getters for Person
    per1.setFirstName("Apple");
    per1.setLastName("Juice");
    per1.setAge(13);

    //test getters
    cout << "Default Person - per1 (first name): " << per1.getFirstName() << endl;
    cout << "Default Person - per1 (last name): " << per1.getLastName() << endl;
    cout << "Default Person - per1 (age): " << per1.getAge() << endl;
    cout << endl;

    //test overloaded constructor for Person
    Person per2 ("Water", "Melon", 18);

    cout << "Overloaded Person - per2 (first name): " << per2.getFirstName() << endl;
    cout << "Overloaded Person - per2 (last name): " << per2.getLastName() << endl;
    cout << "Overloaded Person - per2 (age): " << per2.getAge() << endl;
    cout << endl;


    //create default play1 from class Player
    Player play1;

    //test default constructor for Player
    cout << "Default Player - play1 (first name): " << play1.person.getFirstName() << endl;
    cout << "Default Player - play1 (last name): " << play1.person.getLastName() << endl;
    cout << "Default Player - play1 (age): " << play1.person.getAge() << endl;
    cout << endl;

    //test setters and getters for Player from Person
    play1.person.setFirstName("Orange");
    play1.person.setLastName("Biscuit");
    play1.person.setAge(28);

    //test getters for Player from Person
    cout << "Default Player - play1 (first name): " << play1.person.getFirstName() << endl;
    cout << "Default Player - play1 (last name): " << play1.person.getLastName() << endl;
    cout << "Default Player - play1 (age): " << play1.person.getAge() << endl;
    cout << endl;

    //test overloaded constructor for Player
    Player play2("Chocolate", "Cake", 33);

    cout << "Overloaded Player - play2 (first name): " << play2.person.getFirstName() << endl;
    cout << "Overloaded Player - play2 (last name): " << play2.person.getLastName() << endl;
    cout << "Overloaded Player - play2 (age): " << play2.person.getAge() << endl;
    cout << endl;

    cout << "Overloaded Player - play2 (first name & last name by getPlayerName()): " << play2.getPlayerName() << endl;
    cout << "Overloaded Player - play2 (age by getPlayerAge()): " << play2.getPlayerAge() << endl;
    cout << endl;

    return 0;
}
