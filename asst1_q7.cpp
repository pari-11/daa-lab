#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[index++] = arr[i];
    }

    while (index < n)
        arr[index++] = 0;

    cout << "Array after moving zeros to the end: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}