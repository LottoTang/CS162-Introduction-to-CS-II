#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include <exception>

/* ID: L00690656 Week9B
 * Link.h */

/* class list_error : public std::exception
 * create a custom exception list_error
 * store the string msg into pointer what
 * return msg.c_str() */

class list_error : public std::exception
{
    std::string msg;

    public:
        //custom exception constructor
        list_error(const std::string &msg = ""):msg(msg){}

        const char *what()
        {
            return msg.c_str();
        }
};

/* template <typename T> class Link
 * create a custom class Link with instance of type T */

template <typename T>
class Link
{
    private:
        //create custom variable value, Link pointer with instance of type T
        T value;
        Link <T> *next;

    public:
        //constructor, sets value and next
        Link <T> (T value, Link* next = nullptr) : value(value), next(next) {}

        //destructor
        virtual ~Link(){};

        //getters
        T getValue() const {return this->value;}
        Link <T> *getNext() const {return this->next;}

        //setters
        void setNext(Link <T> *next){this->next = next;};
};

/* template <typename T> class List
 * create a custom class List with instance of type T */

template <typename T>
class List
{
    private:
        //a pointer to the start of the list
        Link <T> *head;

    public:

        //Linked List constructor initialized with nullptr
        List(): head(nullptr){}

        //deletes all the links from the list by recursion
        void deleteRecursive(Link<T> *ptr)
        {
            if (ptr)
            {
                deleteRecursive(ptr->getNext());
                delete ptr;
            }
        }

        virtual ~List()
        {
           deleteRecursive(head);
        }

        /* void addHead (T value)
         * add a new link containing value of type T at the head of the list */

        void addHead (T value)
        {
            //create a new link containing the value
            Link <T> *temp = new Link <T> (value);

            temp->setNext(head);

            head = temp;
        }

        /* T getHead() const
         * return the value of type T contained in the 1st link of the list */

        T getHead() const
        {
            //check if the list is empty
            if (head == nullptr)
                throw list_error("Empty List");

            return head->getValue();
        }

        /* void removeHead()
         * remove the 1st link in the list */

        void removeHead()
        {
            //check if the list is empty
            if (head == nullptr)
                throw list_error("Empty List");

            //temporarily store the current head
            Link <T> *temp = head;

            //update the head as the next link in the list
            head = head->getNext();

            //delete the old link
            delete temp;
        }

        //wrapper function for findValue
        bool findValue (T value) const {return findValue(value, head);}

        //overloaded function for recursive findValue()
        bool findValue (T value, Link <T>* ptr) const
        {
            //check if the head is nullptr, indicating end of the list
            if (ptr == nullptr)
                return false;

            //get the value from the current head, check if the value is = value
            if (ptr->getValue() == value)
                return true;

            //call itself again updating the ptr to the next ptr
            return findValue(value, ptr->getNext());
        }
};

#endif // LINK_H_INCLUDED
