#ifndef W8_PLAYER_H_INCLUDED
#define W8_PLAYER_H_INCLUDED
#include "W8_Person.h"

//ID: L00690656 Week8B

class Player
{
   private:
       Person *person;

   protected:
        std::string className;
        std::string action;

   public:
       Player(std::string firstName= "", std::string lastName = "", int age = 0, std::string className = "unknown", std::string action = "unknown")
       : person(new Person(firstName, lastName, age)), className(className), action(action){}

       //function header
       virtual ~Player(){}

       void setClassName(std::string className);
       void setAction(std::string action);

       std::string getPlayerName() const;
       int getPlayerAge() const;
       std::string getClassName() const;
       std::string getAction() const;
       Person* getAddress() const {return person;}

       Player& operator= (const Player &rhs);

       bool operator== (const Player &rhs);
       friend std::ostream &operator << (std::ostream &os, const Player &rhs);
};

//declaration of derived classes
class Ranger : public Player
{
    public:
        Ranger(std::string firstName, std::string lastName, int age, std::string className = "unknown", std::string action = "unknown")
        : Player(firstName, lastName, age, className, action){}
        ~Ranger(){}
};

class Wizard : public Player
{
    public:
        Wizard(std::string firstName, std::string lastName, int age, std::string className = "unknown", std::string action = "unknown")
        : Player(firstName, lastName, age, className, action){}
        ~Wizard(){}
};

class Rogue : public Player
{
    public:
        Rogue(std::string firstName, std::string lastName, int age, std::string className = "unknown", std::string action = "unknown")
        : Player(firstName, lastName, age, className, action){}
        ~Rogue(){}
};

class Priest : public Player
{
    public:
        Priest(std::string firstName, std::string lastName, int age, std::string className = "unknown", std::string action = "unknown")
        : Player(firstName, lastName, age , className, action){}
        ~Priest(){}
};
#endif // W8_PLAYER_H_INCLUDED
