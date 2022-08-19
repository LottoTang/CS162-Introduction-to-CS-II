#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "CommonFunctions.h"

//week 1_Part B ID: L00690656

using namespace std;

int main()
{
    //variable declaration and initialization
    int preference = 0;
    int player = 1;
    int round = 1;
    int displayCount = 0;
    int botIndex = 0;
    int choiceIndex = 0;
    int const SIZE = 9;

    bool gameWin = false;
    bool nextGame = false;
    bool readAgain = false;
    bool botCheck = false;

    char boardArray[SIZE] = {};

    string choice;

    //do-while: check if user entered 4 to exit the program, loop otherwise
    do
    {
        //display menu
        showMenu();

        //get user preference and validate within range 1-4
        preference = getNumber(1,4);

        //switch function to run the codes based on preference
        switch(preference)
        {
        //show instruction
        case 1:
            {
                displayInstructions(displayCount);

                //1st time display: full instructions, 2nd time: simplified version; reset displayCount for every call of case 1
                if (displayCount >= 0)
                {
                    cout << "Do you want to read the simplified version of Game Description? [y/n]: ";

                    readAgain = playAgain();

                    if (readAgain == true)
                    {
                        displayCount++;

                        displayInstructions(displayCount);

                        pressContinue();

                        system ("CLS");

                        displayCount = 0;
                    }

                    else

                        byeMessage();
                }

                break;
            }

        //local 2 players mode
        case 2:
            {
                //do-while loop: exit when user entered n for playAgain(), loop otherwise
                do
                {
                    //initialize 3x3 grid to empty
                    initBoard(boardArray, SIZE);

                    //variable initialization for every game
                    round = 0;
                    player = 1;
                    gameWin = false;

                    //do-while loop: win || round > 9 will exit the loop
                    do
                    {
                        //display game heading, game information, real-time 3x3 grid boardArray
                        system("CLS");

                        cout << "** 2) Local 2 Players Mode **" << endl;

                        cout << endl;

                        cout << "It is now Player " << player << "'s turn!" << endl;

                        if (player == 1)

                            cout << "Symbol: 'X'" << endl;

                        else

                            cout << "Symbol: 'O'" << endl;

                        showBoard(boardArray,SIZE);

                        cout << endl;

                        cout << "Which location you want to mark?: ";

                        //ask for user input for grid entry, pass the validated input
                        getMove(boardArray, player);

                        //round counter
                        round++;

                        //win will only occur in round 5 and afterwards, checkWin will be implemented
                        if (round >= 5)
                        {
                            gameWin = checkWin(boardArray, SIZE);

                            //if gameWin == false and in round 9, then draw situation is spotted, display draw message
                            if ((round == 9) && (gameWin == false))
                            {
                                system("CLS");

                                cout << "** 2) Local 2 Players Mode **" << endl;

                                showBoard(boardArray,SIZE);

                                cout << endl;

                                cout << "This is a tied game!" << endl;
                            }

                            //display win message
                            if (gameWin == true)
                            {
                                system("CLS");

                                cout << "** 2) Local 2 Players Mode **" << endl;

                                showBoard(boardArray,SIZE);

                                cout << endl;

                                cout << "Player" << player << " wins the game!" << endl;

                                cout << endl;
                            }
                        }

                        //swap player for 1 and 2 for every rounds
                        playerSwap(player);

                    } while ((gameWin != true) && (round < 9));

                    //ask for play again
                    cout << "Do you want to play again [y/n]?: ";

                    nextGame = playAgain();

                    if (nextGame == false)

                        byeMessage();

                } while (nextGame == true);

                break;
            }

        //BOT mode
        case 3:
            {
                //do-while loop: exit when user entered n for playAgain(), loop otherwise
                do
                {
                    //variable initialization for every game
                    round = 0;
                    player = 1;
                    choiceIndex = 0;

                    gameWin = false;
                    botCheck = false;

                    //determine who is the 1st player, and initialize the boardArray to empty
                    system ("CLS");

                    cout << "** 3) Play with BOT **" << endl;

                    player = whoFirst();

                    pressContinue();

                    initBoard(boardArray, SIZE);

                    //do-while loop: win || round > 9 will exit the loop
                    do
                    {
                        //show real-time 3x3 grid, pre-increment for round
                        system("CLS");

                        cout << "** 3) Play with BOT **" << endl;

                        showBoard(boardArray, SIZE);

                        round++;

                        //ask for user input
                        if (player == 1)
                        {

                            cout << endl;

                            cout << "It is your turn!" << endl;

                            cout << "Symbol: 'X'" << endl;

                            cout << endl;

                            cout << "Which location you want to mark?: ";

                            getMove(boardArray, 1);
                        }

                        else
                        //ask for BOT's input
                        {
                            cout << "It is BOT's turn!" << endl;

                            cout << "Symbol: 'O'" << endl;

                            //from round 3 and afterwards, there are potential win/ lose opportunities (if 1st player is user)
                            //botCheckWinLose will determine the appropriate BOT's input - will input for win as the highest priority, then prevent from lose, and eventually random move
                            if (round >= 3)
                            {
                                botCheck = botCheckWinLose(boardArray, SIZE, botIndex);

                                if ((botCheck == true))

                                    boardArray[botIndex] = 'O';

                                else

                                    //botCheck == false case
                                    getBotMove(boardArray);
                            }
                            else

                                //round < 3
                                getBotMove(boardArray);
                        }

                        //win will only occur in round 5 and afterwards, checkWin will be implemented
                        if (round >= 5)
                        {
                            gameWin = checkWin(boardArray, SIZE);

                            //display draw message
                            if ((round == 9) && (gameWin == false))
                            {
                                system("CLS");

                                cout << "** 3) Play with BOT **" << endl;

                                showBoard(boardArray,SIZE);

                                cout << endl;

                                cout << "This is a tied game!" << endl;
                            }

                            //display win message based on who is the winner
                            if (gameWin == true)
                            {
                                system("CLS");

                                cout << "** 3) Play with BOT **" << endl;

                                showBoard(boardArray,SIZE);

                                cout << endl;

                                if (player == 1)

                                    cout << "You win the game!" << endl;

                                else

                                    cout << "BOT wins the game!" << endl;
                            }
                        }

                        //swap player (user and BOT) for every rounds
                        playerSwap(player);

                    } while ((gameWin != true) && (round < 9));

                    cout << endl;

                    //ask for play again
                    cout << "Do you want to play again [y/n]?: ";

                    nextGame = playAgain();

                    if (nextGame == false)

                        byeMessage();

                } while (nextGame == true);

                break;
            }

        //case to exit the program
        case 4:
            {
                cout << "See you next time! Bye!" << endl;

                break;
            }

        }

    } while (preference != 4);

    return 0;
}
