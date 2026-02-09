#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stack<string> st;
    string word = "";
    for(char c : s) {
        if(c == ' ') {
            if(!word.empty()) st.push(word);
            word = "";
        } else {
            word += c;
        }
    }
    if(!word.empty()) st.push(word);

    string ans = "";
    while(!st.empty()) {
        ans += st.top() + " ";
        st.pop();
    }
    return ans;
}

int main() {
    string str = "Hello How are You?";
    cout << "Reversed string: " << reverseWords(str) << endl;
}