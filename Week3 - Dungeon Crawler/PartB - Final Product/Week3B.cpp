#include <iostream>
#include <algorithm>
#include <ctime>
#include "Week3B.h"
//ID: L00690656 - W3 PartB

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
    cout << "** Dungeon Crawl Game **" << endl;
    cout << endl;
    cout << "Game Instruction: "<< endl;
    cout << "-----------------------------" << endl;
    cout << "You will explore the Dungeon to find the exit!" << endl;
    cout << "You can move upwards, leftwards ,downwards, and rightwards [W,A,S,D]" << endl;
    cout << "The base score is 100, every move will -1 point. Let's try to play with higher score!" << endl;
    cout << endl;
    cout << "In the journey, there are 5 symbols:" << endl;
    cout << "1. P: Player - The location of the Player." << endl;
    cout << "2. G: Treasure - (+50 points) for each treasure." << endl;
    cout << "3. T: Trap - (-50 points) - Fall into the trap and lose the game." << endl;
    cout << "4. M: Monster - (-50 points) - Starting from round 2, monsters will be generated and moved around. Lose the game when you meet them!" << endl;
    cout << "5. E: Exit - (+100 points) - You have found the exit and you win the game :D" << endl;
    cout << endl;
}

/* bool yesNo() (equivalent to playAgain())
 * check if user input within [y,n,yes,no]
 * return true for [y,yes], false for [n,no]
 */

bool yesNo()
{
    string choice;
    bool valid = true;

    do
    {
        cin >> choice;
        transform(choice.begin(),choice.end(),choice.begin(), ::tolower);

        if ((choice != "y") && (choice != "n") && (choice != "yes") && (choice != "no"))
        {
            cout << "Please enter either [y/n]: ";
            cin.clear();
            cin.ignore(10000, '\n');
            valid = false;
        }
        else
            valid = true;

    } while (!valid);

    if ((choice == "y")||(choice == "yes"))
        return true;
    else
        return false;

}

/* void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1])
 * randomly place the P, E, T, G into dungeon[][]
 * player's location will be stored in playerLocation[2][1] : [0][0]: horizontal row, [1][0]:vertical column
 * E, T, G will ensure will not overwrite other symbols other than '.'
 */

void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1])
{
    int ran_num1_r = 0;
    int ran_num2_c = 0;
    bool valid = true;

    //random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand (seed);

    //generate random move from 0 - 6
    ran_num1_r = rand() % MAX_SIZE;
    ran_num2_c = rand() % MAX_SIZE;

    //random generate player's initial location
    playerLocation[0][0] = ran_num1_r;
    playerLocation[1][0] = ran_num2_c;

    //place 'P' into dungeon array
    dungeon[playerLocation[0][0]][playerLocation[1][0]] = 'P';

    //random generation of traps, treasures based on parameters passed
    do
    {
        //random generation of exit 'E'
        ran_num1_r = rand() % MAX_SIZE;
        ran_num2_c = rand() % MAX_SIZE;

        //ensure the cell is empty ('.') and will not overwrite other symbols
        if (dungeon[ran_num1_r][ran_num2_c] == '.')
        {
            dungeon[ran_num1_r][ran_num2_c] = 'E';
            valid = true;
        }
        else
            valid = false;
    } while (!valid);

    //random generation of traps based on the numbers of traps passed from parameter
    for (int i = 0; i < traps; i++)
    {
        do
        {
            ran_num1_r = rand() % MAX_SIZE;
            ran_num2_c = rand() % MAX_SIZE;

            //ensure the cell is empty ('.') and will not overwrite other symbols
            if (dungeon[ran_num1_r][ran_num2_c] == '.')
            {
                dungeon[ran_num1_r][ran_num2_c] = 'T';
                valid = true;
            }
            else
                valid = false;
        } while (!valid);
    }

    //random generation of treasures based on the numbers of treasures passed from parameter
    for (int i = 0; i < treasures; i++)
    {
        do
        {
            ran_num1_r = rand() % MAX_SIZE;
            ran_num2_c = rand() % MAX_SIZE;

            //ensure the cell is empty ('.') and will not overwrite other symbols
            if (dungeon[ran_num1_r][ran_num2_c] == '.')
            {
                dungeon[ran_num1_r][ran_num2_c] = 'G';
                valid = true;
            }
            else
                valid = false;
        } while (!valid);
    }
}

/* void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &monsters)
 * generate monsters (at most 10) starting from round 2, generate 1 monster from every 2 rounds
 * monster's location will be stored in monsterLocation[2][10] : [0][0]: horizontal row, [1][0]:vertical column
 */

