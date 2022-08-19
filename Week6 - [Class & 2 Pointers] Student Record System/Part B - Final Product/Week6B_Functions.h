#ifndef WEEK6B_FUNCTIONS_H_INCLUDED
#define WEEK6B_FUNCTIONS_H_INCLUDED
#include <iostream>
#include "Week6B_Student.h"

//ID: L00690656 Week6B

//function header
int getInteger(int min, int max);

Student **createStudent (int studentSize);

void displayStudents (Student * const * const studentPtr, int studentSize);

#endif // WEEK6B_FUNCTIONS_H_INCLUDED
