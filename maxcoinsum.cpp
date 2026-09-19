#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of coins: ";
    cin>>n;

    int coins[n];
    cout<<"Enter the values of the coins: ";
    for(int i=0; i<n; i++) {
        cin>>coins[i];
    }

    cout<<"\nInitial arrangement of coins:"<<endl;
    for(int i=0; i<n; i++) {
        cout<< coins[i] << " ";
    }
    cout << endl;


    // DP table
    int dp[n][n] = {0};

    // Base case:
    // When there is only one coin, Player 1 takes it.
    for (int i = 0; i < n; i++) {
        dp[i][i] = coins[i];
    }


    // Fill the DP table
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            // Player 1 picks the left coin
            int leftChoice =
                coins[i] +
                min(dp[i + 2][j], dp[i + 1][j - 1]);

            // Player 1 picks the right coin
            int rightChoice =
                coins[j] +
                min(dp[i + 1][j - 1], dp[i][j - 2]);

            // Player 1 chooses the better option
            dp[i][j] = max(leftChoice, rightChoice);
        }
    }


    // Display DP table
    cout << "\nDP Table:\n\n";

    cout << "     ";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {

        cout << i << "    ";

        for (int j = 0; j < n; j++) {

            if (j < i)
                cout << "-\t";
            else
                cout << dp[i][j] << "\t";
        }

        cout << endl;
    }


    // Maximum guaranteed score
    cout << "\nMaximum guaranteed score for Player 1: "
         << dp[0][n - 1] << endl;


    // Complexity
    cout << "\nTime Complexity: O(n^2)" << endl;
    cout << "Space Complexity: O(n^2)" << endl;


    // Testing for different input sizes
    cout << "\nTesting for different input sizes:\n";

    int testSizes[] = {10, 50, 100, 200, 500};

    cout << "\nInput Size\tExecution Time (microseconds)\n";

    for (int size : testSizes) {

        // Generate test coin values
        int testCoins[size];

        for (int i = 0; i < size; i++) {
            testCoins[i] = (i % 100) + 1;
        }

        int testDP[size][size] = {0};

        // Start timer
        auto start = chrono::high_resolution_clock::now();

        // Base case
        for (int i = 0; i < size; i++) {
            testDP[i][i] = testCoins[i];
        }

        // Fill DP table
        for (int length = 2; length <= size; length++) {

            for (int i = 0; i <= size - length; i++) {

                int j = i + length - 1;

                int leftChoice;

                if (i + 2 <= j)
                    leftChoice = testCoins[i] +
                                 min(testDP[i + 2][j],
                                     testDP[i + 1][j - 1]);
                else
                    leftChoice = testCoins[i];

                int rightChoice;

                if (i <= j - 2)
                    rightChoice = testCoins[j] +
                                  min(testDP[i + 1][j - 1],
                                      testDP[i][j - 2]);
                else
                    rightChoice = testCoins[j];

                testDP[i][j] = max(leftChoice, rightChoice);
            }
        }

        // Stop timer
        auto end = chrono::high_resolution_clock::now();

        auto duration =
            chrono::duration_cast<chrono::microseconds>(end - start);

        cout << size << "\t\t" << duration.count() << endl;
    }

    return 0;
}