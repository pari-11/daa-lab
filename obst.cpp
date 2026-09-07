#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter number of keys: ";
    cin >> n;

    vector<int> keys(n + 1);
    vector<int> freq(n + 1);

    cout << "Enter keys: ";
    for (int i = 1; i <= n; i++) {
        cin >> keys[i];
    }

    cout << "Enter frequencies: ";
    for (int i = 1; i <= n; i++) {
        cin >> freq[i];
    }

    vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));


    // Base case
    for (int i = 0; i <= n; i++) {
        C[i][i] = 0;
    }


    // length = j - i
    for (int length = 1; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length;

            C[i][j] = 99999;

            // Calculate W(i,j)
            int W = 0;

            for (int x = i + 1; x <= j; x++) {
                W = W + freq[x];
            }


            // Try every possible root k
            for (int k = i + 1; k <= j; k++) {

                int cost = C[i][k - 1] + C[k][j] + W;

                C[i][j] = min(C[i][j], cost);
            }
        }
    }


    // Print table
    cout << "\nOBST Cost Table:\n\n";

    cout << "\t";
    for (int j = 0; j <= n; j++) {
        cout << j << "\t";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {

        cout << i << "\t";

        for (int j = 0; j <= n; j++) {

            if (j < i)
                cout << "-\t";
            else
                cout << C[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nMinimum OBST Cost = " << C[0][n] << endl;

    return 0;
}