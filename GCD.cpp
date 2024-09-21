/**
 Hyeonseo Lee
 2024/09/20
 GCD.cpp
 In this program, it gets two input values in order to calculate the greatest common divisor, and returns GCD.
 */

#include <iostream>
using namespace std;
const int VALID = 1;

// GCD
/**
 This function calculates the greatest common divisor
 Parameters:
    @param first the first value / it cannot be a negative value or 0
    @param second the second value / it cannot be a negative value or 0
 Return Value:
    @return it returns the function itself with the values calculated by using Euclid's algorithm
 */
int GCD (int first, int second);

// check_invalid_numbers
/**
 This function checks the value of the numbers if they are negative value or 0
 Parameters:
    @param first the first value / it can be a positive and negative, but if it is a negative value or 0, this function will ask to the user to put another value
    @param second the second value / it can be a positive and negative, but if it is a negative value or 0, this function will ask to the user to put another value
 Return Value:
    @return it returns VALID(1) if the numbers are natural numbers.
 */
int check_invalid_numbers (int& first, int& second);

int main()
{
    int first = 0;
    int second = 0;
    int result = 0;
    int num_status = 0;
    
    // ********** First Input **********
    cout << "Enter a first value: ";
    cin >> first;
    cout << "Enter a second value: ";
    cin >> second;

    // ********** Check the status of numbers **********
    num_status = check_invalid_numbers(first, second);
    if (num_status == VALID)
    {
        result = GCD(first, second);
    }
    cout << "GCD: " << result << endl;
    return 0;
}

int GCD (int first, int second)
{
    if (second == 0)
    {
        return first;
    }
    return GCD(second, first % second);
}

int check_invalid_numbers (int& first, int& second)
{
    if (first <= 0 || second <= 0)
    {
        cout << "The value is incorrect. Try again." << endl; // check if the value is valid or unvalid
        cout << "Enter a first value: ";
        cin >> first;
        cout << "Enter a second value: ";
        cin >> second;
        return check_invalid_numbers(first, second); // try again if the value is invalid
    }
    return VALID;
}
