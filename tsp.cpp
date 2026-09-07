#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[n][n];

    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int ans = INT_MAX;

    // Start from node 1 (index 0)
    // i, j, k represent the remaining nodes
    for (int i = 1; i < n; i++) {

        for (int j = 1; j < n; j++) {

            if (j == i)
                continue;

            for (int k = 1; k < n; k++) {

                if (k == i || k == j)
                    continue;

                int total = cost[0][i]
                          + cost[i][j]
                          + cost[j][k]
                          + cost[k][0];

                ans = min(ans, total);
            }
        }
    }

    cout << "Minimum cost = " << ans << endl;

    return 0;
}