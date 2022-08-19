#ifndef W2PARTA_H_INCLUDED
#define W2PARTA_H_INCLUDED

// ID: L00690656, W2_PartA

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::setw;
using std::left;
using std::endl;

//function header
int getInteger (int min, int max);

void fillArray(string nameArray[], int arrayCount);

void displayArray(string const nameArray[], int arrayCount);

bool binSearch (string const nameArray[], int arrayCount, string name, int &location);

void insertArray(string nameArray[], int counter, string name);

#endif // W2PARTA_H_INCLUDED
