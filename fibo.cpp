#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    // Base cases
    if (n == 0 || n == 1)
        return n;

    // Already calculated
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Fibonacci series: ";

    for (int i = 0; i < n; i++) {
        cout << fib(i, dp) << " ";
    }

    return 0;
}