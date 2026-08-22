#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter number of cols: ";
    cin >> n;

    int ways[n + 1];

    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    cout << ways[n] << endl;

    return 0;
}