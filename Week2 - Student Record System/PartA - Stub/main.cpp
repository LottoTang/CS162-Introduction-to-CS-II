#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "W2PartA.h"

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::setw;
using std::left;
using std::endl;

int main()
{
    //variable declaration and initialization
    int const SIZE = 20;
    int arrayCount = 0;
    int location = -1;
    bool found = false;
    string nameArray[SIZE] = {};
    string name;

    //program introduction and instruction
    cout << "The program will search the name of a student from the array!" << endl;
    cout << endl;
    cout << "How many names do you want to input [5-20]?: ";

    //function call
    arrayCount = getInteger(5,20);

    cout << endl;
    fillArray(nameArray, arrayCount);

    cout << endl;
    cout << "Type the name of the student you want to be checked: ";

    cin >> name;

    //convert all input into lowercase for comparison in binary search
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    cout << endl;
    cout << "** The name array sorted in ascending order **" << endl;
    displayArray(nameArray, arrayCount);

    found = binSearch(nameArray, arrayCount, name, location);

    cout << endl;

    //display result
    if (found)
        cout << name << " is found in the array at index " << location << "."  << endl;
    else
        cout << "No such name in the array!" << endl;

    cout << endl;

    cout << "Bye!" << endl;

    return 0;
}
