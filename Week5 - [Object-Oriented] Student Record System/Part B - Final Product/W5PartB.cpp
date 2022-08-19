#include <iostream>
#include <algorithm>
#include <iomanip>
#include "W5PartB.h"

// ID: L00690656, W5_PartB

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
    int value = 0;
    bool valid = true;

    do
    {
        valid = true;
        cin >> value;

        //check if value within range && int type
        if (cin.fail() || (value < min || value > max))
        {
            if (cin.fail())
                cout << "Please enter an integer: ";
            else
                cout << "Please enter within range!: ";

            //invalid input and clear input buffer
            valid = false;
            cin.clear();
            cin.ignore(100000000,'\n');
        }
    } while (!valid);

    return value;
}

/* string getLnumber ()
 * get Lnumber and validate within 111111-999999
 * return idString in form of L00XXXXXX (student Lnumber)
 */

string getLnumber ()
{
    int idNumber;
    string idString = {};

    idNumber = getInteger(111111,999999);

    //concatenate "L00" with 6 digits converted to string
    idString = "L00" + to_string(idNumber);

    return idString;
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
    float gpa = 0.00;
    bool valid = true;
    do
    {
        valid = true;
        cout << "Please enter the GPA [2.00 - 4.20]: ";
        cin >> gpa;

        if (cin.fail() || (gpa < GPA_MIN) || (gpa > GPA_MAX))
        {
            if (cin.fail())
                cout << "Please enter a numeric value!" << endl;
            else
                cout << "Please enter within range!" << endl;

            cout << endl;
            valid = false;
            cin.clear();
            cin.ignore(10000,'\n');
        }

    } while(!valid);

    return gpa;
}

/* void insertArray(Student * const studentArray, int counter)
 * find the appropriate location for the array to insert based on Lnumber (ascending order)
 */

void insertArray(Student * const studentArray, int counter)
{
    int index = counter - 1;

    //check if new Lnumber < previous Lnumber stored in studentArray - repeat and go through the whole array if necessary
    while ((index >=0) && ((studentArray+(index+1))->Lnumber < (studentArray+index)->Lnumber))
    {
        //swap the members between the 2 locations
        swap((studentArray+(index+1))->Lnumber, (studentArray+index)->Lnumber);
        swap((studentArray+(index+1))->firstName, (studentArray+index)->firstName);
        swap((studentArray+(index+1))->lastName, (studentArray+index)->lastName);
        swap((studentArray+(index+1))->gpa, (studentArray+index)->gpa);
        index -= 1;
    }
}

/* Student *createArray (int arraySize)
 * create the dynamic array type Student with arraySize
 * return studentArray
 */

Student *createArray (int arraySize)
{
   int counter = 0;
   string str = "\n";

   //create dynamic array with pointer
   Student *studentArray = new Student[arraySize];

   //access the members with -> notation
   for (int i = 0; i < arraySize; i++)
   {
       getline(cin,str);

       cout << "Please enter the first name of student " << i+1 << ": ";
       getline(cin, (studentArray+i)->firstName);
       cout << endl;

       cout << "Please enter the last name of student " << i+1 << ": ";
       getline(cin, (studentArray+i)->lastName);
       cout << endl;

       cout << "Please enter the Lnumber - 6 digits of student ID (e.g.L00XXXXXX [111111-999999]) of student " << i+1 << ": ";
       (studentArray+i)->Lnumber = getLnumber();
       cout << endl;

       cout << "Please enter the GPA of student " << i+1 << ": ";
       (studentArray+i)->gpa = getGPA();
       cout << endl;

       //find the appropriate way to store the elements
       insertArray(studentArray, counter);
       counter++;
   }

   return studentArray;
}

/* void displayArray(Student const * const studentArray, int arraySize)
 * display the index and content of the array
 * the format is good when length of name < 15 (assuming length of first/nickname < 15)
 */

void displayArray(Student const * const studentArray, int arraySize)
{  //display result with formatting
    cout << setw(10) << left << "Index:" << setw(15) << "First Name:" << setw(15) << "Last Name:" << setw(15) << "Lnumber:" << setw(15) << "GPA:" << endl;

    cout << std::setprecision(2);

    //display the elements
    for (int i = 0; i < arraySize; i++)
    {
        cout << setw(10) << left << i+1 << setw(15) << (studentArray+i)->firstName << setw(15) << (studentArray+i)->lastName << setw(15) << (studentArray+i)->Lnumber << setw(15) << std::fixed << (studentArray+i)->gpa << endl;;
    }
}

/* bool binSearch (Student const * const studentArray, int arraySize, string name, int &location)
 * search if the name is found in the array using binary search
 * pass in a SORTED array
 * return found (true for the name is in the array, and vice versa)
 */

bool binSearch (Student const * const studentArray, int arraySize, string name, int &location)
{
    int min = 0;
    int max = arraySize - 1;
    bool found = false;

    while ((max >= min) && (!found))
    {
        //cut the number of search into half
        int mid = (min + max) / 2;

        //found
        string lowerName = (studentArray+mid)->lastName;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        if (lowerName == name)
        {
            found = true;
            location = mid + 1;
        }
        else
        {
            //update max and min if not found (based on alphabetical order)
            if (lowerName > name)
            {
                max = mid - 1;
                found = false;
            }
            else
            {
                min = mid + 1;
                found = false;
            }
        }
    }

    return found;
}

/* void pressContinue()
 * intentionally pause the program by requesting user's input
 */

void pressContinue()
{
    string temp;
    cout << endl;
    cout << "Press Anything then Enter to Continue... ";
    getline(cin, temp);
    cin.clear();
    cin.ignore(10000,'\n');
}
