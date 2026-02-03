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
    cout << current->data << " -> ";
    current = current->next;

    while(current != head) {
        if(current->next == head)
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
        newNode->next = head;
        return;
    }

    Node* current = head;
    while(current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}

void insertAtBegin(Node* &head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* current = head;
    while(current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtPos(Node* &head, int val, int p) {
    Node* newNode = new Node(val);
    if(head == NULL && p>1) {
        head = newNode;
        newNode->next = head;
        return;
    }

    if(p==1) {
        insertAtBegin(head, val);
        return;
    }

    Node* current = head;
    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current == head) {
            cout << "Position is out of bounds" << endl;
            return;
        }
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBegin(Node* &head) {
    if(head == NULL) return;

    if(head->next == head) {
        Node* temp = head;
        head = NULL;
        delete(temp);
        return;
    }

    Node* current = head;
    while(current->next != head) {
        current = current->next;
    }

    Node* temp = head;
    current->next = head->next;
    head = head->next;
    delete(temp);
}

void deleteAtEnd(Node* &head) {
    if(head == NULL) return;

    if(head->next == head) {
        Node* temp = head;
        head = NULL;
        delete(temp);
        return;
    }

    Node* current = head;
    while(current->next->next != head) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = head;
    delete(temp);
}

void deleteAtPos(Node* &head, int p) {
    if(head == NULL && p>1) return;

    if (p==1) {
        deleteAtBegin(head);
        return;
    }

    Node* current = head;
    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current->next == head) {
            cout << "Position is out of bounds" << endl;
            return;
        }
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete(temp);
}

int main() {
    int n;
    cout << "Enter no. of elements to insert: ";
    cin >> n;

    //insertion at end
    cout << "Enter elements of LL (insert at end): " << endl;
    Node* head = NULL;
    for(int i=1;i<=n;i++) {
        int val;
        cin >> val;
        insertAtEnd(head,val);
    }
    printList(head);

    //insertion at begining 
    int b;
    cout << "Enter element of LL (insert at beg): ";
    cin >> b;
    insertAtBegin(head, b);
    printList(head);

    //insert at position
    int e, p;
    cout << "Enter element & position to insert node in LL: ";
    cin >> e >> p;
    insertAtPos(head, e, p);
    cout << "After trying insertion at given pos: ";
    printList(head);


    //deletion at end
    deleteAtEnd(head);
    cout << "LL after deleting last node: ";
    printList(head);

    //deletion at begining
    deleteAtBegin(head);
    cout << "LL after deleting first node: ";
    printList(head);

    //deletion at position
    int pd;
    cout << "Enter position to delete node from LL1: ";
    cin >> pd;
    deleteAtPos(head, pd);
    cout << "After trying deletion at given pos: ";
    printList(head);
}