#ifndef W2PARTB_H_INCLUDED
#define W2PARTB_H_INCLUDED

// ID: L00690656, W2_PartB

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::setw;
using std::left;
using std::endl;

//function header
int getInteger (int min, int max);

void fillArray(string nameArray[],string idArray[], int arrayCount);

void displayArray(string const nameArray[], string const idArray[], int arrayCount);

void selectSort (string nameArray[], string idArray[], int arrayCount);

bool binSearch (string const nameArray[], int arrayCount, string name, int &location);

void insertArray(string nameArray[], string idArray[], int counter, string name, string int_string);

void pressContinue();

#endif // W2PARTB_H_INCLUDED
