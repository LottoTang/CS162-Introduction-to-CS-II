#ifndef WEEK6A_FUNCTIONS_H_INCLUDED
#define WEEK6A_FUNCTIONS_H_INCLUDED
#include <iostream>
#include "Week6A_Student.h"

//ID: L00690656 Week6A

//function header
int getInteger(int min, int max);

Student **createStudent (int studentSize);

void displayStudents (Student * const * const studentPtr, int studentSize);

#endif // WEEK6A_FUNCTIONS_H_INCLUDED
