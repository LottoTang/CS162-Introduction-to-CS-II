#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "W2PartB.h"

// ID: L00690656, W2_PartB

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
                cout << "Please enter within range!: ";

            //invalid input and clear input buffer
            valid = false;
            cin.clear();
            cin.ignore(100000000,'\n');
        }
    } while (!valid);

    return value;
}

/* void insertArray(string nameArray[], int SIZE, int arrayCount, string name)
 * insert element based on alphabetical order (in ascending order)
 */

void insertArray(string nameArray[], string idArray[], int counter, string name, string int_string)
{
    int index = counter - 1;

    while (index >=0 && idArray[index] > int_string)
    {
        idArray[index+1] = idArray[index];
        nameArray[index+1] = nameArray[index];
        index -= 1;
    }
    idArray[index+1] = int_string;
    nameArray[index+1] = name;
    counter += 1;
}

/* void fillArray(string nameArray[], int arrayCount)
 * enter name (converted to lowercase) into array
 */

void fillArray(string nameArray[], string idArray[], int arrayCount)
{
    string name;
    string int_string;
    int idNumber;
    int counter = 0;

    for (int i = 0; i < arrayCount; i++)
    {
        cin.clear();
        cin.ignore(10000,'\n');

        cout << "Name " << i+1 << " :";
        getline(cin, name);
        //converted name into lowercase
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        //nameArray[i] = name;

        //get the last 6 digits
        cout << "ID (e.g.L00XXXXXX)(Enter 6 digits): ";
        idNumber = getInteger(0,999999);
        int_string = to_string(idNumber);

        //concentrate L00 + idNumber
        switch (int_string.length())
        {
            case 1:
                int_string = "L0000000" + to_string(idNumber);
                break;
            case 2:
                int_string = "L000000" + to_string(idNumber);
                break;
            case 3:
                int_string = "L00000" + to_string(idNumber);
                break;
            case 4:
                int_string = "L0000" + to_string(idNumber);
                break;
            case 5:
                int_string = "L000" + to_string(idNumber);
                break;
            case 6:
                int_string = "L00" + to_string(idNumber);
                break;
        }

        insertArray(nameArray, idArray, counter, name, int_string);
        counter++;

    }
}

/* void displayArray(string const nameArray[], int arrayCount)
 * display the index and content of the array
 * the format is good when length of name < 15 (assuming length of first/nickname < 15)
 */

void displayArray(string const nameArray[], string const idArray[], int arrayCount)
{  //display result with formatting
    cout << setw(10) << left << "Index:" << setw(20) << "Name:" << setw(20) << "ID:" << endl;

    for (int i = 0; i < arrayCount; i++)
    {
        cout << setw(10) << left << i+1 << setw(20) << nameArray[i] << setw(20) << idArray[i] << endl;;
    }
}

/* void selectSort (notes required: sortArray()) (string nameArray[], int arrayCount)
 * sort the user entered name into ascending order
 */

void selectSort (string nameArray[], string idArray[], int arrayCount)
{
    for (int i = 0; i < arrayCount; i++)
    {
        int minIndex = i;
        //search the elements after nameArray[minIndex]
        for (int j = i + 1; j < arrayCount; j++)
        {
            //found not in order
            if (nameArray[j] < nameArray[minIndex])
                minIndex = j;
        }

    //swap items
    swap(nameArray[i], nameArray[minIndex]);
    swap(idArray[i], idArray[minIndex]);
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

/* void pressContinue()
 * intentionally pause the program by requesting user's input
 */

void pressContinue()
{
    string temp;
    cout << endl;
    cout << "Press Anything to Continue";
    getline(cin, temp);
    cin.clear();
    cin.ignore(10000,'\n');
}
