//
//  Person.hpp
//  testing
//
//  Created by jim bailey on 3/8/21.
//

/* ID: L00690656 Week9B
 * Person.hpp */

#ifndef Person_hpp
#define Person_hpp

#include <string>
#include <ostream>

class Person {
private:
    std::string fname;
    std::string lname;
    int age;

public:
    Person(std::string fname = "", std::string lname = "", int age = 0)
        : fname(fname), lname(lname), age(age) {}

    void setFirstName(std::string fname) {this->fname = fname;}
    void setLastName(std::string lname) {this->lname = lname;}
    void setAge(int age) {this->age = age;}

    std::string getFirstName() const {return this->fname;}
    std::string getLastName() const {return this->lname;}
    int getAge() const {return this->age;}

    friend
    std::ostream & operator<<(std::ostream & os, const Person & item)
    {
        os << item.getFirstName() << " " << item.getLastName() << " aged " << item.getAge();
        return os;
    }
};

#endif /* Person_hpp */
