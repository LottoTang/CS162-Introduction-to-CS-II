#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "CommonFunctions.h"

//week 1_Part A ID: L00690656

using namespace std;

/* int getNumber (int min, int max)
 * validate an integer input within the given range
 * return number
 */

int getNumber (int min, int max)
{
    int number = 0;
    cin >> number;

    //validate the number is within min and max, && int type
    //code

    //return validated number
    cout << "return valud input from getNumber()" << endl;
    return number;
}

/* bool playAgain()
 * validate the string input (converted to lowercase) and check if it is within [yes,no,y,n]
 * return true for valid input and false for invalid input
 * return choice
 */
bool playAgain()
{
    bool choice = false;

    string word;

    cin >> word;

    //content in word to lowercase

    //check if word is within ['yes,'no,'y','n']

    //if valid input, choice = true and otherwise

    cout << "return true / false for [y/n]" << endl;

    return choice;
}

/* void displayInstructions(int displayCount)
 * display game instruction
 */

void displayInstructions(int displayCount)
{
   //display description
    cout << "displayInstructions" << endl;
}

/* void initBoard(char boardArray[], int boardSize)
 * initialize boardArray to empty state (no marking for X and O)
 */

void initBoard(char boardArray[], int boardSize)
{
    //set all elements in boardArray to empty
    cout << "Initialize boardArray[] to empty" << endl;
}

/* void showBoard (char const boardArray[], int boardSize)
 * display the elements in boardArray, each row will show up to 3 elements
 * expected result: [] [] []
 *                  [] [] []
 *                  [] [] []
 */

void showBoard (char const boardArray[], int boardSize)
{
    cout << "show updated 3x3 grid" << endl;
    cout << endl;
    cout << " [] [] [] " << endl;
    cout << " [] [] [] " << endl;
    cout << " [] [] [] " << endl;
}

/* void getMove (char boardArray[], int player, int &round)
 * get who is the next player, check if the location is empty or not.
 * if empty then mark the respective logo [X,O] into boardArray[location].
 * switch player for successful input
 */

void getMove (char boardArray[], int player)
{
    int location = 0;

    //store the validated user input to location
    location = getNumber(1,9);

    //check if the location is empty

    //if player == 1, mark 'X' else 'O'

    cout << "mark the respective location in grid: boardArray[location] = 'X'" << endl;

    //if the location is not empty
    cout << "The grid is occupied, please select other location" << endl;
}

/* bool checkWin (char boardArray[], int boardSize)
 * win/lose check will start at round 5; in round 9, false will indicate DRAW situation (reason not to implement checkDraw function as requested)
 * horizontal/ vertical/ diagonal check
 * return true for win; false for not yet determined (round 5-8) or DRAW in round 9
 * return game_status
 */

bool checkWin (char boardArray[], int boardSize)
{
    bool game_status = false;

    //check horizontal
    //case for position {(0,1,2),(3,4,5), (6,7,8)} and boardArray[index] is not empty, true if win is found

    //check vertical
    //case for position {(0,3,6),(1,4,7), (2,5,8)} and boardArray[index] is not empty, true if win is found

    //check diagonal (2 cases - (0,4,7) (2,4,6)

    cout << "Check if win is spotted" << endl;
    cout << "win: game_status == true; draw: game_status == false and round > 9 {count in main} " << endl;

    return game_status;
}

/* void showMenu()
 * show the welcoming message and menu
 */

void showMenu()
{
    //display menu
    cout << "** Welcome to the Tic-tac-toe game! **" << endl;
    cout << endl;
    cout << "1. Game Description" << endl;
    cout << "2. Local 2 Players Mode" << endl;
    cout << "3. Play With BOT" << endl;
    cout << "4. Exit" << endl;
}

/* void playerSwap(int &player)
 * swap player for every turns
 * int &player : pass by reference to change the value of player in main()
 */

void playerSwap(int &player)
{
    cout << "Player swap after each rounds" << endl;
}

/* void pressContinue()
 * temporary pause the program and continue when user types something into console
 * the input is not restricted to "enter"
 */

void pressContinue()
{
    //temporary pause the program
    string temp;

    cout << "Press Enter to continue!" << endl;

    getline(cin, temp);

    cin.clear();
    cin.ignore(10000, '\n');
}

/* int whoFirst ()
 * generate random number between 1-2
 * 1: Player first, 2: Bot first
 * return first
 */

int whoFirst ()
{
    int first = 2;

    cout << "Generate a random number between 1-2" << endl;
    cout << "1: player first, 2: BOT first" << endl;

    return first;
}

/* void getBotMove (char boardArray[])
 * generate a random number 1 - 9
 * if boardArray[location-1] is not empty, mark 'O'
 */

void getBotMove (char boardArray[])
{
    cout << "Generate a random move from bot" << endl;
    cout << "If boardArray[random] is not empty, repeat the generation process" << endl;
    cout << "boardArray[random] = 'O' " << endl;
}

/* bool botCheckWinLose (char boardArray[], int boardSize, int &botIndex)
 * determine BOT's move for round 3 and afterwards
 * check BOT if there are opportunities to win (check 'O'), then check if any chance to lose (check 'X')
 * if game_staus is true, &botIndex brings the desired location back to main() to makr 'O'
 * return game_status
 */

bool botCheckWinLose (char boardArray[], int boardSize, int &botIndex)
{
    bool game_status = false;

    cout << "check horizontal/ vertical/ diagonal potential win lose" << endl;
    cout << "BOT will check win first, followed by lose" << endl;
    cout << "win/lose: game_status == true, mark the potential location" << endl;
    return game_status;
}

/* void byeMessage()
 * display exit message when user input n from [y/n] question
 */

void byeMessage()
{
    //display bye message
    cout << endl;

    cout << "The program will direct you to Menu!" << endl;

    pressContinue();

    system("CLS");
}
