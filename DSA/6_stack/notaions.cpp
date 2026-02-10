#include <bits/stdc++.h>
using namespace std;

int EvaluatePrefix(string str) {
    stack<int> st;
    for(int i=str.length()-1; i>=0; i--) {
        if(str[i] >= '0' && str[i] <= '9') {
            st.push(str[i] - '0');
        } else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int result;

            if(str[i] == '+')
                result = op1 + op2;
            else if(str[i] == '-')
                result = op1 - op2;
            else if(str[i] == '*') 
                result = op1 * op2;
            else if(str[i] == '/')
                result = (op2 != 0) ? op1 / op2 : 0;
            else
                result = pow(op1,op2);

            st.push(result);
        }
    }
    return st.top();
}

int EvaluatePostfix(string str) {
    stack<int> st;
    for(char c : str) {
        if(c >= '0' && c <= '9') {
            st.push(c-'0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            int result;
            if(c == '+')
                result = op1 + op2;
            else if(c == '-')
                result = op1 - op2;
            else if(c == '*') 
                result = op1 * op2;
            else if(c == '/')
                result = (op2 != 0) ? op1 / op2 : 0;
            else
                result = pow(op1,op2);

            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string str1 = "+5*92";
    cout << "Prefix Result: " << EvaluatePrefix(str1) << endl;

    string str2 = "23*62/-";
    cout << "Postfix Result: " << EvaluatePostfix(str2) << endl;

}