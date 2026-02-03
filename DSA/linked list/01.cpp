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

void insertAtPos(Node* head,int val, int p) {
    if(head == NULL && p>1)
        return;
    
    Node* newNode = new Node(val);
    if(p==1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current == NULL) {   //if p is > length of LL + 1, return
            cout << "Position out of bounds" << endl;
            return;
        }
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBegin(Node* &head) {
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete(temp);
}

void deleteAtEnd(Node* &head) {
    if(head == NULL) 
        return;
    
    if(head->next == NULL) {
        Node* temp = head;
        head = NULL;
        delete(temp);
        return;
    }
    
    Node* current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = NULL;
    delete(temp);
}

void deleteAtPos(Node* &head, int p) {
    if(head == NULL) return;

    if(p==1) {
        Node* temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    Node* current = head;
    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current->next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete(temp);
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

    //insertion at end
    cout << "Enter elements of LL1 (insert at end): " << endl;
    Node* head1 = NULL;
    for(int i=1;i<=n;i++) {
        int val;
        cin >> val;
        insertAtEnd(head1,val);
    }
    printList(head1);


    //insert at begining
    cout << "Enter elements of LL2 (insert at begining): " << endl;
    Node* head2 = NULL;
    for(int i=1;i<=n;i++) {
        int val;
        cin >> val;
        insertAtBegin(head2,val);
    }
    printList(head2);

    
    //insert at position
    int e, p;
    cout << "Enter element & position to insert node in LL1: ";
    cin >> e >> p;
    insertAtPos(head1, e, p);
    cout << "After trying insertion at given pos: ";
    printList(head1);


    //deletion at end
    deleteAtEnd(head1);
    cout << "LL1 after deleting last node: ";
    printList(head1);


    //deletion at begining
    deleteAtBegin(head2);
    cout << "LL2 after deleting first node: ";
    printList(head2);


    //deletion at position
    int pd;
    cout << "Enter position to delete node from LL1: ";
    cin >> pd;
    deleteAtPos(head1, pd);
    cout << "After trying deletion at given pos: ";
    printList(head1);
}