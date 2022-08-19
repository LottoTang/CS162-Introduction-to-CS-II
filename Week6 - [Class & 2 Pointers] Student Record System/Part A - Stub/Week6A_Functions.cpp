#include "Week6A_Functions.h"
#include <iostream>
#include <iomanip>

//ID: L00690656 Week6A

using std::cin, std::cout, std::endl, std::string, std::setw, std::left;

/** int getInteger(int min, int max) : from previous lab
 * validate int type input with range validation
 * return value
 */

int getInteger(int min, int max)
{
    bool valid = true;
    int value = 0;

    do
    {
        valid = true;
        cin >> value;
        //check int type input and within range
        if ((cin.fail()) || ((value < min) || (value > max)))
        {
            if (cin.fail())
                cout << "Please enter an integer type value!: ";
            else
                cout << "Please enter within range! [" << min << " - " << max << "]: " ;

            //clear input buffer
            valid = false;
            cin.clear();
            cin.ignore(10000,'\n');
        }
    } while (!valid);

    return value;
}

/** Student **createStudent (int studentSize)
 * create pointer to the pointers of array (object) and pointers of array for object (e.g. student1,2,3,4,5...)
 * assign name, age to the object in the pointer of object
 * return pointer to the pointers of array
 */

Student **createStudent (int studentSize)
{
    /*
    create pointer to the pointers of array first
    for (int i = 0; i < studentSize; i++)
        create pointer of array for object
        pass (studentPtr+i) -> setName(name) && setAge(age)
    return studentPtr
    */

    //for testing purpose, set the size as 1
    Student **studentPtr = new Student*[studentSize];
    //Student studentPrt[i] = new Student();

    cout << "Student *createStudent (int studentSize)" << endl;
    cout << endl;

    return studentPtr;
}

/** void displayStudents (Student const* const studentPtr, int studentSize)
 * display the objects in the dynamic array
 */

void displayStudents (Student const* const studentPtr, int studentSize)
{
    /*
    for (int i = 0; i < studentSize; i++)
        display (studentPtr+i) -> getName() && getAge() with formatting (e.g.setw)
    */
    cout << "void displayStudents (Student const* const studentPtr, int studentSize)" << endl;
    cout << endl;
}

