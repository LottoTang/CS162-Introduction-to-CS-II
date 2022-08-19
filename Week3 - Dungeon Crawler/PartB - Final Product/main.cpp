#include <iostream>
#include <algorithm>
#include "Week3B.h"
//ID: L00690656 - W3 PartB

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    bool play_again = true;

    //display program instruction
    displayInstruction();
    pressContinue();

    do
    {
        //variable declaration and initialization
        char dungeon[MAX_SIZE][MAX_SIZE] = {};
        int monsterLocation [2][10] = {};
        int playerLocation_Prev [2][1] = {0,0};
        int playerLocation [2][1] = {0,0};
        int traps = 7, treasures = 5, score = 100;
        int round = 1, monsters = 0;
        bool game_end = false;

        //dungeon initialization
        dungeonInitialize(dungeon);

        //create dungeon (size from MAX_SIZE, traps,treasures fixed in declaration))
        createDungeon(dungeon, traps, treasures, playerLocation);

        //do-while loop: game will iterate until player win or lose
        do
        {
            //record previous player's location [0][0]: horizontal row, [1][0]: vertical column
            playerLocation_Prev[0][0] = playerLocation[0][0];
            playerLocation_Prev[1][0] = playerLocation[1][0];

            //monster related functions
            monsterGenerator(dungeon, monsterLocation, round, monsters);
            monsterMove(dungeon, monsterLocation, monsters, round);

            //show the current dungeon
            displayDungeon(dungeon, round);

            //ask for user input [w/a/s/d]
            getMove(playerLocation);

            //check win/lose/continue
            game_end = checkMove(dungeon, playerLocation, score);

            //update dungeon's symbol
            updateDungeon(dungeon, playerLocation_Prev, playerLocation);

            //round increment
            round++;

        } while (!game_end);

        //display result when game ends
        cout << endl;

        cout << "Score for the game: ";

        if (score > 0)
            cout << score << endl;
        else
            cout << "0" << endl;

        cout << endl;

        //ask for play again, y: continue, n:exit program
        cout << "Do you want to play again? [y/n]: ";

        play_again = yesNo();

    } while(play_again);

    cout << endl;

    cout << "See you next time!" << endl;

    return 0;
}
