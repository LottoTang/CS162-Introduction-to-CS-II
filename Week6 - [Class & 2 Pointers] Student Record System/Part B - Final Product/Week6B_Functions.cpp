#include "Week6B_Functions.h"
#include <iostream>
#include <iomanip>

//ID: L00690656 Week6B

using std::cin, std::cout, std::endl, std::string, std::setw, std::left;

/** int getInteger(int min, int max)
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
    string str = "\n";
    string name = "";
    int age = 0;

    //create pointer to the pointers of array dynamically
    Student **studentPtr = new Student*[studentSize];

    for (int i = 0; i < studentSize; i++)
    {
        //create array of pointers of object
        //studentPtr[i] = new Student(); (for default constructor version)

        getline(cin, str);

        //ask for name
        cout << "Please enter the name of student " << i+1 << ": ";
        getline(cin, name);
        //studentPtr[i]->setName(name); (for default constructor version)
        cout << endl;

        //ask for age
        cout << "Please enter the age of student " << i+1 << " [" << AGE_MIN << " - " << AGE_MAX << "]: ";
        age = getInteger(AGE_MIN, AGE_MAX);
        //studentPtr[i]->setAge(age); (for default constructor version)
        cout << endl;

        //create array of pointers of object (for overloaded version)
        studentPtr[i] = new Student(age, name);
    }

    return studentPtr;
}

/** void displayStudents (Student const* const studentMembers, int studentSize)
 * display the objects in the dynamic array
 */

void displayStudents (Student * const * const studentPtr, int studentSize)
{
    cout << setw(10) << left << "Index " << setw(20) << "Name " << setw(15) << "Age " << endl;

    for (int i = 0; i < studentSize; i++)
    {
        cout << setw(10) << left << i+1 << setw(20) << studentPtr[i]->getName() << setw(15) << studentPtr[i]->getAge() << endl;
    }
}
