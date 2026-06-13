#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
void mathSummary(double);
double calcTax(double ,double);
void printHeader(string);
void displayResult(string, double);
void convertTime(int, int&, int&);
void countCalls();
void displayBox(int);
void displayBox(int, int);
double calcShipping(double, double  = 1.50, double  = 5);

int main()
{
    double income, rate, taxOwed;
    int totalSeconds,minutes, seconds;

    mathSummary(7.11);
    mathSummary(4.2);

    cout<< "Enter a gross income >> ";
    cin >> income;

    cout << "Enter a tax rate as a decimal >> ";
    cin >> rate;

   
    taxOwed = calcTax(income, rate);
    printHeader("COSC 1437 — Programming Fundamentals II");
    displayResult("Tax Owed: $", taxOwed);

    cout<<"Enter a number of seconds >> ";
    cin >> totalSeconds;
    convertTime(totalSeconds,minutes,seconds);
    displayResult("Converted time in minutes: ", minutes);
    displayResult("Converted time in remaining seconds: ", seconds);

    countCalls();
    countCalls();
    countCalls();
    countCalls();

    displayBox(5);
    displayBox(10,10);

    double threeArgsShipping = calcShipping(20,2.3,10);
    displayResult("Calculated shipping with three arguments passed: $", threeArgsShipping);

    double twoArgsShipping = calcShipping(50,4.2);
    displayResult("Calculated shipping with two arguments passed: $", twoArgsShipping);

    double oneArgsShipping = calcShipping(12);
    displayResult("Calculated shipping with one arguments passed: $", oneArgsShipping);

    return 0;
}

/*
    Function Name: mathSummary
    Purpose: Use the predefined cmath functions to find the 
             square root, cube, floor, ceiling, and absolute value of x
    Parameters: double x
    Return Value: void
*/
void mathSummary(double x)
{
    double squareRoot = sqrt(x);
    cout << "The square root of " << x << " is " << squareRoot << endl;

    double cubed = pow(x,3);
    cout << x <<" to the third power is " << cubed <<endl;

    double flr = floor(x);
    cout << "The floor of " << x << " is " << flr << endl;

    double ceiling = ceil(x);
    cout << "The ceiling of " << x << " is " << ceiling << endl;
   
    double absolute = fabs(x * -1);
    cout << "The absolute value of " << x << " is " << absolute << endl;
    cout << endl;
}

/*
    Function Name: calcTax
    Purpose: Returns amount of tax owed by multiplying income and tax rate together.
    Parameters: double income, double rate
    Return Value: double
*/
double calcTax(double income, double rate)
{
    double taxOwed = income * rate;
    return taxOwed;
}

