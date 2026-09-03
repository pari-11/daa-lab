#include <iostream>
using namespace std;

// Function to solve the Josephus problem
// n = number of people
// k = step count
int josephus(int n, int k) {

    // Create an array of size n
    // arr[i] = 1 means the person is alive
    // arr[i] = 0 means the person has been eliminated
    int arr[n];

    // Initially, all people are alive
    for (int i = 0; i < n; i++)
        arr[i] = 1;

    // count = number of people currently alive
    // index = current position from where counting starts
    int count = n, index = 0;

    // Continue eliminating people until only one person remains
    while (count > 1) {

        // step keeps track of how many alive people we have counted
        int step = 0;

        // Count k alive people
        while (step < k) {

            // Only count the person if they are still alive
            if (arr[index] == 1)
                step++;

            // Stop when the kth alive person is found
            if (step == k)
                break;

            // Move to the next position
            // % n makes the index go back to 0 after reaching n-1
            index = (index + 1) % n;
        }

        // Eliminate the kth person
        arr[index] = 0;

        // One person has been eliminated
        count--;

        // Start counting again from the next position
        index = (index + 1) % n;
    }

    // Find the person who is still alive
    for (int i = 0; i < n; i++) {

        // If the person is alive, they are the survivor
        if (arr[i] == 1)
            return i + 1;  // +1 because positions are numbered from 1
    }

    // Return -1 if no survivor is found
    return -1;
}

int main() {

    // Variables for number of people and step count
    int n, k;

    // Take the number of people from the user
    cout << "Enter number of people: ";
    cin >> n;

    // Take the step count from the user
    cout << "Enter step count (k): ";
    cin >> k;

    // Call the josephus function and display the survivor
    cout << "Survivor is at position: " << josephus(n, k) << endl;

    return 0;
}
