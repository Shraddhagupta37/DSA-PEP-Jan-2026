#include <bits/stdc++.h>
using namespace std;

/*
Heap: a complete binary tree (CBT) that follows the heap order property
=> CBT: all levels are filled except the last level; the last level is filled left to right
=> Heap is not a BST

Heap order property: 
    -> Max Heap: 
        1. every parent node is greater than or equal to its children
        2. the largest element is always at root
    -> Min Heap: 
        1. every parent node is smaller than or equa; to its children
        2. the smallest element is always at root

    For 1-based indexing:
    - left child: 2 * i
    - right child: 2 * i + 1
    - parent: i / 2

    For 0-based indexing:
    - left child: 2 * i + 1
    - right child: 2 * i + 2
    - parent: (i - 1) / 2

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