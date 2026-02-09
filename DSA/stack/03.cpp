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


//using linked list
class MyStack {
    public:
    Node* top;

    MyStack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if(top == NULL) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.pop();

    cout << st.peek() << endl;
}