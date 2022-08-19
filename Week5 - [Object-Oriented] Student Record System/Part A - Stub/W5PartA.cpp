#include <iostream>
#include <algorithm>
#include <iomanip>
#include "W5PartA.h"

// ID: L00690656, W5_PartA

using std::cout;
using std::cin;
using std::to_string;
using std::setw;
using std::left;
using std::endl;
using std::swap;

/* int getInteger (int min, int max)
 * check user input (int type) within range
 * return value
 */

int getInteger (int min, int max)
{

    cout << "int getInteger (int min, int max)" << endl;
    cout << "validate int value within range, return value" << endl;
    cout << endl;

    /*
    do
        cin >> value
        check cin.fail || out of range
        if true
            error message
            valid = false
    while (!valid)
    return value
    */

    return 0;
}

/* string getLnumber ()
 * get Lnumber and validate within 111111-999999
 * return idString in form of L00XXXXXX (student Lnumber)
 */

string getLnumber ()
{
    cout << "string getLnumber ()" << endl;
    cout << "get Lnumber validated by getInteger [111111-999999] and concatenate with L00XXXXXX, return string idString" << endl;
    cout << endl;

    int idNumber;
    string idString = {};

    return idString;

    /*
    get value from getInteger(111111-999999)
    data validated by getInteger()
    concatenate with string idString & value
    return idString
    */
}

/* bool comparisonLastName (Student &ex1, Student &ex2)
 * compare the lastname from struct Student
 * return ex1.lastName < ex2.lastName
 */

bool comparisonLastName (Student &ex1, Student &ex2)
{
    return ex1.lastName < ex2.lastName;
}

/* float getGPA()
 * get gpa in range of 2.00 - 4.20
 * return gpa
 */

float getGPA()
{
    cout << "float getGPA()" << endl;
    cout << "validate float gpa within range, return gpa" << endl;
    cout << endl;

    /*
    do
        cin >> gpa
        check cin.fail || out of range (2.00-4.20)
        if true
            error message
            valid = false
    while (!valid)
    return gpa
    */

    float gpa = 2.00;
    return gpa;
}

/* void insertArray(Student *studentArray, int counter, int arraySize)
 * find the appropriate location for the array to insert based on Lnumber (ascending order)
 */

 void insertArray(Student *studentArray, int counter)
{
    cout << "void insertArray(Student *studentArray, int counter)" << endl;
    cout << "find the appropriate location for the array to insert based on Lnumber (ascending order)" << endl;
    cout << endl;

    /*
    index = counter - 1
    while(index >=0 && studentArray[index+1].Lnumber < studentArray[index].Lnumber)
        swap(studentArray[index+1].Lnumber, studentArray[index].Lnumber)
        repeat swap for firstname, lastname, gpa
        index--
    */

}

/* Student *createArray (int arraySize)
 * create the dynamic array type Student with arraySize
 * return studentArray
 */

Student *createArray (int arraySize)
{
   int counter = 0;

   Student *studentArray = new Student[arraySize];

   return studentArray;

    /*
    for (int i = 0; i < arraySize, i++)
        ask for studentArray.firstname
        ask for studentArray.lastname
        ask for studentArray.Lnumber
        ask for studentArray.gpa
        counter++
    return studentArray
    */

}

/* void displayArray(string const nameArray[], int arrayCount)
 * display the index and content of the array
 * the format is good when length of name < 15 (assuming length of first/nickname < 15)
 */

void displayArray(Student const studentArray[], int arraySize)
{
    //display result with formatting
    cout << "void displayArray(Student const studentArray[], int arraySize)" << endl;
    cout << "display array with formatting" << endl;
    cout << endl;
}

/* bool binSearch (string const nameArray[], int arrayCount, string name, int &location) - from Lab2B
 * search if the name is found in the array using binary search
 * pass in a SORTED array
 * return found (true for the name is in the array, and vice versa)
 */

bool binSearch (Student const studentArray[], int arraySize, string name, int &location)
{
    int min = 0;
    int max = arraySize - 1;
    bool found = false;

    cout << "bool binSearch (Student const studentArray[], int arraySize, string name, int &location)" << endl;
    cout << "check if the array contains the lastname provided by user, update location, return found" << endl;
    cout << "true: found, false: not found" << endl;
    cout << endl;

    /*
    while ((max >= min) && (!found))
    {
        int mid = (min + max) / 2;
        if ((studentArray[mid].lastName) == name)
            found = true;
            location = mid + 1;
        else
            if (studentArray[mid].lastName > name)
                max = mid - 1;
                found = false;
            else
                min = mid + 1;
                found = false;
    }
    */

    return found;
}

/* void pressContinue()
 * intentionally pause the program by requesting user's input
 */

void pressContinue()
{
    cout << "void pressContinue()" << endl;
    cout << "temporarily pause the program by asking user's input" << endl;
    cout << endl;

    /*
    cin >> temp
    cin.clear()
    cin.ignore(10000,'\n')
    */
}
