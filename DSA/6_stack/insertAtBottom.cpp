#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int val) {
    if(st.empty()) {
        st.push(val);
        return;
    }
    int p = st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(p);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    insertAtBottom(st, 10);

    cout << "Stack after inserting element at bottom: " << endl;
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}