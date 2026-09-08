#include <iostream>
using namespace std;

int main() {

    int n, k;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    int dp[n + 1][k + 1];

    // Fill the table
    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= k; j++) {

            // Base cases
            if (j == 0 || j == i)
                dp[i][j] = 1;

            // DP formula
            else if (j < i)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << "Binomial Coefficient = " << dp[n][k];

    return 0;
}