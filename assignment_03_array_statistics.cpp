// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std

#include <iostream>
using namespace std;

double calculateSum(double numbers[], int number_of_values)
{
    double total = 0;

    for (int index = 0; index < number_of_values; index++)
    {
        total = total + numbers[index];
    }

    return total;
}

double calculateAverage(double numbers[], int number_of_values)
{
    double total = calculateSum(numbers, number_of_values);
    return total / number_of_values;
}

double findMaximum(double numbers[], int number_of_values)
{
    double maximum_value = numbers[0];

    for (int index = 1; index < number_of_values; index++)
    {
        if (numbers[index] > maximum_value)
        {
            maximum_value = numbers[index];
        }
    }

    return maximum_value;
}

double findMinimum(double numbers[], int number_of_values)
{
    double minimum_value = numbers[0];

    for (int index = 1; index < number_of_values; index++)
    {
        if (numbers[index] < minimum_value)
        {
            minimum_value = numbers[index];
        }
    }

    return minimum_value;
}

int main()
{
    int number_of_values;

    cout << "How many numbers? ";
    cin >> number_of_values;

    if (number_of_values <= 0)
    {
        cout << "Error: Number of values must be a positive integer." << endl;
        return 0;
    }

    double numbers[number_of_values];

    for (int index = 0; index < number_of_values; index++)
    {
        cout << "Enter number " << index + 1 << ": ";
        cin >> numbers[index];
    }

    double total = calculateSum(numbers, number_of_values);
    double average = calculateAverage(numbers, number_of_values);
    double maximum_value = findMaximum(numbers, number_of_values);
    double minimum_value = findMinimum(numbers, number_of_values);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum_value << endl;
    cout << "Minimum: " << minimum_value << endl;

    return 0;
}