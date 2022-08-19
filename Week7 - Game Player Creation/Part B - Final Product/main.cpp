#include <iostream>
#include "Week7B_HelperFunctions.h"
#include "Week7B_Person.h"

//ID: L00690656 Week7B_ver2

using std::endl;
using std::cout;

int main()
{
    int num_player = 0;

    cout << "How many players in the game [5 - 10]: ";
    num_player = getInteger(MIN, MAX_PLAYER);

    Player **gamerArray = createPlayer(num_player);

    displayPlayers(gamerArray, num_player);

    for (int i = 0; i < num_player; i++)
    {
        delete gamerArray[i];
    }

    delete [] gamerArray;

    return 0;
}
