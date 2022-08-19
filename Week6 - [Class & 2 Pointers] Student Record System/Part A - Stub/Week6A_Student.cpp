#include "Week6A_Student.h"
#include <iostream>

//ID: L00690656 Week6A

using std::string;

//constructor/ destructor definition
Student:: Student(): age(0), name(""){}
Student:: Student(int age, string name): age(age), name(name){}
Student:: ~Student() {};

//setters definition
void Student::setAge(int age)
{
    this->age = age;
}

void Student::setName(string name)
{
    this->name = name;
}

//getters definition

int Student::getAge() const
{
    return age;
}

string Student::getName() const
{
    return name;
}
