#include <iostream>
#include "Week3A.h"
//ID: L00690656 - W3 PartA

using std::cout;
using std::cin;
using std::endl;
using std::string;

/* void displayInstruction()
 * display game instructions
 */

void displayInstruction()
{
    //display general instructions
    cout << "void displayInstruction()" << endl;
    cout << "Display general instructions"<< endl;
    cout << endl;
}

/* bool yesNo() (equivalent to playAgain())
 * check if user input within [y,n,yes,no]
 * return true for [y,yes], false for [n,no]
 */

bool yesNo()
{
/*
    do
        ask for input
        convert to lowercase
        if input != [y/yes/n/no]
            error message
            clear input buffer
            ask for input again
        if input == y/yes
            return true
        else
            return false
    while (false)
*/
    cout << "yesNo()" << endl;
    cout << "Ask for user input [y/yes/n/no]" << endl;
    cout << "return true for [y/yes]; false for [n/no]" << endl;
    cout << endl;
    return true;
}

/* void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1])
 * randomly place the P, E, T, G into dungeon[][]
 * player's location will be stored in playerLocation[2][1] : [0][0]: horizontal row, [1][0]:vertical column
 * E, T, G will ensure will not overwrite other symbols other than '.'
 */

void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1])
{
/*  generate 2 random number (1 for row, 1 for column)
    MAX_SIZE as dungeon size
    ran_num1&2 = rand() % MAX_SIZE (ensure from 0 to MAX_SIZE)
    place the generated number to playerLocation[][], mark the cell in dungeon[][] with 'P'

    repeat the above processes with 'E', 'G', 'T'
    'E','G','T': check with in dungeon[][] is '.' first, ensure the new location is empty, if yes mark the symbol in that cell
        if not empty (with other symbols), repeat the generation process

    iterate the processes for 'G', 'T' as the parameter value
*/
    cout << "void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1])" << endl;
    cout << "generate 2 numbers - for rows and columns" << endl;
    cout << "place P/E/G/T into dungeon[][]" << endl;
    cout << "record player location into playerLocaiton[][]" << endl;
    cout << "check if dungeon[][] is '.' before marking the symbols into dungeon[][]" << endl;
    cout << endl;
}

/* void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &monsters)
 * generate monsters (at most 10) starting from round 2, generate 1 monster from every 2 rounds
 * monster's location will be stored in monsterLocation[2][10] : [0][0]: horizontal row, [1][0]:vertical column
 */

void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &mosters)
{
/*  if ((round % 2 == 0) && (monsters < 10))
    do
        generate 2 numbers
        (e.g. ran_num1 = rand() % MAX_SIZE;)
        if (dungeon[ran_num1][ran_num2] == '.')
            mark the cell with 'M'
            mark monsterLocation[0][monsters] = row
            mark monsterLocation[1][monsters] = column
            monsters++
            set as valid = true
        else
            repeat generation of numbers
            set as valid = false
    while (valid = false)
*/
    cout << "void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &monsters)" << endl;
    cout << "generate monsters starting from round 2 and for every 2 rounds" << endl;
    cout << "generate 2 random numbers, mark in dungeon[][] with 'M' and record location in monsterLocation[][]" << endl;
    cout << endl;
}

/* void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monstersLocation[2][10], int monsters, int round)
 * generate random monster's move [-1,0,1] for all monsters
 * only 1 move (either to horizontal or vertical is allowed; or stay in position)
 * monster's location will be stored in monsterLocation[2][10] : [0][0]: horizontal row, [1][0]:vertical column
 */

void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int monsters, int round)
{
 /* if (round > 3)
        for (int i = 0; i < monsters; i++)
            do
                generate 1st number in range [-1 - 1]
                e.g. ran_num1 = rand() % 3 - 1;
                if ran_num1 == 0 (no horizontal move)
                    then generate ran_num2
                    monsterAutoMove(column) = mosterLocation[][]+ran_num2
                    monsterAutoMove(Row) = monsterLocaiton[][]
                else
                    monsterAutoMove(Row) = monsterLocation[][]+ran_num1
                    monsterAutoMove(Colum) = monsterLocaiton[][]

                    check of monsterAutoMove(Column) & (Row) will not out of bound
                        out of bound: error message
                                      valid = false
                        within bound: check dungeon[monsterAutoMove_R][monsterAutoMove_C] = '.'
                                    if yes: mark with 'M'
                                            mark '.' for the original location of monster
                                            record new mosterLocation[][]
                                    if no: valid = false
            while (valid = false)
*/
    cout << "void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monstersLocation[2][10], int monsters, int round)" << endl;
    cout << "generate all monsters move after round 3" << endl;
    cout << "only 1 move (either horizontal, vertical, stay in original), no diagonal move" << endl;
    cout << "mark 'M' on dungeon[][], record monsterLocation[][] for successful move" << endl;
    cout << endl;
}

