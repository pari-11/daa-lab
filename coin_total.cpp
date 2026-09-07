#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, sum;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n + 1);

    cout << "Enter coin values: ";
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    cout << "Enter sum: ";
    cin >> sum;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Sum = 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {

            if (coins[i] > j) {
                // Cannot use current coin
                dp[i][j] = dp[i - 1][j];
            }
            else {
                // Don't use current coin + use current coin
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
    }

    // Print DP table
    cout << "\nDP Table:\n\n";

    cout << "Coins\\Sum\t";
    for (int j = 0; j <= sum; j++) {
        cout << j << "\t";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << coins[i] << "\t\t";

        for (int j = 0; j <= sum; j++) {
            cout << dp[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nNumber of ways: " << dp[n][sum];

    return 0;
}