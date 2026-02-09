#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = head;
    while(current != NULL) {
        if(current->next == NULL)
            cout << current->data << endl;
        else    
            cout << current-> data << " <-> ";
        current = current->next;
    }
}

void printReverseList(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    while(current!=NULL) {
        if(current->prev == NULL)
            cout << current->data << endl;
        else    
            cout << current-> data << " <-> ";
        current = current->prev;
    }
}

void insertAtBegin(Node* &head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
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
    newNode->prev = current;
}

void insertAtPos(Node* &head, int val, int p) {
    Node* newNode = new Node(val);
    if(head == NULL && p>1) {
        head = newNode;
        return;
    }

    if(p==1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    Node* next = head->next;
    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        next = current->next;
    }
    newNode->next = next;
    newNode->prev = current;
    current->next = newNode;
    if(next) next->prev = newNode;
}

void deleteAtBegin(Node* &head) {
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    head->prev = NULL;
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
    if(head == NULL)
        return;

    if(p==1) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete(temp);
        return;
    }

    Node* current = head;
    Node* next = head->next;

    for(int i=1; i<p-1; i++) {
        current = current->next;

        if(current->next == NULL) {
            cout << "Postion out of bounds" << endl;
            return;
        }
        
        next = current->next;
    }
    Node* temp = current->next;
    current->next = next->next;
    if(next->next) next->next->prev = current;
    delete(temp);
}

int main() {
    Node* head = NULL;

    int n;
    cout << "Enter no. of elements to insert: ";
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