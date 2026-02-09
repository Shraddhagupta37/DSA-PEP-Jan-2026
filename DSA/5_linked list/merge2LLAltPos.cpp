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

void mergeAtAltPos(Node* &head1, Node* &head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* next1 = NULL;
    Node* next2 = NULL;

    while(curr1 && curr2) {
        next1 = curr1->next;
        next2 = curr2->next;
        
        curr1->next = curr2;
        curr2->next = next1;

        curr1= next1;
        curr2 = next2;
    }
    head2 = curr2;
}

int main() {
    Node* head1 = NULL;
    int n1; 
    cout << "Enter no. of nodes of LL1: ";
    cin >> n1;
    cout << "Enter elements of LL1: " << endl;
    for(int i=1; i<=n1; i++) {
        int val;
        cin >> val;
        insertAtEnd(head1,val);
    }

    Node* head2 = NULL;
    int n2;
    cout << "Enter no. of nodes of LL2: ";
    cin >> n2;
    cout << "Enter elements of LL2: " << endl;
    for(int i=1; i<=n2; i++) {
        int val;
        cin >> val;
        insertAtEnd(head2,val);
    }

    mergeAtAltPos(head1, head2);
    printList(head1);
}