/*
    Function Name: printHeader
    Purpose: Prints a formatted header by outputting title bars and the courseTitle 
             in the middle
    Parameters: string courseTitle
    Return Value: void
*/
void printHeader(string courseTitle)
{
    cout << "===========================================================" << endl;
    cout << courseTitle << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

/*
    Function Name: displayResult
    Purpose: Prints a result by outputting the label followed by the value.
    Parameters: string label, double value
    Return Value: void
*/
void displayResult(string label, double value)
{
    cout << fixed << setprecision(2);
    cout << label << value <<endl;
    cout << endl;
}

/*
    Function Name: convertTime
    Purpose: Converts a total amount of seconds into minutes and remaining seconds
    Parameters: int totalSeconds, int &minutes, int &seconds
    Return Value: void
*/
void convertTime(int totalSeconds, int &minutes, int &seconds )
{
    //Minutes and seconds are reference types because I need 
    //to alter the actual variables rather than a copy of those 
    //variables. In addition, it would be impossible to return both
    //minutes and seconds if they were value parameters.

    minutes = totalSeconds / 60;
    seconds =  totalSeconds % 60;
}

/*
    Function Name: countCalls
    Purpose: Displays the amount of times the function has been called
    Parameters: none
    Return Value: void

    A static variable is different from a regular local variable in that its value 
    persists between calls rather than resetting each call.
*/
void countCalls()
{
    static int callCount = 0;   
    callCount++;
    cout << "countCalls has been called " << callCount << " times " << endl;
    cout << endl;
}

/*
    Function Name: displayBox
    Purpose: Draws a square box (*) by multiplying width by itself
    Parameters: int width
    Return Value: void
*/
void displayBox(int width)
{
    //height of box
    for(int i = 0; i< width; i++)
    {
        //width of box
        for( int j=0; j < width; j++)
        {
            //if first or last row
            if(i == 0 || i == width-1)
            {
                 cout << "*";
            }
            else 
            {
                //first column
                if(j == 0 || j == width-1)
                {
                    cout << "*";
                }
                else
                {
                    cout <<" ";
                }
                
            }
           
        }
        cout<<endl;
    }
    cout << endl;
}

/*
    Function Name: displayBox
    Purpose: Draws a rectangular box (*) by multiplying width by height
    Parameters: int width, int height
    Return Value: void
*/
void displayBox(int width, int height)
{
    //height of box
    for(int i = 0; i< height; i++)
    {
        //width of box
        for( int j=0; j < width; j++)
        {
           //if first or last row
            if(i == 0 || i == height-1)
            {
                 cout << "*";
            }
            else 
            {
                //first column
                if(j == 0 || j == width-1)
                {
                    cout << "*";
                }
                else
                {
                    cout <<" ";
                }
                
            }
        }
        cout<<endl;
    }
    cout << endl;
}

/*
    Function Name: calcShipping
    Purpose: Calculates shipping by multiplying ratePerPound by weight and adding it to baseFee
    Parameters: double weight, double ratePerPound, double baseFee
    Return Value: double
*/
double calcShipping(double weight, double ratePerPound, double baseFee)
{
    double totalCost = baseFee + (weight*ratePerPound);
    return totalCost;
}

//function prototype

/*Test Run #1
    The square root of 7.11 is 2.66646
    7.11 to the third power is 359.425
    The floor of 7.11 is 7
    The ceiling of 7.11 is 8
    The absolute value of 7.11 is 7.11

    The square root of 4.2 is 2.04939
    4.2 to the third power is 74.088
    The floor of 4.2 is 4
    The ceiling of 4.2 is 5
    The absolute value of 4.2 is 4.2

    Enter a gross income >> 100000
    Enter a tax rate as a decimal >> .06
    ===========================================================
    COSC 1437 — Programming Fundamentals II
    ===========================================================

    Tax Owed: $6000.00

    Enter a number of seconds >> 135
    Converted time in minutes: 2.00

    Converted time in remaining seconds: 15.00

    countCalls has been called 1 times 

    countCalls has been called 2 times 

    countCalls has been called 3 times 

    countCalls has been called 4 times 

    *****
    *   *
    *   *
    *   *
    *****

    **********
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    **********

    Calculated shipping with three arguments passed: $56.00

    Calculated shipping with two arguments passed: $215.00

    Calculated shipping with one arguments passed: $23.00
*/

/*Test Run #2
    The square root of 7.11 is 2.66646
    7.11 to the third power is 359.425
    The floor of 7.11 is 7
    The ceiling of 7.11 is 8
    The absolute value of 7.11 is 7.11

    The square root of 4.2 is 2.04939
    4.2 to the third power is 74.088
    The floor of 4.2 is 4
    The ceiling of 4.2 is 5
    The absolute value of 4.2 is 4.2

    Enter a gross income >> 220000
    Enter a tax rate as a decimal >> .25
    ===========================================================
    COSC 1437 — Programming Fundamentals II
    ===========================================================

    Tax Owed: $55000.00

    Enter a number of seconds >> 101
    Converted time in minutes: 1.00

    Converted time in remaining seconds: 41.00

    countCalls has been called 1 times 

    countCalls has been called 2 times 

    countCalls has been called 3 times 

    countCalls has been called 4 times 

    *****
    *   *
    *   *
    *   *
    *****

    **********
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    *        *
    **********

    Calculated shipping with three arguments passed: $56.00

    Calculated shipping with two arguments passed: $215.00

    Calculated shipping with one arguments passed: $23.00
*/


