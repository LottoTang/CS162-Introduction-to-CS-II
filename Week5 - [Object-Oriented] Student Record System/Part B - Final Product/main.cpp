#include <iostream>
#include <algorithm>
#include "W5PartB.h"

//ID: L00690656, W5_PartB

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{

    //variable declaration and initialization
    int arraySize = 0, location = 0;
    bool found = false;
    string name;

    //program introduction and instruction
    cout << "The program will search the last name of a student and show his/her personal particulars" << endl;
    cout << endl;
    cout << "How many students' particulars to be entered?: ";


    //get the number of students to enter (assume 999999 is the max. no. of student)
    arraySize = getInteger(RANGE_MIN, RANGE_MAX);
    cout << endl;

    //create array of struct Student dynamically
    Student *studentArray = createArray(arraySize);
    cout << endl;

    cout << "Students' first name, last name, Lnumber and GPA (sorted based on Lnumber in ascending order)" << endl;
    cout << endl;
    //display database sorted by Lnumber
    displayArray(studentArray, arraySize);

    pressContinue();

    //prepare a SORTED array before binary search
    std::sort(studentArray, studentArray+arraySize, comparisonLastName);
    cout << endl;

    cout << "Type the last name of the student you want to be checked: ";
    getline(cin, name);

    //convert all input into lowercase for comparison in binary search
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout << endl;
    cout << "Students' particulars (sorted based on students' last name in ascending order)" << endl;
    cout << endl;

    //display database sorted by last name
    displayArray(studentArray, arraySize);

    //check if such name is found in database
    found = binSearch(studentArray, arraySize, name, location);

    cout << endl;

    //display result
    if (found)
        cout << name << " is found in the database at index " << location << "."  << endl;
    else
        cout << "No such name in the database!" << endl;

    cout << endl;

    cout << "Bye!" << endl;

    //delete the dynamic array to free up the heap memory
    delete[] studentArray;

    return 0;
}
