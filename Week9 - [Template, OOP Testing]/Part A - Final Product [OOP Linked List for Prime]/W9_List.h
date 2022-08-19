#ifndef W9_LINK_H_INCLUDED
#define W9_LINK_H_INCLUDED

/* ID: L00690656 Week9A
 * W9_Link.h */

class Link
{
    private:
        int value;
        Link *next;

    public:
        //constructor, sets value and next
        Link(int value = 0, Link* next = nullptr) : value(value), next(next) {}

        //destructor
        virtual ~Link(){};

        //getters
        int getValue() const;
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

        //deletes all the links from the list by recursion
        ~List();

        //add a new link containing value at the head of the list
        void addHead (int value);

        //return the value contained in the 1st link of the list
        int getHead() const;

        //remove the 1st link in the list
        void removeHead();

        //wrapper function for findValue
        bool findValue (int value) const;

        //overloaded function for recursive findValue()
        bool findValue (int value, Link* ptr) const;
};

#endif // W9_LINK_H_INCLUDED
