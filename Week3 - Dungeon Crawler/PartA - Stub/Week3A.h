#ifndef WEEK3B_H_INCLUDED
#define WEEK3B_H_INCLUDED
//ID: L00690656 - W3 PartB

int const MAX_SIZE = 8;

//function headers

void displayInstruction();

bool yesNo();

void createDungeon(char dungeon[MAX_SIZE][MAX_SIZE], int traps, int treasures, int playerLocation[2][1]);

void monsterGenerator (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int round, int &mosters);

void monsterMove (char dungeon[MAX_SIZE][MAX_SIZE], int monsterLocation[2][10], int monsters, int round);

void dungeonInitialize (char dungeon[MAX_SIZE][MAX_SIZE]);

void displayDungeon (char const dungeon[MAX_SIZE][MAX_SIZE], int round);

void getMove(int playerLocation[2][1]);

bool checkMove (char const dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation[2][1], int &score);

void updateDungeon (char dungeon[MAX_SIZE][MAX_SIZE], int const playerLocation_Prev[2][1], int const playerLocation[2][1]);

void pressContinue();

#endif // WEEK3B_H_INCLUDED
