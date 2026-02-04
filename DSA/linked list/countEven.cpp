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

int countEven(Node* head) {
    if(head == NULL) return -1;

    Node* current = head;
    int count = 0;
    while(current != NULL) {
        if(current->data % 2 == 0)
            count++;

        current = current->next;
    }
    return count;
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

    cout << "Even valued Nodes: " << countEven(n1) << endl;
}