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

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    string str = "Hello How are You?";
    cout << "Reversed order of words: " << reverseWords(str) << endl;

    cout << "Reversed string: " << reverseString(str) << endl;
} 