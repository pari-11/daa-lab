#include <iostream>
using namespace std;

int josephusBinary(int n) {
    int power=1;
    while (power*2<=n)
        power*=2;
    return 2*(n-power)+1;
}

int main() {
    int n;
    cin>>n;
    cout<<"Survivor = "<<josephusBinary(n);
}