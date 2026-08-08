#include <iostream>
using namespace std;

int josephusArray(int n, int k) {
    int arr[1000];
    for (int i=0; i<n; i++)
        arr[i]=i+1;
    int alive=n;
    int index=0;

    while (alive>1) {
        int count=0;
        while (count<k-1) {
            index = (index+1)%n;
            if (arr[index]!=0)
                count++;
        }

        while (arr[index]==0)
            index = (index+1)%n;
        arr[index] = 0;
        do {
            index = (index+1) % n;
        } while (arr[index]==0);
        alive--;
    }

    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            return arr[i];
    return -1;
}

int main() {
    int n, k;
    cin>>n>>k;
    cout<<"Survivor = "<<josephusArray(n,k);
}