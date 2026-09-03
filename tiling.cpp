#include<iostream>
using namespace std;

int main() {
    // Variable to store the number of columns
    int n;

    // Take the number of columns as input
    cout << "Enter number of cols: ";
    cin >> n;

    // Array to store the number of ways for each number of columns
    int ways[n + 1];

    // Base cases
    // There are 0 ways for 0 columns
    ways[0] = 0;

    // There is 1 way for 1 column
    ways[1] = 1;

    // There are 2 ways for 2 columns
    ways[2] = 2;

    // Calculate the number of ways for 3 to n columns
    for (int i = 3; i <= n; i++) {

        // Current value = sum of the previous two values
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    // Display the total number of ways
    cout << ways[n] << endl;

    return 0;
}
