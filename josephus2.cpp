#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data=x;
        next=NULL;
    }
};

int josephusLinkedList(int n, int k) {
    Node* head=new Node(1);
    Node* temp=head;
    for (int i=2; i<=n; i++) {
        temp->next=new Node(i);
        temp=temp->next;
    }

    temp->next=head;

    Node* prev=temp;
    Node* curr=head;

    while (curr!=curr->next) {

        for (int i=1; i<k; i++) {
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        Node* del=curr;
        curr=curr->next;

        delete del;
    }

    int ans=curr->data;
    delete curr;

    return ans;
}

int main() {
    int n, k;
    cin>>n>>k;
    cout<<"Survivor = "<<josephusLinkedList(n,k);
}