//
//  Helper.hpp
//  Player List
//
//  Created by jim bailey on 3/3/21.
//

//ID: L00690656 Week8A

#ifndef Helper_hpp
#define Helper_hpp
#include <string>
#include "W8_Player.h"

using std::string;

enum Characters {ePlayer, ePriest, eRanger, eRogue, eWizard, eNUM_CHARS};

void makePersonInfo(string & fName, string & lName, int & age);

Player * makePlayer(Characters choice);

#endif /* Helper_hpp */
