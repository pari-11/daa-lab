#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int a[10][10];

    cout << "Enter the matrix elements:\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];

    cout << "The transpose of the matrix is:\n";

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }

    return 0;
}