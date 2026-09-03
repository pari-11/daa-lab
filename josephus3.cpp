#include <iostream>
using namespace std;


// Recursive function to find the survivor
int josephus(int n, int k) {

    // Base case:
    // If only one person is left, their index is 0
    if (n == 1)
        return 0;

    // Recursive case:
    // Find the survivor for n-1 people
    // and calculate its new position after adding k
    return (josephus(n - 1, k) + k) % n;
}


int main() {

    // Variables:
    // n = number of people
    // k = step/counting number
    int n, k;

    // Take the number of people as input
    cout << "Enter the number of people (n): ";
    cin >> n;

    // Take the step count as input
    cout << "Enter the step count (k): ";
    cin >> k;

    // Call the recursive josephus function
    // +1 is used because the function uses 0-based indexing
    // while people are numbered from 1
    cout << "Survivor = " << josephus(n, k) + 1 << endl;

    return 0;
}
