#ifndef W8B_LINK_H_INCLUDED
#define W8B_LINK_H_INCLUDED
#include "W8_Player.h"

//ID: L00690656 Week8B

class Link
{
    private:
        Player *value;
        Link *next;

    public:
        //constructor, sets value and next
        Link(Player *value = nullptr, Link* next = nullptr) : value(value), next(next) {}

        //destructor
        virtual ~Link(){}

        //getters
        Player *getValue() const;
        Link *getNext() const;

        //setters
        void setNext(Link *next);
};

class List
{
    private:
        //a pointer to the start of the list
        Link *head;

    public:

        //Linked List constructor initialized with nullptr
        List(): head(nullptr){}

        //deletes all the links from the list
        ~List(){delete head;}

        //add a new link containing value at the head of the list
        void addHead (Player *value);

        //return the value contained in the 1st link of the list
        Player *getHead() const;

        //remove the 1st link in the list
        void removeHead();

        //return true if value is in the list
        bool findValue(Player *value) const;

};

#endif // W8B_LINK_H_INCLUDED
