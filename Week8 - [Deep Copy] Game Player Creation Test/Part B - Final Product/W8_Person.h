#ifndef W8_PERSON_H_INCLUDED
#define W8_PERSON_H_INCLUDED
#include <iostream>

//ID: L00690656 Week8B

//declaration of class Person with definition
class Person
{
    private:
        std::string firstName;
        std::string lastName;
        int age;

    public:
        //default constructor and overloaded constructor
        Person(): firstName(""), lastName(""), age(0) {}
        Person(std::string firstName, std::string lastName, int age)
            : firstName(firstName), lastName(lastName), age(age) {}
        ~Person(){}

        //setters
        void setFirstName (std::string firstName){this->firstName = firstName;}
        void setLastName (std::string lastName){this->lastName = lastName;}
        void setAge (int age){this->age = age;}

        //getters
        std::string getFirstName () const {return this->firstName;}
        std::string getLastName () const {return this->lastName;}
        int getAge () const {return this->age;}
};

#endif // W8_PERSON_H_INCLUDED
