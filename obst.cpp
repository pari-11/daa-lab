#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n; //number of frequencies/keys
    cout<<"Enter the number of keys: ";
    cin>>n;

    int keys[100];
    int freq[100];
    int C[n][n] = {0}; //initializing the cost table to 0

    cout<<"Enter the keys: ";
    for(int i=0; i<n; i++) {
        cout<<"Key "<<i<<": ";
        cin>>keys[i];
    }

    cout<<"Enter the frequencies: ";
    for(int i=0; i<n; i++) {
        cout<<"Key "<<i<<": ";
        cin>>freq[i];
    }

    //base case C[i][i]
    for(int i=0; i<n; i++) {
        C[i][i] = freq[i];
    }

    //solve according to j-i
    for(int length=1; length<n; length++) { //length = j-i
        for(int i=0; i<n-length; i++) { //index 0 1 2 3
            int j = i + length; //if j-i = 1, then if we know i=0, then its subsequent j will be 0+i =0+1 and so on

            C[i][j] = 99999; //initialise a big value so that we can compare roots according to values of k
            
            int W=0;
            for(int x=i; x<=j; x++) {
                W = W + freq[x];
            }

            for(int k=i; k<=j; k++){
                int left=0;
                int right=0;

                if(k>i) {
                    left = C[i][k - 1];
                }
                if(k<j) {
                    right = C[k + 1][j];
                }
                int cost = left + right + W;
                C[i][j] = min(C[i][j], cost);
            }
        }
    } 

        cout << "\nC Table:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (j >= i)
                cout << C[i][j] << "\t";
            else
                cout << "-\t";
        }

        cout << endl;
    }

    cout<<"\nMinimum OBST Cost = "<<C[0][n - 1]<<endl;
    return 0;
}
