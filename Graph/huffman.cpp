#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c; freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct cmp {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

// DFS to generate codes
void generateCodes(Node* root, string code, map<char,string> &codes){
    if(!root) return;
    if(!root->left && !root->right) { // leaf node
        codes[root->ch] = code;
    }
    generateCodes(root->left, code+"0", codes);
    generateCodes(root->right, code+"1", codes);
}

int main() {
    string s;
    cin >> s;

    // frequency map
    map<char,int> freq;
    for(char c : s) freq[c]++;

    // min-heap
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(auto p : freq){
        pq.push(new Node(p.first, p.second));
    }

    // build Huffman tree
    while(pq.size() > 1){
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();

        Node* parent = new Node('#', a->freq + b->freq);
        parent->left = a;
        parent->right = b;

        pq.push(parent);
    }

    Node* root = pq.top();

    // generate codes
    map<char,string> codes;
    generateCodes(root, "", codes);

    // print codes
    for(auto p : codes){
        cout << p.first << " : " << p.second << endl;
    }

    // encode string
    cout << "Encoded string: ";
    for(char c : s) cout << codes[c];
    cout << endl;

    return 0;
}
