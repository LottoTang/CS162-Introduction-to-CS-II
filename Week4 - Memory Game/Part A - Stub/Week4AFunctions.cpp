#include <iostream>
#include <algorithm>
#include <ctime>
#include "Week4AFunctions.h"
//ID: L00690656 W4_Part A

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

    cout << "getInteger() - return value within range" << endl;

    do
    {
        //initialize to true for every check
        valid = true;

        /*
            do
                get value from user
                check if value within range || not integer input
                    error message for invalid input
                    valid = false
                    return true if valid input
            while (valid == true)
            return value
        */

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

    cout << "yesNo () - return true for [y/yes]; false for [n/no]" << endl;

    do
    {
        //initialization for every check
        answer = {};
        valid = true;

        /*
            do
                get answer from user
                transform string answer to lowercase
                check if within [y/yes/n/no]
                    error message for invalid input
                    valid = false
                return true if [y/yes]; false for [n/no]
            while (valid == true)
            return true/false
        */

    } while (!valid);

    return true;
}

/** inline int getIndex (int rowIndex, int colIndex, int colLength)
 * convert move from user for flattened 1D-array (for easy mode)
 * return 0-15
 */

inline int getIndex (int rowIndex, int colIndex, int colLength)
{
    cout << "getIndex () - return the index for 1D flattened array" << endl;

    return colIndex + rowIndex * colLength;
}

/** void pressContinue()
 * intentionally pause the program by asking user's input for continuation
 */

void pressContinue()
{
    cout << "void pressContinue() - intentionally pause the program by asking a input" << endl;
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
    cout << "What is your preference [1-3]: " << endl;
}

/** void displayInstruction()
 * display game instructions; 1st time for full version and simplified version afterwards
 */

void displayInstruction()
{
    static int counter = 0;

    cout << "---------------------------------------------------" << endl;

    cout << "displayInstruction() - show game instruction: 1st full; 2nd simplified" << endl;

    //for 1st time display only
    if (counter == 0)
    {
        cout << "** 1) Game Instructions (Full) **" << endl;
        /* show game instruction */

        counter++;
    }
    else
    {
        cout << "** 1) Game Instructions (Simplified) **" << endl;
        /* show game instruction*/
        counter++;
    }
}

/** void shuffle (char * const gameArray, int arrayLength)
 * shuffle the order of the element in the array
 */

void shuffle (char * const gameArray, int arrayLength)
{
    cout << "shuffle() - generate a random number, shuffle the order of the array" << endl;

    /*
    for loop (int i = 0; i < arrayLength; i++)
        generate random number from 0 - arrayLength
        {swap}
        temp = gameArray[i]
        gameArray[i] = gameArray[random]
        gameArray[random] = temp
    */
}

/** char *createBoard(int choice, int arrayLength)
 * initialize the whole array with A-O / A-H for hard and easy game
 * shuffle the order of the array
 * return gameArray
 */

char *createBoard(int choice, int arrayLength)
{

    cout << "char *createBoard() - create dynamic array and assign the alphabets to the array" << endl;

    /* based on choose (level of difficulty)
       1: easy
       2: hard
       create *gameArray = new char[arrayLength]
       for loop
            assign A-H / A-O for easy and hard mode to the array (each alphabet will assign in 2 array cells)
       shuffle the array
       return gameArray
    */

    char *gameArray = new char[arrayLength];

    return gameArray;
}

/** void showBoard(char * const gameArray, int rowLength, int colLength, int round)
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const * const gameArray, int rowLength, int colLength, int round)
{

    cout << "void showBoard() - show the board for the element of gameArray" << endl;

    /*
      for (int i = 0; i < rowLength * colLength; i++)
        if gameArray[i] != SPACE
            mark the cell with 'X'
        else
            mark the cell with ' '
    */

}

/** void getMove (char const * const gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE])
 * get the location of the 1st card guessing, validate the location is not SPACE
 */

void getMove (char const * const gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE])
{
    cout << "getMove() - get the 1st move, validate the location in gameArray[1st move] != SPACE" << endl;

    /*
      do
        moveArray1[column] = getInteger(0,colLength - 1)
        moveArray1[row] = getInteger(0,rowLength - 1)
        check if (gameArray[getIndex(moveArray1[1], moveArray1[0], colLength)] == SPACE)
            if yes: invalid input + error message
            if no: valid input --> moveArray1 saved the location of the move
        while (!valid)
    */
}

/** void showBoard(char const * const gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int round)
 * overloaded function
 * display the content of the 1st card chosen by user
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const * const gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int round)
{
    cout << "void showBoard(overloaded1) - show the board for the element of gameArray (with the 1st move)" << endl;

    /*
      for (int i = 0; i < rowLength * colLength; i++)
        if (i == getIndex(the moveArray[1], moveArray[0], colLength)
            display the content of the cell (flap the card)
        else
            if gameArray[i] != SPACE
                mark the cell with 'X'
            else
                mark the cell with ' '
    */
        // display the user's choice card (1st card)
    cout << endl;
}

/** void getMove (char * const gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE], int moveArray2[MOVE_SIZE])
 * get the location of the 1st card guessing, validate the location is not SPACE
 */

void getMove (char const * const gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE], int moveArray2[MOVE_SIZE])
{
    cout << "getMove(overloaded1) - get the 1st move, validate the location in gameArray[1st move] != SPACE" << endl;

    /*
      do
        moveArray1[column] = getInteger(0,colLength - 1)
        moveArray1[row] = getInteger(0,rowLength - 1)
        check if (gameArray[getIndex(moveArray2[1], moveArray2[0], colLength)] == SPACE) || ((moveArray2[1] == moveArray1[1]) && (moveArray2[0] == moveArray1[0]))
            if yes: (case 1: space) invalid input + error message
            if yes: (case 2: same move as previous) -> error message
            if no: valid input --> moveArray2 saved the location of the move
        while (!valid)
    */
}

/** void showBoard(char const * const gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int round)
 * overloaded function
 * display the content of the 1st and 2nd card chosen by user
 * display the board with 'X' for the unpaired items, ' ' for the paired items
 */

void showBoard(char const * const gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int round)
{
    cout << "void showBoard(overloaded1) - show the board for the element of gameArray (with the 1st + 2nd move)" << endl;

    /*
      for (int i = 0; i < rowLength * colLength; i++)
        if (i == getIndex(the moveArray1[1], moveArray1[0], colLength) || (i == getIndex(the moveArray2[1], moveArray2[0], colLength)
            display the content of the cell (flap the cards for both 1st and 2nd)
        else
            if gameArray[i] != SPACE
                mark the cell with 'X'
            else
                mark the cell with ' '
    */

    cout << endl;
}

/** bool checkMatch (char const * const gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength, int &score)
 * check if the 1st card is having the same alphabet with the 2nd card
 * return true for having the same content, false otherwise
 */

bool checkMatch (char const * const gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength, int &score)
{
    cout << "checkMatch() - check the 2 choices chosen by user are having the same content" << endl;
    /*
        check the 2 choices chosen by user are having the same content
        if both are the same -> return true && score ++
        if not -> return false
    */
        return true;
}

/** void updateBoard (char *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength)
 * update the 2 spots with the paired location by ' '
 */

void updateBoard (char *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength)
{
    cout << "updateBoard() - update the 2 locations with ' ' if checkMatch() passes true" << endl;
    /*
        gameArray[location1] = ' ';
        gameArray[location2] = ' ';
    */
}
