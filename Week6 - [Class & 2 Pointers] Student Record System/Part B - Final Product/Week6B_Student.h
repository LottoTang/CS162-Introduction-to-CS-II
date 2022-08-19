#ifndef WEEK6B_STUDENT_H_INCLUDED
#define WEEK6B_STUDENT_H_INCLUDED
#include <iostream>

//ID: L00690656 Week6B

using std::string;

//constant declaration
const int AGE_MAX = 90;
const int AGE_MIN = 10;
const int STUDENT_MAX = 999999;
const int STUDENT_MIN = 1;

//class declaration
class Student
{
    private:
        //class variables
        int age;
        string name;

    public:
        //constructors & destructor
        Student();
        Student(int age, string name);
        ~Student();

        //setters
        void setAge(int age);
        void setName(string name);

        //getters
        int getAge() const;
        string getName() const;

        //inline function (compare the name in ascending order): overload with operator
        inline bool operator() (Student const * const student1, Student const * const student2)
        {
            return student1->getName() < student2->getName();
        }
};

#endif // WEEK6A_STUDENT_H_INCLUDED
