#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "CommonFunctions.h"

//week 1_Part A ID: L00690656

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

                //ask to read again
                cout << "Do you want to read again? [y/n]: ";

                //readAgain = playAgain();

                readAgain = playAgain();

                byeMessage();
            }

                break;

        //local 2 players mode
        case 2:
            {
                system("CLS");

                //initialize 3x3 grid to empty
                initBoard(boardArray, SIZE);

                //variable initialization for every game
                round = 0;
                player = 1;
                gameWin = false;

                //do-while loop: win || round > 9 will exit the loop

                    //display game heading, game information, real-time 3x3 grid boardArray
                    cout << "** 2) Local 2 Players Mode **" << endl;

                    cout << endl;

                    cout << "It is now Player " << player << "'s turn!" << endl;

                    showBoard(boardArray,SIZE);

                    cout << endl;

                    cout << "Which location you want to mark?: ";

                    //ask for user input for grid entry, pass the validated input
                    getMove(boardArray, player);

                    //round counter
                    round++;

                    //implemented when if (round >= 5), here for testing only
                    gameWin = checkWin(boardArray, SIZE);

                    //if gameWin == false and in round 9, then draw situation is spotted, display draw message
                    if ((round == 9) && (gameWin == false))
                    {

                        cout << "** 2) Local 2 Players Mode **" << endl;

                        showBoard(boardArray,SIZE);

                        cout << endl;

                        cout << "This is a tied game!" << endl;
                    }

                    //display win message
                    if (gameWin == true)
                    {

                        cout << "** 2) Local 2 Players Mode **" << endl;

                        showBoard(boardArray,SIZE);

                        cout << endl;

                        cout << "Player" << player << " wins the game!" << endl;

                        cout << endl;
                    }

                    //swap player for 1 and 2 for every rounds
                    playerSwap(player);

                    //ask for play again
                    cout << "Do you want to play again [y/n]?: ";

                    nextGame = playAgain();

                    byeMessage();

                break;
            }

        //BOT mode
        case 3:
        {
            //do-while loop: exit when user entered n for playAgain(), loop otherwise

            //variable initialization for every game
            round = 1;
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

            showBoard(boardArray,SIZE);

            cout << endl;

            if (player == 1)
            {
                cout << "Which location you want to mark?: ";

                //ask for user input for grid entry, pass the validated input
                getMove(boardArray, player);
            }

            else

            {
                getBotMove(boardArray);
                //implemented if (round = 3), here for testing only
                botCheck = botCheckWinLose(boardArray, SIZE, botIndex);
            }

            //round counter
            round++;

            //implemented when if (round >= 5), here for testing only
            gameWin = checkWin(boardArray, SIZE);

            //if gameWin == false and in round 9, then draw situation is spotted, display draw message
            if ((round == 9) && (gameWin == false))
            {
                if ((round == 9) && (gameWin == false))
                {
                    system("CLS");

                    cout << "** 3) Play with BOT **" << endl;

                    showBoard(boardArray,SIZE);

                    cout << endl;

                    cout << "This is a tied game!" << endl;
                }
            }

            //display win message based on who is the winner
            if (gameWin == true)
            {

                cout << "** 3) Play with BOT **" << endl;

                showBoard(boardArray,SIZE);

                cout << endl;

                    if (player == 1)

                        cout << "You win the game!" << endl;

                    else

                        cout << "BOT wins the game!" << endl;
            }

            //swap player for 1 and 2 for every rounds
            playerSwap(player);

            cout << "repeat the game until round > 9 || win" << endl;

            //ask for play again
            cout << "Do you want to play again [y/n]?: ";

            nextGame = playAgain();

            byeMessage();

            break;
        }

        //case to exit the program
        case 4:
            {
                cout << "See you next time! Bye!" << endl;

                break;
            }

        default:
            {
                cout << "invalid input!" << endl;
                preference = 4 ;
                break;
            }
        }

    } while (preference != 4);

    return 0;
}
