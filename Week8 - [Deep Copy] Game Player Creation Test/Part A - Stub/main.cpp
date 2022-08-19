//
//  main.cpp
//  Lab 8 Player List
//
//  Created by jim bailey on 2/22/21.
//

//ID: L00690656 Week8A

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cin, std::cout, std::endl, std::string;

#include "Helper.hpp"

#define TEST_PERSON
#define TEST_POLY
#define TEST_OPERATORS


#ifdef TEST_PERSON
#include "W8_Person.h"
#endif
#if defined(TEST_POLY) or defined(TEST_OPERATORS)
#include "W8_Player.h"
#endif

int main()
{
    // initalize random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    string fName, lName;
    int age;

#ifdef TEST_PERSON

    //create Person object
    cout << "Testing Person" << endl;
    makePersonInfo(fName, lName, age);
    Person testPerson(fName, lName, age);
    cout << endl;

    //display testPerson info
    cout << "Testing constructor" << endl;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " " << testPerson.getLastName() << " " << testPerson.getAge() << endl;
    cout << endl;

    //create a new Person object
    makePersonInfo(fName, lName, age);

    //set the new Person object info to existing testPerson (expect replacing the original personal info)
    testPerson.setFirstName(fName);
    testPerson.setLastName(lName);
    testPerson.setAge(age);

    //display replaced testPerson
    cout << "Testing setters" << endl;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " "
    << testPerson.getLastName() << " " << testPerson.getAge() << endl;
    cout << endl;

    cout << "Done testing Person " << endl << endl;

#endif // TEST_PERSON

#ifdef TEST_POLY

    cout << "Testing Player polymorphism" << endl;
    cout << endl;

    //create pointer to the pointer of array
    Player ** players = new Player * [eNUM_CHARS];

    //create players[] pointer pointing to Derived classes / Player object
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        players[i] = makePlayer(static_cast<Characters>(i));
    }

    //display the content of the players array
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        cout << " " << players[i]->getPlayerName()
        << " aged " << players[i]->getPlayerAge()
        << " playing a " << players[i]->getClassName()
        << " " << players[i]->getAction() << endl;
    }

    //free up the memory
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        delete players[i];
    }
    delete [] players;

    cout << endl;
    cout << "Done testing Player polymorphism" << endl << endl;

#endif // TEST_POLY

#ifdef TEST_OPERATORS

    //create priest and ranger class object
    cout << "Testing overloaded operators for Player" << endl << endl;
    Player * priest = makePlayer(ePriest);
    Player * ranger = makePlayer(eRanger);
    //shallow copying
    Player copy(*priest);


    cout << "The priest and priest copy are: " << endl;
    cout << " " << *priest << " with the address: " << priest->getAddress() << endl;
    cout << " " << copy << " with the address: " << copy.getAddress() << endl << endl;

    //original copy: *priest is replaced by *ranger (hard copying)
    copy = *ranger;
    cout << "The ranger and assigned copy are: " << endl;
    //expect copy's address is unchanged
    cout << " " << *ranger << ranger->getAddress() << endl;
    cout << " " << copy << copy.getAddress() << endl << endl;

    cout << "The priest and ranger " << ((*ranger==*priest)?"are":"are not") << " equal." << endl;
    cout << "The ranger and copy " << ((*ranger==copy)?"are":"are not") << " equal." << endl << endl;

    cout << "Done testing overloaded operators for Player" << endl << endl;

    //free up the memory by calling the overriding destructor
    delete priest;
    delete ranger;

#endif // TEST_OPERATORS

    return 0;
}
