#include <iostream>
#include <algorithm>
#include "Week6A_Functions.h"

//ID: L00690656 Week6A

using std::cout, std::sort, std::endl;

int main()
{
    /*
    program instruction
    ask for studentSize from getInteger(STUDENT_MIN, STUDENT_MAX)
    create the pointer of pointers of array, followed by pointers to array (object - student1,2,3,4,5...)
    sort the array in ascending order based on name
    display the array
    free up the dynamic array

    functions sequence:
    getInteger(STUDENT_MIN, STUDENT_MAX)
    Student **studentPtr = createStudent(studentSize);
    sort(studentPtr, studentPtr+studentSize);
    displayStudents(studentPtr, studentSize);
    delete [] studentPtr;
    */

    //program instruction
    cout << "How many students in your class? [1-999999]: " << endl;

    cout << endl;

    cout << "Ask for studentSize by getInteter(MIN,MAX)" << endl;

    cout << endl;

    cout << "Create pointer to pointer of arrays, followed by pointers to array (object)" << endl;

    cout << endl;

    cout << "Sort the array in ascending order by sort()" << endl;

    cout << endl;

    cout << "Display array by displayStudents()" << endl;

    cout << endl;

    cout << "Delete dynamic memory by delete []" << endl;
}
