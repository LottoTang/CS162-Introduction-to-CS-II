#ifndef COMMONFUNCTIONS_H_INCLUDED
#define COMMONFUNCTIONS_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//week 1_Part B ID: L00690656

using namespace std;

//functions header
int getNumber (int min, int max);
void displayInstructions(int displayCount);
void initBoard(char boardArray[], int boardSize);
void showBoard (char const boardArray[], int boardSize);
void getMove (char boardArray[], int player);
bool checkWin (char const boardArray[], int boardSize);
bool playAgain ();
void showMenu();
void playerSwap(int &player);
void pressContinue();
int whoFirst ();
void getBotMove (char boardArray[]);
bool botCheckWinLose (char const boardArray[], int boardSize, int &botIndex);
void byeMessage();

#endif // COMMONFUNCTIONS_H_INCLUDED

