#include <bits/stdc++.h>
using namespace std;

class Solution{	
	public:		
		bool palindromeCheck1(string s){
			if(s.length() <= 1) return true;
			if(s[0] != s[s.length()-1]) return false;
            //Time Complexity: O(n^2), as substr creates a new string every time
			return palindromeCheck1(s.substr(1, s.length()-2));  
		}

        bool palindromeCheck2(string& s) {
            if (s.length() <= 1) return true;
            if (s.front() != s.back()) return false;
            //Modifies the original string
            s.erase(s.begin());
            s.pop_back();

            return palindromeCheck2(s);
        }

        bool palindromeCheck3(string s, int i) {
            //requires start index to be passed
            if (i >= s.length() / 2) return true;
            if (s[i] != s[s.length() - 1 - i]) return false;
            return palindromeCheck3(s, i + 1);
        }
};

int main() {
    Solution sol;
    string s = "racecar";
    if(sol.palindromeCheck1(s)){
        cout<<"Palindrome"<<endl;
    } else {
        cout<<"Not a Palindrome"<<endl;
    }
    return 0;
}