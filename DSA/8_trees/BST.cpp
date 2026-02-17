#include <bits/stdc++.h>
using namespace std;

/*
A binary search tree (BST) is a special type of binary tree where every node follows the property:
    - The value of the left child is less than the value of the parent node.
    - The value of the right child is greater than the value of the parent node.

Or: 
for evrery node: 
    - all values in the left subtree (LST) are smaller
    - all values in the right subtree (RST) are greater
Both LST and RST are also BSTs.

Property: 
    - inorder traversal of a BST gives sorted order of the elements in the tree.
*/

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

int main() {

}