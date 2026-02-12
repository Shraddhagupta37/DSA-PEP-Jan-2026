#include <bits/stdc++.h>
using namespace std;

/*
Tree: non-linear, hierarchial data structure consisting of nodes connected by edges
Binary Tree: a tree is a binary tree when every node has at most 2 children

Terminology: 
    1. Leaf: a node with no children
    2. Internal: a node which is not a leaf node (has a child)
    3. Siblings: the children of same parent
    4. Length of Path: number of nodes on path - 1
    5. Ancestor & Descendent: if there is a path from node A to node B, then A is called an ancestor of B, and B is called a descendent of A
    6. Subtree: any node of a tree, with all of its descendents
    7. Level: refers to its distance from the root of the tree; the root is generally level 0
    
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