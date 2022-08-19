#include <iostream>
#include <algorithm>
#include <ctime>
#include "Week4BFunctions.h"
//ID: L00690656 W4_Part B

using std::cin;
using std::cout;
using std::endl;
using std::string;

/** int getInteger(int min, int max)
 * validate int type input and make sure the value within range
 * return value
 */

int getInteger(int min, int max)
{
    int value = 0;
    bool valid = true;

    do
    {
        //initialize to true for every check
        valid = true;

        cin >> value;

        cout << endl;

        //check if not int type or out of range
        if ((cin.fail())||((value < min) || (value > max)))
        {
           if (cin.fail())
                cout << "Please enter an integer value: ";
           else
                cout << "Please enter an integer value within range: ";

            valid = false;

            //clear input buffer
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (!valid);

    return value;

}

/** bool yesNo ()
 * ask for either yes/no from user
 * return true if [yes/y]; false if [no/n]
 */

bool yesNo ()
{
    string answer = {};
    bool valid = true;

    do
    {
        //initialization for every check
        answer = {};
        valid = true;

        cin >> answer;

        //convert string to lowercase
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        //case if out of the desired words
        if ((answer != "yes") && (answer != "y") && (answer != "no") && (answer !="n"))
        {
            cout << "Please enter either [y/n]: ";
            valid = false;
            cin.clear();
            cin.ignore(10000,'\n');
        }
    } while (!valid);

    //return true/false
    if ((answer == "yes") || (answer == "y"))
        return true;
    else
        return false;
}

/** inline int getIndex (int rowIndex, int colIndex, int colLength)
 * convert move from user for flattened 1D-array (for easy mode)
 * return 0-15
 */

inline int getIndex (int rowIndex, int colIndex, int colLength)
{
    return colIndex + rowIndex * colLength;
}

/** void pressContinue()
 * intentionally pause the program by asking user's input for continuation
 */

void pressContinue()
{
    string temp = {};
    cout << "Press anything and press Enter to continue... ";
    cin >> temp;
    cin.clear();
    cin.ignore(10000,'\n');
}

/** void showMenu()
 * display the general menu of the program
 */

void showMenu()
{
    cout << "---------------------------------------------------" << endl;
    cout << "** Welcome to Memory Game **" << endl;
    cout << endl;
    cout << "1) Game Instructions" << endl;
    cout << "2) Memory Game" << endl;
    cout << "3) Exit" << endl;
    cout << endl;
    cout << "What is your preference [1-3]: ";
}

/** void displayInstruction()
 * display game instructions; 1st time for full version and simplified version afterwards
 */

void displayInstruction()
{
    static int counter = 0;

    cout << "---------------------------------------------------" << endl;

    //for 1st time display only
    if (counter == 0)
    {
        cout << "** 1) Game Instructions (Full) **" << endl;
        cout << endl;
        cout << "a) For each turn, you will be asked to flip 2 cards on the grid." << endl;
        cout << "b) If the 2 cards are the same (e.g. both A & A), your guest is correct and the grids of this pair will become empty :D" << endl;
        cout << "c) If the 2 cards are different (e.g. A & B), your guest is incorrect and the 2 cards keep in the original position :(" << endl;
        cout << "d) To win this game, match all the pairs with the fewest attempts!" << endl;
        cout << endl;
        cout << "Cards to be included in Hard Mode (15): A - O" << endl;
        cout << "Cards to be included in Easy Mode (8) : A - H" << endl;
        cout << endl;
        cout << "Example: " << endl;
        cout << "'X' - available cards for flipping" << endl;
        cout << "' ' - matched pairs" << endl;
        cout << endl;
        cout << "** Round 1 **" << endl;
        cout << "X X A X" << endl;
        cout << "X X X X" << endl;
        cout << "X X A X" << endl;
        cout << "X X X X" << endl;
        cout << endl;
        cout << "** Round 2 ** (After matching a pair)" << endl;
        cout << "X X   X" << endl;
        cout << "X X X X" << endl;
        cout << "X X   X" << endl;
        cout << "X X X X" << endl;
        cout << endl;
        counter++;
    }
    else
    {
        cout << "** 1) Game Instructions (Simplified) **" << endl;
        cout << endl;
        cout << "a) For each turn, you will be asked to flip 2 cards on the grid." << endl;
        cout << "b) If the 2 cards are the same (e.g. both A & A), your guest is correct and the grids of this pair will become empty :D" << endl;
        cout << "c) If the 2 cards are different (e.g. A & B), your guest is incorrect and the 2 cards keep in the original position :(" << endl;
        cout << "d) To win this game, match all the pairs with the fewest attempts!" << endl;
        cout << endl;
        cout << "Game symbols: " << endl;
        cout << "'X' - available cards for flipping" << endl;
        cout << "' ' - matched pairs" << endl;
        cout << endl;
        counter++;
    }
}

/** void shuffle (char *gameArray, int arrayLength)
 * shuffle the order of the element in the array
 */

void shuffle (char *gameArray, int arrayLength)
{
    //random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    //variable declaration and initialization
    char temp = ' ';
    int randomIndex = 0;

    //for-loop go through the whole array
    for (int i = 0; i < arrayLength; i++)
    {
        //create a random number from 0 - (arrayLength - 1)
        randomIndex = rand()% arrayLength;

        //swap process
        temp = *(gameArray + i);
        *(gameArray + i) = *(gameArray + randomIndex);
        *(gameArray + randomIndex) = temp;
    }
}

/** char *createBoard(int choice, int arrayLength)
 * initialize the whole array with A-O / A-H for hard and easy game
 * shuffle the order of the array
 * return gameArray
 */

char *createBoard(int choice, int arrayLength)
{
    if (choice == 1)
    {
        char *gameArray = new char[arrayLength];

        for (int i = 0; i < arrayLength; i+=2)
        {
            //assign A-H to gameArray[i]
            *(gameArray + i) = char(65 + i/2);
            //each alphabet will be assigned to the array twice
            *(gameArray + i+1) = char(65 + i/2);
        }

        shuffle(gameArray, arrayLength);
        return gameArray;
    }
    else
    {
        char *gameArray = new char[arrayLength];

        for (int i = 0; i < arrayLength; i+=2)
        {
            *(gameArray + i) = char(65 + i/2);
            *(gameArray + i+1) = char(65 + i/2);
        }

        shuffle(gameArray, arrayLength);
        return gameArray;
    }
}

/** void showBoard(char *gameArray, int rowLength, int colLength, int round)
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const *gameArray, int rowLength, int colLength, int round)
{
    cout << "---------------------------------------------------" << endl;

    cout << "** Memory Game -- Round " << round << " : 1st Card **" << endl;

    cout << endl;

    cout << "R/C" << endl;

    //display column index
    for (int i = 0; i < colLength; i++)
        cout << "  " << i;

    cout << endl;

    //go through the array and mark with 'X' or ' '
    for (int i = 0; i < rowLength * colLength; i++)
    {
        //display row index
        if (i == 0)
            cout << "0";
        else
        {
            //display row index
            if (i % colLength == 0)
            {
                cout << endl;
                cout << i/colLength;
            }
        }

        //display the unpaired cards with 'X', if paired then ' '
        if (*(gameArray + i) != SPACE)
            cout << " X ";
        else
            cout << "   ";
    }

    cout << endl;
}

/** void getMove (char const *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE])
 * get the location of the 1st card guessing, validate the location is not SPACE
 */

void getMove (char const *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE])
{
    bool valid = true;

    //loop until valid = true (the location is not SPACE)
    do
    {
        valid = true;

        cout << endl;

        //ask for user's choice for picking the 1st card (column)
        cout << "Please select the vertical column: [0 - " << colLength - 1 << "]: ";
        moveArray1[0] = getInteger(0, colLength - 1);

        //ask for user's choice for picking the 1st card (row)
        cout << "Please select the horizontal row: [0 - " << rowLength - 1 << "]: ";
        moveArray1[1] = getInteger(0, rowLength - 1);

        //check if gameArray [position] is SPACE
        if (gameArray[getIndex(moveArray1[1], moveArray1[0], colLength)] == SPACE)
        {
            cout << "The location is empty! Please choose other location." << endl;
            valid = false;
        }

    } while (!valid);
}

/** void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int round)
 * overloaded function
 * display the content of the 1st card chosen by user
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int round)
{
    cout << "---------------------------------------------------" << endl;

    cout << "** Memory Game -- Round " << round << " : 2nd Card **" << endl;

    cout << endl;

    cout << "R/C" << endl;

    //display column index
    for (int i = 0; i < colLength; i++)
        cout << "  " << i;

    cout << endl;

    //go through the array and mark with 'X' or ' '
    for (int i = 0; i < rowLength * colLength; i++)
    {
        //display row index
        if (i == 0)
            cout << "0";
        else
        {
            //display row index
            if (i % colLength == 0)
            {
                cout << endl;
                cout << i/colLength;
            }
        }

        // display the user's choice card (1st card)
        if (i == getIndex(moveArray1[1], moveArray1[0], colLength))
            cout << " " << gameArray[getIndex(moveArray1[1], moveArray1[0],colLength)] << " ";
        else
        //display 'X' or ' ' for the other cards
        {
            if (*(gameArray + i) != SPACE)
                cout << " X ";
            else
                cout << "   ";
        }
    }
    cout << endl;
}

/** void getMove (char *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE], int moveArray2[MOVE_SIZE])
 * get the location of the 1st card guessing, validate the location is not SPACE
 */

void getMove (char const *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE], int moveArray2[MOVE_SIZE])
{
    bool valid = true;

    //loop until valid = true (the location is not SPACE or 2 location choices are different)
    do
    {
        valid = true;

        cout << endl;

        //ask for user's choice for picking the 1st card (column)
        cout << "Please select the vertical column for: [0 - " << colLength - 1 << "]: ";
        moveArray2[0] = getInteger(0, colLength - 1);

        //ask for user's choice for picking the 1st card (row)
        cout << "Please select the horizontal row: [0 - " << rowLength - 1 << "]: ";
        moveArray2[1] = getInteger(0, rowLength - 1);

        //check if gameArray [position] is SPACE or choice of 2nd card is not the same as 1st card
        if ((gameArray[getIndex(moveArray2[1], moveArray2[0], colLength)] == SPACE) || ((moveArray2[1] == moveArray1[1]) && (moveArray2[0] == moveArray1[0])))
        {
            //check if gameArray [position] is SPACE
            if (gameArray[getIndex(moveArray2[1], moveArray2[0], colLength)] == SPACE)
                cout << "The location is empty! Please choose the other location." << endl;
            else
                cout << "Please choose different location from the previous." << endl;
            valid = false;
        }

    } while (!valid);
}

