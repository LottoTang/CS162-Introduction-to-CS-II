#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "CommonFunctions.h"

//week 1_Part B ID: L00690656

using namespace std;

/* int getNumber (int min, int max)
 * validate an integer input within the given range
 * return number
 */

int getNumber (int min, int max)
{
    int number = 0;
    bool valid = true;

    do
    {
        valid = true;

        cin >> number;

        //check if it is an integer type or within the given range
        if ((cin.fail()) || ((number < min) || (number > max)))
        {
            //if not integer type
            if (cin.fail())
                cout << "Please enter an integer value!" << endl;
            else
                //case for integer type but out of range
                cout << "Please enter an integer within range!" << endl;

            //invalid input spotted
            valid = false;

            //clear input buffer and error flag
            cin.clear();
            cin.ignore(10000,'\n');
        }

    } while (!valid);

    return number;
}

/* bool playAgain()
 * validate the string input (converted to lowercase) and check if it is within [yes,no,y,n]
 * return true for valid input and false for invalid input
 * return choice
 */
bool playAgain()
{
    bool valid = true;
    bool choice = true;
    string word;

    do
    {
        cin >> word;

        //content in word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        //if word == 'yes' || 'y'
        if ((word == "yes") || (word == "y"))
            return choice;
        else
        {
            //if word == 'no' || 'n'
            if ((word == "no") || (word == "n"))
                return (!choice);

            //case for string not either [yes,no,y,n]
            else
            {
                cout << "Please enter either [y/n]!" << endl;
                //invalid input spotted
                valid = false;

                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

    } while (valid != true);

    return choice;
}

/* void displayInstructions(int displayCount)
 * display game instruction
 * 2nd time will display simplified description
 */

void displayInstructions(int displayCount)
{
   //display full description for the 1st time
    if(displayCount == 0)
    {
        system("CLS");
        cout << "** 1) Game Description - Detailed **" << endl;
        cout << endl;
        cout << "Tic-tac-toe is a game for 2 players!" << endl;
        cout << "The players will be assigned either a 'X' or 'O' mark." << endl;
        cout << "They will select an available space in a 3x3 grid and drop their mark for every turn." << endl;
        cout << endl;
        cout << "** How To Win? **" << endl;
        cout << "The player who succeeds in placing 3 of their marks in a horizontal, vertical, or diagonal row is the winner!" << endl;
        cout << endl;
        cout << "** Sample of a 3x3 grid **" << endl;
        cout << "[1] [2] [3]" << endl;
        cout << "[4] [5] [6]" << endl;
        cout << "[7] [8] [9]" << endl;
        cout << endl;
        cout << "** Sample of A Win Game : Horizontal **" << endl;
        cout << "[O] [O] [O]" << endl;
        cout << "[4] [5] [6]" << endl;
        cout << "[7] [8] [9]" << endl;
        cout << endl;
        cout << "** Sample of A Win Game : Vertical **" << endl;
        cout << "[1] [O] [3]" << endl;
        cout << "[4] [O] [6]" << endl;
        cout << "[7] [O] [9]" << endl;
        cout << endl;
        cout << "** Sample of A Win Game : Diagonal **" << endl;
        cout << "[O] [2] [3]" << endl;
        cout << "[4] [O] [6]" << endl;
        cout << "[7] [8] [O]" << endl;
        cout << endl;
    }
    else
    {
        //if user wants to view a simplified description
        system("CLS");
        cout << "** 1) Game Description - Simplified **" << endl;
        cout << endl;
        cout << "Each players will be assigned a 'X' or 'O' and they will drop the mark in an available space in a 3x3 grid." << endl;
        cout << "The one who succeeds in placing 3 of their marks in a horizontal, vertical, or diagonal row is the winner!" << endl;
        cout << endl;
        cout << "** Sample of a 3x3 grid **" << endl;
        cout << "[1] [2] [3]" << endl;
        cout << "[4] [5] [6]" << endl;
        cout << "[7] [8] [9]" << endl;
    }
}

/* void initBoard(char boardArray[], int boardSize)
 * initialize boardArray to empty state (no marking for X and O)
 */

void initBoard(char boardArray[], int boardSize)
{
    //set all elements in boardArray to empty
    for (int i = 0; i < boardSize; i++)

        boardArray[i] = {};
}

/* void showBoard (char const boardArray[], int boardSize)
 * display the elements in boardArray, each row will show up to 3 elements
 * expected result: [] [] []
 *                  [] [] []
 *                  [] [] []
 */

void showBoard (char const boardArray[], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        //each row will display up to 3 elements, and a new line will be implemented for the next 3 elements
        if (i % 3 == 0)
            cout << endl;

        cout << "[ " << boardArray[i] << " ]  ";
    }

    cout << endl;
}

/* void getMove (char boardArray[], int player, int &round)
 * get who is the next player, check if the location is empty or not.
 * if empty then mark the respective logo [X,O] into boardArray[location].
 * switch player for successful input
 */

void getMove (char boardArray[], int player)
{
    bool validMove = false;

    do
    {
        int location = 0;

        //store the validated user input to location
        location = getNumber(1,9);

        //check if boardArray[location-1] is empty
        if (boardArray[location - 1] == NULL)
        {
            //if empty, for player 1, mark X into the array
            if (player == 1)
            {
                boardArray[location - 1] = 'X';
                //successful move
                validMove = true;
            }
            //case for player 2, mark O into the array
            else
            {
                boardArray[location - 1] = 'O';
                validMove = true;
            }
        }
        // case for the arrayboard[location-1] is occupied
        else

            cout << "The location has been marked! Please mark other location: ";

    } while (validMove != true);

}

/* bool checkWin (char boardArray[], int boardSize)
 * win/lose check will start at round 5; in round 9, false will indicate DRAW situation (reason not to implement checkDraw function as requested)
 * horizontal/ vertical/ diagonal check
 * return true for win; false for not yet determined (round 5-8) or DRAW in round 9
 * return game_status
 */

bool checkWin (char const boardArray[], int boardSize)
{
    bool game_status = false;
    int index = 0;

    //check horizontal
    do
    {
        //case for position {(0,1,2),(3,4,5), (6,7,8)} and boardArray[index] is not empty
        if ((boardArray[index] == boardArray[index+1]) && (boardArray[index] != NULL))
        {
             if (boardArray[index+1] == boardArray[index+2])
                //check 3 'O' or 'X' in a row
                game_status = true;
            else
                //check for the next row
                index += 3;
        }
        else
            index += 3;

    } while ((index < boardSize) && (game_status != true));

    //check vertical, if win is not found in horizontal
    if (game_status == false)
    {
        index = 0;

        do
        {
            //case for position {(0,3,6),(1,4,7), (2,5,8)} and boardArray[index] is not empty
            if ((boardArray[index] == boardArray[index+3]) && (boardArray[index] != NULL))
            {
                if (boardArray[index+3] == boardArray[index+6])
                    game_status = true;
                else
                    //check for the next column
                    index += 1;
            }
            else
                index += 1;

        } while ((index < 3) && (game_status != true));
    }

    //check diagonal (from top left corner)
    if (game_status == false)
    {
        index = 0;

        //case for position {(0,4,8)} and boardArray[index] is not empty
        if ((boardArray[index] == boardArray[index+4]) && (boardArray[index] != NULL))
        {
            if (boardArray [index+4] == boardArray [index+8])
                game_status = true;
        }
    }

    //check diagonal (from top right corner)
    if (game_status == false)
    {
        index = 0;

        //case for position {(2,4,6)} and boardArray[index] is not empty
        if ((boardArray[index+2] == boardArray[index+4]) && (boardArray[index+2] != NULL))
        {
            if (boardArray [index+4] == boardArray [index+6])
                game_status = true;
        }
    }

    return game_status;
}

/* void showMenu()
 * show the welcoming message and menu
 */

void showMenu()
{
    cout << "** Welcome to the Tic-tac-toe game! **" << endl;
    cout << endl;
    cout << "1. Game Description" << endl;
    cout << "2. Local 2 Players Mode" << endl;
    cout << "3. Play With BOT" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Please select one of the above commands [1-4]: ";
}

/* void playerSwap(int &player)
 * swap player for every turns
 * int &player : pass by reference to change the value of player in main()
 */

void playerSwap(int &player)
{
    if (player == 1)
        player = 2;
    else
        player = 1;
}

/* void pressContinue()
 * temporary pause the program and continue when user types something into console
 * the input is not restricted to "enter"
 */

void pressContinue()
{
    string temp;

    cout << endl;

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
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand (seed);

    //generate random number between 1 to 2
    int first = rand() % 2 + 1;

    cout << endl;

    if (first == 1)
        cout << "You first!" << endl;
    else
        cout << "Bot first!" << endl;

    return first;
}

/* void getBotMove (char boardArray[])
 * generate a random number 1 - 9
 * if boardArray[location-1] is not empty, mark 'O'
 */

void getBotMove (char boardArray[])
{
    bool validMove = false;

    //random number generator setup
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand (seed);

    do
    {
        int location = 0;

        //random number between 1 to 9
        location = rand()%9 + 1;

        //if boardArray[location-1] is not empty, mark 'O'
        if (boardArray[location - 1] == NULL)
        {
            boardArray[location - 1] = 'O';
            //valid move spotted
            validMove = true;
        }
    } while (validMove != true);
}

/* bool botCheckWinLose (char boardArray[], int boardSize, int &botIndex)
 * determine BOT's move for round 3 and afterwards
 * check BOT if there are opportunities to win (check 'O'), then check if any chance to lose (check 'X')
 * if game_staus is true, &botIndex brings the desired location back to main() to makr 'O'
 * return game_status
 */

bool botCheckWinLose (char const boardArray[], int boardSize, int &botIndex)
{
    bool game_status = false;
    char choice[2] = {'O','X'};
    int index = 0;
    int choiceIndex = 0;

    //do-while loop: check if game_status is true || checked 'O' and 'X'
    do
    {
        do
        {
            //check horizontal if a row having 2 'O' or 'X' to seek potential win/ lose
            if ((boardArray[index] == boardArray[index+1]) && (boardArray[index] == choice[choiceIndex]))
            {
                //if the potential win/lose grid is empty, mark the corresponding symbol
                if (boardArray[index+2] == NULL)
                {
                    game_status = true;
                    botIndex = index + 2;
                }

                else
                    //check for the next row
                    index += 3;
            }

            else

            {
                if((boardArray[index] == boardArray[index+2]) && (boardArray[index] == choice[choiceIndex]))
                {
                    if (boardArray[index+1] == NULL)
                    {
                        game_status = true;
                        botIndex = index + 1;
                    }

                    else
                        index += 3;
                }

                else

                {
                    if((boardArray[index+1] == boardArray[index+2]) && (boardArray[index+1] == choice[choiceIndex]))
                    {
                        if (boardArray[index] == NULL)
                        {
                            game_status = true;
                            botIndex = index;
                        }

                        else
                            index += 3;
                    }

                    else

                        index += 3;
                }
            }

        } while ((index < boardSize) && (game_status != true));

        //check vertical win/lose
        if (game_status == false)
        {
            index = 0;
            do
            {
                if ((boardArray[index] == boardArray[index+3]) && (boardArray[index] == choice[choiceIndex]))
                {
                    if (boardArray[index+6] == NULL)
                    {
                        game_status = true;
                        botIndex = index + 6;
                    }

                    else

                        index += 1;
                }

                else

                {
                    if ((boardArray[index+3] == boardArray[index+6]) && (boardArray[index+3] == choice[choiceIndex]))
                    {
                        if (boardArray[index] == NULL)
                        {
                            game_status = true;
                            botIndex = index;
                        }

                        else

                            index += 1;
                    }

                    else

                    {
                        if ((boardArray[index] == boardArray[index+6]) && (boardArray[index] == choice[choiceIndex]))
                        {
                            if (boardArray[index+3] == NULL)
                            {
                                game_status = true;
                                botIndex = index + 3;
                            }

                            else

                                index += 1;
                        }

                        else

                            index += 1;
                    }

                }

            } while ((index < 3) && (game_status != true));
        }

        //check diagonal (from top left corner)
        if (game_status == false)
        {
            index = 0;

            if ((boardArray[index] == boardArray[index+4]) && (boardArray[index] == choice[choiceIndex]))
            {
                if (boardArray[index+8] == NULL)
                {
                    game_status = true;
                    botIndex = index + 8;
                }
            }

            else

            {
                if ((boardArray [index+4] == boardArray [index+8]) && (boardArray[index+4] == choice[choiceIndex]))
                {
                    if (boardArray[index] == NULL)
                    {
                        game_status = true;
                        botIndex = index;
                    }
                }

                else

                {
                    if ((boardArray [index] == boardArray [index+8]) && (boardArray[index] == choice[choiceIndex]))
                    {
                        if (boardArray[index+4] == NULL)
                        {
                            game_status = true;
                            botIndex = index + 4 ;
                        }
                    }
                }
            }
        }

        //check diagonal (from top right corner)
        if (game_status == false)
        {
            index = 0;

            if ((boardArray[index+2] == boardArray[index+4]) && (boardArray[index+2] == choice[choiceIndex]))
            {
                if (boardArray[index+6] == NULL)
                {
                    game_status = true;
                    botIndex = index + 6;
                }
            }

            else

            {
                if ((boardArray [index+2] == boardArray [index+6]) && (boardArray[index+2] == choice[choiceIndex]))
                {
                    if (boardArray[index+4] == NULL)
                    {
                        game_status = true;
                        botIndex = index + 4;
                    }
                }

                else

                {
                    if ((boardArray [index+4] == boardArray [index+6]) && (boardArray[index+4] == choice[choiceIndex]))
                    {
                        if (boardArray[index+2] == NULL)
                        {
                            game_status = true;
                            botIndex = index + 2;
                        }
                    }
                }
            }
        }

    //check for the other symbol
    choiceIndex++;

    } while ((choiceIndex < 2) && (game_status == false));

    return game_status;
}

/* void byeMessage()
 * display exit message when user input n from [y/n] question
 */

void byeMessage()
{
    cout << endl;

    cout << "The program will direct you to Menu!" << endl;

    pressContinue();

    system("CLS");
}
