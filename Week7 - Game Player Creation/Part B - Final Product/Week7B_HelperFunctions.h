#ifndef WEEK7B_HELPERFUNCTIONS_H_INCLUDED
#define WEEK7B_HELPERFUNCTIONS_H_INCLUDED
#include "Week7B_Player.h"

//ID: L00690656 Week7B_ver2

using std:: string;

int const MIN = 5;
int const MAX_PLAYER = 10;
int const MAX_AGE = 90;

int getInteger(int const min, int const max);

string checkClass();

Player **createPlayer(int const num_player);

void displayPlayers (Player * const *const gamerArray, int const num_player);

#endif // WEEK7B_HELPERFUNCTIONS_H_INCLUDED
