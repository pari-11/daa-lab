#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int freq;
    char data;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

class Huffmann {
    public:
    void generateCodes(Node* root, string code, unordered_map<char, string>& hc) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            hc[root->data] = code;
            return;
        }

        generateCodes(root->left, code + '0', hc);
        generateCodes(root->right, code + '1', hc);
    }    

    void buildHuffmann(string text) {
        unordered_map<char, int> freq;

        for(char ch : text) {
            freq[ch]++;
        }

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for(auto pair : freq) {
            pq.push(new Node(pair.first, pair.second)); //creating a node for every character
        }

        while(pq.size() > 1) {
            Node* left = pq.top();
            pq.pop(); //smallest element added to tree

            Node* right = pq.top();
            pq.pop(); //second smallest added to tree

            Node* parent = new Node('$', left->freq + right->freq);

            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        Node* root = pq.top();

        unordered_map<char, string> hc;
        generateCodes(root, "", hc);

        cout<<"Huffmann Codes: ";
        for(auto pair : hc) {
            cout<<pair.first << " -> " << pair.second<<endl;
        }

        string encoded = "";
        for(char ch : text) {
            encoded += hc[ch];
        }

        cout<<"Original text: "<<text<<endl;
        cout<<"Huffmann encoded text: "<<encoded;
    }
};

int main() {
    string text;
    cout<<"Enter the string: ";
    cin>>text;

    Huffmann h;
    h.buildHuffmann(text);

    return 0;
}