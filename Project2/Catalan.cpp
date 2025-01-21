/*
 * Catalan.cpp
 * 
 * This program calculates the nth Catalan number based on a command-line argument. 
 * The calculation is done recursively, and the program limits the range of acceptable 
 * inputs to avoid overflow. 
 * 
 * Usage: catalan <non-negative integer between 1-19>
 * 
 * Author: Veer Saini
 */

#include <iostream>
#include <cstdlib>
using namespace std;

// Recursive function to calculate the nth Catalan number
int catalanAlgorithm(int n) {
    // Base cases: C(0) and C(1) are both 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case: Calculate nth Catalan number by summing over
    // C(i) * C(n - i - 1) for all i from 0 to n-1
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += catalanAlgorithm(i) * catalanAlgorithm(n - i - 1);
    }

    return result;
}

// Function to check if the input is within acceptable bounds
int checkBounds(int n) {
    // Check for negative input and prompt for valid input if needed
    if (n < 0) {
        cout << "Catalan numbers are only defined for non-negative integers! \nPlease type a number between 1-19" << endl;
        return -1;
    }

    // Check if input exceeds the limit for int calculation
    if (n > 19) {
        cout << "The number is too large for the algorithm to handle! \nPlease type a number between 1-19!" << endl;
        return -1;
    }

    // Calculate and return the Catalan number if input is valid
    return catalanAlgorithm(n);
}

int main(int argc, char *argv[]) {
    // Ensure exactly one argument is passed
    if (argc != 2) {
        cout << "Error: Please type in a non-negative integer between 1-19!" << endl;
        return 1;
    }

    // Convert command-line argument to an integer
    int n = atoi(argv[1]);
    // Check input bounds and calculate the Catalan number if valid
    int result = checkBounds(n);

    // Print result if the Catalan number was successfully computed
    if (result != -1) {
        cout << result << endl;
    }

    return 0;
}