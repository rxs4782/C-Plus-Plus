/************************************************************
 *
 *   02. Rainfall Statistics
 * 
 *  Write a program that lets the user enter the total 
 *  rainfall for each of 12 months into an array of doubles. 
 *  The program should calculate and display the total 
 *  rainfall for the year, the average monthly rainfall, 
 *  and the months with the highest and lowest amounts.
 * 
 *  Input Validation: Do not accept negative numbers for 
 *  monthly rainfall figures.
 *
 * 	Jesus Hilario Hernandez
 * 	1/12/20
 *
 *************************************************************/
#include <iostream>
using namespace std;

// Global constants
const int ARRAY_SIZE = 12;

// Function Prototypes
double inputValidate(double);
void getValues(double []);
double average(double);
double calculateTotal(double []);
int findHighestMonth(double []);
int findLowestMonth(double []);
void display(double, double, int, int);


int main()
{
    double rainfall[ARRAY_SIZE];
    cout << "Enter average rainfall for each month: " << endl;
    getValues(rainfall);

    double total_rainfall = calculateTotal(rainfall);
    double avarage_rainfall = average(total_rainfall);
    int highest_month = findHighestMonth(rainfall);
    int lowest_month = findLowestMonth(rainfall);
    display(total_rainfall, avarage_rainfall, highest_month, lowest_month);

    return 0;
}

/********************************************************
 * function definitions                                 *
 ********************************************************/
double inputValidate(double user_number)
{
    while(!(cin >> user_number) || user_number < 0)
    {
        cout << "Error: please enter a positive number."
             << "Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return user_number;
}

void getValues(double array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << (i + 1)
             << ": ";
        array[i] = inputValidate(array[i]);
    }
    
}

double calculateTotal(double array[])
{
    double total = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
        total += array[i];

    return total;
}

double average(double sum)
{
    return sum / ARRAY_SIZE;
}

int findHighestMonth(double array[])
{
    double max = array[0];
    int index = 1;

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if(array[i] >= max)
        {
            max = array[i];  
            index = (i + 1); 
        }
      
    }

    return index;
}

int findLowestMonth(double array[])
{
    double min = array[0];
    int index = 1;

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if(array[i] <= min)
        {
            min = array[i];
            index = (i + 1);
        }
            
    }
    
    return index;
}

void display(double total, double average, int highest, int lowest)
{
    string months[] = {"January", "February", "March",
                       "April"  , "May"     , "June",
                       "July"   , "August"  , "September",
                       "October", "November", "December"};

    cout << "\nTotal rainfall for the year   = "
         << total
         << endl;
    
    cout << "Average monthly rainfall      = "
         << average
         << endl;
    
    cout << "Month with highest amount     = ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (highest == (i + 1))
            cout << months[i];
        
    }
    cout << endl;
    
    cout << "Month with lowest amount      = "
         << lowest
         << endl;
}