void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &monsters)
{
    int ran_num1_r = 0;
    int ran_num2_c = 0;
    bool valid = true;

    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand (seed);

    //monsters will be generated for every 2 rounds when no. of monsters < 10
    if ((round % 2 == 0) && (monsters < 10))
    {
        do
        {
            ran_num1_r = rand() % MAX_SIZE;
            ran_num2_c = rand() % MAX_SIZE;

            //ensure the cell is empty ('.') and will not overwrite other symbols
            if (dungeon[ran_num1_r][ran_num2_c] == '.')
            {
                dungeon[ran_num1_r][ran_num2_c] = 'M';

                //the row for the 1st monster will be monsterLocation[0][monsters], column: [1][monsters]
                monsterLocation[0][monsters] = ran_num1_r;
                monsterLocation[1][monsters] = ran_num2_c;

                //increment for every successful add-up for monsters
                monsters++;
                valid = true;
            }
            else
                valid = false;

        } while (!valid);
    }
}

/* void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monstersLocation[2][10], int monsters, int round)
 * generate random monster's move [-1,0,1] for all monsters
 * only 1 move (either to horizontal or vertical is allowed; or stay in position)
 * monster's location will be stored in monsterLocation[2][10] : [0][0]: horizontal row, [1][0]:vertical column
 */

void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monstersLocation[2][10], int monsters, int round)
{
    int ran_num1 = 0;
    int ran_num2 = 0;
    int trial_counter = 0;
    int monsterAutoMove_r = 0;
    int monsterAutoMove_c = 0;
    bool valid = true;

    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand (seed);

    //the 1st monster generated in round 2 will not move, all the monsters will move after round 3
    if (round > 3)
    {
        //random generation of monster's move for <monsters> times
        for (int i = 0; i < monsters; i++)
        {
            do
            {
                //initialization for every iteration
                monsterAutoMove_r = 0;
                monsterAutoMove_c = 0;

                //generate move [-1,0,1]
                ran_num1 = rand() % 3 - 1;

                //check case if horizontal-axis is unchanged
                if (ran_num1 == 0)
                {
                    //vertical move only
                    //possible cases: ran_num2 = -1,0,1
                    ran_num2 = rand() % 3 - 1;
                    monsterAutoMove_c = monstersLocation[1][i] + ran_num2;
                    monsterAutoMove_r = monstersLocation[0][i];
                }
                else
                //vertical-axis move only
                {
                    monsterAutoMove_r = monstersLocation[0][i] + ran_num1;
                    monsterAutoMove_c = monstersLocation[1][i];
                }

                //check if the new location is out of bound
                if ((monsterAutoMove_r < 0 || monsterAutoMove_r > MAX_SIZE - 1) || (monsterAutoMove_c < 0 || monsterAutoMove_c > MAX_SIZE - 1))
                    valid = false;

                //case for new location is within range
                else
                {

                    //ensure the cell is empty ('.') and will not overwrite other symbols
                    if (dungeon[monsterAutoMove_r][monsterAutoMove_c] == '.')
                    {
                        //mark the new location as 'M'
                        dungeon[monsterAutoMove_r][monsterAutoMove_c] = 'M';
                        //mark the initial location to become '.'
                        dungeon[monstersLocation[0][i]][monstersLocation[1][i]] = '.';
                        //record the new location for monster[i]
                        monstersLocation[0][i] = monsterAutoMove_r;
                        monstersLocation[1][i] = monsterAutoMove_c;
                        valid = true;
                    }
                    else
                    {
                        trial_counter++;
                        valid = false;
                    }
                }

            //the generation for each iteration will do 5 times (to minimize any unchanged move)
            //to prevent the loop if 'M' is surrounded by other symbols other than '.', in this case, monster[i] cannot move and keep looping, after 5 trials if valid = false
            //trial_counter will trigger the leave of the do-while loop
            } while ((!valid) && (trial_counter < 5)) ;
        }
    }
}

/* void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE])
 * create a dungeon in 2D array: size : MAX_SIZE * MAX_SIZE
 * initialize all the cell with '.'
 */

void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)

            dungeon[i][j] = '.';
    }
}

/* void displayDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int round)
 * display the content of dungeon[][] with formatting
 */

void displayDungeon (char const dungeon[MAX_SIZE][MAX_SIZE], int round)
{
    system("CLS");

    cout << "Dungeon Crawl - Round " << round << endl;

    cout << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            cout << " " << dungeon[i][j];
        }
        cout << endl;
    }
}

/* void getMove(char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation[2][1])
 * ask for user to move [w/a/s/d], check if the new move is valid (not out of bound)
 * record the new move to playerLocation - [0][0]: horizontal row, [1][0]:vertical column
 */

