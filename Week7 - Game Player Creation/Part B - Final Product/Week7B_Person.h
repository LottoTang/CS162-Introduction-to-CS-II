#ifndef WEEK7B_PERSON_H_INCLUDED
#define WEEK7B_PERSON_H_INCLUDED
#include <iostream>

//ID: L00690656 Week7B_ver2

using std::string;

//declaration of class Person
class Person
{
    private:
        string firstName;
        string lastName;
        int age;

    public:
        //default constructor and overloaded constructor using initialization list
        Person(): firstName(""), lastName(""), age(0){}
        Person(string firstName, string lastName, int age) : firstName(firstName), lastName(lastName), age(age){}
        //destructor
        ~Person(){}

        //setters
        void setFirstName (string firstName) {this->firstName = firstName;}
        void setLastName (string lastName) {this->lastName = lastName;}
        void setAge (int age) {this->age = age;}

        //getters
        string getFirstName() const {return this->firstName;}
        string getLastName() const {return this->lastName;}
        int const getAge () const {return this->age;}
};

#endif // WEEK7B_PERSON_H_INCLUDED
