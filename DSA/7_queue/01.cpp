#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
    int front;
    int rear;
    int* arr;
    int size;

    MyQueue(int size) {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }

    void enqueue(int val) {
        if(rear+1 == size) {
            cout << "Queue overflow" << endl;
            return;
        }

        if(front == -1) {
            front = 0;
        }
        arr[++rear] = val;
    }

    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        front++;
    }

    int peek() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        return arr[front];
    }
};

int main() {
    MyQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.dequeue();
    q.dequeue();

    cout << q.peek() << endl;
} 