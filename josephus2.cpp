#include<iostream>
using namespace std;


// Node class represents one person in the circular linked list
class Node {
public:
    int data;       // Stores the person's number
    Node* next;     // Stores address of the next person

    // Constructor to create a node
    Node(int value) {
        data = value;
        next = NULL;
    }
};


// Josephus class contains the complete Josephus logic
class Josephus {
public:
    Node* head;     // Points to the first person

    // Constructor
    Josephus() {
        head = NULL;
    }


    // Function to create the circular linked list
    void create(int n) {

        // Create the first person
        head = new Node(1);

        // temp is used to move through the list
        Node* temp = head;

        // Create remaining people from 2 to n
        for(int i = 2; i <= n; i++) {

            // Create a new node
            temp->next = new Node(i);

            // Move temp to the newly created node
            temp = temp->next;
        }

        // Connect the last node back to the first node
        // This makes the linked list circular
        temp->next = head;
    }


    // Function to perform Josephus elimination
    void solve(int k) {

        // current points to the person being counted
        Node* current = head;

        // previous points to the person before current
        Node* previous = head;


        // Find the last node of the circular linked list
        while(previous->next != head) {
            previous = previous->next;
        }


        // Continue until only one person is left
        while(current->next != current) {

            // Move k-1 positions
            for(int i = 1; i < k; i++) {

                // Move previous one step forward
                previous = current;

                // Move current one step forward
                current = current->next;
            }


            // Print the person who is eliminated
            cout << "Eliminated: " << current->data << endl;


            // Remove current from the circular linked list
            previous->next = current->next;


            // Delete the eliminated node
            delete current;


            // Start counting from the next person
            current = previous->next;
        }


        // Only one person remains
        cout << "Survivor: " << current->data << endl;


        // Delete the last remaining node
        delete current;

        // Set head to NULL
        head = NULL;
    }
};


int main() {

    // Variables for number of people and counting number
    int n, k;

    // Take number of people as input
    cout << "Enter number of people: ";
    cin >> n;

    // Take counting number as input
    cout << "Enter counting number: ";
    cin >> k;


    // Check for invalid input
    if(n <= 0 || k <= 0) {
        cout << "Invalid input";
        return 0;
    }


    // Create an object of Josephus class
    Josephus j;


    // Create the circular linked list
    j.create(n);


    // Perform the elimination
    j.solve(k);


    return 0;
}
