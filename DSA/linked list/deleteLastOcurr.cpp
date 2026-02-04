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

void deleteLastOcurrence(Node* &head, int key) {
    if(head == NULL) return;

    Node* current = head;
    Node* before_first = NULL;
    Node* before_last = NULL;

    if(current->data == key) {
        before_first = head;
        // before_last = head;
    }

    while(current->next != NULL) {
        if(current->next->data == key && before_first == NULL){
            before_first = current;
        }

        if(current->next->data == key) {
            before_last = current;
        }

        current = current->next;
    }

    if(before_last != NULL) {
        before_last->next = before_last->next->next;
    } else if (before_first != NULL) {
        head = head->next;
    } else {
        cout << "Key not found" << endl;
        return;
    }
}

int main() {
    Node* n1 = new Node(33);
    Node* n2 = new Node(42);
    Node* n3 = new Node(18);
    Node* n4 = new Node(42);
    Node* n5 = new Node(17);
    Node* n6 = new Node(11);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    deleteLastOcurrence(n1, 42);
    printList(n1);
}