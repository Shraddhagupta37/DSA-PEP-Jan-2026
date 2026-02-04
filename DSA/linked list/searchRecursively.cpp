#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool searchKey(Node* head, int key) {
    if(head == NULL) return false;

    if(head->data == key) return true;
    return searchKey(head->next, key);
}

int main() {
    Node* n1 = new Node(33);
    Node* n2 = new Node(42);
    Node* n3 = new Node(18);
    Node* n4 = new Node(11);
    Node* n5 = new Node(17);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << "Key found: " << searchKey(n1, 42) << endl;
}