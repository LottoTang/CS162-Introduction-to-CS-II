#ifndef W5PARTA_H_INCLUDED
#define W5PARTA_H_INCLUDED

// ID: L00690656, W5_PartA

using std::string;

//constant (assuming maximum number of student: 999999)
int const RANGE_MIN = 0;
int const RANGE_MAX = 99999;
float const GPA_MIN = 2.00;
float const GPA_MAX = 4.20;

//struct Student declaration
struct Student
{
    string firstName;
    string lastName;
    string Lnumber;
    float gpa;

    //constructor of Student
    Student(string fName = {}, string lName = {}, string Lnum = {}, float gpa_score = 0.00)
    {
        firstName = fName; lastName = lName; Lnumber = Lnum; gpa = gpa_score;
    }

};

//function header
int getInteger (int min, int max);

string getLnumber ();

bool comparisonLastName (Student &ex1, Student &ex2);

float getGPA();

void insertArray(Student *studentArray, int counter);

Student *createArray (int arraySize);

void displayArray(Student const studentArray[], int arraySize);

bool binSearch (Student const studentArray[], int arraySize, string name, int &location);

void pressContinue();

#endif // W5PARTA_H_INCLUDED
