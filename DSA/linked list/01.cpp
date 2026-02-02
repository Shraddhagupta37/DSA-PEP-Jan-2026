#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printList(Node* head) {
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return;
    }

    Node* current = head;
    while(current != NULL) {
        if(current->next == NULL)
            cout << current->data << endl;
        else
            cout << current->data << " -> ";
            
        current = current->next;
    }
}

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtBegin(Node* &head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

int main() {
    //static way to create LL
    // Node* n1 = new Node(1);
    // Node* head = n1;

    // Node* n2 = new Node(2);
    // n1->next = n2;

    // Node* n3 = new Node(3);
    // n2->next = n3;

    int n;
    cout << "Enter no. of elements of LL: ";
    cin >> n;
    cout << "Enter elements of LL: " << endl;

    //insertion at end
    Node* head = NULL;
    for(int i=1;i<=n;i++) {
        int val;
        cin >> val;
        insertAtEnd(head,val);
    }

    printList(head);

}