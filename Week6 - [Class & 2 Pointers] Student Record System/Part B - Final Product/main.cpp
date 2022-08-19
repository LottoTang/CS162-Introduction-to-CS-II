#include <iostream>
#include <algorithm>
#include "Week6B_Functions.h"

//ID: L00690656 Week6B

using std::cout, std::sort, std::endl;

int main()
{
    int studentSize = 0;

    //program instruction
    cout << "How many students in your class? [1-999999]: ";
    studentSize = getInteger(STUDENT_MIN, STUDENT_MAX);
    cout << endl;

    //create the pointer to an array of pointers to students and stored in main()
    Student **studentPtr = createStudent(studentSize);

    //sort the array in ascending order based on name
    sort(studentPtr, studentPtr+studentSize, Student());

    displayStudents(studentPtr, studentSize);

    //free up the memory for the pointer to array (object), then pointer to pointer
    for (int i = 0; i < studentSize; i++)
    {
        delete *(studentPtr+i);
    }
    delete [] studentPtr;
}
