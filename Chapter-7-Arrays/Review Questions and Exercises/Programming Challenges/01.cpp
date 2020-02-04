/************************************************************
 *
 *   01. Largest/Smallest Array Values
 *
 *  Write a program that lets the user enter 10 values into 
 *  an array. The program should then display the largest 
 *  and smallest values stored in the array.
 *
 * 	Jesus Hilario Hernandez
 * 	1/12/20
 *
 *************************************************************/
#include <iostream>
using namespace std;

// Global constants
const int ARRAY_SIZE = 10;

// Prototypes
int inputValidate(int);
void getValues(int [], int);
void displayValues(int []);

int main()
{
    int user_value_array[ARRAY_SIZE];
    int user_number;

    getValues(user_value_array, user_number);
    displayValues(user_value_array);

    return 0;
}

/********************************************************
 * function definitions                                 *
 ********************************************************/
int inputValidate(int user_number)
{
    while(!(cin >> user_number))
    {
        cout << "Error: an integer must be entered. "
             << "Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return user_number;
}

void getValues(int array[], int user_number)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Enter number for element #"
             << (i + 1) << ": ";
        array[i] = inputValidate(array[i]);
    }
}

void displayValues(int array[])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "array[" << (i) << "] = "
             << array[i]
             << endl;
    }
}