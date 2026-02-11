#include <bits/stdc++.h>
using namespace std;

void rearrangeQueue(queue<int> &q) {
    int n = q.size();
    if(n % 2 != 0) {
        cout << "Queue must have an even number of elements." << endl;
        return;
    }

    stack<int> st;
    int halfSize = n / 2;

    // Step 1: Push the first half of the queue onto the stack
    for(int i = 0; i < halfSize; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack back to the queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the first half of the queue to the back
    for(int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push the first half of the queue onto the stack again
    for(int i = 0; i < halfSize; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 5: Interleave the elements from the stack and the queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);


    rearrangeQueue(q);

    cout << "Rearranged Queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}