#include <iostream>
#include "Week4BFunctions.h"
//ID: L00690656 W4_Part B

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //variable declaration and initialization
    int choice = 0, preference = 0, round = 1, score = 0;
    int arrayLength = 0, rowLength = 0, colLength = 0;
    int moveArray1[MOVE_SIZE] = {};
    int moveArray2[MOVE_SIZE] = {};

    //outermost do-while loop: exit the whole program when (preference == 3)
    do
    {
        showMenu();

        //ask for user's preference
        preference = 0;
        preference = getInteger(1,3);

        //action based on preference
        switch (preference)
        {
            //display game instruction (1st: full; 2+: simplified version)
            case 1:
                {
                    displayInstruction();
                    pressContinue();
                    break;
                }
            //memory game
            case 2:
                {
                    do
                    {
                        //variable declaration and initialization
                        bool guess = false;
                        int scoreWin = 0;

                        arrayLength = 0, rowLength = 0, colLength = 0;
                        score = 0, round = 1;

                        cout << "---------------------------------------------------" << endl;

                        //ask for game level
                        cout << "Select Level of Difficulty: 1) Easy; 2) Hard :";
                        choice = getInteger(1,2);

                        //game setup based on level
                        if (choice == 1)
                        {
                            arrayLength = EASY_ROW * EASY_COL;
                            rowLength = EASY_ROW;
                            colLength = EASY_COL;
                            scoreWin = EASY_SCORE;
                        }
                        else
                        {
                            arrayLength = HARD_ROW * HARD_COL;
                            rowLength = HARD_ROW;
                            colLength = HARD_COL;
                            scoreWin = HARD_SCORE;
                        }

                        //create char *gameArray (in 1D form)
                        char *gameArray = createBoard(choice, arrayLength);

                        //inner do-while loop: when (score == EASY/HARD_SCORE), ask if play again
                        do
                        {
                            //functions call - display board, get 2 moves, display updated board, check move
                            showBoard(gameArray, rowLength, colLength, round);

                            getMove(gameArray, rowLength, colLength, moveArray1);

                            showBoard(gameArray, rowLength, colLength, moveArray1, round);

                            getMove(gameArray, rowLength, colLength, moveArray1, moveArray2);

                            showBoard(gameArray, rowLength, colLength, moveArray1, moveArray2, round);

                            guess = checkMatch(gameArray, moveArray1, moveArray2, colLength, score);

                            //if 2 cards having the same content
                            if (guess)
                            {
                                updateBoard(gameArray, moveArray1, moveArray2, colLength);
                                cout << "The guess is correct :) You have matched a pair!" << endl;
                            }
                            else
                                //2 cards with different content
                                cout << "The guess is wrong:( Try again!" << endl;

                            cout << endl;

                            round++;

                            pressContinue();

                        } while (score != scoreWin);

                        //delete dynamic memory after the game
                        delete gameArray;

                        cout << endl;

                        cout << "Congratulations! You have matched all the pairs!" << endl;

                        cout << endl;

                        //ask if he/she wants to play again
                        cout << "Do you want to play again? [y/n]: ";

                    } while (yesNo());

                    break;
                }

            //exit the program
            case 3:
                {
                    break;
                }
        }

    } while (preference != 3);

    cout << "See you next time!" << endl;

    return 0;
}
