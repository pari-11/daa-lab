#include <iostream>
using namespace std;


// Function to find the Josephus survivor using binary representation
// This method works for the Josephus problem when k = 2
int josephusBinary(int n) {

    // Start with the smallest power of 2
    int highestPower = 1;

    // Find the largest power of 2 that is less than or equal to n
    while (highestPower * 2 <= n) {
        highestPower = highestPower * 2;
    }

    // Find the number of people remaining after removing
    // the largest power of 2 from n
    int remaining = n - highestPower;

    // Calculate the survivor
    // Formula for k = 2:
    // Survivor = 2 * remaining + 1
    int survivor = 2 * remaining + 1;

    // Return the survivor
    return survivor;
}


int main() {

    // Variable to store the number of people
    int n;

    // Take the number of people as input
    cout << "Enter number of people: ";
    cin >> n;

    // Call the function and display the survivor
    cout << "Survivor = " << josephusBinary(n);

    return 0;
}
