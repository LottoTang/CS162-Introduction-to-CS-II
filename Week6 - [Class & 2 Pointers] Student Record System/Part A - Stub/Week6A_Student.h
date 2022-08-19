#ifndef WEEK6A_STUDENT_H_INCLUDED
#define WEEK6A_STUDENT_H_INCLUDED
#include <iostream>

//ID: L00690656 Week6A

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

        //inline function (compare the name in ascending order)
        inline bool operator < (const Student &ex1) const
        {
            return this->name < ex1.name;
        }
};

#endif // WEEK6A_STUDENT_H_INCLUDED
