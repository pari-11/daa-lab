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
    int n;
    cout<<"Enter the number of servers: ";
    cin>>n;
    
    //create a linked list
    Node* head = new Node(0);
    Node* temp = head;

    for(int i=1; i<=n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    //make it circular
    temp->next = head;
    
    //print before balancing/shedding
    cout<<"Before elimination: ";

    temp = head; //bring temp back to head
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);
    cout<<endl;

    int count = n; 
    Node* current = head;
    Node* previous = temp;

    while(current->next != current) {
        for(int i=0; i<n; i++) {
            if(int sum%2 == 0) {

            }
        }
    }

}
