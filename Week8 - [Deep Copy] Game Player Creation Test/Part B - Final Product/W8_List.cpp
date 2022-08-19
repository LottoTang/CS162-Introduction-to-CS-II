#include "W8_List.h"
#include <iostream>

/* ID: L00690656 Week8B
 * W8_List.cpp */

Player* Link:: getValue() const
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

void List:: addHead(Player *value)
{
    //create a new link containing the value
    Link *temp = new Link(value);

    temp->setNext(head);

    head = temp;
}

Player* List:: getHead() const
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

bool List:: findValue (Player* value) const
{
    bool found = false;

    //loop through the whole list, check if there is the targeted value until it is the end of list or not found
    for (Link* currentLink = head; (currentLink != nullptr) && (!found); currentLink = currentLink->getNext())
    {
        if (currentLink->getValue() == value)
            found = true;
    }

    return found;
}
