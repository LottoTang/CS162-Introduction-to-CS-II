#include "W8_Player.h"
#include <iostream>

//ID: L00690656 Week8B

//function definition

void Player::setClassName(std::string className)
{
    this->className = className;
}

void Player::setAction(std::string action)
{
    this->action = action;
}

std::string Player::getPlayerName() const
{
    return person->getFirstName() + " " + person->getLastName();
}

int Player::getPlayerAge() const
{
    return person->getAge();
}

std::string Player::getClassName() const
{
    return className;
}

std::string Player::getAction() const
{
    return action;
}

//overloaded operator=
Player &Player:: operator= (const Player &rhs)
{
    //copy all the fields in Player
    *(this->person) = *(rhs.person);
    this->className = rhs.className;
    this->action = rhs.action;

    return *this;
}

//overloaded operator==
bool Player:: operator== (const Player &rhs)
{
    return (this->getPlayerName() == rhs.getPlayerName() && this->getPlayerAge() == rhs.getPlayerAge() && this->className == rhs.className && this->action == rhs.action);
}

//overloaded operator<<
std::ostream &operator << (std::ostream &os, const Player &rhs)
{
    os << rhs.getPlayerName() << " aged " << rhs.getPlayerAge() << " playing " << rhs.getClassName() << " " << rhs.getAction() << std::endl;

    return os;
}
