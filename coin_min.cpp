#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n + 1);

    cout << "Enter coins: ";
    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 999));

    // Amount 0 needs 0 coins
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {

            if (coins[i] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = min(dp[i - 1][j],
                               dp[i][j - coins[i]] + 1);
            }
        }
    }

    cout << "\nMinimum number of coins = "
         << dp[n][amount] << endl;

    // Print DP table
    cout << "\nDP Table:\n\n";

    cout << setw(8) << "Coin";

    for (int j = 0; j <= amount; j++)
        cout << setw(5) << j;

    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << setw(8) << coins[i];

        for (int j = 0; j <= amount; j++) {
            cout << setw(5) << dp[i][j];
        }

        cout << endl;
    }

    return 0;
}