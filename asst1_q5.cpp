#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of N: ";
    cin >> n;

    int arr[100];
    int sum = 0;

    cout << "Enter " << n - 1 << " numbers: ";

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int total = n * (n + 1) / 2;

    cout << "The missing number is: " << total - sum;

    return 0;
}