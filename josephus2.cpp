#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    int n, k;
    cout<<"Enter the number of people: ";
    cin>>n;

    cout<<"Enter the counting number: ";
    cin>>k;

    //create a linked list
    Node* head = new Node(1);
    Node* temp = head;

    for(int i=2; i<=n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    //make it circular
    temp->next = head;

    //current previous
    Node* current = head;
    Node* previous = temp;

    //elimination
    while(current->next != current) {//until there is one node left this loop will run 
        
        //moving k positions
        for(int i=1; i<k; i++) {
            previous = current;
            current = current->next;
        }

        cout<<"Eliminated: "<< current->data<<endl;

        //deleting current
        previous->next = current->next;
        delete current;

        current = previous->next;
    } 

    cout<<"Survivor: "<< current->data<<endl;

    delete current;
    return 0;
    
}
