#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    bool visited[100] = {false};

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Duplicate elements are: ";

    for (int i = 0; i < n; i++) {

        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }

        if (count > 1)
            cout << arr[i] << " ";
    }

    return 0;
}