void getMove(int playerLocation[2][1])
{
    char player_move;
    bool valid = true;

    do
    {
        cout << "Enter [w,a,s,d] for your move: ";
        // data validation within w/a/s/d, pass the input when valid = true
        do
        {
            valid = true;
            cin >> player_move;
            //convert the input to lowercase for comparison
            player_move = tolower(player_move);

            //input out of [w/a/s/d]
            if ((player_move != 'w') && (player_move != 'a') && (player_move != 's') && (player_move != 'd'))
            {
                cout << "Please enter either [w,a,s,d]: ";
                //clear input buffer
                cin.clear();
                cin.ignore(10000, '\n');
                valid = false;
            }
        } while (!valid);

        //switch for selecting code for [w/a/s/d]
        switch (player_move)
        {
            //move upwards
            case 'w':
                {
                    //check if out of bound
                    if ((playerLocation[0][0] - 1) < 0)
                    {
                        cout << "You cannot go outside the dungeon! Please enter the other move!" << endl;
                        cout << endl;
                        valid = false;
                    }
                    else
                    //record the new playerLocation after the move
                    {
                        playerLocation[0][0] = playerLocation[0][0] - 1;
                    }
                    break;
                }
                //move leftwards
                case 'a':
                {
                    if ((playerLocation[0][1] - 1) < 0)
                    {
                        cout << "You cannot go outside the dungeon! Please enter the other move!" << endl;
                        cout << endl;
                        valid = false;
                    }
                    else
                    {
                        playerLocation[0][1] = playerLocation[0][1] - 1;
                    }
                    break;
                }
                //move downwards
                case 's':
                {
                    if ((playerLocation[0][0] + 1) > (MAX_SIZE - 1))
                    {
                        cout << "You cannot go outside the dungeon! Please enter the other move!" << endl;
                        cout << endl;
                        valid = false;
                    }
                    else
                    {
                        playerLocation[0][0] = playerLocation[0][0] + 1;
                    }
                    break;
                }
                //move rightwards
                case 'd':
                {
                    if ((playerLocation[0][1] + 1) > (MAX_SIZE - 1))
                    {
                        cout << "You cannot go outside the dungeon! Please enter the other move!" << endl;
                        cout << endl;
                        valid = false;
                    }
                    else
                    {
                        playerLocation[0][1] = playerLocation[0][1] + 1;
                    }
                    break;
                }
        }

        cin.clear();
        cin.ignore(10000, '\n');

    //valid is keeping true unless out of bound
    } while (!valid);

}

/* bool checkMove (char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation[2][1], int &score)
 * check the new move touches the symbols, change the game_end and score accordingly
 * return game_end: true when [M/T/E], false when [G/.]
 */

bool checkMove (char const dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation[2][1], int &score)
{
    bool game_end = false;

    //new move touching trap 'T'
    if (dungeon[playerLocation[0][0]][playerLocation[1][0]] == 'T')
    {
        cout << endl;
        cout << "You fell into the trap! You Lose :( " << endl;
        score -= 50;
        //set game_end = true
        game_end = true;
    }
    else
    {
        //new move touching exit 'E'
        if (dungeon[playerLocation[0][0]][playerLocation[1][0]] == 'E')
        {
            cout << endl;
            cout << "You escaped from the dungeon! You Win :) " << endl;
            score += 100;
            game_end = true;
        }
        else
        {
            //new move touching treasure 'G'
            if (dungeon[playerLocation[0][0]][playerLocation[1][0]] == 'G')
            {
                cout << endl;
                cout << "You got a treasure! Score + 50!" << endl;
                pressContinue();
                score += 50;
                game_end = false;
            }
            else
            {
                //new move touching monster 'M'
                if (dungeon[playerLocation[0][0]][playerLocation[1][0]] == 'M')
                {
                    cout << endl;
                    cout << "You met the monster! You Lose :( " << endl;
                    score -= 50;
                    game_end = true;
                }
                else
                //new move touching nothing '.'
                {
                    game_end = false;
                    score--;
                }
            }
        }
    }
    return game_end;
}

/* void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int playerLocation_Prev[2][1], int playerLocation[2][1])
 * update the dungeon from the 2D array - playerLocation_Prev[2][1], playerLocation[2][1]
 */

void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation_Prev[2][1], int const playerLocation[2][1])
{
    //[0][0]: horizontal row, [0][1]: vertical column
    dungeon[playerLocation_Prev[0][0]][playerLocation_Prev[1][0]] = '.';
    dungeon[playerLocation[0][0]][playerLocation[1][0]] = 'P';
}

/* void pressContinue()
 * intentionally pause the program for user's response
 */

void pressContinue()
{
    system("pause");
}
