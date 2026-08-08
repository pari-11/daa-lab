#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter the size of first array: ";
    cin >> n1;

    int a[100];

    cout << "Enter the elements of first sorted array: ";
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    cout << "Enter the size of second array: ";
    cin >> n2;

    int b[100];

    cout << "Enter the elements of second sorted array: ";
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    int c[200];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];

    cout << "The merged array is: ";

    for (int i = 0; i < k; i++)
        cout << c[i] << " ";

    return 0;
}