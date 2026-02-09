#include <bits/stdc++.h>
using namespace std;

//using array
class myStack {
    public:
    int* arr;
    int top;
    int size;

    myStack(int size) {
        top = -1;
        arr = new int[size];
        this->size = size;
    }

    bool isEmpty() {
        return (top == -1); 
    }

    bool isFull() {
        if(top >= size) return true;
        else return false;
    }

    void push(int val) {
        if(top+1 == size) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    myStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    st.pop();
    cout << st.peek() << endl;

    //printing stack elements
    while(!st.isEmpty()) {
        cout << st.peek() << " ";
        st.pop();
    }
}