/** void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int round)
 * overloaded function
 * display the content of the 1st and 2nd card chosen by user
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int round)
{
    cout << "---------------------------------------------------" << endl;

    cout << "** Memory Game -- Round " << round << endl;

    cout << endl;

    cout << "R/C" << endl;

    //display column index
    for (int i = 0; i < colLength; i++)
        cout << "  " << i;

    cout << endl;

    //go through the array and mark with 'X' or ' '
    for (int i = 0; i < rowLength * colLength; i++)
    {
        //display row index
        if (i == 0)
            cout << "0";
        else
        {
            //display row index
            if (i % colLength == 0)
            {
                cout << endl;
                cout << i/colLength;
            }
        }

        //display the 1st card and 2nd card' content
        if (i == getIndex(moveArray1[1], moveArray1[0], colLength) || (i == getIndex(moveArray2[1], moveArray2[0], colLength)))
        {
            if (i == getIndex(moveArray1[1], moveArray1[0], colLength))
                cout << " " << gameArray[getIndex(moveArray1[1], moveArray1[0],colLength)] << " ";
            else
                cout << " " << gameArray[getIndex(moveArray2[1], moveArray2[0],colLength)] << " ";

        }

        else
        {
            if (*(gameArray + i) != SPACE)
                cout << " X ";
            else
                cout << "   ";
        }
    }
    cout << endl;
    cout << endl;
}

/** bool checkMatch (char const *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength, int &score)
 * check if the 1st card is having the same alphabet with the 2nd card
 * return true for having the same content, false otherwise
 */

bool checkMatch (char const *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength, int &score)
{
    //check the 2 choices chosen by user is having the same content
    if (gameArray[getIndex(moveArray1[1], moveArray1[0], colLength)] == gameArray[getIndex(moveArray2[1], moveArray2[0],colLength)])
    {
        score++;
        return true;
    }
    else
        return false;
}

/** void updateBoard (char *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength)
 * update the 2 spots with the paired location by ' '
 */

void updateBoard (char *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength)
{
    gameArray[getIndex(moveArray1[1], moveArray1[0], colLength)] = ' ';
    gameArray[getIndex(moveArray2[1], moveArray2[0], colLength)] = ' ';
}
