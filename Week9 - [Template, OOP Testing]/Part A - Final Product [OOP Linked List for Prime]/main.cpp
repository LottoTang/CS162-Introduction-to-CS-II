//
//  main.cpp
//  Lab9A
//
//  Created by jim bailey on 12/28/21.
//

/* ID: L00690656 Week9A
 * W9_List.cpp */

#include <iostream>
#include "W9_List.h"

using std::cout, std::endl;

int main()
{
    const int NUM_PRIMES = 9;
    int primes[NUM_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    //create linked list with nullptr as head
    List theList;

    //assign primes[i] into the linked list
    for (int i = 0; i < NUM_PRIMES; i++)
    {
        theList.addHead(primes[i]);
    }

    cout << "Should list the numbers from 0 to 24 saying which ones are prime" << endl << endl;
    //check from 0 to 24, see if the linked list contains the prime number set in primes[]
    for (int i = 0; i < 25; i++)
    {
        //recursive findValue(int i) as the wrapper function
        cout << i << (theList.findValue(i)?" is ":" is not ") << "prime" << endl;
    }

    cout << endl << "should list the primes from 23 to 2 backwards" << endl;
    for (int i = 0; i < NUM_PRIMES; i++)
    {
        cout << theList.getHead() << " ";
        //delete the Link in the linked list by recursive destructor
        theList.removeHead();
    }

    cout << endl;

    return 0;
}
