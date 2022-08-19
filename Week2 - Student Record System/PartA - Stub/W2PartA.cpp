#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "W2PartA.h"

// ID: L00690656, W2_PartA

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::setw;
using std::left;
using std::endl;

/* int getInteger (int min, int max)
 * check user input (int type) within range
 * return value
 */

int getInteger (int min, int max)
{
    int value = 0;
    bool valid = true;

    do
    {
        valid = true;
        cin >> value;

        //check if value within range && int type
        if (cin.fail() || (value < min || value > max))
        {
            if (cin.fail())
                cout << "Please enter an integer: ";
            else
                cout << "Please enter within range [5-20]: ";

            //invalid input and clear input buffer
            valid = false;
            cin.clear();
            cin.ignore(10000,'\n');
        }
    } while (!valid);

    return value;
}

/* void insertArray(string nameArray[], int SIZE, int arrayCount, string name)
 * insert element based on alphabetical order (in ascending order)
 */

void insertArray(string nameArray[], int counter, string name)
{
    int index = counter - 1;

    while (index >=0 && nameArray[index] > name)
    {
        nameArray[index+1] = nameArray[index];
        index -= 1;
    }
    nameArray[index+1] = name;
    counter += 1;
}

/* void fillArray(string nameArray[], int arrayCount)
 * enter name (converted to lowercase) into array
 */

void fillArray(string nameArray[], int arrayCount)
{
    string name;
    int counter = 0;

    for (int i = 0; i < arrayCount; i++)
    {
        cout << "Name " << i+1 << " :";
        cin >> name;

        //converted name into lowercase
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        insertArray(nameArray, counter, name);
        counter++;
    }
}

/* void displayArray(string const nameArray[], int arrayCount)
 * display the index and content of the array
 * the format is good when length of name < 15 (assuming length of first/nickname < 15)
 */

void displayArray(string const nameArray[], int arrayCount)
{
    cout << setw(10) << left << "Index:" << setw(20) << "Name:" << setw(20) << endl;

    for (int i = 0; i < arrayCount; i++)
    {
        cout << setw(10) << left << i+1 << setw(20) << nameArray[i] << endl;
    }
}

/* bool binSearch (string const nameArray[], int arrayCount, string name, int &location)
 * search if the name is found in the array using binary search
 * pass in a SORTED array
 * return found (true for the name is in the array, and vice versa)
 */

bool binSearch (string const nameArray[], int arrayCount, string name, int &location)
{
    int min = 0;
    int max = arrayCount - 1;
    bool found = false;

    while ((max >= min) && (!found))
    {
        //cut the number of search into half
        int mid = (min + max) / 2;

        //found
        if ((nameArray[mid]) == name)
        {
            found = true;
            location = mid + 1;
        }
        else
        {
            //update max and min if not found (based on alphabetical order)
            if (nameArray[mid] > name)
            {
                max = mid - 1;
                found = false;
            }
            else
            {
                min = mid + 1;
                found = false;
            }
        }
    }

    return found;
}
