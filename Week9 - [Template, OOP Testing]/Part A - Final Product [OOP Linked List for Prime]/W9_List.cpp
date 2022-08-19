#include "W9_List.h"
#include <iostream>

/* ID: L00690656 Week9A
 * W9_List.cpp */

int Link:: getValue() const
{
    return this->value;
}

Link* Link:: getNext() const
{
    return this->next;
}

void Link:: setNext(Link *next)
{
    this->next = next;
}

void List:: addHead(int value)
{
    //create a new link containing the value
    Link *temp = new Link(value);

    temp->setNext(head);

    head = temp;
}

int List:: getHead() const
{
    //check if the list is empty
    if (head == nullptr)
        throw std::range_error("Empty List");

    return head->getValue();
}

void List:: removeHead()
{
    //check if the list is empty
    if (head == nullptr)
        throw std::range_error("Empty List");

    //temporarily store the current head
    Link *temp = head;

    //update the head as the next link in the list
    head = head->getNext();

    //delete the old link
    delete temp;
}

/* bool List:: findValue (int value) const
 * wrapper function for overloaded findValue()
 * return the result from overloaded fundValue
 */

bool List:: findValue (int value) const
{
    return findValue(value, head);
}

/* bool List:: findValue (int value, Link* ptr) const
 * find the desired value and search through the linked list by recursion
 * return true if found, false is not found*/

bool List:: findValue (int value, Link* ptr) const
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

/*
 * List:: ~List()
 * go through the Link from head and free up the memory
 */

List:: ~List()
{
    //free each link's memory in the list
    Link* currentLink = head;
    Link* nextLink = NULL;

    while (currentLink != NULL)
    {
        //assign head.next to nextLink
        nextLink = currentLink->getNext();

        //delete the original head
        delete currentLink;

        //update the currentLink as nextLink for next delete operation
        currentLink = nextLink;
    }
}
