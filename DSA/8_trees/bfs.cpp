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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;

    if(root == NULL) return ans;
        
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for(int i=0; i<levelSize; i++) {
            Node* node = q.front();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            q.pop();

            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    
    return ans;
}

//approach 2 (using NULL):
void printLevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> level;

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        if(node != NULL) {
            cout << node->data << " ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        } else if(!q.empty()) {
            q.push(NULL);
        }
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = levelOrder(root);
    cout << "Levels of the tree:" << endl;
    for(auto level: ans) {
        for(int node: level) {
            cout << node << " ";
        }
        cout << endl;
    }

    cout << "Level order traversal: ";
    printLevelOrder(root);
}