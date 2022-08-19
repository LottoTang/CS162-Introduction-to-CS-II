//
//  main.cpp
//  Template List
//
//  Created by jim bailey on 3/8/21.
//

/* ID: L00690656 Week9B
 * main.cpp */

#include <iostream>
#include "List.h"
#include "Person.hpp"

using std::cout, std::endl, std::string;

int main()
{
    const int SIZE = 6;
    const int NUM_PERSONS = 2;
    string words[] = {"ant", "bear", "cat", "dog", "eel", "fish"};
    Person bilbo("Bilbo", "Baggins", 121);
    Person gandalf("Gandalf", "The Grey", 10000);
    Person frodo("Frodo", "Baggins", 33);

    //create List instance with different <type>
    List<int> intList;
    List<string> stringList;
    List<Person*> personList;

    // testing integers
    for (int i = 0; i < SIZE; i++)
    {
        intList.addHead(2 * i + 1);
    }

    int num1 = 4, num2 = 5;
    cout << num1 << (intList.findValue(num1)?" is":" is not") << " there " << endl;
    cout << num2 << (intList.findValue(num2)?" is":" is not") << " there " << endl << endl;;

    for (int i = 0; i < SIZE; i++)
    {
        cout << intList.getHead() << " ";
        intList.removeHead();
    }
    cout << endl << endl;;

    // testing strings
    for (int i = 0; i < SIZE; i++)
    {
        stringList.addHead(words[i]);
    }

    string word1 = "cat", word2 = "goat";
    cout << word1 << (stringList.findValue(word1)?" is":" is not") << " there " << endl;
    cout << word2 << (stringList.findValue(word2)?" is":" is not") << " there " << endl << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << stringList.getHead() << " ";
        stringList.removeHead();
    }
    cout << endl << endl;;

    // testing Persons
    personList.addHead(&bilbo);
    personList.addHead(&gandalf);

    cout << bilbo << (personList.findValue(&bilbo)?" is":" is not") << " there " << endl;
    cout << frodo << (personList.findValue(&frodo)?" is":" is not") << " there " << endl << endl;;

    for (int i = 0; i < NUM_PERSONS; i++)
    {
        cout << *(personList.getHead()) << endl;
        personList.removeHead();
    }
    cout << endl;

    // testing Exception
    try{
        cout << intList.getHead() << endl;
        cout << "Should have thrown an exception." << endl;
    }
    catch(list_error &ex){
        cout << "List error saying: " << ex.what() << endl;
    }
    catch( ... ) {
        cout << "Caught something else" << endl;
    }

    return 0;
}
