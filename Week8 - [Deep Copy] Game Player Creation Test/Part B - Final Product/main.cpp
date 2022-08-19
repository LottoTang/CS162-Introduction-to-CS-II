//
//  main.cpp
//  Lab 8 Player List
//
//  Created by jim bailey on 2/22/21.
//

//ID: L00690656 Week8B

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cin, std::cout, std::endl, std::string;

#include "Helper.hpp"

#define TEST_PERSON
#define TEST_POLY
#define TEST_OPERATORS
#define TEST_LIST

#ifdef TEST_PERSON
#include "W8_Person.h"
#endif
#if defined(TEST_POLY) or defined(TEST_OPERATORS)
#include "W8_Player.h"
#endif
#ifdef TEST_LIST
#include "W8_List.h"
#endif


int main()
{
    // initalize random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    string fName, lName;
    int age;

#ifdef TEST_PERSON

    cout << "Testing Person" << endl << endl;;

    makePersonInfo(fName, lName, age);

    //create Person object: testPerson
    Person testPerson(fName, lName, age);

    cout << "Testing constructor" << endl << endl;;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " "
    << testPerson.getLastName() << " " << testPerson.getAge() << endl << endl;

    //replaced the original testPerson with new fName, lName, age
    makePersonInfo(fName, lName, age);
    testPerson.setFirstName(fName);
    testPerson.setLastName(lName);
    testPerson.setAge(age);

    cout << "Testing setters" << endl << endl;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " "
    << testPerson.getLastName() << " " << testPerson.getAge() << endl << endl;

    cout << "Done testing Person " << endl << endl;

#endif // TEST_PERSON

#ifdef TEST_POLY
    cout << "Testing Player polymorphism" << endl << endl;

    //create pointer to the pointer of Player
    Player ** players = new Player * [eNUM_CHARS];

    //create Player or Derived Class objects stored in players pointer
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        players[i] = makePlayer(static_cast<Characters>(i));
    }

    //test get function from Player class
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        cout << " " << players[i]->getPlayerName()
        << " aged " << players[i]->getPlayerAge()
        << " playing a " << players[i]->getClassName()
        << " " << players[i]->getAction() << endl;
    }

    //free up memory
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        delete players[i];
    }
    delete [] players;

    cout << endl << "Done testing Player polymorphism" << endl << endl;

#endif // TEST_POLY

#ifdef TEST_OPERATORS

    cout << "Testing overloaded operators for Player" << endl;
    Player * priest = makePlayer(ePriest);
    Player * ranger = makePlayer(eRanger);
    //create a copy of priest by soft copying
    Player copy(*priest);

    cout << "The priest and priest copy are: " << endl;
    cout << " " << *priest << endl;
    cout << " " << copy << endl << endl;

    //test for operator= (hard copying)
    copy = *ranger;
    cout << "The ranger and assigned copy are: " << endl;
    cout << " " << *ranger << endl;
    cout << " " << copy << endl << endl;

    cout << "The priest and ranger " << ((*ranger==*priest)?"are":"are not") << " equal." << endl;
    cout << "The ranger and copy " << ((*ranger==copy)?"are":"are not") << " equal." << endl << endl;

    cout << "Done testing overloaded operators for Player" << endl << endl;

    //free up memory by calling overriding destructor
    delete priest;
    delete ranger;

#endif // TEST_OPERATORS

#ifdef TEST_LIST

    cout << "Testing the List functionality" << endl << endl;
    const int MAX_ITEMS = 7;

    //create the LinkedList with the head nullptr
    List theList;

    // creating an array of random characters
    Player ** playerArray = new Player*[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        Characters theCharacter = static_cast<Characters>
                (rand() %(eNUM_CHARS-1)+1);
        playerArray[i] = makePlayer(theCharacter);
    }
    cout << "The playerArray is " << endl << endl;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        cout << *(playerArray[i]) << endl;
    }
    cout << endl;

    // now adding those items to the list
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        theList.addHead(playerArray[i]);
    }

    // testing against a bilbo
    Rogue bilbo("Bilbo", "Baggins", 51);

    cout << "Biblo " << (theList.findValue(&bilbo)?"is":"is not")
        << " in the list" << endl << endl;

    //test remove head
    cout << "Removing items, should be in reverse order" << endl;
    try {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            cout << *(theList.getHead()) << endl;
            theList.removeHead();
        }
    }
    catch(std::range_error & ex){
        cout << "Caught range error saying: " << ex.what() << endl;
    }
    catch(...) {
        cout << "Caught unknown exception" << endl;
    }
    cout << endl;


    cout << "Now getting one extra item, should get exception" << endl;
    try {
        Player * temp = theList.getHead();
        cout << "Get head succeeded and got" << endl;
        cout << temp << endl;
    }
    catch(std::range_error & ex){
        cout << "Caught range error saying: " << ex.what() << endl;
    }
    catch(...) {
       cout << "Caught unknown exception" << endl;
    }
    cout << endl;

    // now redoing it with Bilbo in the middle
    for (int i = 0; i < 3; i++)
    {
        theList.addHead(playerArray[i]);
    }
    theList.addHead(&bilbo);
    for (int i = 3; i < MAX_ITEMS; i++)
    {
        theList.addHead(playerArray[i]);
    }

    cout << "After creating a new list containing bilbo" << endl;
    cout << "Biblo " << (theList.findValue(&bilbo)?"is":"is not")
        << " in the list" << endl;

    cout << "Here he is" << endl;
    cout << bilbo << endl << endl;

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        delete playerArray[i];
    }
    delete [] playerArray;

    cout << "Done testing the List functionality" << endl << endl;

#endif // TEST_LIST


    return 0;
}
