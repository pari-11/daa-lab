#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to find the winning server
int findWinner(int N) {

    // Vector to store all active servers
    vector<int> servers;

    // Initially all servers are active
    // Servers are numbered from 0 to N-1
    for (int i = 0; i < N; i++) {
        servers.push_back(i);
    }

    // Variable to keep track of the pass number
    int pass = 1;


    // Continue elimination until only one server remains
    while (servers.size() > 1) {

        // Calculate the sum of all active servers
        long long sum = 0;

        for (int x : servers) {
            sum += x;
        }


        // Vectors to store servers that remain and are dropped
        vector<int> remaining;
        vector<int> dropped;


        // Display the current pass
        cout << "\n--- Pass " << pass << " ---\n";

        // Display all currently active servers
        cout << "Active servers: ";

        for (int x : servers)
            cout << x << " ";

        // Display the calculated sum
        cout << "\nSum = " << sum;


        // If the sum is even, elimination happens clockwise
        if (sum % 2 == 0) {

            cout << " -> EVEN -> CLOCKWISE\n";

            // Start elimination from the first server
            cout << "Starting from: " << servers.front() << "\n";


            // Keep 1st server, drop 2nd,
            // keep 3rd, drop 4th, and so on
            for (int i = 0; i < servers.size(); i++) {

                if (i % 2 == 0) {
                    // Keep the server at an even index
                    remaining.push_back(servers[i]);
                }
                else {
                    // Drop the server at an odd index
                    dropped.push_back(servers[i]);
                }
            }
        }


        // If the sum is odd, elimination happens counter-clockwise
        else {

            cout << " -> ODD -> COUNTER-CLOCKWISE\n";

            // Start elimination from the last server
            cout << "Starting from: " << servers.back() << "\n";


            // Traverse the servers from the last to the first
            for (int i = servers.size() - 1; i >= 0; i--) {

                // Calculate the position while moving
                // from the last server towards the first
                int position = servers.size() - 1 - i;


                // Keep 1st server, drop 2nd,
                // keep 3rd, drop 4th, and so on
                if (position % 2 == 0) {

                    // Keep the server
                    remaining.push_back(servers[i]);
                }
                else {

                    // Drop the server
                    dropped.push_back(servers[i]);
                }
            }


            // Reverse the remaining servers
            // to keep them in ascending order
            reverse(remaining.begin(), remaining.end());
        }


        // Display the servers that were dropped
        cout << "Dropped: ";

        for (int x : dropped)
            cout << x << " ";


        // Display the servers that remain active
        cout << "\nRemaining: ";

        for (int x : remaining)
            cout << x << " ";

        cout << "\n";


        // Replace the active servers with
        // the servers that remained
        servers = remaining;

        // Move to the next pass
        pass++;
    }


    // Display the final winner
    cout << "\n========================\n";
    cout << "WINNER: Server " << servers[0] << "\n";
    cout << "========================\n";


    // Return the winning server
    return servers[0];
}


int main() {

    // Variable to store the number of servers
    int N;

    // Take the number of servers as input
    cout << "Enter number of servers: ";
    cin >> N;

    // Call the findWinner function
    findWinner(N);

    return 0;
}
