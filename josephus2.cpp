#include <iostream>
using namespace std;

// Node class for circular linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};


// Function to solve Josephus problem
void josephus(int n, int k) {

    // Create the first node
    Node* head = new Node(1);
    Node* temp = head;

    // Create remaining nodes
    for(int i = 2; i <= n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    // Make the linked list circular
    temp->next = head;

    // Current person and previous person
    Node* current = head;
    Node* previous = temp;

    // Continue until only one person remains
    while(current->next != current) {

        // Move k-1 positions
        for(int i = 1; i < k; i++) {
            previous = current;
            current = current->next;
        }

        // Print eliminated person
        cout << "Eliminated: " << current->data << endl;

        // Remove current node
        previous->next = current->next;

        // Delete current node
        delete current;

        // Move to next person
        current = previous->next;
    }

    // Print the survivor
    cout << "Survivor: " << current->data << endl;

    // Delete final node
    delete current;
}


int main() {
    int n, k;

    cout << "Enter the number of people: ";
    cin >> n;

    cout << "Enter the counting number: ";
    cin >> k;

    // Call the Josephus function
    josephus(n, k);

    return 0;
}