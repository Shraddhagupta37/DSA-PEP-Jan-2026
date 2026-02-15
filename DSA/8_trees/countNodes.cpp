#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countNodes(Node* root) {
    if(root == NULL) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

int countLeafNodes(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) 
        return 1;

    int leftCount = countLeafNodes(root->left);
    int rightCount = countLeafNodes(root->right);
    return leftCount + rightCount;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;
}