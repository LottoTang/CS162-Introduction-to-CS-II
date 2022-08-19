#ifndef WEEK4BFUNCTIONS_H_INCLUDED
#define WEEK4BFUNCTIONS_H_INCLUDED
//ID: L00690656 W4_Part B

int const HARD_ROW = 5, HARD_COL = 6, EASY_ROW = 4, EASY_COL = 4, MOVE_SIZE = 2, EASY_SCORE = 8, HARD_SCORE = 15;

char const SPACE = ' ', UNKNOWN = 'X';

int getInteger(int min, int max);

bool yesNo();

inline int getIndex (int rowIndex, int colIndex, int colLength);

void pressContinue();

void showMenu();

void displayInstruction();

void shuffle (char *gameArray, int arrayLength);

char *createBoard(int choice, int arrayLength);

void showBoard(char const *gameArray, int rowLength, int colLength, int round);

void getMove (char const *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE]);

void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int round);

void getMove (char const *gameArray, int rowLength, int colLength, int moveArray1[MOVE_SIZE], int moveArray2[MOVE_SIZE]);

void showBoard(char const *gameArray, int rowLength, int colLength, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int round);

bool checkMatch (char const *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength, int &score);

void updateBoard (char *gameArray, int const moveArray1[MOVE_SIZE], int const moveArray2[MOVE_SIZE], int colLength);

#endif // WEEK4BFUNCTIONS_H_INCLUDED
