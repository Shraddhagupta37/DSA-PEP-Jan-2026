#include <bits/stdc++.h>
using namespace std;

int main() {
    //using stack from STL
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    cout << st.size() << endl;
    cout << (st.empty() ? "Empty" : "Not Empty") << endl;
}