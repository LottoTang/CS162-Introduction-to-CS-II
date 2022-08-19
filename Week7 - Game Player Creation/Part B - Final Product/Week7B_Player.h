#ifndef WEEK7B_PLAYER_H_INCLUDED
#define WEEK7B_PLAYER_H_INCLUDED
#include "Week7B_Person.h"
#include <string>

//ID: L00690656 Week7B_ver2

using std::string;

//declaration of class Player inherited from Person
class Player

{
    private:
        Person *person;

    public :

        //default and overloaded constructor
        Player();
        Player(string firstName, string lastName, int age);

        //getter
        string getPlayerName() const;
        int getPlayerAge() const;

        //pure virtual method
        virtual ~Player(){delete person;}
        virtual string getClassName() const = 0;
        virtual string getAction() const = 0;

};

//4 classes [Ranger, Wizard, Rogue, Priest] inherited from class Player
class Ranger : public Player
{
    public:
        //overloaded constructor
        Ranger(string firstName, string lastName, int age);
        //function for overriding
        //destructor to overriding, call to delete Ranger related objects
        ~Ranger();
        string getClassName() const;
        string getAction() const;
};

class Wizard : public Player
{
    public:
        Wizard(string firstName, string lastName, int age);
        ~Wizard();
        string getClassName() const;
        string getAction() const;
};

class Rogue : public Player
{
    public:
        Rogue(string firstName, string lastName, int age);
        ~Rogue();
        string getClassName() const;
        string getAction() const;
};

class Priest : public Player
{
    public:
        Priest(string firstName, string lastName, int age);
        ~Priest();
        string getClassName() const;
        string getAction() const;
};

#endif // WEEK7B_PLAYER_H_INCLUDED
