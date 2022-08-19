#include <iostream>
#include <algorithm>
#include "Week7B_HelperFunctions.h"
#include "Week7B_Player.h"

//ID: L00690656 Week7B_ver2

using std::cin, std::cout, std::endl;
using std::string;

/** int getInteger (int min, int max)
 * get int input and validate within range
 * return number
 */

int getInteger (int min, int max)
{
    int number = 0;
    bool valid = true;

    do
    {
        valid = true;
        cin >> number;
        cout << endl;

        //check int type input or out of range
        if ((cin.fail()) || (number < min || (number > max)))
        {
            if (cin.fail())
                cout << "Please enter again with an integer value: ";
            else
                cout << "Please enter again within range [" << min << " - " << max << "]: ";

            valid = false;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!valid);

    return number;
}

/** string checkClass()
 * get string choice and validate within the 4 classes
 * return choice
 */

string checkClass()
{
    string choice = "";
    bool valid = true;

    do
    {
        valid = true;
        cin >> choice;

        //convert the string to lowercase for checking
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if ((choice != "ranger") && (choice != "wizard") && (choice != "rogue") && (choice != "priest"))
        {
            cout << "Please enter a valid role for the player: ";
            valid = false;
            cin.clear();
            cin.ignore(10000,'\n');
        }

    } while (!valid);

    return choice;
}

/** Player **createPlayer(int const num_player)
 * create the pointer to an array of pointers of Player
 * create the 4 classes object dynamically in the array of pointers of Player
 * return the pointer - gamerArray
 */

Player **createPlayer(int const num_player)
{
    string firstName, lastName;
    int age;
    string role;

    //create the pointer array to an array of pointers of Player
    Player **gamerArray = new Player *[num_player];

    //get particulars for the objects
    for (int i = 0; i < num_player; i++)
    {
        firstName = "";
        lastName = "";
        role = "";
        age = 0;

        cout << "First name for player " << i+1 << ": ";
        cin >> firstName;
        cout << endl;

        cout << "Last name for player " << i+1 << ": ";
        cin >> lastName;
        cout << endl;

        cout << "Age for player " << i+1 << ": ";
        age = getInteger(MIN, MAX_AGE);

        cout << "Choose either 1 of the role [Ranger, Wizard, Rogue, Priest]: ";
        role = checkClass();

        //create the derived objects from the 4 classes dynamically inherited from Player
        if (role == "ranger")
            gamerArray[i] = new Ranger(firstName, lastName, age);
        else
        {
            if (role == "wizard")
                gamerArray[i] = new Wizard(firstName, lastName, age);
            else
            {
                if (role == "rogue")
                    gamerArray[i] = new Rogue(firstName, lastName, age);
                else
                    gamerArray[i] = new Priest(firstName, lastName, age);
            }
        }

        cout << endl;
    }

    return gamerArray;
}

/** void displayPlayers (Player * const * const gamerArray, int num_player)
 * display the information of the derived classes inherited from Player
 */

void displayPlayers (Player * const * const gamerArray, int num_player)
{
    for (int i = 0; i < num_player; i++)
    {
        //getClassName(), getAction() will override the virtual function from class Player respectively
        cout << gamerArray[i]->getPlayerName() << " aged " << gamerArray[i]->getPlayerAge() << " playing a " << gamerArray[i]->getClassName() << " " << gamerArray[i]->getAction() << endl;
    }
}
