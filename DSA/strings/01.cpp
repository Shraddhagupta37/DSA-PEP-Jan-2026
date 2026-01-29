#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseString(string str) {
    int l = 0, r = str.length()-1;
    while(l<r) {
        swap(str[l],str[r]);
        l++;
        r--;
    }
    return str;
}

bool isPalindrome(string str) {
    int l = 0, r = str.length()-1;
    while(l<r) {
        if(!isalpha(str[l])) l++; continue;
        if(!isalpha(str[r])) r--; continue;

        if(str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

string removeDuplicates(string str) {
    // Space complexity: O(n)
    // unordered_set<char> seen;
    // string ans = "";
    // for(char x: str) {
    //     if(!seen.count(x)) {
    //         seen.insert(x);
    //         ans += x;
    //     }
    // } 
    // return ans;

    // Space complexity: O(1)
    vector<bool> visited(256, false);
    string ans = "";
    for(char x : str) {
        if(!visited[x]) {
            visited[x] = true;
            ans.push_back(x);
        }
    }
    return ans;
}

int main() {
    string str1 = "hello";
    
    cout << reverseString(str1) << endl;

    cout << isPalindrome("naman") << endl;
    cout << isPalindrome("n$o^o@n") << endl; 

    cout << removeDuplicates("banana") << endl;
}   