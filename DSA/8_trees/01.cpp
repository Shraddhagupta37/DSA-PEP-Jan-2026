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
    8. balanced tree: a binary tree is balanced if for every node in the tree, the difference in height between its left and right subtrees is at most 1
    9. Height -> the maximum level in a tree determines its height, the height of a node in a tree is the length of the longest path from that node to a leaf node
    10. Depth -> the depth of the node is the number of nodes along the path from the root to that node

Properties of Binary Tree --->
    1. if h = height of the binary tree, then
        a -> maximum number of leaves = 2^h 
        b -> maximum number of nodes = 2^(h+1)-1
    2. if a binary tree contains m nodes at level l, it contains at most 2m nodes at level l+1
    3. since a binary tree can contain at most 1 node at level 0(root), it can contain at most 2^l nodes at level l
    4. the total number of edges in a full binary tree with n nodes is n-1 edges

Types --->
    1. Full binary tree -> a tree of height h has all its leaves at level h, means all non leaf nodes of a full binary tree has two children, and the leaf node have no children
    2. Complete binary tree -> all levels are filled except the last level, the last level should be filled from left to right
    3. Skew binary tree -> tilted to any one side only -> left skewed binary tree and right skewed binary tree


A binary tree is balanced if for every node the height diff b/w its left & right subtree is st most one
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

    void InorderTraversal(Node* root) {
        if(root == NULL) return;

        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }

    void PreorderTraversal(Node* root) {
        if(root == NULL) return;
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }

    void PostorderTraversal(Node* root) {
        if(root == NULL) return;
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Inorder traversal: ";
    root->InorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    root->PreorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    root->PostorderTraversal(root);
    cout << endl;
    
}