/* void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE])
 * create a dungeon in 2D array: size : MAX_SIZE * MAX_SIZE
 * initialize all the cell with '.'
 */

void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE])
{
/*for (int i = 0; i < MAX_SIZE; i++)
    for (int j = 0; j < MAX_SIZE; j++;
        dungeon[i][j] = '.';
*/
    cout << "void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE])" << endl;
    cout << "initialize dungeon in size MAX_SIZE * MAX_SIZE with all '.'" << endl;
    cout << endl;
}

/* void displayDungeon (char const dungeon[MAX_SIZE][MAX_SIZE], int round)
 * display the content of dungeon[][] with formatting
 */

void displayDungeon (char const dungeon[MAX_SIZE][MAX_SIZE], int round)
{
/*  display number of rounds
    display current dungeon[][]
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++;
            cout << " " << dungeon[i][j];
*/

    cout << "void displayDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int round)" << endl;
    cout << "display dungeon with the value of current round" << endl;
    cout << "Sample: assume size: 5*5, treasure = 2, trap = 2" << endl;
    cout << "T . . G ." << endl;
    cout << ". P . . ." << endl;
    cout << ". . . T ." << endl;
    cout << "G . . . ." << endl;
    cout << ". . . E ." << endl;
    cout << endl;

}

/* void getMove(int playerLocation[2][1])
 * ask for user to move [w/a/s/d], check if the new move is valid (not out of bound)
 * record the new move to playerLocation - [0][0]: horizontal row, [1][0]:vertical column
 */

void getMove(int playerLocation[2][1])
{
/*  do
        do
            ask for user input with data validation [w/a/s/d]
        while(valid = false)

        switch case to determine user input [w/a/s/d]
        check if new move is not out of bound
            w: move upwards; update playerLocation[][]
            a: move leftwards; update playerLocation[][]
            s: move downwards; update playerLocation[][]
            d: move rightwards; update playerLocation[][]
    while(valid = false)
*/
    cout << "void getMove(char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation[2][1])" << endl;
    cout << "ask for user input [w/a/s/d] with data validation" << endl;
    cout << "switch case to determine move up/down/left/right" << endl;
    cout << "update playerLocation[][]" << endl;
    cout << endl;
}

/* bool checkMove (char const dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation[2][1], int &score)
 * check the new move touches the symbols, change the game_end and score accordingly
 * return game_end: true when [M/T/E], false when [G/.]
 */

bool checkMove (char const dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation[2][1], int &score)
{

/*  check dungeon[playerLocation[0][0][playerLocation[1][0]]] touches which symbol
    if (dungeon[playerLocation[0][0]][playerLocation[1][0]] == 'T')
        game_end = true
        score-= 50
        lose message
    else
        check with 'G', '.' : game_end = false
        check with 'M', 'E' : game_end = true

    return game_end

*/
    cout << "bool checkMove (char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation[2][1], int &score)" << endl;
    cout << "dungeon[playerLocation[0][0]][playerLocation[1][0]] touches which symbol" << endl;
    cout << "return true when 'T','E','M'" << endl;
    cout << "return false when '.','G'" << endl;
    cout << endl;
    return false;

}

/* void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation_Prev[2][1], int const playerLocation[2][1])
 * update the dungeon from the 2D array - playerLocation_Prev[2][1], playerLocation[2][1]
 */

void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation_Prev[2][1], int const playerLocation[2][1])
{
/*
    dungeon[playerLocation_Prev[0][0]][playerLocation_Prev[1][0]] = '.';
    dungeon[playerLocation[0][0]][playerLocation[1][0]] = 'P';
*/
    cout << "void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation_Prev[2][1], int playerLocation[2][1])" << endl;
    cout << "update new playerLocation with 'P', original playerLocation with '.'" << endl;
    cout << endl;
}

/* void pressContinue()
 * intentionally pause the program for user's response
 */

void pressContinue()
{
/*
    wait for user input to continue
*/
    cout << "void pressContinue()" << endl;
    cout << "intentionally pause the program by asking user input anything to continue" << endl;
    cout << endl;
}
