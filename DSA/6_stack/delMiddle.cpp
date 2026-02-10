#include <bits/stdc++.h>
using namespace std;

int removeTop(stack<int> &st, int m) {
    if(st.size() == m) {
        int p = st.top();
        st.pop();
        return p;
    }
    int p = st.top();
    st.pop();
    int ans = removeTop(st, m);

    st.push(p);
    return ans;
}

int delMiddle(stack<int> &st) {
    int n = st.size();
    int m = (n%2 == 0) ? n/2+1 : n/2+1;
    
    int ans = removeTop(st, m);
    return ans;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "Middle element: " << delMiddle(st) << endl;
    cout << "Stack after deleting middle element: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}